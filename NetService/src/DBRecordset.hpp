#ifndef DB_RECORDSET_H_
#define DB_RECORDSET_H_

#include "DBDefine.h"

class DBField;
class DBRecordset
{
    friend class DBCommand;
    typedef std::vector<Record> Recordset;

public:
    bool fetchNext();
    bool fetchPrev();
    bool fetchFirst();
    bool fetchLast();
    const DBField& operator [] (int32 filedIndex) const;
    const DBField& operator [] (const std::string& filedName);

private:
    DBRecordset() {}
    ~DBRecordset() {}

    /*void addRecord(DBField* field)
    {
        _record.StringKeySet.insert(std::make_pair(field->fieldName(), field));
        _record.IntKeySet.insert(std::make_pair(field->fieldPos, field));
    }*/

    Recordset& recordset()
    {
        return _recordset;
    }

    Recordset _recordset;
};

#endif