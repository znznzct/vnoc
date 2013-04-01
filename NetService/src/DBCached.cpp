//============================================================================
// Name        : DBCached.cpp
// Author      : AngryPowman
// Version     :
// Copyright   : VNOC
// Description : 
//============================================================================

#include "DBCached.h"
#include <ezlogger_headers.hpp>
#include <sqlite3/sqlite3.h>
#include <fstream>

DBCached::DBCached()
{
    _db = NULL;
}


DBCached::~DBCached()
{
}

bool DBCached::init(string filename)
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
        int closeResult = sqlite3_close(_db);
        if (closeResult == SQLITE_OK)
        {
            return true;
        }
        else
        {
            EZLOGGERVLSTREAM(axter::log_often) << "An exception occured when closing the sqlite object.\n" 
                << "Result = " << closeResult
                << endl;;
            return false;
        }
    }

    int result = sqlite3_open(filename.c_str(), &_db);
    if (result != SQLITE_OK)
    {
        return false;
    }

    return true;
}

void DBCached::destroy()
{
    sqlite3_close(_db);
}
