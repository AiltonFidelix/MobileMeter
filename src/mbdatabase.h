#ifndef MBDATABASE_H
#define MBDATABASE_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class MBDataBase
{
public:
    static MBDataBase *instance();

    bool connect();
    bool disconnect();

protected:
    MBDataBase();

private:
    QSqlDatabase m_db;
    QString m_dbPath;

private:
    bool exist();
    bool createTables();

};

#endif // MBDATABASE_H
