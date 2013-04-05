#include "DBCommand.h"
#include "DBConnection.h"
#include <ezlogger_headers.hpp>
#include <sqlite3/sqlite3.h>
#include "DBField.hpp"

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


    for (uint32 i = 0; i < _recordset.size(); ++i)
    {
        delete [] _recordset[i];
    }
    _recordset.clear();
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
/*
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

}*/

bool DBCommand::query()
{
    //int result = sqlite3_step(_stmt);
    //if (result != SQLITE_ROW && result == SQLITE_DONE)
    //{
    //    _isResultSet = false;
    //    return false;
    //}

    int32 fetchedRows = rowsAffected();
    _recordset.resize(fetchedRows);

    int rowIndex = 0;
    while (sqlite3_step(_stmt) == SQLITE_ROW)
    {
        int32 colCount = sqlite3_column_count(_stmt);
        _recordset[rowIndex] = new DBField[colCount]();
        
        //遍历查询出来的所有列
        for (int32 i = 0; i < colCount; ++i)
        {
            _recordset[rowIndex][i].stmt = _stmt;

#ifdef DB_UTF16    
            DBString fieldName = sqlite3_column_name16(_stmt, i);  
#else   
            DBString fieldName = sqlite3_column_name(_stmt, i);  
#endif   

            DB_DATA_TYPE dataType = (DB_DATA_TYPE)sqlite3_column_type(_stmt, i);
            _recordset[rowIndex][i].fieldData.name = fieldName;
            _recordset[rowIndex][i].fieldData.pos = i;
            _recordset[rowIndex][i].dataTypeValue.type = dataType;
        }
    }

    EZLOGGERVLSTREAM(axter::log_often) << "Query operation Done, " << rowsAffected() << " rows fetched." << endl;
    _isResultSet = true;
    return true;
}

bool DBCommand::query(const DBString& commandText)
{
    if (setCommandText(commandText) == false)
    {
        return false;
    }

    return query();
}

bool DBCommand::execute()
{
    int result = sqlite3_step(_stmt);
    if (result != SQLITE_OK)
    {
        return false;
    }

    _isResultSet = false;
    return (sqlite3_finalize(_stmt) == SQLITE_OK) ? true : false;
}

bool DBCommand::execute(const DBString& commandText)
{
    if (setCommandText(commandText) == false)
    {
        return false;
    }

    return execute();
}

int DBCommand::rowsAffected() const
{
    return sqlite3_changes(_conn->connection());
}

bool DBCommand::isResultSet() const
{
    return _isResultSet;
}