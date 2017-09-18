#include "test.h"
#include "test_mock.h"

#include "dataelem.h"
#include "man.h"
#include "dataman.h"
#include "dataio.h"
#include "datamarshal.h"


#include <QObject>
#include <QtTest/QtTest>

#include "mock/fakeit.hpp"
using namespace fakeit;
//-----------------------------
QTEST_MAIN(tTest)
//-----------------------------


//-----------------------------
void tTest::initTestCase()
{
    _DataMan = new tDataMan(nullptr);

    if(!_DataMan)
        QFAIL("Couldn't create DataMan");


    _Data0 = new tDataElem(NsDataElem::id1, 2.5);
    _Data1 = new tDataElem(NsDataElem::id2, 1.5);
    _Data2 = new tDataElem(NsDataElem::id3, 2);


    _DataMan->addElem(_Data0);
    _DataMan->addElem(_Data1);
    _DataMan->addElem(_Data2);

    tDataElems * Elems = _DataMan->elems();

    QVERIFY2(Elems && Elems->count() ==3, "Tests data not added properly");
}
//-----------------------------
void tTest::cleanupTestCase()
{
    delete _DataMan;
}
//-----------------------------
void tTest::sortData()
{

    tDataElems ElemsSorted = _DataMan->elemsSortedAscending();

    QVERIFY2(ElemsSorted.count() ==3, "tTest::sortData() - data count changed unexpectedly after sorting");

    QVERIFY2( (ElemsSorted.at(0) == _Data1) &&
              (ElemsSorted.at(1) == _Data2) &&
              (ElemsSorted.at(2) == _Data0)
              , "tTest::sortData() - data not sorted in ascending order");
}
//----------------------------------
struct SomeInterface {
   virtual int foo(int) { return 5;}
   virtual int bar(int,int) = 0;
};

//-----------------------------
void tTest::testMock()
{
    Mock<SomeInterface> mock;
    When(Method(mock,foo)).AlwaysReturn(2);

    int tst1 = mock().foo(1);
    int tst2 = mock().foo(2);
    int tst3 = mock().foo(3);
    QVERIFY2(mock().foo(3) == 2, "foo ddint return right answer");
}
//-----------------------------
void tTest::readWriteData()
{


    tDataMarshalJson Mar;
    tDataIoFile Io;
    tDataElems * Elems = _DataMan->elems();

    QVERIFY2(Io.writeData(*Elems, &Mar), "couldnt write data properly");

    tDataElems ElemsRead =  Io.readData(&Mar);
    QVERIFY2(ElemsRead.count() == Elems->count(), "tTest::sortData() - data count changed unexpectedly after reading");


    QVERIFY2( (*(ElemsRead.at(0)) == *_Data0) &&
              (*(ElemsRead.at(1)) == *_Data1) &&
              (*(ElemsRead.at(2)) == *_Data2)
              , "tTest::sortData() - data not read as expectedr");

}








