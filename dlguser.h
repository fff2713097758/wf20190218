#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QPushButton>


namespace Ui {
class DlgUser;
}

class DlgUser : public QDialog
{
    Q_OBJECT

public:
    explicit DlgUser(QWidget *parent = nullptr);
    ~DlgUser();

private slots:
    void on_butSave_clicked();

    void on_butExit_clicked();

private:
    void init_user_table();

private:
    QPushButton * m_butClose;

private:
    Ui::DlgUser *ui;
};

#endif // USER_H
