#ifndef DB_COMMAND_H_
#define DB_COMMAND_H_

#include "DBDefine.h"
#include "DBRecordset.hpp"
#include <vector>
#include <boost/function.hpp>

class DBConnection;
struct sqlite3_stmt;

typedef boost::function<void ()> EventCallBack;

class DBCommand
{
public:
    DBCommand();
    explicit DBCommand(DBConnection* conn);
    explicit DBCommand(DBConnection* conn, const DBString& commandText);

    ~DBCommand();

private:
    void cleanup();

public:
    void setConnection(DBConnection* conn);
    bool setCommandText(const DBString& commandText);

public:
    DBCommand& operator << (const std::string& value);
    DBCommand& operator << (int32 value);
    DBCommand& operator << (int64 value);
    DBCommand& operator << (double value);
    DBCommand& operator << (Blob* blob);

public:
    bool query();
    bool query(const DBString& commandText);
    bool execute();
    bool execute(const DBString& commandText);
    int  rowsAffected() const;
    bool isResultSet() const;

public:
    DBString commandText() const;

private:
    DBConnection* _conn;
    sqlite3_stmt* _stmt;
    DBRecordset   _dbRecordset;
    DBString      _commandText;
    bool          _isResultSet;
    int32         _rowsAffetched;
};

#endif