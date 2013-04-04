#include "DBCommand.h"
#include "DBConnection.h"
#include <ezlogger_headers.hpp>
#include <sqlite3/sqlite3.h>

DBCommand::DBCommand()
{
    cleanup();
}

DBCommand::DBCommand(DBConnection* conn) 
    : _conn(conn)
{
}

DBCommand::DBCommand(DBConnection* conn, const DBString& commandText)
    : _conn(conn)
{
    setCommandText(commandText);
}

DBCommand::~DBCommand()
{
    cleanup();
}

void DBCommand::cleanup()
{
    _conn = NULL;
    _stmt = NULL;
}

void DBCommand::setConnection(DBConnection* conn)
{
    _conn = conn;
}

bool DBCommand::setCommandText(const DBString& commandText)
{
#ifdef DB_UTF16
    int result = sqlite3_prepare16_v2(_conn, commandText.c_str(), -1, &_stmt, NULL);
#else
    int result = sqlite3_prepare_v2(_conn->connection(), commandText.c_str(), -1, &_stmt, NULL);
#endif

    if (result != SQLITE_OK)
    {
        return false;
    }

    _commandText = commandText;
    return true;
}

DBCommand& DBCommand::operator << (const DBString& value)
{

}


DBCommand& DBCommand::operator << (int32 value)
{

}


DBCommand& DBCommand::operator << (int64 value)
{

}


DBCommand& DBCommand::operator << (double value)
{

}


DBCommand& DBCommand::operator << (Blob* blob)
{

}


DBField& DBCommand::operator [] (int32 filedIndex)
{

}


DBField& DBCommand::operator [] (const DBString& filedName)
{

}

bool DBCommand::execute()
{
    int result = sqlite3_step(_stmt);

    //sqlite3 : Evaluate An SQL Statement
    //If the SQL statement being executed returns any data, 
    //then SQLITE_ROW is returned each time a new row of data is ready for processing by the caller
    if (result == SQLITE_ROW)
    {
        _isResultSet = true;
    }
    else
    {
        return (sqlite3_finalize(_stmt) == SQLITE_OK) ? true : false;
    }

    return true;
}

bool DBCommand::execute(const DBString& commandText)
{
    if (setCommandText(commandText) == false)
    {
        return false;
    }

    return execute();
}


int  DBCommand::rowsAffected() const
{

}


bool DBCommand::fetchNext()
{

}


bool DBCommand::fetchPrev()
{

}


bool DBCommand::fetchFirst()
{

}


bool DBCommand::fetchLast()
{

}

DBConnection* DBCommand::connection() const
{

}


DBString DBCommand::commandText() const
{

}