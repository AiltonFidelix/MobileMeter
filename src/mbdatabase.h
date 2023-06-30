#ifndef MBDATABASE_H
#define MBDATABASE_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QStringList>

class MBDataBase
{
public:
    static MBDataBase *instance();

    bool connect();
    bool disconnect();
    bool authenticate(const QString &user, const QString &password);

    QStringList errors();

protected:
    MBDataBase();

private:
    typedef QMap<QString, QStringList> ScriptList;

    QSqlDatabase m_db;
    QString m_path;

    QStringList m_errors;

private:
    bool exist();
    bool createTables();
    void loadScripts(const QString &dir, ScriptList *scriptList);
};

#endif // MBDATABASE_H
