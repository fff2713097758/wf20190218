#ifndef SENDTHREAD_H
#define SENDTHREAD_H


#include <QThread>


class SendThread : public QThread
{
public:
    SendThread();

    virtual void run();
};

#endif // SENDTHREAD_H
