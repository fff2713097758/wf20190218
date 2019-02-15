#ifndef FORMSET1_H
#define FORMSET1_H

#include <QWidget>

namespace Ui {
class DlgSetSub1;
}

class DlgSetSub1 : public QWidget
{
    Q_OBJECT

public:
    explicit DlgSetSub1(QWidget *parent = nullptr);
    ~DlgSetSub1();

private:
    Ui::DlgSetSub1 *ui;
};

#endif // FORMSET1_H
