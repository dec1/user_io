#pragma once

#include <QList>
#include <QDir>

class QString;
class tDataMarshal;
class tDataElem;
using tDataElems = QList<tDataElem*>;

//----------------------------------------------
// Base class for persisting Data
// Subclasses define the concrete implementation
// tDataIoFile reads/writes files
// other subclasses could read/write via http to webserver, sql to database etc

// tDataMarshal - "Bridge pattern"
// implentation of Serialization is orthogonal to implementation of Persistence
// Any combination of each is possible (sent Json to webserver, save xml to file etc) - avoids exponential oproliferation of subclasses

//-----------------------------------------------
class tDataIo
{
public:

    virtual bool writeData(tDataElems Elems, tDataMarshal * Dm)=0;
    virtual tDataElems readData(tDataMarshal * Dm)=0;
};


//-----------------------------------------------
class tDataIoFile
{
public:

    static QString defaultFilePath(){ return QDir::homePath() + "/werte.txt";}

    explicit tDataIoFile(QString FilePath = defaultFilePath());

    virtual bool writeData(tDataElems Elems, tDataMarshal * Dm);
    virtual tDataElems readData(tDataMarshal * Dm);

    QString filePath(){ return _FilePath;}
protected:
    QString _FilePath;
};
