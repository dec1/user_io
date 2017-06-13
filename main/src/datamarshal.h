

#pragma once

#include <QList>

class QByteArray;
class tDataElem;
using tDataElems = QList<tDataElem*>;


// Serialization/marschalling eg to/from json, xml etc
// Sub classes define the concrete implementation eg data<->json, data<->xml etc
// Used by tDataIo via Bridge Pattern
//-----------------------------------------------
class tDataMarshal
{
public:

    virtual QByteArray asByteArray(tDataElems Elems) = 0;
    virtual tDataElems fromByteArray(QByteArray Ba) = 0;
};


//-----------------------------------------------
class tDataMarshalJson : public tDataMarshal
{
public:
    virtual QByteArray asByteArray(tDataElems Elems);
    virtual tDataElems fromByteArray(QByteArray Ba);
};
