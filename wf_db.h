#ifndef WF_DB_H
#define WF_DB_H

#include <QString>
#include <QVariant>
#include <QVector>
#include <QDebug>

class COLUMN
{
public:
    QString name;
    QString data;

public:
    COLUMN()
    {
        name = "";
        data = "";
    }

    COLUMN(QString _name)
    {
        name = _name;
        data = "";
    }
};


class Columns
{
public:
    QString tableName;
    QVector<COLUMN> columns;

public:
    //获取创建数据库及表的SQL语句
    QString get_sql_create_table()
    {
        QString sql;
        sql =  "create table ";
        sql += tableName;
        sql += " (";
        QVector<COLUMN>::iterator it;
        for(it = columns.begin(); it != columns.end(); ++it){
            sql += it->name;
            if(it == columns.begin())
                sql += " varchar primary key";
            else
                sql += " varchar";
            if(it != (columns.end() - 1))
                sql += ',';
        }
        sql += ')';
        qDebug() << "sql:" << sql << "\n";
        return sql;
    }

    //获取插入表格记录的SQL语句
    QString get_sql_insert_or_replace()
    {
        QString sql;
        sql = "insert or replace into ";
        sql += tableName;
        sql += " (";

        QVector<COLUMN>::iterator it;
        for(it = columns.begin(); it != columns.end(); ++it){
            sql += it->name;
            if(it != columns.end() - 1)
                sql += ", ";
        }
        sql += ") values (";
        for(it = columns.begin(); it != columns.end(); ++it){
            sql += '\'';
            sql += it->data;
            sql += '\'';
            if(it != columns.end() - 1)
                sql += ", ";
        }
        sql += ");";

        qDebug() << sql << '\n';
        return sql;
    }

    //获取读取记录的SQL语句
    QString get_sql_query(QString filter)
    {
        QString sql;
        sql = "select * from ";
        sql += tableName;
        sql += " where ";
        sql += filter;

        qDebug() << sql << '\n';
        return sql;
    }

public:
    inline int size()
    {
        return columns.size();
    }

    QString get_field(int colIndex)
    {
        if(colIndex < 0)
            return "";
        if(columns.size() > colIndex)
            return columns[colIndex].data;
        return "";
    }

    QString get_field(QString colName)
    {
        QVector<COLUMN>::iterator it;
        for(it = columns.begin(); it != columns.end(); ++it){
            if(it->name == colName)
                return it->data;
        }
        return "";
    }

    int set_field(int colIndex, QString data)
    {
        if(colIndex < 0)
            return 0;
        if(columns.size() > colIndex){
            columns[colIndex].data = data;
            return 1;
        }
        return 0;
    }

    int set_field(QString colName, QString data)
    {
        QVector<COLUMN>::iterator it;
        for(it = columns.begin(); it != columns.end(); ++it){
            if(it->name == colName){
                it->data = data;
                return 1;
            }
        }
        return 0;
    }

    QString & operator[](int index)
    {
        if((index < 0) || (index >= columns.size())){
            qDebug() << "Wf_run block Wf_db class Columns index error !\n";
            return columns[0].data;
        }
        return columns[index].data;
    }

};

class RecordSick : public Columns
{
public:
    RecordSick()
    {
        tableName = "sick";
        columns.push_back(COLUMN("ID"));
        columns.push_back( COLUMN("Name"));
        columns.push_back( COLUMN("Sex"));
        columns.push_back( COLUMN("Age"));
        columns.push_back( COLUMN("History"));//病历号
        columns.push_back( COLUMN("Bed"));//床号
        columns.push_back( COLUMN("Section"));//科室
        columns.push_back( COLUMN("Diagnose"));//诊断
        columns.push_back( COLUMN("Sender"));
        columns.push_back( COLUMN("Checker"));
        columns.push_back( COLUMN("Assessor"));
        columns.push_back( COLUMN("Remark"));
    }
};


//化学检测项目
class RecordChemic : public Columns
{
public:
    RecordChemic()
    {
        tableName = "chemic";
        columns.push_back(COLUMN("ID"));
        columns.push_back(COLUMN("FOB"));
        columns.push_back(COLUMN( "Tf"));//转铁蛋白
        columns.push_back(COLUMN( "CALP"));//钙卫蛋白calprotectin
        columns.push_back(COLUMN( "RV"));//轮状病毒 rotavirus
        columns.push_back(COLUMN( "ADV"));//腺病毒adenovirus
        columns.push_back(COLUMN( "CSK"));//柯萨奇病毒coxsackievirus
        columns.push_back(COLUMN( "NV"));//诺如病毒Norovirus
        columns.push_back(COLUMN( "HP"));//幽门螺旋杆菌Helicobacter
        columns.push_back(COLUMN( "CB"));//大肠杆菌colibacillus
        columns.push_back(COLUMN( "VBC"));//霍乱弧菌vibrio cholerae
    }
};

//镜检扫描项目
class RecordMicro : public Columns
{
public:
    RecordMicro()
    {
        tableName = "micro";
        columns.push_back(COLUMN("ID"));
        columns.push_back(COLUMN( "RBC"));
        columns.push_back(COLUMN( "WBC"));
        columns.push_back(COLUMN( "PHG"));//吞噬细胞phagocyte
        columns.push_back(COLUMN( "PYC"));//脓细胞pyocyte
        columns.push_back(COLUMN( "FD"));//脂肪滴fat droplet
        columns.push_back(COLUMN( "OV"));//虫卵ovum
        columns.push_back(COLUMN( "MC"));//霉菌mycete
        columns.push_back(COLUMN( "MU"));//粘液mucus
        columns.push_back(COLUMN( "SAC"));//酵母菌saccharomycetes
        columns.push_back(COLUMN( "PC"));//植物细胞plant cell
        columns.push_back(COLUMN( "PAS"));//寄生虫parasite
        columns.push_back(COLUMN( "CHC"));//夏科雷登结晶Charcot's crystal
        columns.push_back(COLUMN( "Other"));;//其他
    }
};


/*
 * fff, 2019.1.11
 * 数据库操作类，用于保存和读取数据库记录
 */
class Wf_db
{
public:
    //为空
    Wf_db();

public:
    //创建专用数据库及表格
    static int create_database();

    //保存病人资料记录
    static int set_sick(RecordSick & rec);

    //读取病人资料记录
    static int get_sick(QString filter, QList< RecordSick > & recs);

    //保存化学记录
    static int set_chemic(RecordChemic & rec);

    //读取化学记录
    static int get_chemic(QString filter, QList< RecordChemic > & recs);

    //保存镜检记录
    static int set_micro(RecordMicro & rec);

    //读取镜检记录
    static int get_micro(QString filter, QList< RecordMicro > & recs);

};


#endif // WF_DB_H
