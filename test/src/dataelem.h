#pragma once

#include <QVariant>
#include <QString>

//---------------------------------------------------------------------
// a unique id for each tDataElem ( ~ "value" that user can enter).
// Allows data elements to be resorted etc without losing track of which they originally referred to.
// Better than using the ui visible string, since this is language (locale) dependent and could change anyways (eg to correct spelling mistake)

namespace NsDataElem
{
    enum etId { id1, id2, id3, idNone = -1};
}

//----------------------------------------------------
//----------------------------------------------------
// "Model" in "MVC pattern"
// The data associated with user input
// Value in spin box, its type, and a unique id.
// Using QVariant avoids potential float/integer/double conversions, and allows for further generalization eg to name/string data types
//----------------------------------------------
class tDataElem
{
    using etId = NsDataElem::etId;
    const etId idNone = NsDataElem::idNone;

public:
    tDataElem(etId id,  QVariant::Type Type);
    tDataElem(etId id,  QVariant Value);

    etId id()      const  { return _id; }
    QVariant val() const  { return _Val;}

    void setVal(QVariant Val) { _Val = Val;}

    bool operator== (const tDataElem &Other) const;


protected:
    etId _id = idNone;
    QVariant _Val;
};
//----------------------------------------------

