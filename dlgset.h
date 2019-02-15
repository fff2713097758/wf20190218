#ifndef DLGSET_H
#define DLGSET_H

#include <QDialog>
#include <QListWidgetItem>
#include "dlgsetsub1.h"
#include "dlgsetsub2.h"


namespace Ui {
class DlgSet;
}

class DlgSet : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSet(QWidget *parent = nullptr);
    ~DlgSet();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_butSave_clicked();

    void on_butExit_clicked();

private:
    DlgSetSub1 * m_formSet1;
    DlgSetSub2 * m_formSet2;

private:
    void show_page(int index);

protected:
     void resizeEvent(QResizeEvent *resizeEvent) override;
     virtual void changeEvent(QEvent *);

private:
    Ui::DlgSet *ui;
};

#endif // DLGSET_H
