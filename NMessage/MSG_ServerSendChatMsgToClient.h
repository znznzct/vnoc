#ifndef VNOC_C_MESSAGE_MSG_ServerSendChatMsgToClient
#define VNOC_C_MESSAGE_MSG_ServerSendChatMsgToClient
#include "MessageDef.h"
#include "CMessage.h"
#include "MsgDataValue/StringData.h"
#include "MsgDataValue/NumData.hpp"

///> Generate by MessageProduse. DO NOT EDIT!

namespace VNOC
{
namespace Message
{

class MSG_ServerSendChatMsgToClient : public CMessage
{
public:
    MSG_ServerSendChatMsgToClient()
    {
        RegisterPort("ChatMsg", MsgDataMType_Data, MsgDataType_String);

        InitializeMessage(MSG_ServerSendChatMsgToClient_Id);
    }

    MSG_ServerSendChatMsgToClient(const CMessage& Msg)
    {
        RegisterPort("ChatMsg", MsgDataMType_Data, MsgDataType_String);

        CMessage::Copy(Msg, MSG_ServerSendChatMsgToClient_Id);
    }

    virtual ~MSG_ServerSendChatMsgToClient(){}

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