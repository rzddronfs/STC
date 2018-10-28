#ifndef CALCWORKER_H
#define CALCWORKER_H

#include "../CalcEnv/CalcEnv.h"
#include <QQueue>
#include <QMutex>
#include <QtConcurrent/QtConcurrent>


struct CalcTask
{
    TypeWork opcode = twAdd;
    double valueA = 0;
    double valueB = 0;
    double minDuration = 0; // seconds
};

struct CalcResult
{
    CalcTask task;
    double value = 0;
    ErrorCode errorCode = ecGood;
};


class CalcWorker
{
public:
    CalcWorker();
    ~CalcWorker();

    void EnqueueRequest( const CalcTask & task );
    int GetRequestsCount() const;
    int GetResultsCount() const;
    CalcResult DequeueResult();
    QQueue< CalcResult > TryDequeueResult();
    QQueue< CalcResult > WaitForResult();

private:
    void DoWork();
    ErrorCode FindErrorValue( int value ) const;
    void EnqueueResult( const CalcResult & result );

private:
    bool m_StopFlag = false;
    QMutex m_RequestMutex;
    QMutex m_ResultMutex;
    QQueue< CalcTask > m_QueueRequests;
    QQueue< CalcResult > m_QueueResults;
    QFuture< void > m_workerFuture;
    QWaitCondition m_resultCondition;
};

#endif // CALCWORKER_H
