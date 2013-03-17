#ifndef UTPRODUCE_IFILE
#define UTPRODUCE_IFILE

#include "../../StdAfx.h"


namespace UTProduce
{
namespace File
{

enum MsgFileOpenType
{
	FILE_OPEN_NULL,
	FILE_OPEN_R,
	FILE_OPEN_W,
	FILE_OPEN_A,
	FILE_OPEN_R_PLUS,
	FILE_OPEN_W_PLUS,
	FILE_OPEN_A_PLUS
};

enum MsgFileSeekType
{
	FILE_SEEK_SET,
	FILE_SEEK_CUR,
	FILE_SEEK_END
};

class IFile
{					  
public:
	IFile(){}
	virtual ~IFile(){}

public:
	virtual bool Open(const char* lpPath, const char* lpMode) = 0;
	virtual bool Close() = 0;
	virtual unsigned int Read(void* lpBuffer, unsigned int uSize, unsigned int uCount) = 0;
	virtual unsigned int Write(const void* lpBuffer, unsigned int uSize, unsigned int uCount) = 0;
	virtual int Seek(long lOffset, int nOrigin) = 0;;
};


}// namespace File
}// namespace UTProduce


#endif // UTPRODUCE_IFILE