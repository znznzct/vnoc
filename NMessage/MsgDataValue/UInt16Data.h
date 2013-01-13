#ifndef  VNOC_I_MESSAGE_DATA_UINT16
#define  VNOC_I_MESSAGE_DATA_UINT16

#include "MsgDataValue.h"

namespace VNOC
{
namespace Message
{

class UInt16Data:public MsgDataValue
{
public:
    UInt16Data(){}
    virtual ~UInt16Data(){}

    virtual MsgStatus ToUInt16(
        OUT uint16& Value
        )
    {
        Value = m_Value;
        return MsgStatus_Ok;
    }
private:
    uint16      m_Value;
};

}// namespace Message
}// namespace VNOC

#endif