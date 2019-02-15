#ifndef FORMQUERY_H
#define FORMQUERY_H

#include <QWidget>

namespace Ui {
class FormQuery;
}

class FormQuery : public QWidget
{
    Q_OBJECT

public:
    explicit FormQuery(QWidget *parent = nullptr);
    ~FormQuery();

protected:
    virtual void changeEvent(QEvent * event);

private:
    Ui::FormQuery *ui;
};

#endif // FORMQUERY_H
