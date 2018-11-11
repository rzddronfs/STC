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

private slots:


private:
    Ui::Frontend *ui;
};

#endif // FRONTEND_H
