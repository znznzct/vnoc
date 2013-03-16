#include "XMLMsgGatherer.h"


namespace UTProduce
{
namespace XML
{
XMLMsgGatherer::XMLMsgGatherer()
{
}

XMLMsgGatherer::~XMLMsgGatherer()
{
	Clear();
}

bool XMLMsgGatherer::InsertXMLMsg(const std::string& strMsgName, const XMLMsg& XMLMsgObj)
{
	if(strMsgName.empty() || XMLMsgObj.IsInvalid()){
		return false;
	}
	
	m_mapMsgGroup_name[strMsgName] = XMLMsgObj;
	m_mapMsgGroup_id[XMLMsgObj.GetId()] = strMsgName;
	return true;

}

bool XMLMsgGatherer::DeleteXMLMsg(const std::string& strMsgName)
{
	
	auto itName = m_mapMsgGroup_name.find(strMsgName);
	if(itName != m_mapMsgGroup_name.end())
	{
		auto itId = m_mapMsgGroup_id.find(itName->second.GetId());
		if(itId != m_mapMsgGroup_id.end()){
			m_mapMsgGroup_id.erase(itId);
			m_mapMsgGroup_name.erase(itName);
			return true;
		}
	}

	return false;
}

XMLMsg* XMLMsgGatherer::GetXMLMsg(const std::string& strMsgName)
{
	auto it = m_mapMsgGroup_name.find(strMsgName);
	if(it != m_mapMsgGroup_name.end()){
		return &(it->second);
	}

	return 0;
}

XMLMsg* XMLMsgGatherer::GetXMLMsg(int nMsgId)
{
	auto itId = m_mapMsgGroup_id.find(nMsgId);
	if(itId != m_mapMsgGroup_id.end())
	{
		auto itName = m_mapMsgGroup_name.find(itId->second);
		if(itName != m_mapMsgGroup_name.end()){
			return &(itName->second);
		}
	}

	return 0;
	

}


int  XMLMsgGatherer::GetSize() const
{
	return m_mapMsgGroup_name.size();
}

bool XMLMsgGatherer::IsRight() const
{
	return !IsInvalid();
}

bool XMLMsgGatherer::IsInvalid() const
{
	return (m_mapMsgGroup_id.size() == 0 ||
		    m_mapMsgGroup_name.size() == 0 ||
			m_mapMsgGroup_id.size() != m_mapMsgGroup_name.size());
}





void XMLMsgGatherer::Clear()
{
	m_mapMsgGroup_name.clear();
	m_mapMsgGroup_id.clear();

}

std::map<std::string, XMLMsg>::iterator XMLMsgGatherer::Begin()
{
	return m_mapMsgGroup_name.begin();
}

std::map<std::string, XMLMsg>::iterator XMLMsgGatherer::End()
{
	return m_mapMsgGroup_name.end();
}

}// namespace XML
}// namespace UTProduce