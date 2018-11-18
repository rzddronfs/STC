#ifndef FRONTEND_H
#define FRONTEND_H

#include "Calcworker.h"
#include <QWidget>

namespace Ui {
class Frontend;
}

class Frontend : public QWidget
{
    Q_OBJECT

public:
    explicit Frontend(QWidget *parent = nullptr);
    ~Frontend();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_evaluate_clicked();

private:
  void AppendDigit( const char* digit );
  bool AcceptValue( double* result );

private:
    Ui::Frontend *ui;

private:
    QScopedPointer< Ui::Frontend > m_ui;
    CalcTask m_calcTask;
};

#endif // FRONTEND_H
