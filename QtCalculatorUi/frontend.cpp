#include "frontend.h"
#include "ui_frontend.h"
#include <sstream>


Frontend::Frontend(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Frontend)
{
    ui = m_ui.data();
    ui->setupUi(this);
}

Frontend::~Frontend() = default;


void Frontend::AppendDigit( const char* digit )
{
  const QString & text = ui->lineDisplay->text();
  ui->lineDisplay->setText( text + digit );
}

void Frontend::on_pushButton_clear_clicked()
{
  ui->lineDisplay->setText( "0" );
  m_calcTask = CalcTask();
}

void Frontend::on_pushButton_0_clicked()
{
  AppendDigit( "0" );
}

void Frontend::on_pushButton_1_clicked()
{
  AppendDigit( "1" );
}

void Frontend::on_pushButton_2_clicked()
{
  AppendDigit( "2" );
}

void Frontend::on_pushButton_3_clicked()
{
  AppendDigit( "3" );
}

void Frontend::on_pushButton_4_clicked()
{
  AppendDigit( "4" );
}

void Frontend::on_pushButton_5_clicked()
{
  AppendDigit( "5" );
}

void Frontend::on_pushButton_6_clicked()
{
  AppendDigit( "6" );
}

void Frontend::on_pushButton_7_clicked()
{
  AppendDigit( "7" );
}

void Frontend::on_pushButton_8_clicked()
{
  AppendDigit( "8" );
}

void Frontend::on_pushButton_9_clicked()
{
  AppendDigit( "9" );
}

void Frontend::on_pushButton_divide_clicked()
{
  m_calcTask.opcode = TypeWork::twDivide;
}

void Frontend::on_pushButton_multiply_clicked()
{
  m_calcTask.opcode = TypeWork::twMultiply;
}

void Frontend::on_pushButton_minus_clicked()
{
  m_calcTask.opcode = TypeWork::twSubtract;
}

void Frontend::on_pushButton_plus_clicked()
{
  m_calcTask.opcode = TypeWork::twAdd;
}

void Frontend::on_pushButton_point_clicked()
{
  AppendDigit( "." );
}

void Frontend::on_pushButton_evaluate_clicked()
{

}
