#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "calcworker.h"
#include <QMainWindow>


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

public slots:
    void DoWork(); 

signals:
    void ResultReady();

private:
  CalcWorker* m_calcWorker;
  QQueue< CalcResult > m_result;
};


class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void OnOutputReady();

    void on_inputLine_returnPressed();

signals:
    void ProcessOutput();

protected:
  void closeEvent( QCloseEvent * event ) override;

private:
    TypeWork FindTypeWork( const std::wstring & token ) const;
    std::string FindErrorMessage( ErrorCode ec ) const;

private:
    Ui::Calculator *ui;
    QScopedPointer< CalcWorker > m_calcWorker;
    QThread m_outputThread;
    QScopedPointer< OutputFetcher > m_outputFetcher;
};

#endif // CALCULATOR_H
