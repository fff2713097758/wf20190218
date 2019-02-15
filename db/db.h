#ifndef _DB_H
#define _DB_H


#include <QString>



class Result
{
public:
    qint64 ID;//          INTEGER ;
    QString name;//        VARCHAR (30),
    char sex;//         BOOLEAN (1),
    char age[7];//         CHAR (7),
    QString history;//     VARCHAR (20),
    QString bed;//         VARCHAR (20),
    QString sect;//        VARCHAR (20),
    QString diagnose;//    VARCHAR (30),
    QString sender;//      VARCHAR (20),
    QString checker;//     VARCHAR (20),
    QString review;//      VARCHAR (20),
    QString color;//       VARCHAR (10),
    QString state;//       VARCHAR (10),
    QString otherinfo;//   VARCHAR (200),
    char fobs;//        CHAR (1),
    QString fob;//         VARCHAR (6),
    char tfs;//         CHAR (1),
    QString tf;//          VARCHAR (6),
    char calps;//       CHAR (1),
    QString calp;//        VARCHAR (6),
    char rvs ;//        CHAR (1),
    QString rv  ;//        VARCHAR (6),
    char advs   ;//     CHAR (1),
    QString adv  ;//       VARCHAR (6),
    char csks    ;//    CHAR (1),
    QString csk  ;//       VARCHAR (6),
    char nvs   ;//      CHAR (1),
    QString nv ;//         VARCHAR (6),
    char hps   ;//      CHAR (1),
    QString hp ;//         VARCHAR (6),
    char cbs   ;//      CHAR (1),
    QString cb ;//         VARCHAR (6),
    char vbcs  ;//      CHAR (1),
    QString vbc  ;//       VARCHAR (6),
    QString otherchemic;// VARCHAR (200),
    QString rbc  ;//       VARCHAR (20),
    QString wbc  ;//       VARCHAR (20),
    QString phg  ;//       VARCHAR (20),
    QString pyc ;//        VARCHAR (20),
    QString fd   ;//       VARCHAR (20),
    QString ov  ;//        VARCHAR (20),
    QString mc  ;//        VARCHAR (20),
    QString mu  ;//        VARCHAR (20),
    QString sac ;//        VARCHAR (20),
    QString pc  ;//        VARCHAR (20),
    QString pas ;//        VARCHAR (20),
    QString chc ;//        VARCHAR (20),
    QString othermicro;//  VARCHAR (200)
};


class Db
{
public:
    Db();
};

#endif // _DB_H
