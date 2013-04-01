#include "VNOCUser.h"
#include "GlobalDefinition.h"

VNOCUser::VNOCUser()
{
}

VNOCUser::~VNOCUser()
{
}

void VNOCUser::setUniqueID(GUID_t guid)
{
    _guid = guid;
}

GUID_t VNOCUser::getUniqueID() const
{
    return _guid;
}

void VNOCUser::setNickName(const std::string &studentName)
{
    if (studentName.length() <= MAX_NICKNAME_LEN)
    {
        _studentName = studentName;
    }
}

const std::string VNOCUser::getNickName() const
{
    return _studentName;
}

void VNOCUser::heartbeat(int64 now)
{

}