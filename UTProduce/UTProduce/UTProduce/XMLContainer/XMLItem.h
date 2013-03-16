#ifndef UTPRODUCE_XMLITEM
#define UTPRODUCE_XMLITEM


#include "IXMLObject.h"
using namespace UTProduce::MsgDef;

namespace UTProduce
{
namespace XML
{

class XMLItem : public IXMLObject
{
public:
	XMLItem(MsgItemMType ItemMType   = MsgDef::MsgItemMType_Null,
		    const std::string& strItemName = "\0",
			MsgItemType	 ItemType    = MsgDef::MsgItemType_Null);
	XMLItem(const XMLItem& xmlItemObj);
	virtual ~XMLItem();

public:

public:
	void SetMType(MsgItemMType MTypeObj);
	void SetName(const std::string& strNameObj);
	void SetType(MsgItemType TypeObj);
	MsgItemMType GetMType() const;
	const char*	 GetName() const;
	MsgItemType  GetType() const;
	bool IsRight() const;
	bool IsInvalid() const;
	void Clear();

private:
	MsgItemMType m_ItemMType;	    // <item mtype="list" name="Example_1" type="uint32" />
	std::string	 m_strItemName;	   // <item mtype="list" name=""Example_2" type="string"/>
	MsgItemType	 m_ItemType;      // <item mtype="list" name="Example_2" type="uint32" />
};


}// namespace XML
}// namespace UTProduce


#endif // UTPRODUCE_XMLITEM