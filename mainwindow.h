#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "table.h"
#include "formmain.h"
#include "formreport.h"
#include "formquery.h"
//#include "formdebug.h"
//#include "formsop.h"


enum MAC_STATE{
    MAC_INIT,
    MAC_RUNNING,
    MAC_PAUSE,
    MAC_SHUTDOWN,
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    FormMain   * m_formMain;
    FormReport * m_formReport;
    FormQuery  * m_formQuery;
   // FormDebug  * m_formDebug;
   // FormSop    * m_formSop;

    MAC_STATE m_macState;

private:
    //void load_sample_image(QString sampleDir);
    void switch_page(uint pageIndex);

protected:
    void paintEvent(QPaintEvent *) override;

protected slots:
 //   void menu_open();

private slots:

    void on_actionDebug_triggered();

    void on_actionMain_triggered();

    void on_actionReport_triggered();

    void on_actionClose_triggered();

    void on_actionMinimize_triggered();

    void on_actionQuery_triggered();

    void on_actionSop_triggered();

    void on_actionStart_triggered();

    void on_actionShutdown_triggered();

    void on_actionSet_triggered();

    void on_actionSickinput_triggered();

    void on_actionCheck_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
