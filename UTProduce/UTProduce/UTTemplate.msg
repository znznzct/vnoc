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
	CPPUNIT_TEST( @MsgName@_Test );
	CPPUNIT_TEST_SUITE_END();
	
public:
    void setUp()
    {
    }
    void tearDown()
    {
    }
	
public:
	void @MsgName@_Test()
	{
		CBufferMessage buf;
		@MsgName@ TM@MsgName@;
		TM@MsgName@.Set@item_name@(@item_type_value@);
		
		g_m2pack.PackMessage(&TM@MsgName@, buf);
		CMessage parserMsg(CMessage2Parser::GetMsgType(buf));
		CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == @MsgName@_Id);
		g_m2parser.Parser(&parserMsg, buf);	
		
		@MsgName@ TP@MsgName@(parserMsg);
		@item_mtype@ @item_name@;
		TP@MsgName@.Get@item_name@(@item_name@);
		CPPUNIT_ASSERT(@item_name@ == @item_type_value@);
	}

};
CPPUNIT_TEST_SUITE_REGISTRATION ( MSG_Message_Test );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(MSG_Message_Test, "testNMessage");

#endif // CPPTEST