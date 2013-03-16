#ifndef UTPRODUCE_MSGDEF
#define UTPRODUCE_MSGDEF


#include "StdAfx.h"


namespace UTProduce
{
namespace MsgDef
{


enum MsgStatus
{
	MsgStatus_Ok,
	MsgStatus_Err,
	MsgStatus_Unk,
	MsgStatus_FormatFailure,
	MsgStatus_TypeErr
};

enum MsgItemType
{
	MsgItemType_Null,
	MsgItemType_String,
	MsgItemType_Uint8,
	MsgItemType_Uint16,
	MsgItemType_Uint32,
	MsgItemType_int8,
	MsgItemType_int16,
	MsgItemType_int32
};

enum MsgItemMType
{
	MsgItemMType_Null,
	MsgItemMType_Data,
	MsgItemMType_List
};



#ifndef		IN													
#define		IN													 
#endif															  
#ifndef		OUT													   
#define		OUT
#endif
#ifndef		MsgDataName
#define		MsgDataName				std::string
#endif
#ifndef		uint8
#define		uint8					unsigned CHAR 
#endif
#ifndef		uint16
#define		uint16					unsigned short
#endif
#ifndef		uint32
#define		uint32					unsigned int
#endif
#ifndef		int8
#define		int8					char
#endif
#ifndef		int16
#define		int16					unsigned short
#endif
#ifndef		int32
#define		int32					unsigned int
#endif


#define		MsgType					MsgItemType
#define		MsgMType				MsgItemMType

#define		MSG_BEGIN				0x56	// 'V' 标记消息的开始
#define		MSG_END					0x43	// 'C' 标记消息的结束
#define		MSG_VER					1		//	版本号
#define		MSG_HEADLEN				10
#define		MSG_TAIL_LEN			1

#define		MSG_CLASS_BEGIN			1
#define		MSG_CLASS_END			1
#define		MSG_CLASS_LEN			4
#define		MSG_CLASS_VER			1
#define		MSG_CLASS_SERIAL		2
#define		MSG_CLASS_GUID			16
#define		MSG_CLASS_COMMAND		4
#define		MSG_CLASS_OBL			4
#define		MSG_CLASS_PARAMCONST	1
#define		MSG_CLASS_VERIFY		2
#define		MSG_CLASS_PARAM			4
#define		MSG_CLASS_PARAM_COUNT	4

#define		MSG_PACKSIZE_INDEX		MSG_CLASS_VER + MSG_CLASS_BEGIN
#define		MSG_COMMAND_INDEX		MSG_PACKSIZE_INDEX + MSG_CLASS_LEN

#define		XMLFileRoot				"vnoc"
											// <vnoc>
#define		XMLMsg_msg				"msg"	//	 <msg name="MSG_Test" id="2100">
#define		XMLMsg_Name				"name"	//		<item mtype="data" name="Example_1" type="uint8" />	
#define		XMLMsg_Id				"id"	//		<item mtype="data" name="Example_2" type="string" />
											//		<item mtype="list" name="Example_3" type="int32" />
#define		XMLItem_MType			"mtype"	//		<item mtype="list" name="Example_4" type="string" />
#define		XMLItem_Name			"name"	//		<item mtype="data" name="Example_5" type="int8" />
#define		XMLItem_Type			"type"	//	 </msg>
											// </vnoc>
#define		XMLItemMType_List		"list"
#define		XMLItemMType_Data		"data"

#define		XMLItemType_Uint32		"uint32"
#define		XMLItemType_Uint16		"uint16"
#define		XMLItemType_Uint8		"uint8"
#define		XMLItemType_int32		"int32"
#define		XMLItemType_int16		"int16"
#define		XMLItemType_int8		"int8"
#define		XMLItemType_String		"string"

#define		MsgPack_Unk				0


}// namespace MsgDef
}// namespace UTProduce



#endif // UTPRODUCE_MSGDEF