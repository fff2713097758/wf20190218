#ifndef MICROTHREAD_H
#define MICROTHREAD_H

#include <QThread>

class MicroThread : public QThread
{
    Q_OBJECT
public:
    MicroThread();

    virtual void run();
};

#endif // MICROTHREAD_H
