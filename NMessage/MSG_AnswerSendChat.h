#ifndef VNOC_C_MESSAGE_MSG_AnswerSendChat
#define VNOC_C_MESSAGE_MSG_AnswerSendChat
#include "MessageDef.h"
#include "CMessage.h"
#include "MsgDataValue/StringData.h"
#include "MsgDataValue/NumData.hpp"

///> Generate by MessageProduse. DO NOT EDIT!

namespace VNOC
{
namespace Message
{

class MSG_AnswerSendChat : public CMessage
{
public:
    MSG_AnswerSendChat()
    {
        RegisterPort("SendMsgRlt", MsgDataMType_Data, MsgDataType_Uint8);

        InitializeMessage(MSG_AnswerSendChat_Id);
    }

    MSG_AnswerSendChat(const CMessage& Msg)
    {
        RegisterPort("SendMsgRlt", MsgDataMType_Data, MsgDataType_Uint8);

        CMessage::Copy(Msg, MSG_AnswerSendChat_Id);
    }

    virtual ~MSG_AnswerSendChat(){}

    MsgStatus SetSendMsgRlt(const Define::uint8& Value)
    {
        return Write("SendMsgRlt", new NumData<Define::uint8>(Value));
    }

    MsgStatus GetSendMsgRlt(Define::uint8& Value) const
    {
        MsgDataValue* pReadValue = NULL;
        Read("SendMsgRlt", pReadValue);
        return pReadValue->ToUInt8(Value);
    }
};

}// namespace Message
}// namespace VNOC

#endif