#ifndef WF_RUN_H
#define WF_RUN_H

/*
 * Code by fff
 * date : 2019.1.8
 * 设备运行控制代码类
 *
 */

#include <QVector>

typedef QVector<uchar> vtcmd;

class Wf_run
{
private:
    //设备实例管理类，仅内部使用。
    static void * m_pClassAdmin;

public:
    //为空
    Wf_run();

public:
    //初始化设备实例，调用任何设备通讯前必须调用该函数一次
    static int  create_instance();

    //释放设备实例，至此任何程序不得再调用设备通讯
    static void release_instance();

    //打开所有串口
    static int  open_comm();

    //关闭所有串口
    static void close_comm();

    //发送命令
    //[in] cmd -- 要发送的命令数组
    //ret: 设备返回的命令数组
    static vtcmd send_cmd(vtcmd cmd);

};

#endif // WF_RUN_H
