#ifndef SAMPLELIST_H
#define SAMPLELIST_H

#include <QTableWidget>


class SampleList
{
public:
    SampleList();

    int create_sample(int ID);

    int change_state(int ID, int column, QString info);

    int show_table(QTableWidget * table);
};

#endif // SAMPLELIST_H
