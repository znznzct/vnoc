#ifndef DB_CONNECTION_H_
#define DB_CONNECTION_H_

#include "Common.h"
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>

class DBRecordset;
class DBCommand;
struct sqlite3;

/* connection status */
enum CONNECTION_STATE { STATE_CLOSED, STATE_OPENED };

class DBConnection : public boost::noncopyable
{
public:
    DBConnection();
    ~DBConnection();

public:
    bool open(const std::string& filename);
    void close();
    bool isAlive() const;
    sqlite3* connection();
    CONNECTION_STATE state() const;

private:
    sqlite3* _db;
    bool _isOpened;
    CONNECTION_STATE _state;

};

#endif