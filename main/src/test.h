 #pragma once

#include <QObject>

class tDataMan;
class tDataElem;

//--------------------------------
class tTest: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();


    void sortData();
    void readWriteData();
protected:
    tDataMan * _DataMan;
    tDataElem * _Data0;
    tDataElem * _Data1;
    tDataElem * _Data2;
};
//----------------------------------






