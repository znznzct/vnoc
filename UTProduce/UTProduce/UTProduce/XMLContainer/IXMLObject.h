#ifndef UTPRODUCE_IXMLOBJECT
#define UTPRODUCE_IXMLOBJECT

#include "../MsgDef.h"
#include <map>
#include <string>
#include <utility>
#include <cstdlib>

namespace UTProduce
{
namespace XML
{

class IXMLObject
{
public:
	IXMLObject(){}
	virtual ~IXMLObject(){}

public:
	//virtual void Init()	= 0;
	//virtual void UnInit() = 0;
};

}// namespace XML
}// namespace UTProduce


#endif // UTPRODUCE_XMLOBJECT