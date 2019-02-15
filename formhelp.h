#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class FormHelp;
}

class FormHelp : public QWidget
{
    Q_OBJECT

public:
    explicit FormHelp(QWidget *parent = nullptr);
    ~FormHelp();

private:

protected:
    virtual void resizeEvent(QResizeEvent *event);

private slots:
    void on_butClose_clicked();

private:
    Ui::FormHelp *ui;
};

#endif // HELP_H
