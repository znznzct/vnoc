#pragma once
#include "VnocProtocol.hpp"
#include "RoomManager.h"
#include "VNOCUser.h"
#include "UserManage.hpp"

class RecMessageHandler : public IMessageHandler
{
public:
    RecMessageHandler(VnocProtocol *protocol):protocol_(protocol)
    {
        protocol_->RegisterMessageHandler( this );
    }

    virtual VMsg getMessageType() const
    {
        return MSG_RequestEnterClassroom_Id;
    }

    virtual int operator()(const CMessage *msg, MessageContext *ctx)
    {
        MSG_AnswerEnterClassroom aecMessage;
        MSG_RequestEnterClassroom recMessage( *msg );
        uint32 roomID;
        recMessage.GetRoomID( roomID );
        /* these two fields are still not used now.
        string password;
        recMessage.GetRoomPassword( password );
        string verification;
        recMessage.GetVerificationCode( verification );
        */
        Room *room= RoomManager::instance().getRoom( roomID );
        VNOCUser &vUser = CUserManage::GetInstance()->getOnlineUser( ctx->userName );
        if (room != NULL)
        {
            bool tag = room->addUser( &vUser );
            aecMessage.SetRetTag( tag ? 0 : 1 );
        }
        else
        {
            aecMessage.SetRetTag( 1 );
        }
        protocol_->SendVnocMessage( &aecMessage, ctx );
        return 1;
    }

private:
    VnocProtocol *protocol_;
};