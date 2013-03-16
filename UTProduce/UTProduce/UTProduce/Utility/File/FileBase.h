#ifndef UTPRODUCE_FILEBASE
#define UTPRODUCE_FILEBASE

#include <iostream>
#include "IFile.h"

namespace UTProduce
{
namespace File
{

class FileBase	: public IFile
{					  
public:
	FileBase();
	virtual ~FileBase();

public:
	virtual bool Open(const char* lpPath, const char* lpMode);
	virtual bool Open(const std::string& strPath, MsgFileOpenType openMode);
	virtual bool Close();
	virtual unsigned int Read(void* lpBuffer, unsigned int uSize, unsigned int uCount);
	virtual unsigned int Write(const void* lpBuffer, unsigned int uSize, unsigned int uCount);
	virtual int Seek(long lOffset, int nOrigin);
	virtual long GetFileSize();
	void DoSomething(){std::cout<<"do something"<<std::endl;}


private:
	//FileBase& operator = (const FileBase& fileBaseObj);

protected:
	virtual long _GetFileCurPos();
	const char* _GetOpenType(MsgFileOpenType openType);// = FILE_OPEN_NULL);

protected:
	FILE* m_pFile;

};


}// namespace File
}// namespace UTProduce


#endif // UTPRODUCE_FILEBASE