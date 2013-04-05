#ifndef DB_FIELD_H_
#define DB_FIELD_H_

#include "DBDefine.h"
#include <sqlite3/sqlite3.h>

class DBField
{
    friend class DBCommand;

public:
    int fieldPos() const
    {
        return fieldData.pos;
    }

    DB_DATA_TYPE fieldType() const;
    DBString fieldName() const;
    int32 fieldSize() const;

private:
    DBField()
    {
        /*dataTypeValue.data = NULL;
        dataTypeValue.len = 0;
        dataTypeValue.type = DB_DATA_TYPE_NONE;
        dataTypeValue.unsigned_flag = false;

        fieldData.pos = 0;*/
    }

    sqlite3_stmt* stmt;
    

#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif
    struct
    {
        uint32 len;
        void* data;
        DB_DATA_TYPE type;
        bool unsigned_flag;
    } dataTypeValue;

    struct
    {
        int32 pos;
        DBString name;

    } fieldData;

#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

};



#endif