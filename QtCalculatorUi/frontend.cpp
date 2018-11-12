#include "frontend.h"
#include "ui_frontend.h"


Frontend::Frontend(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Frontend)
{
    ui = m_ui.data();
    ui->setupUi(this);
}

Frontend::~Frontend() = default;
