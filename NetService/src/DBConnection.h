#ifndef DB_CONNECTION_H_
#define DB_CONNECTION_H_

#include "DBDefine.h"
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>

class DBCommand;
struct sqlite3;

/* connection status */
enum CONNECTION_STATE { STATE_CLOSED, STATE_OPENED };

class DBConnection : public boost::noncopyable
{
public:
    DBConnection();
    DBConnection(const DBString& filename);
    ~DBConnection();

private:
    void cleanup();

public:
    bool open();
    bool open(const DBString& filename);
    void close();
    void setDBFile(const DBString& filename);
    bool isAlive() const;
    sqlite3* connection();
    CONNECTION_STATE state() const;

private:
    sqlite3* _db;
    bool _isOpened;
    CONNECTION_STATE _state;
    DBString _dbFile;
};

#endif