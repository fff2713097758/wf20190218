#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <dlgload.h>


QTranslator * g_transEn = new QTranslator();
QTranslator * g_transCn = new QTranslator();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    g_transCn->load("D:/G/fds/wf/wf/wf_cn.qm");
    g_transEn->load("D:/G/fds/wf/wf/wf_en.qm");

//    DlgLoad dlg;
//    if(dlg.exec() == QDialog::Accepted){

        a.installTranslator(g_transEn);

        MainWindow w;
        // w.showMaximized();
        w.showFullScreen();

        return a.exec();
//    }
//    return 0;
}
