#ifdef CPPTEST
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <Windows.h>
#include <string.h>
#include <shlwapi.h>
#include <atlstr.h>
#include <string>
#include <vector>
#include "../../NMessage/MessageUnion.h"
#include "../../NMessage/Message2Pack.h"
#include "../../NMessage/Message2Parser.h"
#include "../../NMessage/ParserMessageXML.h"
#include "../../NMessage/BufferMessage.h"

using namespace VNOC::Message;
using namespace VNOC::Message::Define;

///> Generate by UTProduse. DO NOT EDIT!

CMessage2Pack g_m2pack;
CMessage2Parser g_m2parser;

class MSG_Message_Test : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( MSG_Message_Test );
	CPPUNIT_TEST( MSG_AnswerClassInfo_Test );
    CPPUNIT_TEST( MSG_AnswerClassList_Test );
    CPPUNIT_TEST( MSG_AnswerLogin_Test );
    CPPUNIT_TEST( MSG_AnswerProfileSync_Test );
    CPPUNIT_TEST( MSG_AnswerRegister_Test );
    CPPUNIT_TEST( MSG_AnswerVerificationCode_Test );
    CPPUNIT_TEST( MSG_RequestClassInfo_Test );
    CPPUNIT_TEST( MSG_RequestClassList_Test );
    CPPUNIT_TEST( MSG_RequestLogin_Test );
    CPPUNIT_TEST( MSG_RequestProfileSync_Test );
    CPPUNIT_TEST( MSG_RequestRegister_Test );
    CPPUNIT_TEST( MSG_RequestVerificationCode_Test );
    
	CPPUNIT_TEST_SUITE_END();
	
public:
    void setUp()
    {
    }
    void tearDown()
    {
    }
	
