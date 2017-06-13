#include "datamarshal.h"
#include "dataelem.h"


#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDir>
#include <QtDebug>



// Note: QList/QByteArray are implicitly shared (copy on write semantics) -> no performance penalty for passing by val
// http://doc.qt.io/qt-5/implicit-sharing.html
// (otherwise could/should pass as "const &")
//----------------------------------------------------------------
QByteArray tDataMarshalJson::asByteArray(tDataElems Elems)
{

    QJsonObject Main;

    // Write a preamble with (format) version, as well as the data itself in body
    // If the format changes in a later version, update this number.
    // Can then easily detect files written in older format and use fallback if required.

    QJsonObject Head;
    Head["version"] = "1.0.0";
    Main["head"] = Head;

    QJsonObject Body;


    QJsonArray Jarr;
    foreach(tDataElem *Data, Elems)
    {
        if(!Data)
            continue;

        QJsonObject Jobj;
        Jobj["id"]      = Data->id();
        Jobj["value"]   = Data->val().toString();
        Jobj["type"]    = Data->val().typeName();
        Jarr.append(Jobj);

    }


    Body["data"]= Jarr;
    Main["body"]= Body;

    QJsonDocument Jdoc(Main);
    QByteArray Ba = Jdoc.toJson();


    return Ba;
}
//------------------------------------------
tDataElems tDataMarshalJson::fromByteArray(QByteArray Ba)
{
// Note: In production code would program more defensively here
// Stricter checks on data being read eg verifying int is valid enum,
// parsing format version etc

    tDataElems Elems;

    QJsonDocument Doc =  QJsonDocument::fromJson(Ba);
    if(Doc.isNull())
        return Elems;

    QJsonObject Job = Doc.object();
    QJsonObject Head = Job["head"].toObject();
    QJsonObject Body = Job["body"].toObject();
    QJsonArray Jarr = Body["data"].toArray();
    for (int i = 0; i < Jarr.size(); ++i)
    {
        QJsonObject Job = Jarr[i].toObject();

       int id_int  = Job["id"].toInt() ;
       QString Type = Job["type"].toString();
       QVariant Val = Job["value"].toVariant();  // Workaround: toVariant() not avaialable in Qt 5.4 - support ealier versions of Qt by manually creating QVariant here instead


       NsDataElem::etId id = static_cast<NsDataElem::etId>(id_int);

       //qDebug()<<" Read ... id: " << id << ", Val = " << Val << ", type= " << Type;

       tDataElem * Elem = new tDataElem(static_cast<NsDataElem::etId>(id), Val );
       Elems<<Elem;
    }


    return Elems;
}
