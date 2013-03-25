#ifndef VNOC_C_MESSAGE_MSG_SendChatMsgToServer
#define VNOC_C_MESSAGE_MSG_SendChatMsgToServer
#include "MessageDef.h"
#include "CMessage.h"
#include "MsgDataValue/StringData.h"
#include "MsgDataValue/NumData.hpp"

///> Generate by MessageProduse. DO NOT EDIT!

namespace VNOC
{
namespace Message
{

class MSG_SendChatMsgToServer : public CMessage
{
public:
    MSG_SendChatMsgToServer()
    {
        RegisterPort("ChatMsg", MsgDataMType_Data, MsgDataType_String);

        InitializeMessage(MSG_SendChatMsgToServer_Id);
    }

    MSG_SendChatMsgToServer(const CMessage& Msg)
    {
        RegisterPort("ChatMsg", MsgDataMType_Data, MsgDataType_String);

        CMessage::Copy(Msg, MSG_SendChatMsgToServer_Id);
    }

    virtual ~MSG_SendChatMsgToServer(){}

    MsgStatus SetChatMsg(const std::string& Value)
    {
        return Write("ChatMsg", new StringData(Value));
    }

    MsgStatus GetChatMsg(std::string& Value) const
    {
        MsgDataValue* pReadValue = NULL;
        Read("ChatMsg", pReadValue);
        return pReadValue->ToStr(Value);
    }
};

}// namespace Message
}// namespace VNOC

#endif