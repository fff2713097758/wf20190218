#ifndef FORMSOP_H
#define FORMSOP_H

#include <QWidget>

namespace Ui {
class FormSop;
}

class FormSop : public QWidget
{
    Q_OBJECT

public:
    explicit FormSop(QWidget *parent = nullptr);
    ~FormSop();

private:
    Ui::FormSop *ui;
};

#endif // FORMSOP_H
