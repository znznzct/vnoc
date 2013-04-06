#ifndef DB_FIELD_H_
#define DB_FIELD_H_

#include "DBDefine.h"
#include <sqlite3/sqlite3.h>

const int32 INVALID_FIELD_POS = -1;

class DBField
{
    friend class DBCommand;

public:
    int fieldPos() const
    {
        return _fieldData.pos;
    }

    const DBString& fieldName() const
    {
        return _fieldData.field_name;
    }

private:
    DBField(sqlite3_stmt* stmt) : _stmt(stmt)
    {
    }

    struct FieldData
    {
        DBString field_name;
        int32 pos;

        FieldData() : pos(INVALID_FIELD_POS) {}
    } _fieldData;

    sqlite3_stmt* _stmt;
};



#endif