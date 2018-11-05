#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "calcworker.h"
#include <QMainWindow>
#include <exception>


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

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void OnOutputReady();
    void OnException();
    void OnFetcherException();
    void on_inputLine_returnPressed();

signals:
    void ProcessOutput();
    void ExceptionThrown();

protected:
  void closeEvent( QCloseEvent * event ) override;

private:
    TypeWork FindTypeWork( const std::wstring & token ) const;
    std::string FindErrorMessage( ErrorCode ec ) const;

private:
    QScopedPointer< Ui::Calculator > ui;
    QScopedPointer< CalcWorker > m_calcWorker;
    QThread m_outputThread;
    QScopedPointer< OutputFetcher > m_outputFetcher;
    std::exception_ptr m_exception = nullptr;
};

#endif // CALCULATOR_H
