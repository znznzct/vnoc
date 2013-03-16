#ifndef UTPRODUCER_PRODUCER
#define UTPRODUCER_PRODUCER

#include "XMLParser.h"


namespace UTProduce
{
namespace XML
{
// VAR--->variable   VAL--->value   VEC--->vector
#define UT_TEST				"CPPUNIT_TEST( @MsgName@_Test );"
#define FUN_NAME			"void @MsgName@_Test()"
#define DEF_TM_MSG_VAR		"@MsgName@ TM@MsgName@;"
#define DEF_ITEM_VAR		"@item_mtype@ @item_name@;"
#define SET_ITEM_VAL		"TM@MsgName@.Set@item_name@(@item_type_value@);"
#define DEF_ITEM_VEC		"std::vector<@item_mtype@> @item_name@;"
#define PUSH_ITEM_VAL		"@item_name@.push_back(@item_type_value@);"
#define PACK_MSG			"g_m2pack.PackMessage(TM@MsgName@, buf);"
#define UT_ASSERT_MSG_TYPE	"CPPUNIT_ASSERT(CMessage2Parser::GetMsgType(buf) == @MsgName@_Id);"
#define PARSE_MSG			"g_m2parser.Parser(&parserMsg, buf);"
#define DEF_TP_MSG_VAR		"@MsgName@ TP@MsgName@(parserMsg);"	
#define GET_ITEM_VAL		"TP@MsgName@.Get@item_name@(@item_name@);"
#define UT_ASSERT_ITEM_VAL	"CPPUNIT_ASSERT(@item_name@ == @item_type_value@);"


class Producer
{
public:
	Producer();
	virtual ~Producer();

protected:
	const char* _GetItemTypeStr(MsgDef::MsgItemType msgItemType);
	long long _GetRandNum(MsgDef::MsgItemType msgItemType); 
};


} // namespace XML
} // namespace UTProduce



#endif // UTPRODUCER_PRODUCER