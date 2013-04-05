#include "DBDefine.h"
#include "DBConnection.h"
#include <ezlogger_headers.hpp>
#include <sqlite3/sqlite3.h>
#include <fstream>

DBConnection::DBConnection()
{
    cleanup();
}

DBConnection::DBConnection(const DBString& filename)
{
    cleanup();
    setDBFile(filename);
}

DBConnection::~DBConnection()
{
    this->close();
}

void DBConnection::cleanup()
{
    _db = NULL;
    _state = STATE_CLOSED;
}

bool DBConnection::open(const DBString& filename)
{
    setDBFile(filename);
    return open();
}

bool DBConnection::open()
{
    fstream file(_dbFile, ios::in);
    if (!file.is_open())
    {
        EZLOGGERVLSTREAM(axter::log_often)
            << "Failed to open database, file not exists.\n" 
            << "    Path = " << _dbFile 
            << endl;

        return false;
    }

    if (_db != NULL)
    {
        close();
    }

#ifdef DB_UTF16
    int result = sqlite3_open16(_dbFile.c_str(), &_db);
#else
    int result = sqlite3_open(_dbFile.c_str(), &_db);
#endif

    if (result != SQLITE_OK)
    {
        EZLOGGERVLSTREAM(axter::log_often) 
            << "Failed to open database.\n" 
            << "    Result = " << result 
            << endl;
        return false;
    }

    _state = STATE_OPENED;
    return true;
}

void DBConnection::close()
{
    int result = sqlite3_close(_db);
    if (result != SQLITE_OK)
    {
        EZLOGGERVLSTREAM(axter::log_often) << "An exception occured when closing the sqlite object.\n" 
            << "Result = " << result
            << endl;;
    }

    _db = NULL;
}

void DBConnection::setDBFile(const DBString& filename)
{
    _dbFile = filename;
}

bool DBConnection::isAlive() const
{
    return (_state == STATE_OPENED);
}

sqlite3* DBConnection::connection()
{
    return _db;
}

CONNECTION_STATE DBConnection::state() const
{
    return _state;
}