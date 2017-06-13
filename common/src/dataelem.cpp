#include "dataelem.h"

using etId = NsDataElem::etId;

//------------------------------------------------------------------
tDataElem::tDataElem(etId id,  QVariant::Type Type)
     : _id(id),  _Val(Type)
{

}
//------------------------------------------------------------------
tDataElem::tDataElem(etId id,  QVariant Value)
     : _id(id),  _Val(Value)
{

}
//------------------------------------------------------------------
bool tDataElem::operator== (const tDataElem &Other) const
{
    return (Other.id()  == id() ) &&
           (Other.val() == val());
}


