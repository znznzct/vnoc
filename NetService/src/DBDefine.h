#ifndef DB_DEFINE_H_
#define DB_DEFINE_H_

#include "Common.h"
#include <sqlite3/sqlite3.h>
#include <string>

#ifdef DB_UTF16
typedef std::wstring DBString;
#else
typedef std::string DBString;
#endif

class DBField;
//typedef std::vector<DBField*> Recordset;

enum DB_DATA_TYPE
{
    DB_DATA_TYPE_NONE    = 0,
    DB_DATA_TYPE_INTEGER = SQLITE_INTEGER,
    DB_DATA_TYPE_FLOAT   = SQLITE_FLOAT,
    DB_DATA_TYPE_BLOB    = SQLITE_BLOB,
    DB_DATA_TYPE_NULL    = SQLITE_NULL,
    DB_DATA_TYPE_TEXT    = SQLITE_TEXT
};

struct Blob
{
    Blob(byte* b, int s) : blob(b), size(s)
    {
    }

    byte* blob;
    int size;
};

typedef std::unordered_map<string, DBField*> StringKeyValue;
typedef std::unordered_map<int, DBField*> IntKeyValue;

typedef struct
{
    StringKeyValue StringKeySet;
    IntKeyValue IntKeySet;
} Record;

#endif