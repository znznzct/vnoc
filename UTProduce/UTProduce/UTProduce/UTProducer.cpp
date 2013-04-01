#include "UTProducer.h"




namespace UTProduce
{
namespace XML
{
UTProducer::UTProducer()
{
	srand(unsigned(time(0)));
}

UTProducer::~UTProducer()
{
}


bool UTProducer::LoadUTFileTemplate(const std::string& strFileName)
{
	if(m_FileBase.Open(strFileName, File::FILE_OPEN_R))
	{
		char* strContent = new char[m_FileBase.GetFileSize() + 1];
		::memset(strContent, 0, m_FileBase.GetFileSize() + 1);
		m_FileBase.Read(strContent, sizeof(char), m_FileBase.GetFileSize() + 1);
		m_strFileTemplate = strContent;
		return true;
	}
	return false;
}

bool UTProducer::LoadXMLFile(const std::string& strFileName)
{
	m_xmlParser.ParseXML(strFileName);
	if(m_xmlParser.GetXMLMsgGatherer(m_MsgGatherer)){
		return true;
	}

	return false;
}

bool UTProducer::_WriteUTIntoFile()
{
	std::string strRlt = m_strProHeaderUTAssRlt + m_strProBodyTestFunRlt + m_strProFooterRlt;
	if(!m_FileBase.Open("MSG_Message_Test.cpp", File::FILE_OPEN_W_PLUS)){
		return false;
	}
	if(m_FileBase.Write((void*)strRlt.c_str(), 1, strRlt.length()) < 0){
		return false;
	}

	return true;
}

bool UTProducer::ProduceUTFile(const std::string& strFileTempName, const std::string& strXMLFileName)
{
	if(!LoadUTFileTemplate(strFileTempName) || !LoadXMLFile(strXMLFileName)){
		return false;
	}

	if(!_ProduceHeaderUTAss() || !_ProduceBodyTestFun() || !_ProduceFooter()){
		return false;
	}
	
	if(!_WriteUTIntoFile()){
		return false;
	}

	return true;
}



bool UTProducer::_ProduceHeaderUTAss()
{
	if(!_ExtractHeaderTemplate()){
		return false;
	}
	std::string strAttachMsgTest;
	for(auto itMsg = m_MsgGatherer.Begin();
		itMsg != m_MsgGatherer.End();
		++itMsg)
	{
		std::string strTestCon_copy = UT_TEST;
		strTestCon_copy.replace(strTestCon_copy.find("@MsgName@"), sizeof("@MsgName@") - 1, itMsg->second.GetName());
		strAttachMsgTest += (strTestCon_copy + "\n" + "    ");
	}
	m_strProHeaderUTAssRlt = m_strHeaderTemplate;
	m_strProHeaderUTAssRlt.replace(m_strProHeaderUTAssRlt.find(UT_TEST), strlen(UT_TEST), strAttachMsgTest);
	
	return true;
}

bool UTProducer::_ExtractHeaderTemplate()
{
	int nHeader = m_strFileTemplate.find(FUN_NAME);
	if(nHeader == std::string::npos){
		return false;
	}
	m_strHeaderTemplate.resize(nHeader);
	std::copy(m_strFileTemplate.begin(), m_strFileTemplate.begin() + nHeader, m_strHeaderTemplate.begin());
	return true;
}



bool UTProducer::_ProduceBodyTestFun()
{
	if (!_ExtractBodyTemplate()	
		|| !_ExtractTopOfBodyTemplate()
		|| !_ExtractMiddleOfBodyTemplate()
		|| !_ExtractBottomOfBodyTemplate()){
		return false;
	}

	for(auto itMsg = m_MsgGatherer.Begin();
		itMsg != m_MsgGatherer.End();
		++itMsg)
	{
		_SetStrTestFunNeedProduce();
		for(auto itItem = itMsg->second.Begin();
			itItem != itMsg->second.End();
			++itItem)
		{
			if(itItem->second.GetMType() == MsgDef::MsgItemMType_Null || itItem->second.GetType() == MsgDef::MsgItemType_Null)
			{
				continue;
			}
			else if(itItem->second.GetMType() == MsgDef::MsgItemMType_Data)
			{
				_ProduceBodyTestFun_MtypeData(
				_GetItemTypeStr(itItem->second.GetType()), itItem->second.GetName(), _GetRandNum(itItem->second.GetType()));
			}
			else if(itItem->second.GetMType() == MsgDef::MsgItemMType_List)
			{
				_ProduceBodyTestFun_MtypeList(
				_GetItemTypeStr(itItem->second.GetType()), itItem->second.GetName(), _GetRandNum(itItem->second.GetType()));
			}

		}
		_ProduceTestFunction(itMsg->second.GetName());
	}
	return true;
} 

bool UTProducer::_ExtractBodyTemplate()
{
	int nFirst = m_strFileTemplate.find(FUN_NAME);
	int nLast  = m_strFileTemplate.find("};");
	if(nFirst == std::string::npos || nLast == std::string::npos){
		return false;
	}
	m_strBodyTemplate.resize(nLast - nFirst);
	std::copy(m_strFileTemplate.begin() + nFirst, m_strFileTemplate.begin() + nLast, m_strBodyTemplate.begin());
	return true;
}

bool UTProducer::_ExtractTopOfBodyTemplate()
{
	int nTop = m_strBodyTemplate.find(SET_ITEM_VAL);
	if(nTop == std::string::npos){
		return false;
	}
	m_strBodyTemp_top.resize(nTop);
	std::copy(m_strBodyTemplate.begin(), m_strBodyTemplate.begin() + nTop, m_strBodyTemp_top.begin());
	return true;
}

bool UTProducer::_ExtractMiddleOfBodyTemplate()
{
	int nMiddle = m_strBodyTemplate.find(DEF_ITEM_VAR);
	if(nMiddle == std::string::npos){
		return false;
	}
	m_strBodyTemp_mid.resize(nMiddle - m_strBodyTemplate.find(SET_ITEM_VAL) - strlen(SET_ITEM_VAL));
	std::copy(m_strBodyTemplate.begin() + m_strBodyTemplate.find(SET_ITEM_VAL) + strlen(SET_ITEM_VAL),
		      m_strBodyTemplate.begin() + nMiddle, m_strBodyTemp_mid.begin());
	return true;
}

bool UTProducer::_ExtractBottomOfBodyTemplate()
{
	m_strBodyTemp_Bot = "\n    }\n\n    ";
	return true;
}


void UTProducer::_SetStrTestFunNeedProduce()
{
	m_strBody_top = m_strBodyTemp_top;
	m_strBody_mid = m_strBodyTemp_mid;
	m_strBody_Bot = m_strBodyTemp_Bot;
}

void UTProducer::_ProduceBodyTestFun_MtypeData(const std::string& strItemType, const std::string& strItemName, long long nRandNum)
{
	char strVarVal[11] = {0};
	if(nRandNum == -2/*==string*/){
		strcpy(strVarVal, "\"´ó°×ÍÃ\"");
	}else{
		sprintf_s(strVarVal, "%d", (rand() % nRandNum));
	}
	
	
	_ProduceStrSetItemVal(strItemName, strVarVal);
	_ProduceStrDefVar(strItemType, strItemName);
	_ProduceStrGetItemVal(strItemName);
	_ProduceStrUTAssItemVarVal(strItemName, strVarVal);
}

void UTProducer::_ProduceBodyTestFun_MtypeList(const std::string& strItemType, const std::string& strItemName, long long nRandNum)
{
	_ProduceStrDefVec(strItemType, strItemName);
	_ProduceStrGetItemVal(strItemName);
	std::string strPushItemVal = _ModifyItemNameOfStrToPushItemVec(strItemName);
	for(int vectorIndex = 0; vectorIndex != 3; ++vectorIndex)
	{
		char strVarVal[11] = {0};
		if(nRandNum == -2/*==string*/){
			strcpy(strVarVal, "\"´ó°×ÍÃ\"");
		}else{
			sprintf_s(strVarVal, "%d", (rand() % nRandNum));
		}
		_ProduceStrPushItemVec(strPushItemVal, strVarVal);
		_ProduceStrUTAssItemVecVal(strItemName, vectorIndex, strVarVal);	
	}
	_ProduceStrSetItemVal(strItemName, strItemName);
}

void UTProducer::_ProduceStrSetItemVal(const std::string& strItemName, const std::string& strVarVal)
{
	std::string strSetItemVal = SET_ITEM_VAL;
	strSetItemVal.replace(strSetItemVal.find("@item_name@"), strlen("@item_name@"), strItemName);
	strSetItemVal.replace(strSetItemVal.find("@item_type_value@"), strlen("@item_type_value@"), strVarVal);
	m_strBody_top += (strSetItemVal + "\n        ");
}

void UTProducer::_ProduceStrDefVar(const std::string& strItemType, const std::string& strItemName)
{
	std::string strDefVar = DEF_ITEM_VAR;
	strDefVar.replace(strDefVar.find("@item_mtype@"), strlen("@item_mtype@"), strItemType);
	strDefVar.replace(strDefVar.find("@item_name@"), strlen("@item_name@"), strItemName);
	m_strBody_mid += (strDefVar + "\n        ");
}

void UTProducer::_ProduceStrGetItemVal(const std::string& strItemName)
{
	std::string strGetItemVal =GET_ITEM_VAL;
	strGetItemVal.replace(strGetItemVal.find("@item_name@"), strlen("@item_name@"), strItemName);
	strGetItemVal.replace(strGetItemVal.find("@item_name@"), strlen("@item_name@"), strItemName);
	m_strAttachGetItemVal += (strGetItemVal + "\n        ");
}

void UTProducer::_ProduceStrUTAssItemVarVal(const std::string& strItemName, const std::string& strVarVal)
{
	std::string strUtAssItemVal = UT_ASSERT_ITEM_VAL;
	strUtAssItemVal.replace(strUtAssItemVal.find("@item_name@"), strlen("@item_name@"), strItemName);
	strUtAssItemVal.replace(strUtAssItemVal.find("@item_type_value@"), strlen("@item_type_value@"), strVarVal);
	m_strAttachUTAss+= (strUtAssItemVal + "\n        ");
}

void UTProducer::_ProduceStrDefVec(const std::string& strItemType, const std::string& strItemName)
{
	std::string strDefItemVec = DEF_ITEM_VEC;
	strDefItemVec.replace(strDefItemVec.find("@item_mtype@"), strlen("@item_mtype@"), strItemType);
	strDefItemVec.replace(strDefItemVec.find("@item_name@"), strlen("@item_name@"), strItemName);
	m_strBody_top += (strDefItemVec + "\n        ");
}

std::string UTProducer::_ModifyItemNameOfStrToPushItemVec(const std::string& strItemName)
{
	std::string strPushItemVal = PUSH_ITEM_VAL;
	strPushItemVal.replace(strPushItemVal.find("@item_name@"), strlen("@item_name@"), strItemName);
	return strPushItemVal;
}

void UTProducer::_ProduceStrPushItemVec(const std::string& strPushItemVal, const std::string& strVarVal)
{
	std::string strEachPushItemVal = strPushItemVal;
	strEachPushItemVal.replace(strEachPushItemVal.find("@item_type_value@"), strlen("@item_type_value@"), strVarVal);
	m_strBody_top += (strEachPushItemVal + "\n        ");
}

void UTProducer::_ProduceStrUTAssItemVecVal(const std::string& strItemName, int nIndex, const std::string& strVarVal)
{
	std::string strUtAssert = UT_ASSERT_ITEM_VAL;
	char strIndex[5] = {0};
	sprintf_s(strIndex, "[%d]", nIndex);
	std::string ItemVecName = strItemName;
	ItemVecName += strIndex;
	strUtAssert.replace(strUtAssert.find("@item_name@"), strlen("@item_name@"),ItemVecName);
	strUtAssert.replace(strUtAssert.find("@item_type_value@"), strlen("@item_type_value@"), strVarVal);
	m_strAttachUTAss += (strUtAssert + "\n        ");
}

void UTProducer::_AttachStrGetItemVal()
{
	m_strBody_mid += m_strAttachGetItemVal;
	m_strAttachGetItemVal.clear();
}
void UTProducer::_AttachStrUTAss()
{
	m_strBody_mid += m_strAttachUTAss;
	m_strAttachUTAss.clear();
}

void UTProducer::_ProduceTestFunction(const std::string& strItemName)
{
	_AttachStrGetItemVal();
	_AttachStrUTAss();	
	m_strProBodyTestFunRlt += (m_strBody_top + m_strBody_mid + m_strBody_Bot);
	_ReplaceAllMsgName(strItemName);
}


void UTProducer::_ReplaceAllMsgName(const std::string& strMsgName)
{
	while(m_strProBodyTestFunRlt.find("@MsgName@") != std::string::npos)
	{
		m_strProBodyTestFunRlt.replace(m_strProBodyTestFunRlt.find("@MsgName@"),
								       strlen("@MsgName@"),
									   strMsgName);
	}
}


bool UTProducer::_ProduceFooter()
{
	int nPosition = m_strFileTemplate.find("};");
	if(nPosition == std::string::npos){
		return false;
	}
	m_strProFooterRlt.resize(m_strFileTemplate.length() - nPosition);
	std::copy(m_strFileTemplate.begin() + nPosition, m_strFileTemplate.end(), m_strProFooterRlt.begin());
	m_strProFooterRlt.insert(0, "\n");
	return true;
}








}// namespace XML
}// namespace UTProduce