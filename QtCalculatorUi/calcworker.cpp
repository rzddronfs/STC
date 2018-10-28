#include "calcworker.h"
#include <QThread>
#include <cassert>
#include <thread>
#include <chrono>


CalcWorker::CalcWorker()
{
    m_workerFuture = QtConcurrent::run( [this](){ return this->DoWork(); } );
}

CalcWorker::~CalcWorker()
{
    m_resultCondition.wakeAll();
    QMutexLocker lock( &m_RequestMutex );
    m_StopFlag = true;
    lock.unlock();
    m_workerFuture.waitForFinished();
}


void CalcWorker::EnqueueRequest( const CalcTask & task )
{
    QMutexLocker lock( &m_RequestMutex );
    m_QueueRequests.enqueue( task );
}

CalcResult CalcWorker::DequeueResult()
{
    QMutexLocker lock( &m_ResultMutex );
    if( m_QueueResults.empty() )
    {
        assert( false );
        throw std::runtime_error( "The results queue is empty" );
    }

    return m_QueueResults.dequeue();
}

QQueue< CalcResult > CalcWorker::TryDequeueResult()
{
    QMutexLocker lock( &m_ResultMutex );

    QQueue< CalcResult > result;

    if( !m_QueueResults.empty() )
      result.push_back( m_QueueResults.dequeue() );

    return result;
}

QQueue< CalcResult > CalcWorker::WaitForResult()
{
    QMutexLocker lock( &m_ResultMutex );

    m_resultCondition.wait( &m_ResultMutex );

    QQueue< CalcResult > result;

    if( !m_QueueResults.empty() )
      result.push_back( m_QueueResults.dequeue() );

    return result;
}

int CalcWorker::GetRequestsCount() const
{
    QMutexLocker lock( const_cast< QMutex* >( &m_RequestMutex ) );
    return m_QueueRequests.size();
}

int CalcWorker::GetResultsCount() const
{
    QMutexLocker lock( const_cast< QMutex* >( &m_ResultMutex ) );
    return m_QueueResults.size();
}

ErrorCode CalcWorker::FindErrorValue( int value ) const
{
    switch( value )
    {
        case ecGood: return ecGood;
        case ecDenormalized: return ecDenormalized;
        case ecUnknownTypeWork: return ecUnknownTypeWork;
    }
    assert( false );
    throw std::logic_error( "Unknown error code" );
}

void CalcWorker::EnqueueResult( const CalcResult & result )
{  
    QMutexLocker resultLock( &m_ResultMutex );
    m_QueueResults.enqueue( result );
    resultLock.unlock();
    m_resultCondition.wakeOne();
}

void CalcWorker::DoWork()
{
   while( true )
   {
        QMutexLocker lock( &m_RequestMutex );

        if( m_StopFlag )
            break;

        if( m_QueueRequests.empty() )
            continue;

        const CalcTask & task = m_QueueRequests.dequeue();

        lock.unlock();

        CalcResult result;
        result.task = task;
        int errorCode = ecGood;

        const auto startTime = std::chrono::steady_clock::now();

        result.value = ::DoIt( task.opcode, task.valueA, task.valueB, errorCode );
        result.errorCode = FindErrorValue( errorCode );

        const auto finishTime = std::chrono::steady_clock::now();
        const auto timePassed = (finishTime - startTime);

        std::this_thread::sleep_for( result.task.minDuration * std::chrono::seconds( 1 ) - timePassed );

        EnqueueResult( result );
   }
}
