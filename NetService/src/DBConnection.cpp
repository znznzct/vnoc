#include "DBDefine.h"
#include "DBConnection.h"
#include <ezlogger_headers.hpp>
#include <sqlite3/sqlite3.h>
#include <fstream>

DBConnection::DBConnection()
{
    _db = NULL;
    _state = STATE_CLOSED;
}

DBConnection::~DBConnection()
{
    this->close();
}

bool DBConnection::open(const DBString& filename)
{
    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        EZLOGGERVLSTREAM(axter::log_often)
            << "Failed to open database, file not exists.\n" 
            << "    Path = " << filename 
            << endl;

        return false;
    }

    if (_db != NULL)
    {
        close();
    }

#ifdef DB_UTF16
    int result = sqlite3_open16(filename.c_str(), &_db);
#else
    int result = sqlite3_open(filename.c_str(), &_db);
#endif

    if (result != SQLITE_OK)
    {
        EZLOGGERVLSTREAM(axter::log_often) 
            << "Failed to open database.\n" 
            << "    Result = " << result 
            << endl;
        return false;
    }

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

bool DBConnection::isAlive() const
{
    return (_state == STATE_OPENED);
}

CONNECTION_STATE DBConnection::state() const
{
    return _state;
}