public:
	void MSG_AnswerClassInfo_Test()
	{
		CBufferMessage buf;
		MSG_AnswerClassInfo TMMSG_AnswerClassInfo;
		TMMSG_AnswerClassInfo.SetRoomID(18096);
        TMMSG_AnswerClassInfo.SetRoomManageId(4193);
        TMMSG_AnswerClassInfo.SetRoomName("´ó°×ÍÃ");
        TMMSG_AnswerClassInfo.SetRoomPassword("´ó°×ÍÃ");
        std::vector<uint32> RoomPeopleListId;
        RoomPeopleListId.push_back(19484);
        RoomPeopleListId.push_back(19056);
        RoomPeopleListId.push_back(1813);
        TMMSG_AnswerClassInfo.SetRoomPeopleListId(RoomPeopleListId);
        TMMSG_AnswerClassInfo.SetRoomPeopleNumMax(1463);
        TMMSG_AnswerClassInfo.SetRoomRank(6611);
        TMMSG_AnswerClassInfo.SetRoomState(25708);
        TMMSG_AnswerClassInfo.SetRoomType(2825);
        
		
		g_m2pack.PackMessage(&TMMSG_AnswerClassInfo, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_AnswerClassInfo_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_AnswerClassInfo TPMSG_AnswerClassInfo(parserMsg);
		uint32 RoomID;
        uint32 RoomManageId;
        std::string RoomName;
        std::string RoomPassword;
        uint32 RoomPeopleNumMax;
        uint32 RoomRank;
        uint32 RoomState;
        uint32 RoomType;
        TPMSG_AnswerClassInfo.GetRoomID(RoomID);
        TPMSG_AnswerClassInfo.GetRoomManageId(RoomManageId);
        TPMSG_AnswerClassInfo.GetRoomName(RoomName);
        TPMSG_AnswerClassInfo.GetRoomPassword(RoomPassword);
        TPMSG_AnswerClassInfo.GetRoomPeopleListId(RoomPeopleListId);
        TPMSG_AnswerClassInfo.GetRoomPeopleNumMax(RoomPeopleNumMax);
        TPMSG_AnswerClassInfo.GetRoomRank(RoomRank);
        TPMSG_AnswerClassInfo.GetRoomState(RoomState);
        TPMSG_AnswerClassInfo.GetRoomType(RoomType);
        CPPUNIT_ASSERT(RoomID == 18096);
        CPPUNIT_ASSERT(RoomManageId == 4193);
        CPPUNIT_ASSERT(RoomName == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(RoomPassword == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(RoomPeopleListId[0] == 19484);
        CPPUNIT_ASSERT(RoomPeopleListId[1] == 19056);
        CPPUNIT_ASSERT(RoomPeopleListId[2] == 1813);
        CPPUNIT_ASSERT(RoomPeopleNumMax == 1463);
        CPPUNIT_ASSERT(RoomRank == 6611);
        CPPUNIT_ASSERT(RoomState == 25708);
        CPPUNIT_ASSERT(RoomType == 2825);
        
    }

    void MSG_AnswerClassList_Test()
	{
		CBufferMessage buf;
		MSG_AnswerClassList TMMSG_AnswerClassList;
		std::vector<uint32> RoomIdList;
        RoomIdList.push_back(29288);
        RoomIdList.push_back(8025);
        RoomIdList.push_back(20807);
        TMMSG_AnswerClassList.SetRoomIdList(RoomIdList);
        std::vector<std::string> RoomNameList;
        RoomNameList.push_back("´ó°×ÍÃ");
        RoomNameList.push_back("´ó°×ÍÃ");
        RoomNameList.push_back("´ó°×ÍÃ");
        TMMSG_AnswerClassList.SetRoomNameList(RoomNameList);
        std::vector<uint32> RoomStateList;
        RoomStateList.push_back(11114);
        RoomStateList.push_back(16043);
        RoomStateList.push_back(2978);
        TMMSG_AnswerClassList.SetRoomStateList(RoomStateList);
        
		
		g_m2pack.PackMessage(&TMMSG_AnswerClassList, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_AnswerClassList_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_AnswerClassList TPMSG_AnswerClassList(parserMsg);
		TPMSG_AnswerClassList.GetRoomIdList(RoomIdList);
        TPMSG_AnswerClassList.GetRoomNameList(RoomNameList);
        TPMSG_AnswerClassList.GetRoomStateList(RoomStateList);
        CPPUNIT_ASSERT(RoomIdList[0] == 29288);
        CPPUNIT_ASSERT(RoomIdList[1] == 8025);
        CPPUNIT_ASSERT(RoomIdList[2] == 20807);
        CPPUNIT_ASSERT(RoomNameList[0] == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(RoomNameList[1] == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(RoomNameList[2] == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(RoomStateList[0] == 11114);
        CPPUNIT_ASSERT(RoomStateList[1] == 16043);
        CPPUNIT_ASSERT(RoomStateList[2] == 2978);
        
    }

    void MSG_AnswerLogin_Test()
	{
		CBufferMessage buf;
		MSG_AnswerLogin TMMSG_AnswerLogin;
		TMMSG_AnswerLogin.SetATLGUID("´ó°×ÍÃ");
        TMMSG_AnswerLogin.SetLoginResult(138);
        TMMSG_AnswerLogin.SetToken(5851);
        
		
		g_m2pack.PackMessage(&TMMSG_AnswerLogin, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_AnswerLogin_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_AnswerLogin TPMSG_AnswerLogin(parserMsg);
		std::string ATLGUID;
        uint8 LoginResult;
        uint32 Token;
        TPMSG_AnswerLogin.GetATLGUID(ATLGUID);
        TPMSG_AnswerLogin.GetLoginResult(LoginResult);
        TPMSG_AnswerLogin.GetToken(Token);
        CPPUNIT_ASSERT(ATLGUID == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(LoginResult == 138);
        CPPUNIT_ASSERT(Token == 5851);
        
    }

    void MSG_AnswerProfileSync_Test()
	{
		CBufferMessage buf;
		MSG_AnswerProfileSync TMMSG_AnswerProfileSync;
		TMMSG_AnswerProfileSync.SetMessageSynchro("´ó°×ÍÃ");
        
		
		g_m2pack.PackMessage(&TMMSG_AnswerProfileSync, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_AnswerProfileSync_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_AnswerProfileSync TPMSG_AnswerProfileSync(parserMsg);
		std::string MessageSynchro;
        TPMSG_AnswerProfileSync.GetMessageSynchro(MessageSynchro);
        CPPUNIT_ASSERT(MessageSynchro == "´ó°×ÍÃ");
        
    }

    void MSG_AnswerRegister_Test()
	{
		CBufferMessage buf;
		MSG_AnswerRegister TMMSG_AnswerRegister;
		TMMSG_AnswerRegister.SetRetTag(12902);
        
		
		g_m2pack.PackMessage(&TMMSG_AnswerRegister, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_AnswerRegister_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_AnswerRegister TPMSG_AnswerRegister(parserMsg);
		uint32 RetTag;
        TPMSG_AnswerRegister.GetRetTag(RetTag);
        CPPUNIT_ASSERT(RetTag == 12902);
        
    }

    void MSG_AnswerVerificationCode_Test()
	{
		CBufferMessage buf;
		MSG_AnswerVerificationCode TMMSG_AnswerVerificationCode;
		TMMSG_AnswerVerificationCode.SetCaptcha("´ó°×ÍÃ");
        TMMSG_AnswerVerificationCode.SetCaptchaType(209);
        TMMSG_AnswerVerificationCode.SetLoginTag(23);
        
		
		g_m2pack.PackMessage(&TMMSG_AnswerVerificationCode, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_AnswerVerificationCode_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_AnswerVerificationCode TPMSG_AnswerVerificationCode(parserMsg);
		std::string Captcha;
        uint8 CaptchaType;
        uint8 LoginTag;
        TPMSG_AnswerVerificationCode.GetCaptcha(Captcha);
        TPMSG_AnswerVerificationCode.GetCaptchaType(CaptchaType);
        TPMSG_AnswerVerificationCode.GetLoginTag(LoginTag);
        CPPUNIT_ASSERT(Captcha == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(CaptchaType == 209);
        CPPUNIT_ASSERT(LoginTag == 23);
        
    }

    void MSG_RequestClassInfo_Test()
	{
		CBufferMessage buf;
		MSG_RequestClassInfo TMMSG_RequestClassInfo;
		TMMSG_RequestClassInfo.SetRoomID(13079);
        
		
		g_m2pack.PackMessage(&TMMSG_RequestClassInfo, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_RequestClassInfo_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_RequestClassInfo TPMSG_RequestClassInfo(parserMsg);
		uint32 RoomID;
        TPMSG_RequestClassInfo.GetRoomID(RoomID);
        CPPUNIT_ASSERT(RoomID == 13079);
        
    }

    void MSG_RequestClassList_Test()
	{
		CBufferMessage buf;
		MSG_RequestClassList TMMSG_RequestClassList;
		TMMSG_RequestClassList.SetUserType(8505);
        
		
		g_m2pack.PackMessage(&TMMSG_RequestClassList, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_RequestClassList_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_RequestClassList TPMSG_RequestClassList(parserMsg);
		uint32 UserType;
        TPMSG_RequestClassList.GetUserType(UserType);
        CPPUNIT_ASSERT(UserType == 8505);
        
    }

    void MSG_RequestLogin_Test()
	{
		CBufferMessage buf;
		MSG_RequestLogin TMMSG_RequestLogin;
		TMMSG_RequestLogin.SetAccountNumber("´ó°×ÍÃ");
        TMMSG_RequestLogin.SetPassword("´ó°×ÍÃ");
        TMMSG_RequestLogin.SetVerificationCode("´ó°×ÍÃ");
        
		
		g_m2pack.PackMessage(&TMMSG_RequestLogin, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_RequestLogin_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_RequestLogin TPMSG_RequestLogin(parserMsg);
		std::string AccountNumber;
        std::string Password;
        std::string VerificationCode;
        TPMSG_RequestLogin.GetAccountNumber(AccountNumber);
        TPMSG_RequestLogin.GetPassword(Password);
        TPMSG_RequestLogin.GetVerificationCode(VerificationCode);
        CPPUNIT_ASSERT(AccountNumber == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(Password == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(VerificationCode == "´ó°×ÍÃ");
        
    }

    void MSG_RequestProfileSync_Test()
	{
		CBufferMessage buf;
		MSG_RequestProfileSync TMMSG_RequestProfileSync;
		TMMSG_RequestProfileSync.SetAutograph("´ó°×ÍÃ");
        TMMSG_RequestProfileSync.SetHeadForm(204);
        TMMSG_RequestProfileSync.SetHeadPortrait("´ó°×ÍÃ");
        TMMSG_RequestProfileSync.SetNickname("´ó°×ÍÃ");
        TMMSG_RequestProfileSync.SetRank(0);
        
		
		g_m2pack.PackMessage(&TMMSG_RequestProfileSync, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_RequestProfileSync_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_RequestProfileSync TPMSG_RequestProfileSync(parserMsg);
		std::string Autograph;
        uint8 HeadForm;
        std::string HeadPortrait;
        std::string Nickname;
        uint8 Rank;
        TPMSG_RequestProfileSync.GetAutograph(Autograph);
        TPMSG_RequestProfileSync.GetHeadForm(HeadForm);
        TPMSG_RequestProfileSync.GetHeadPortrait(HeadPortrait);
        TPMSG_RequestProfileSync.GetNickname(Nickname);
        TPMSG_RequestProfileSync.GetRank(Rank);
        CPPUNIT_ASSERT(Autograph == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(HeadForm == 204);
        CPPUNIT_ASSERT(HeadPortrait == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(Nickname == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(Rank == 0);
        
    }

    void MSG_RequestRegister_Test()
	{
		CBufferMessage buf;
		MSG_RequestRegister TMMSG_RequestRegister;
		TMMSG_RequestRegister.SetAutograph("´ó°×ÍÃ");
        TMMSG_RequestRegister.SetEmailAddress("´ó°×ÍÃ");
        TMMSG_RequestRegister.SetHeadForm(173);
        TMMSG_RequestRegister.SetHeadPortrait("´ó°×ÍÃ");
        TMMSG_RequestRegister.SetNickname("´ó°×ÍÃ");
        TMMSG_RequestRegister.SetRank(213);
        
		
		g_m2pack.PackMessage(&TMMSG_RequestRegister, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_RequestRegister_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_RequestRegister TPMSG_RequestRegister(parserMsg);
		std::string Autograph;
        std::string EmailAddress;
        uint8 HeadForm;
        std::string HeadPortrait;
        std::string Nickname;
        uint8 Rank;
        TPMSG_RequestRegister.GetAutograph(Autograph);
        TPMSG_RequestRegister.GetEmailAddress(EmailAddress);
        TPMSG_RequestRegister.GetHeadForm(HeadForm);
        TPMSG_RequestRegister.GetHeadPortrait(HeadPortrait);
        TPMSG_RequestRegister.GetNickname(Nickname);
        TPMSG_RequestRegister.GetRank(Rank);
        CPPUNIT_ASSERT(Autograph == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(EmailAddress == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(HeadForm == 173);
        CPPUNIT_ASSERT(HeadPortrait == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(Nickname == "´ó°×ÍÃ");
        CPPUNIT_ASSERT(Rank == 213);
        
    }

    void MSG_RequestVerificationCode_Test()
	{
		CBufferMessage buf;
		MSG_RequestVerificationCode TMMSG_RequestVerificationCode;
		TMMSG_RequestVerificationCode.SetMachineAddress("´ó°×ÍÃ");
        
		
		g_m2pack.PackMessage(&TMMSG_RequestVerificationCode, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == MSG_RequestVerificationCode_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		MSG_RequestVerificationCode TPMSG_RequestVerificationCode(parserMsg);
		std::string MachineAddress;
        TPMSG_RequestVerificationCode.GetMachineAddress(MachineAddress);
        CPPUNIT_ASSERT(MachineAddress == "´ó°×ÍÃ");
        
    }

    
};
CPPUNIT_TEST_SUITE_REGISTRATION ( MSG_Message_Test );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(MSG_Message_Test, "testNMessage");

#endif // CPPTEST