#include "XMLItem.h"

namespace UTProduce
{
namespace XML
{

XMLItem::XMLItem(MsgItemMType ItemMType, const std::string& strItemName, MsgItemType ItemType)
	 : m_ItemMType(ItemMType)
	 , m_strItemName(strItemName)
	 , m_ItemType(ItemType)		   
{
}

XMLItem::XMLItem(const XMLItem& xmlItemObj)
{
	this->m_ItemMType = xmlItemObj.m_ItemMType;
	this->m_strItemName = xmlItemObj.m_strItemName;
	this->m_ItemType = xmlItemObj.m_ItemType;
}

XMLItem::~XMLItem()
{
	Clear();
}

void XMLItem::SetMType(MsgItemMType MTypeObj)
{
	m_ItemMType = MTypeObj;
}

void XMLItem::SetName(const std::string& strNameObj)
{
	m_strItemName = strNameObj;
}

void XMLItem::SetType(MsgItemType TypeObj)
{
	m_ItemType = TypeObj;
}

MsgItemMType XMLItem::GetMType() const
{
	return m_ItemMType;
}

const char*	XMLItem::GetName() const 
{
	return m_strItemName.c_str();
}

MsgItemType XMLItem::GetType() const
{
	return m_ItemType;
}

bool XMLItem::IsRight()	const
{
	if(m_ItemMType == MsgItemMType_Null || m_strItemName.empty() || m_ItemType == MsgItemType_Null)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool XMLItem::IsInvalid() const
{
	return !IsRight();
}

void XMLItem::Clear()
{
	m_ItemMType = MsgItemMType_Null;
	m_strItemName.clear();
	m_ItemType = MsgItemType_Null;
}

}// namespace XML
}// namespace UTProduce