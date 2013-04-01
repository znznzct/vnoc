#ifndef UTPRODUCE_XMLMSG
#define UTPRODUCE_XMLMSG

#include "XMLItem.h"
using namespace UTProduce::MsgDef;

namespace UTProduce
{
namespace XML
{

class XMLMsg : public IXMLObject
{
public:
	XMLMsg(const std::string& MsgName = "\0", int nId = 0);
	XMLMsg(const std::string& MsgName, const std::string& strId);
	XMLMsg(const XMLMsg& xmlMsgObj);
	virtual ~XMLMsg();

public:
	int			GetId() const;
	const char* GetName() const;
	const char* GetAbbrName();
	XMLItem*	GetXMLItem(const std::string& strItemName);
	int			GetSize() const;
	bool		SetId(int nId);
	bool		SetId(const std::string& strId);
	bool		SetName(const std::string& strMsgName);
	bool		InsetXMLItem(const std::string& strItemName, const XMLItem& ItemObj);
	bool		IsRight() const;
	bool		IsInvalid() const;
	void		Clear();
	std::map<std::string, XMLItem>::iterator Begin();
	std::map<std::string, XMLItem>::iterator End();


private:
	std::string m_strMsgName;							// <msg name="MSGExample" id="1111">
	int m_nId;										   //     <item mtype="list" name="Example_1" type="uint32" />
	std::map<std::string, XMLItem> m_mapItemGroup;	  //      <item mtype="list" name="Example_2" type="string" />
};													 //    </msg>


}// namespace XML
}// namespace UTProduce


#endif // UTPRODUCE_XMLMSG