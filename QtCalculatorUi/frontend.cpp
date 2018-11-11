#include "frontend.h"
#include "ui_frontend.h"

Frontend::Frontend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frontend)
{
    ui->setupUi(this);
}

Frontend::~Frontend()
{
    delete ui;
}
