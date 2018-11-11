#include "calculator.h"
#include "ui_calculator.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <cassert>


void OutputFetcher::DoWork() 
{
  try
  {
    m_calcWorker->WaitForResult().swap( m_result );
    emit ResultReady();
  }
  catch( ... )
  {
    m_exception = std::current_exception();
    emit ExceptionThrown();
  }
}

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui( new Ui::Calculator ),
    m_calcWorker( new CalcWorker() )
{
    ui->setupUi(this);
    m_outputFetcher.reset( new OutputFetcher( *m_calcWorker ) );
    m_outputFetcher->moveToThread( &m_outputThread );
    connect( this, &Calculator::ProcessOutput, m_outputFetcher.data(), &OutputFetcher::DoWork);
    connect( m_outputFetcher.data(), &OutputFetcher::ResultReady, this, &Calculator::OnOutputReady);
    connect( this, &Calculator::ExceptionThrown, this, &Calculator::OnException);
    connect( m_outputFetcher.data(), &OutputFetcher::ExceptionThrown, this, &Calculator::OnFetcherException);
    m_outputThread.start( QThread::LowestPriority );
    emit ProcessOutput();
}

Calculator::~Calculator()
{
    m_outputThread.quit();
    m_outputThread.wait();
}

TypeWork Calculator::FindTypeWork( const std::wstring & token ) const
{
    constexpr std::pair< TypeWork, wchar_t > opcodeCharMap[] =
    {
        { twAdd, L'+' },
        { twSubtract, L'-' },
        { twMultiply, L'*' },
        { twDivide, L'/' },
    };

    for( const auto & opcodeCharPair : opcodeCharMap )
    {
        if( token.npos != token.find( opcodeCharPair.second ) )
            return opcodeCharPair.first;
    }

    throw std::runtime_error( "Invalid opcode" );
}

void Calculator::OnException()
{
  QString message;

  try
  {
    std::exception_ptr e = m_exception;
    m_exception = nullptr;
    std::rethrow_exception( e );
  }
  catch( const std::exception & e )
  {
    message = QString( e.what() );
  }
  catch( ... )
  {
    message = QString( "Unknown exception" );
  }

  ui->resultsListing->appendHtml( 
    EntagWithHtml( QString( "Error: " ) + message, ExceptionFormatTag() ) ); 
}

void Calculator::OnFetcherException()
{
  m_exception = m_outputFetcher->GetException();
  m_outputFetcher->ResetException();
  OnException();
}

void Calculator::on_inputLine_returnPressed()
{
  try
  {
    const QString & expression = ui->inputLine->text();
    std::wstringstream rawExpression;
    rawExpression.str( expression.toStdWString() + L'\n' );

    std::wstring token;
    std::getline( rawExpression, token, L',' );

    CalcTask calcTask;
    calcTask.opcode = FindTypeWork( token );

    struct Utility
    {
      static std::basic_istream< wchar_t > & SkipComma( std::basic_istream< wchar_t > & stream )
      {
        return stream.ignore( std::numeric_limits< std::streamsize >::max(), L',' );
      }
    };

    rawExpression >> calcTask.valueA >> Utility::SkipComma >> calcTask.valueB;

    if( !rawExpression.good() )
        throw std::runtime_error( GetInvalidFormatMessage() );

    if( (rawExpression >> Utility::SkipComma).good() )
      if( !(rawExpression >> calcTask.minDuration).good() )
        throw std::runtime_error( GetInvalidFormatMessage() );

    m_calcWorker->EnqueueRequest( calcTask );

    ui->inputLine->clear();
    ui->resultsListing->appendHtml( EntagWithHtml( expression, EchoFormatTag() ) );
  }
  catch( ... )
  {
    m_exception = std::current_exception();
    emit ExceptionThrown();
  }
}

std::string Calculator::FindErrorMessage( ErrorCode ec ) const
{
  switch( ec )
  {
    case ecGood: 
      return "Ok: ";
    case ecDenormalized: 
      return "Approximate: ";
    default:
    case ecUnknownTypeWork:
      assert( false );
      throw std::logic_error( "Invalid operation" );
  }

  assert(false);
  throw std::logic_error( "This code is supposed to be unreachable" );
}

QString Calculator::EntagWithHtml(const QString & message, ErrorCodeFormatTag) const
{
  return QString( "<font color=\"red\">" ) + message.toHtmlEscaped() + "</font>"; 
}

QString Calculator::EntagWithHtml(const QString & message, ExceptionFormatTag) const
{
  return QString( "<b><font color=\"red\">" ) + message.toHtmlEscaped() + "</font></b>";
}

QString Calculator::EntagWithHtml(const QString & message, ResultFormatTag) const
{
  return QString( "<font color=\"blue\">" ) + message.toHtmlEscaped() + "</font>";
}

QString Calculator::EntagWithHtml(const QString & message, EchoFormatTag) const
{
  return QString( "<font color=\"green\">" ) + message.toHtmlEscaped() + "</font>";
}

void Calculator::OnOutputReady()
{
  try
  {
    const QQueue< CalcResult > & calcResult = m_outputFetcher->GetResult();

    if( calcResult.empty() )
      return;

    const CalcResult & result = calcResult.front(); 

    std::stringstream formatter;
    formatter << std::fixed << std::setprecision( 2 ) << result.value << std::flush;
  
    ui->resultsListing->appendHtml(    
      EntagWithHtml( FindErrorMessage( result.errorCode ).c_str(), ErrorCodeFormatTag() )
      + EntagWithHtml( formatter.str().c_str(), ResultFormatTag() )
    );

    emit ProcessOutput();
  }
  catch( ... )
  {
    m_exception = std::current_exception();
    emit ExceptionThrown();
  }
}

void Calculator::closeEvent( QCloseEvent * event )
{
  try
  {
    m_calcWorker.reset();
    return QMainWindow::closeEvent( event );
  }
  catch( ... )
  {
    m_exception = std::current_exception();
    emit ExceptionThrown();
  }
}

