#include "UTProducer.h"
#include <iostream>

using namespace UTProduce::File;

void main()
{  
	UTProduce::XML::UTProducer utProducer;
	std::string strTempFileName;
	std::string strMsgDefFileName;

	std::cout<< "请输入UT模版文件的名称(输入0代表默认文件): "<< std::endl;
	std::cin>>strTempFileName;
	if(strTempFileName == "0"){
		strTempFileName = "UTTemplate.msg";
	}

	std::cout<< "请输入消息定义文件的名称(输入0代表默认文件): "<< std::endl;
	std::cin>>strMsgDefFileName;
	if(strMsgDefFileName == "0"){
		strMsgDefFileName = "msgdef.xml";
	}
	
	if(utProducer.ProduceUTFile(strTempFileName, strMsgDefFileName)){
		std::cout<< "生成成功"<< std::endl;
	}else{
		std::cout<< "生成失败"<< std::endl;
	} 
	system("pause");
}															