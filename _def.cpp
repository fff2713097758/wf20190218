#include "_def.h"

//#define FLAT_BUT_STYLE "QPushButton{border-image: url(:/icon/return.png) 0 0 0 0;border:none;color:rgb(255, 255, 255);}\
//                        QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}\
//                        QPushButton:pressed{background-color: rgb(200, 62, 134);border:none;color:rgb(255, 255, 255);}"

QString get_style(QString iconName)
{
    QString s;
    s = "QPushButton{border-image: url(:/icon/";
    s += iconName;//return.png
    s += ") 0 0 0 0;border:none;color:rgb(255, 255, 255);}\
          QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}\
          QPushButton:pressed{background-color: rgb(200, 62, 134);border:none;color:rgb(255, 255, 255);}";
    return s;
}
