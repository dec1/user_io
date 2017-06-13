#include "dataio.h"
#include "dataelem.h"
#include "datamarshal.h"
#include "logman.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDir>
//-----------------------------------------------------
tDataIoFile::tDataIoFile(QString FilePath)
    :  _FilePath(FilePath)
{}
//-----------------------------------------------------
bool tDataIoFile::writeData(tDataElems Elems, tDataMarshal * Dm)
{
    if(!Dm)
        return false;


    QFile File(filePath());

    if (!File.open(QIODevice::WriteOnly))
    {
        tLogMan::mesgUi("Error Saving", "Couldn't open file for wrinting: " + filePath());
        return false;
    }

    QByteArray Ba = Dm->asByteArray(Elems);
    qint64 ret = File.write(Ba);

    //File.close();

    return ret > 0;
}
//------------------------------------------------------
tDataElems tDataIoFile::readData(tDataMarshal * Dm)
{

    tDataElems Elems;

    if(!Dm)
        return Elems;

    QFile File(filePath());

    if (!File.open(QIODevice::ReadOnly))
    {
        tLogMan::mesgUi("Error reading", "Couldn't open file for reading: " + filePath());
        return Elems;
    }

    QByteArray Ba = File.readAll();
    Elems  = Dm->fromByteArray(Ba);

    return Elems;
}
