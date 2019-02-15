#ifndef PIPETHREAD_H
#define PIPETHREAD_H

#include <QThread>

class PipeThread : public QThread
{
public:
    PipeThread();

    virtual void run();
};

#endif // PIPETHREAD_H
