#ifndef FORMSET2_H
#define FORMSET2_H

#include <QWidget>

namespace Ui {
class DlgSetSub2;
}

class DlgSetSub2 : public QWidget
{
    Q_OBJECT

public:
    explicit DlgSetSub2(QWidget *parent = nullptr);
    ~DlgSetSub2();

private:
    Ui::DlgSetSub2 *ui;
};

#endif // FORMSET2_H
