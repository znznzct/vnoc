#ifndef DB_COMMAND_H_
#define DB_COMMAND_H_

#include "DBDefine.h"
#include <boost/function.hpp>

class DBConnection;
class DBRecordset;
class DBField;
struct Blob;
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
    void setCommandText(const DBString& commandText);

public:
    DBCommand& operator << (const std::string& value);
    DBCommand& operator << (int32 value);
    DBCommand& operator << (int64 value);
    DBCommand& operator << (double value);
    DBCommand& operator << (Blob* blob);
    DBField& operator [] (int32 filedIndex);
    DBField& operator [] (const std::string& filedName);

public:
    bool execute();
    bool execute(const std::string& commandText);
    int  rowsAffected() const;
    bool fetchNext();
    bool fetchPrev();
    bool fetchFirst();
    bool fetchLast();

public:
    DBConnection* connection() const;
    DBString commandText() const;

private:
    DBConnection* _conn;
    sqlite3_stmt* _stmt;
    DBString _commandText;
};

#endif