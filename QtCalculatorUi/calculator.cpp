#include "calculator.h"
#include "ui_calculator.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <exception>


void OutputFetcher::DoWork() 
{
    m_result.swap( m_calcWorker->WaitForResult() );           
    emit ResultReady();
}

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator),
    m_calcWorker( new CalcWorker() )
{
    ui->setupUi(this);
    m_outputFetcher.reset( new OutputFetcher( *m_calcWorker ) );
    m_outputFetcher->moveToThread( &m_outputThread );
    connect( this, &Calculator::ProcessOutput, m_outputFetcher.data(), &OutputFetcher::DoWork);
    connect( m_outputFetcher.data(), &OutputFetcher::ResultReady, this, &Calculator::OnOutputReady);
    m_outputThread.start( QThread::LowestPriority );
    emit ProcessOutput();
}

Calculator::~Calculator()
{
    m_outputThread.quit();
    m_outputThread.wait();
    delete ui;
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

void Calculator::on_inputLine_returnPressed()
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
        throw std::runtime_error( "Invalid format: must be <opcode>,<value>,<value>" );

    m_calcWorker->EnqueueRequest( calcTask );

    ui->inputLine->clear();
    ui->resultsListing->appendHtml( QString( "<font color=\"green\">" ) + expression + "</font>" );
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

void Calculator::OnOutputReady()
{
  const QQueue< CalcResult > & calcResult = m_outputFetcher->GetResult();

  if( calcResult.empty() )
    return;

  const CalcResult & result = calcResult.front(); 

  std::stringstream formatter;
  formatter << std::fixed << std::setprecision( 2 );
  formatter << "<font color=\"red\">" << FindErrorMessage( result.errorCode ) << "</font>" 
    << "<font color=\"blue\">" << result.value << "</font>" << std::flush;
  
  ui->resultsListing->appendHtml( QString( formatter.str().c_str() ) );
  emit ProcessOutput();
}

void Calculator::closeEvent( QCloseEvent * event )
{
  m_calcWorker.reset();
  return QMainWindow::closeEvent( event );
}

