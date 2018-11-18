#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "calcworker.h"
#include <QMainWindow>
#include <exception>


class Frontend;


namespace Ui {
class Calculator;
}


class OutputFetcher : public QObject
{
    Q_OBJECT

public:
    explicit OutputFetcher( CalcWorker & calcWorker )
      : m_calcWorker( &calcWorker )
    {
    
    }

    const QQueue< CalcResult > & GetResult() const { return m_result; }
    std::exception_ptr GetException() const { return m_exception; }
    void ResetException() { m_exception = nullptr; }

public slots:
    void DoWork(); 

signals:
    void ResultReady();
    void ExceptionThrown();

private:
  CalcWorker* m_calcWorker;
  QQueue< CalcResult > m_result;
  std::exception_ptr m_exception = nullptr;
};


class Calculator : public QMainWindow
{
    Q_OBJECT

private:
   struct ErrorCodeFormatTag{};
   struct ExceptionFormatTag{};
   struct ResultFormatTag{};
   struct EchoFormatTag{};

public:
  static constexpr const char* GetInvalidFormatMessage() { return "Invalid format: must be <opcode>,<value>,<value>[,<timeout>]"; } 

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void OnAddTask();
    void OnOutputReady();
    void OnException();
    void OnFetcherException();
    void on_inputLine_returnPressed();

signals:
    void ProcessOutput();
    void ExceptionThrown();

protected:
  void closeEvent( QCloseEvent * event ) override;
  void setVisible( bool visible ) override;

private:
    TypeWork FindTypeWork( const std::wstring & token ) const;
    std::string FindErrorMessage( ErrorCode ec ) const;
    QString EntagWithHtml( const QString & message, ErrorCodeFormatTag ) const;
    QString EntagWithHtml( const QString & message, ExceptionFormatTag ) const;
    QString EntagWithHtml( const QString & message, ResultFormatTag ) const;
    QString EntagWithHtml( const QString & message, EchoFormatTag ) const;

// Qt wizard expects this expression
private:
    Ui::Calculator* ui;

private:
    QScopedPointer< Ui::Calculator > m_ui;
    QScopedPointer< OutputFetcher > m_outputFetcher;
    QScopedPointer< CalcWorker > m_calcWorker;
    QScopedPointer< Frontend > m_frontend;
    QThread m_outputThread;
    std::exception_ptr m_exception = nullptr;
};

#endif // CALCULATOR_H
