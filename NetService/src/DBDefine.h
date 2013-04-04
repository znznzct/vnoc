#ifndef DB_DEFINE_H_
#define DB_DEFINE_H_

#include "Common.h"
#include <string>

#ifdef DB_UTF16
typedef std::wstring DBString;
#else
typedef std::string DBString;
#endif

struct Blob
{
    Blob(byte* b, int s) : blob(b), size(s)
    {
    }

    byte* blob;
    int size;
};

#endif