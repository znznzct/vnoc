#include "Producer.h"


namespace UTProduce
{
namespace XML
{

Producer::Producer()
{
}

Producer::~Producer()
{
}

const char* Producer::_GetItemTypeStr(MsgDef::MsgItemType msgItemType)
{
	switch(msgItemType)
	{
	case MsgItemType_Null:
		return "\0";
	case MsgItemType_String:
		return "std::string";
	case MsgItemType_Uint8:
		return "uint8";
	case MsgItemType_Uint16:
		return "uint16";
	case MsgItemType_Uint32:
		return "uint32";
	case MsgItemType_int8:
		return "int8";
	case MsgItemType_int16:
		return "int16";
	case MsgItemType_int32:
		return "int32";
	default:
		return "\0";
	}
}

long long Producer::_GetRandNum(MsgDef::MsgItemType msgItemType)
{
	switch(msgItemType)
	{
	case MsgItemType_Null:
		return -1;
	case MsgItemType_String:
		return -2; 
	case MsgItemType_Uint8:
		return 255;
	case MsgItemType_Uint16:
		return 65535;
	case MsgItemType_Uint32:
		return 4294967295;
	case MsgItemType_int8:
		return 127;
	case MsgItemType_int16:
		return 32767;
	case MsgItemType_int32:
		return 2147483647;
	default:
		return -1;
	}
}


} // namespace XML
} // namespace UTProduce