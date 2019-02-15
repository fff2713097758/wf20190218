#ifndef FORMDEBUG_H
#define FORMDEBUG_H

#include <QWidget>
#include <QPushButton>
#include "formdebugsub1.h"
#include "formdebugsub2.h"
#include "formdebugsub3.h"
#include "formdebugsub4.h"
#include "formdebugsub5.h"

namespace Ui {
class FormDebug;
}

class FormDebug : public QWidget
{
    Q_OBJECT

public:
    explicit FormDebug(QWidget *parent = nullptr);
    ~FormDebug();

private:
    FormDebugSub1 * m_formDebugSub1;
    FormDebugSub2 * m_formDebugSub2;
    FormDebugSub3 * m_formDebugSub3;
    FormDebugSub4 * m_formDebugSub4;
    FormDebugSub5 * m_formDebugSub5;

private:
    void switch_debug_sub(int subIndex);

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void changeEvent(QEvent *);

private slots:
    void on_tbTab1_clicked();

    void on_tbTab2_clicked();

    void on_tbTab3_clicked();

    void on_tbTab4_clicked();

    void on_tbTab5_clicked();

    void on_butClose_clicked();

private:
    Ui::FormDebug *ui;
};

#endif // FORMDEBUG_H
