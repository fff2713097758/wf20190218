#ifndef WF_SET_H
#define WF_SET_H

/*
 * Writer : fff
 * Date : 2018.1.8
 * 参数设置类
 */

#include <QString>
#include <QVariant>


class Wf_set
{
private:
    //数据管理类，仅内部使用
    static void * m_pDataAdmin;

public:
    //为空
    Wf_set();

public:
    //创建数据管理类实例，在此之前不能调用该类任何成员函数
    static int create_instance();

    //释放数据管理类实例，在此之后不能再调用该类成员函数
    static void release_instance();


    //读取整型参数
    static int get_int(QString app, QString key, int defaultValue = 0);

    //读取浮点型参数
    static double get_double(QString app, QString key, double defaultValue = 0);

    //读取字符串型参数
    static QString get_str(QString app, QString key, QString defaultValue = (""));

    //其他类型参数读取
    static QVariant get(QString app, QString key);


    //设置整型参数
    static void set_int(QString app, QString key, int value);

    //设置浮点型参数
    static void set_double(QString app, QString key, double value);

    //设置字符串型参数
    static void set_str(QString app, QString key, QString value);

    //设置其他类型参数
    static void set(QString app, QString key, QVariant value);


};

#endif // WF_SET_H
