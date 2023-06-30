#include "mbdatabase.h"

#include <QApplication>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

static MBDataBase *m_instance;

MBDataBase::MBDataBase()
{
    m_path = QString("%1/%2.db").arg(QApplication::applicationDirPath(), APP_NAME);
}

MBDataBase*
MBDataBase::instance()
{
    if(m_instance == nullptr)
        m_instance = new MBDataBase();

    return m_instance;
}

bool
MBDataBase::connect()
{
    m_errors.clear();

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_path);

    if(!exist())
    {
        return createTables();
    }

    return m_db.open();
}

bool
MBDataBase::disconnect()
{
    m_db.close();
    delete m_instance;
    return true;
}

bool
MBDataBase::authenticate(const QString &user, const QString &password)
{
    m_errors.clear();

    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(password.toLatin1());
    QString mbPassword(md5.result().toBase64());
    mbPassword = mbPassword.mid(mbPassword.size()/2, 6);

    QSqlQuery query(m_db.database());

    if(!query.exec(QString("SELECT PASSWORD FROM USERS WHERE USER = '%1'").arg(user)))
    {
        m_errors << QString("Failed to authenticate!");
        return false;
    }

    if(!query.next())
    {
        m_errors << QString("User not found!");
        return false;
    }

    if(query.value(0).toString() == mbPassword)
        return true;

    m_errors << QString("User or Password wrong!");

    return false;
}

QStringList
MBDataBase::errors()
{
    return m_errors;
}

bool
MBDataBase::exist()
{
    return QFile::exists(m_path);
}

bool
MBDataBase::createTables()
{
    bool ok = true;

    ok &= m_db.open();

    if(!ok)
    {
        m_errors << QString("Failed to open database connection!");
        return ok;
    }

    QSqlQuery query(m_db);

    const QString dir = "./scripts";

    ScriptList *scripts = new ScriptList;

    loadScripts(dir, scripts);

    QMapIterator<QString, QStringList> j(*scripts);

    while (j.hasNext())
    {
         j.next();

         QStringList scripts = j.value();

         for(const QString &script : scripts)
         {
            bool success = query.exec(script);

            if(!success)
                m_errors << query.lastError().text();

            ok &= success;
         }
    }

    delete scripts;

    return ok;
}

void
MBDataBase::loadScripts(const QString &dir, ScriptList *scriptList)
{
    QDirIterator dirIterator(dir, QDirIterator::Subdirectories);

    while (dirIterator.hasNext())
    {
        dirIterator.next();

        if(dirIterator.fileInfo().isDir())
        {
            continue;
        }

        QFile file(dirIterator.filePath());
        file.open(QFile::ReadOnly);

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QString fileScript = QString(in.readAll());
        file.close();

        QStringList scripts;

        scripts << fileScript.split(";");

        scriptList->insert(dirIterator.fileName(), scripts);
    }
}
