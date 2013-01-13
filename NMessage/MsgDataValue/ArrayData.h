#ifndef  VNOC_I_MESSAGE_DATA_ARRAY
#define  VNOC_I_MESSAGE_DATA_ARRAY

#include "../MessageDef.h"

namespace VNOC
{
namespace Message
{

class ArrayData
{
public:
    ArrayData(){}
    virtual ~ArrayData(){}

    size_t Size(){ return m_arrValuePtr.size();}

    bool Empty(){ return m_arrValuePtr.empty();}

    std::vector<MsgDataValue*>::const_iterator Begin() const { return m_arrValuePtr.begin();}

    std::vector<MsgDataValue*>::const_iterator End() const { return m_arrValuePtr.end();}

    void Push( 
        IN MsgDataValue Value
        ) 
    {
        return m_arrValuePtr.push_back(&Value);
    }
private:
    std::vector<MsgDataValue*>                  m_arrValuePtr;
};

}// namespace Message
}// namespace VNOC

#endif