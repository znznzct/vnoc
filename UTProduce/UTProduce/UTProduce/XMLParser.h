#ifndef UTRPODUCE_XMLPARSER
#define UTRPODUCE_XMLPARSER

#include "utility/File/FileBase.h"
#include "utility/TinyXML/tinyxml.h"
#include "XMLContainer/XMLMsgGatherer.h"

namespace UTProduce
{
namespace XML
{

class XMLParser
{
public:
	XMLParser();
	virtual ~XMLParser();
	 
public:
	void Clear();
	bool ParseXML(const std::string& strPath);
	bool GetXMLMsgGatherer(XMLMsgGatherer& xmlMsgGatherer);

private:
	//bool _GetRootElement();
	bool _LoadTinyXmlFile(const std::string& strPath);
	bool _SetTinyBasalElement();
	bool _SetTinyBasalNode();
		bool _RoundLoadTinyMsg();
				bool _LoadTinyMsgName();
				bool _LoadTinyMsgId();
				bool _RoundLoadTinyItem();
					bool _LoadTinyItem_MType();
					bool _LoadTinyItem_Name();
					bool _LoadTinyItem_Type();

private:
	XMLMsgGatherer m_XMLMsgGatherer;

private:
	TiXmlDocument m_TinyXmlDoc;	   
	TiXmlElement* m_TinyEleRoot;
	std::string m_strTinyNameRoot;

private:
	TiXmlNode* m_TinyNodeMsg;
	TiXmlElement* m_TinyEleMsg;
	std::string m_strTinyMsgName;
	std::string m_strId;
	XMLMsg m_mXMLMsg;

private:
	TiXmlNode* m_TinyNodeItem;
	TiXmlElement* m_TinyEleItem;
	XMLItem m_mXMLItem;
};



}// namespace XML
}// namespace UTProduce

#endif // UTRPODUCE_XMLPARSER 