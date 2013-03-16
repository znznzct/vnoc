#include "FileBase.h"

namespace UTProduce
{
namespace File
{


FileBase::FileBase()
{
}

FileBase::~FileBase()
{
	Close();
}

bool FileBase::Open(const char* lpPath, const char* lpMode)
{
	if(!lpPath || !lpMode){
		return false;
	}

	if(::_tfopen_s(&m_pFile, lpPath, lpMode))
	{
		m_pFile = 0;
		puts("can't open file");
	}
	return m_pFile ? true : false;
}

bool FileBase::Open(const std::string& strPath, MsgFileOpenType openMode)
{
	const char* lpPath = strPath.c_str();
	return Open(lpPath, _GetOpenType(openMode));
}

bool FileBase::Close()
{
	if(m_pFile)
	{
		if(::fclose(m_pFile)){
			return false;
		}
		m_pFile = 0;
		return true;
	}
	return false;
}
			
unsigned int FileBase::Read(void* lpBuffer, unsigned int uSize, unsigned int uCount)
{
	if(!lpBuffer || !uSize  || !uCount || !m_pFile){
		return -1;
	}

	unsigned int uRead = 0;
	uRead = ::fread(lpBuffer, uSize, uCount, m_pFile);
	return uRead;
}
			
unsigned int FileBase::Write(const void* lpBuffer, unsigned int uSize, unsigned int uCount)
{
	if(!lpBuffer || !uSize  || !uCount || !m_pFile){
		return -1;
	}
	
	unsigned int uWrite = 0;
	uWrite = ::fwrite(lpBuffer, uSize, uCount, m_pFile);
	return uWrite;
}
			
int FileBase::Seek(long lOffset, int nOrigin)
{
	if(m_pFile)
	{
		return fseek(m_pFile, nOrigin, lOffset);
	}
	return -1;
}



long FileBase::GetFileSize()
{
	if(m_pFile)
	{
		int nFileSize = 0;
		int nOldPos = _GetFileCurPos();
		Seek(FILE_SEEK_END, 0);
		nFileSize = ftell(m_pFile);
		Seek(FILE_SEEK_SET, nOldPos);
		return nFileSize;
	}
	return -1;
}

long FileBase::_GetFileCurPos()
{
	if(m_pFile){
		return (ftell(m_pFile));
	}
	return -1;
}	   

const char* FileBase::_GetOpenType(MsgFileOpenType openType/* =FILE_OPEN_NULL */)
{
	switch(openType)
	{
	case FILE_OPEN_NULL:
		return 0;
	case FILE_OPEN_R:
		return ("r");
	case FILE_OPEN_R_PLUS:
		return ("r+");
	case FILE_OPEN_W:
		return ("w");
	case FILE_OPEN_W_PLUS:
		return ("w+");
	case FILE_OPEN_A:
		return ("a");
	case FILE_OPEN_A_PLUS:
		return ("a+");
	default:
		return 0;
	}
}

/*
FileBase& FileBase::operator = (const FileBase& fileBaseObj)
{
	return *this;
}*/

}// namespace File
}// namespace UTProduce
