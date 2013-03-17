#ifndef UTPRODUCE_XMLMSGGATHER
#define UTPRODUCE_XMLMSGGATHER

#include "../Utility/File/FileBase.h"
#include "XMLItem.h"
#include "XMLMsg.h"

namespace UTProduce
{
namespace XML
{

class XMLMsgGatherer : public IXMLObject
{
public:
	XMLMsgGatherer();
	virtual ~XMLMsgGatherer();

public:
	bool InsertXMLMsg(const std::string& strMsgName, const XMLMsg& XMLMsgObj);
	bool DeleteXMLMsg(const std::string& strMsgName);
	XMLMsg* GetXMLMsg(const std::string& strMsgName);
	XMLMsg* GetXMLMsg(int nMsgName);
	int  GetSize() const;
	bool IsRight() const;
	bool IsInvalid() const;
	void Clear();
	std::map<std::string, XMLMsg>::iterator Begin();
	std::map<std::string, XMLMsg>::iterator End();

private:
	std::map<std::string, XMLMsg> m_mapMsgGroup_name;
	std::map<int, std::string> m_mapMsgGroup_id;
};


}// namespace XML
}// namespace UTProduce



#endif // UTPRODUCE_XMLMSGGATHER