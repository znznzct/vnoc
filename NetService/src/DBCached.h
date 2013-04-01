//============================================================================
// Name        : DBCached.h
// Author      : AngryPowman
// Version     :
// Copyright   : VNOC
// Description : 
//============================================================================

#ifndef DBCACHED_H_
#define DBCACHED_H_

#include "Common.h"
#include <boost/noncopyable.hpp>

struct sqlite3;
class DBCached : public boost::noncopyable
{
protected:
    DBCached();
    virtual ~DBCached();

protected:
    bool init(string filename);
    void destroy();

private:
    sqlite3* _db;
};

#endif