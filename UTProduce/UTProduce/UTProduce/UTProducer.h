#ifndef UTPRODUCE_UTPRODUCER
#define UTPRODUCE_UTPRODUCER

#include "Producer.h"
#include <ctime>
//#include "Utility/File/FileBase.h"


namespace UTProduce
{
namespace XML
{

class UTProducer : public Producer
{
public:
	UTProducer();
	virtual ~UTProducer();

public:
	bool Produce(std::string strFull, std::string strReplace, IXMLObject xmlObject);

public:
	bool LoadUTFileTemplate(const std::string& strFileName);
	bool LoadXMLFile(const std::string& strFileName);
	bool ProduceUTFile(const std::string& strFileTempName, const std::string& strXMLFileName);
	

private:
	bool _ProduceHeaderUTAss();
		bool _ExtractHeaderTemplate();
	bool _ProduceBodyTestFun();
		bool _ExtractBodyTemplate();
		bool _ExtractTopOfBodyTemplate();
		bool _ExtractMiddleOfBodyTemplate();
		bool _ExtractBottomOfBodyTemplate();
		void _SetStrTestFunNeedProduce();
		void _ProduceBodyTestFun_MtypeData(const std::string& strItemType, const std::string& strItemName, long long nRandNum);
		void _ProduceBodyTestFun_MtypeList(const std::string& strItemType, const std::string& strItemName, long long nRandNum);
			void _ProduceStrSetItemVal(const std::string& strItemName, const std::string& strVarVal);
			void _ProduceStrDefVar(const std::string& strItemType, const std::string& strItemName);
			void _ProduceStrGetItemVal(const std::string& strItemName);
			void _ProduceStrUTAssItemVarVal(const std::string& strItemName, const std::string& strVarVal);
			void _ProduceStrDefVec(const std::string& strItemType, const std::string& strItemName);
			std::string _ModifyItemNameOfStrToPushItemVec(const std::string& strItemName);
			void _ProduceStrPushItemVec(const std::string& strPushItemVal, const std::string& strVarVal);
		    void _ProduceStrUTAssItemVecVal(const std::string& strItemName, int nIndex, const std::string& strVarVal);
				void _AttachStrGetItemVal();
				void _AttachStrUTAss();
			void _ReplaceAllMsgName(const std::string& strMsgName);
		void _ProduceTestFunction(const std::string& strItemName);
	bool _ProduceFooter();
	bool _WriteUTIntoFile();


private:
	File::FileBase m_FileBase;
	XMLParser m_xmlParser;
	XMLMsgGatherer m_MsgGatherer;

private:
	std::string m_strFileTemplate;
	std::string m_strHeaderTemplate;
	std::string m_strBodyTemplate;
		std::string m_strBodyTemp_top;
		std::string m_strBodyTemp_mid;
		std::string m_strBodyTemp_Bot;
			std::string m_strBody_top;
			std::string m_strBody_mid;
			std::string m_strBody_Bot;
			std::string m_strAttachGetItemVal;
			std::string m_strAttachUTAss;
	std::string m_strProHeaderUTAssRlt;
	std::string m_strProBodyTestFunRlt;
	std::string m_strProFooterRlt;
};


}// namespace XML
}// namespace UTProduce








#endif // UTPRODUCE_UTPRODUCER