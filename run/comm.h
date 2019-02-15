#ifndef COMM_H
#define COMM_H

#include <QVector>

class comm
{
public:
    comm();

    int open();

    int close();

    int send_cmd(QVector<uchar> & cmd);
};

#endif // COMM_H
