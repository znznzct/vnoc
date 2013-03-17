#include "XMLParser.h"


namespace UTProduce
{
namespace XML
{

XMLParser::XMLParser()
{
	m_TinyEleRoot	= NULL;
	m_TinyNodeMsg	= NULL;
	m_TinyEleMsg	= NULL;
	m_TinyNodeItem  = NULL;
	m_TinyEleItem   = NULL;
}

XMLParser::~XMLParser()
{
	Clear();
}

void XMLParser::Clear()
{
	m_strTinyNameRoot.clear();
	m_strTinyMsgName.clear();
	m_strId.clear();
	m_mXMLMsg.Clear();
	m_mXMLItem.Clear();

	/*if(m_TinyEleRoot != NULL){
		delete m_TinyEleRoot;
		m_TinyEleRoot = NULL;
	}*/
	/*if(m_TinyNodeMsg != NULL){
		delete m_TinyNodeMsg;
		m_TinyNodeMsg = NULL;
	}*/
	/*if(m_TinyEleMsg != NULL){
		delete m_TinyEleMsg;
		m_TinyEleMsg = NULL;
	}*/
	/*if(m_TinyNodeItem != NULL){
		delete m_TinyNodeItem;
		m_TinyNodeItem = NULL;
	}
	if(m_TinyEleItem != NULL){
		delete m_TinyEleItem;
		m_TinyEleItem = NULL;
	}*/	
}

bool XMLParser::GetXMLMsgGatherer(XMLMsgGatherer& xmlMsgGatherer)
{
	if(m_XMLMsgGatherer.IsInvalid()){
		return false;
	}

	xmlMsgGatherer = m_XMLMsgGatherer;
	return true;
}

bool XMLParser::ParseXML(const std::string& strPath)
{
	if(!_LoadTinyXmlFile(strPath)){
		return false;
	}

	if(!_SetTinyBasalElement()){
		return false;
	}

	if(!_SetTinyBasalNode()){
		return false;
	}

	if(!_RoundLoadTinyMsg()){
		return false;
	}

	return true;
}

bool XMLParser::_LoadTinyXmlFile(const std::string& strPath)
{
	return m_TinyXmlDoc.LoadFile(strPath.c_str());	
}

bool XMLParser::_SetTinyBasalElement()
{
	m_TinyEleRoot = m_TinyXmlDoc.RootElement();
	m_strTinyNameRoot = m_TinyEleRoot->Value();
	if(m_strTinyNameRoot != XMLFileRoot){
		return false;
	}

	return true;
}
bool  XMLParser::_SetTinyBasalNode()
{
	m_TinyNodeMsg = m_TinyXmlDoc.FirstChild(XMLFileRoot);
	if(!m_TinyNodeMsg){
		return false;
	}

	return true;
}

bool  XMLParser::_RoundLoadTinyMsg()
{
	for(m_TinyEleMsg = m_TinyNodeMsg->FirstChildElement();
		m_TinyEleMsg != NULL;
		m_TinyEleMsg = m_TinyEleMsg->NextSiblingElement())
	{
		if(strcmp(m_TinyEleMsg->Value(), XMLMsg_msg)  != 0){
			return false;
		}																	
		
		if(_LoadTinyMsgName() == false || _LoadTinyMsgId() == false || _RoundLoadTinyItem() == false){
			continue; 
		}

		m_XMLMsgGatherer.InsertXMLMsg(m_mXMLMsg.GetName(), m_mXMLMsg);
		m_mXMLMsg.Clear();
		if(m_XMLMsgGatherer.IsInvalid()){
			return false;
		}
	}

	return true;
}

bool XMLParser::_LoadTinyMsgName()
{
	m_strTinyMsgName = m_TinyEleMsg->Attribute(XMLMsg_Name);
	return m_mXMLMsg.SetName(m_strTinyMsgName) ? true : false;
}

bool XMLParser::_LoadTinyMsgId()
{
	m_strId = m_TinyEleMsg->Attribute(XMLMsg_Id);
	return m_mXMLMsg.SetId(m_strId) ? true : false;
}

bool XMLParser::_RoundLoadTinyItem()
{
	m_TinyNodeItem = m_TinyEleMsg->FirstChild();
	if(m_TinyNodeItem == NULL){
		return false;
	}

	for(m_TinyEleItem = m_TinyNodeItem->ToElement();
		m_TinyEleItem != NULL;
		m_TinyEleItem = m_TinyEleItem->NextSiblingElement())
	{
		if(_LoadTinyItem_MType() == false || _LoadTinyItem_Name() == false || _LoadTinyItem_Type() == false){	
			return false;
		}
		m_mXMLMsg.InsetXMLItem(m_mXMLItem.GetName(), m_mXMLItem);
		m_mXMLItem.Clear();	
	}

	return true;
}

bool XMLParser::_LoadTinyItem_MType()
{
	if(m_TinyEleItem->Attribute(XMLItem_MType))
	{
		std::string strItemMType = m_TinyEleItem->Attribute(XMLItem_MType);
		if(strItemMType == XMLItemMType_Data){
			m_mXMLItem.SetMType(MsgItemMType_Data);
		}
		else if(strItemMType == XMLItemMType_List){
			m_mXMLItem.SetMType(MsgItemMType_List);
		}

		return true;
	}

	return false;
}

bool XMLParser::_LoadTinyItem_Name()
{
	if(m_TinyEleItem->Attribute(XMLItem_Name))
	{
		m_mXMLItem.SetName(m_TinyEleItem->Attribute(XMLItem_Name));
		return true;
	}

	return false;
}

bool XMLParser::_LoadTinyItem_Type()
{
	if(m_TinyEleItem->Attribute(XMLItem_Type))
	{
		std::string strItemType = m_TinyEleItem->Attribute(XMLItem_Type);
		if(strItemType == XMLItemType_String){
			m_mXMLItem.SetType(MsgItemType_String);
		}
		else if(strItemType == XMLItemType_Uint8){
			m_mXMLItem.SetType(MsgItemType_Uint8);
		}
		else if(strItemType == XMLItemType_Uint16){
			m_mXMLItem.SetType(MsgItemType_Uint16);
		}
		else if(strItemType == XMLItemType_Uint32){
			m_mXMLItem.SetType(MsgItemType_Uint32);
		}
		else if(strItemType == XMLItemType_int8){
			m_mXMLItem.SetType(MsgItemType_int8);
		}
		else if(strItemType == XMLItemType_int16){
			m_mXMLItem.SetType(MsgItemType_int16);
		}
		else if(strItemType == XMLItemType_int32){
			m_mXMLItem.SetType(MsgItemType_int32);
		}

		return true;
	}

	return false;
}

}// namespace XML
}// namespace UTProduce