#ifndef IMAGELIB_H
#define IMAGELIB_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class FormImageLib;
}

class FormImageLib : public QWidget
{
    Q_OBJECT

public:
    explicit FormImageLib(QWidget *parent = nullptr);
    ~FormImageLib();

private:

protected:
    virtual void resizeEvent(QResizeEvent *event);

private slots:
    void on_butClose_clicked();

private:
    Ui::FormImageLib *ui;
};

#endif // IMAGELIB_H
