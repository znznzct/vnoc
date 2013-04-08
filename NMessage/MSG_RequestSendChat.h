#ifndef VNOC_C_MESSAGE_MSG_RequestSendChat
#define VNOC_C_MESSAGE_MSG_RequestSendChat
#include "MessageDef.h"
#include "CMessage.h"
#include "MsgDataValue/StringData.h"
#include "MsgDataValue/NumData.hpp"

///> Generate by MessageProduse. DO NOT EDIT!

namespace VNOC
{
namespace Message
{

class MSG_RequestSendChat : public CMessage
{
public:
    MSG_RequestSendChat()
    {
        RegisterPort("ChatMsg", MsgDataMType_Data, MsgDataType_String);

        RegisterPort("Nickname", MsgDataMType_Data, MsgDataType_String);

        InitializeMessage(MSG_RequestSendChat_Id);
    }

    MSG_RequestSendChat(const CMessage& Msg)
    {
        RegisterPort("ChatMsg", MsgDataMType_Data, MsgDataType_String);

        RegisterPort("Nickname", MsgDataMType_Data, MsgDataType_String);

        CMessage::Copy(Msg, MSG_RequestSendChat_Id);
    }

    virtual ~MSG_RequestSendChat(){}

    MsgStatus SetChatMsg(const std::string& Value)
    {
        return Write("ChatMsg", new StringData(Value));
    }

    MsgStatus SetNickname(const std::string& Value)
    {
        return Write("Nickname", new StringData(Value));
    }

    MsgStatus GetChatMsg(std::string& Value) const
    {
        MsgDataValue* pReadValue = NULL;
        Read("ChatMsg", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetNickname(std::string& Value) const
    {
        MsgDataValue* pReadValue = NULL;
        Read("Nickname", pReadValue);
        return pReadValue->ToStr(Value);
    }
};

}// namespace Message
}// namespace VNOC

#endif