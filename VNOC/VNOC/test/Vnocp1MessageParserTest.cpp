#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../MessageParser.h"
#include <string.h>
class Vnocp1MessageParserTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( Vnocp1MessageParserTest );
    CPPUNIT_TEST( simpleTest );
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp()
    {
        
    }
    void tearDown()
    {

    }
public:
    void simpleTest()
    {
        byte testAVC [] = {0x55,
		0x00,0x00,0x00,0x1E,
		0x01,
		0x01,
		0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,
		0x15,
		0x00,0x00,0x00,0x00,
		0x03,
		0x00,0x00,0x00,0x04,
		0x00,0x00,0x00,0x01,
		0x00,0x00,0x00,0x10,
		0x00,0x00,0x00,0x01,
		0x01,
 		0x33,0x33,0x33,0x33,
 		0x33,0x33,0x33,0x33,
		0x33,0x33,0x33,0x33,
		0x33,0x33,0x33,0x33,
		0x00,0x05,
		0x43};
		CMessageParser msgParser;
		CMessage* msg = msgParser.Parse(testAVC, sizeof(testAVC));
		CPPUNIT_ASSERT(msg->GetMessageType() == MSG_AVC_TYPE);//验证消息类型是AVC
		MSG_AVC* msg_avc = (MSG_AVC *)msg;
		//验证令牌
		byte expectToken[]={0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66};
		CPPUNIT_ASSERT(memcmp(msg_avc->GetToken(),expectToken, sizeof(expectToken)) == 0);
		//验证验证码类型
		CPPUNIT_ASSERT(msg_avc->GetCaptchaType() == 0x01);
		//验证验证码内容
		byte CaptchaContent[]={0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33};
		CPPUNIT_ASSERT(memcmp(msg_avc->GetCaptcha(),CaptchaContent(), sizeof(CaptchaContent)) == 0);

		CPPUNIT_ASSERT(true);
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION ( Vnocp1MessageParserTest );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(Vnocp1MessageParserTest, "Vnocp1MessageParserTest");