#ifndef DB_RECORDSET_H_
#define DB_RECORDSET_H_

#include "Common.h"
#include "DBDefine.h"

class DBField;
class DBRecordset
{
public:
    DBRecordset();
    ~DBRecordset();

public:
    bool fetchNext();
    bool fetchPrev();
    bool fetchFirst();
    bool fetchLast();

private:
    Recordset _recordset;
};

#endif