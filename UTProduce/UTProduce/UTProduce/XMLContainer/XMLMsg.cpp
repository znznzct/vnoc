#include "XMLMsg.h"

namespace UTProduce
{
namespace XML
{

XMLMsg::XMLMsg(const std::string& MsgName, int nId) 
	: m_strMsgName(MsgName)
	, m_nId(nId)
{
}

XMLMsg::XMLMsg(const std::string& MsgName, const std::string& strId)
{
	m_strMsgName = MsgName;
	m_nId = std::atoi(strId.c_str());
}

XMLMsg::XMLMsg(const XMLMsg& xmlMsgObj)
{
	this->m_strMsgName = xmlMsgObj.m_strMsgName;
	this->m_nId = xmlMsgObj.m_nId;
	this->m_mapItemGroup = xmlMsgObj.m_mapItemGroup;
}

XMLMsg::~XMLMsg()
{
	Clear();
}

int XMLMsg::GetId() const
{
	return m_nId;
}

const char* XMLMsg::GetName() const
{
	return m_strMsgName.c_str();
}

const char* XMLMsg::GetAbbrName()
{
	std::string strAbbrName;
	int nLen = m_strMsgName.length();
	strAbbrName += m_strMsgName[4];

	for(int i = 5; i < nLen; ++i)
	{
		if(m_strMsgName[i] >= 'A' && m_strMsgName[i] <= 'Z' )
		{
			strAbbrName += (m_strMsgName[i] + 32);
		}
	}
	return strAbbrName.c_str();
}

XMLItem* XMLMsg::GetXMLItem(const std::string& strItemName)
{
	auto it = m_mapItemGroup.find(strItemName);
	if(it != m_mapItemGroup.end()){
		return &(it->second);
	}

	return 0;
}

int XMLMsg::GetSize() const
{
	return m_mapItemGroup.size();
}

bool XMLMsg::SetId(int nId)
{
	if(nId == 0){
		return false;
	}

	m_nId = nId;
	return true;
}

bool XMLMsg::SetId(const std::string& strId)
{
	if(strId.empty()){
		return false;
	}

	return SetId(std::atoi(strId.c_str()));
}

bool XMLMsg::SetName(const std::string& strMsgName)
{
	if(strMsgName.empty()){
		return false;
	}

	m_strMsgName = strMsgName;
	return true;
}

bool XMLMsg::InsetXMLItem(const std::string& strItemName, const XMLItem& ItemObj)
{
	if(strItemName.empty() || (!ItemObj.IsRight())){
		return false;
	}
	
	m_mapItemGroup[strItemName] = ItemObj;
	return true;
}

bool XMLMsg::IsRight() const
{
	if(m_strMsgName.empty() || m_mapItemGroup.empty())
	{
		return false;
	}
	return true;
}

bool XMLMsg::IsInvalid() const
{
	return !IsRight();
}

void XMLMsg::Clear()
{
	m_strMsgName.clear();
	m_nId = 0;
	m_mapItemGroup.clear();
}

std::map<std::string, XMLItem>::iterator XMLMsg::Begin()
{
	return m_mapItemGroup.begin();
}

std::map<std::string, XMLItem>::iterator XMLMsg::End()
{
	return m_mapItemGroup.end();
}


}// namespace XML
}// namespace UTProduce