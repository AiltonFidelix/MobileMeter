#include "mbdatabase.h"

#include <QFile>
#include <QDir>
#include <QApplication>

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
    delete m_instance;
    return true;
}

bool
MBDataBase::exist()
{
    return QFile::exists(m_path);
}

bool
MBDataBase::createTables()
{
    m_db.open();

    QSqlQuery query(m_db);

#warning // TODO: add tables creation
    query.exec("");

    return true;
}
