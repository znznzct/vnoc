#ifndef DBCACHED_H_
#define DBCACHED_H_

#include "Common.h"
#include <sqlite3/sqlite3.h>

class DBCached
{
public:
    DBCached();
    DBCached(string filename);
    virtual ~DBCached();

protected:
    bool init(string filename);
    bool destroy();

private:
    sqlite3* _db;
};

#endif