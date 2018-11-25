#include "frontend.h"
#include "ui_frontend.h"
#include "calculator.h"
#include <sstream>
#include <iomanip>
#include <cassert>


Frontend::Frontend(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Frontend)
{
    ui = m_ui.data();
    ui->setupUi(this);
}

Frontend::~Frontend() = default;

void Frontend::SetResult(double value)
{
  std::stringstream formatter;
  formatter << std::fixed << value;
  ui->lineDisplay->setText( formatter.str().c_str() );
}

void Frontend::AppendDigit( const char* digit )
{
  const QString & text = ui->lineDisplay->text();
  const QString & result = (text == "0")? digit : text + digit;
  ui->lineDisplay->setText( result );
}

QString Frontend::PrepareOperation(TypeWork opcode)
{
  QString result;

  switch(opcode)
  {
    case TypeWork::twAdd:
      result += "+";
    break;

    case TypeWork::twSubtract:
      result += "-";
    break;

    case TypeWork::twMultiply:
      result += "*";
    break;

    case TypeWork::twDivide:
      result += "/";
    break;

    default:
      assert( false );
      throw std::logic_error( "unknown operation" );
  }

  result += QString( "," ) + ui->lineDisplay->text();
  ui->lineDisplay->setText( "0" );

  return result;
}

void Frontend::on_pushButton_clear_clicked()
{
  ui->lineDisplay->setText( "0" );
  m_taskExpression.clear();
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
  m_taskExpression = PrepareOperation( TypeWork::twDivide );
}

void Frontend::on_pushButton_multiply_clicked()
{
  m_taskExpression = PrepareOperation( TypeWork::twMultiply );
}

void Frontend::on_pushButton_minus_clicked()
{
  m_taskExpression = PrepareOperation( TypeWork::twSubtract );
}

void Frontend::on_pushButton_plus_clicked()
{
  m_taskExpression = PrepareOperation( TypeWork::twAdd );
}

void Frontend::on_pushButton_point_clicked()
{
  AppendDigit( "." );
}

void Frontend::on_pushButton_evaluate_clicked()
{
  m_taskExpression += QString( "," ) + ui->lineDisplay->text();
  emit Evaluate();
}
