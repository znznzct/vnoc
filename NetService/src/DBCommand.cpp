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
    : _conn(conn), _commandText(commandText)
{
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

void DBCommand::setCommandText(const DBString& commandText)
{
#ifdef DB_UTF16
    //int result = sqlite3_prepare_16();
#else
    //int result = sqlite3_prepare();
#endif

    _commandText = commandText;
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

}

bool DBCommand::execute(const DBString& commandText)
{

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