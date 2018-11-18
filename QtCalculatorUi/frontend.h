#ifndef FRONTEND_H
#define FRONTEND_H

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

    const QString & GetTaskExpression() const { return m_taskExpression; }
    void SetResult( double value );

signals:
    void Evaluate();

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
  QString PrepareOperation( enum TypeWork opcode );

private:
    Ui::Frontend *ui;

private:
    QScopedPointer< Ui::Frontend > m_ui;
    QString m_taskExpression;
};

#endif // FRONTEND_H
