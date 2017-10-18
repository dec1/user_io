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






#include "mock/fakeit.hpp"
using namespace fakeit;
//----------------------------------
struct SomeInterface {
   virtual int foo() { return 0;} // "usually" succeds (sub classes may not!)
   virtual int bar(int,int) = 0;
};
//----------------------------------
class MyClass
{
public:
    MyClass(SomeInterface * Ed) : _ExternalDep(Ed) {}
    bool doSomething() { return _ExternalDep && _ExternalDep->foo() == 0;}
private:
    SomeInterface * _ExternalDep;
};
//-----------------------------
void tTest::testMock()
{
    Mock<SomeInterface> mock;
    When(Method(mock,foo)).AlwaysReturn(-1);  // mock extenal dep to "fail" deterministically!

    QVERIFY2(mock().foo() == -1, "foo didnt return right answer");  // verify that foo "fails"

    // MyClass has a dependency on SomeInterface (eg it calls foo())
    SomeInterface & Si = mock.get();
    MyClass* MyObj = new MyClass(&Si);
    bool ok = MyObj->doSomething(); // calls SomeInterface::foo() which we have made deterministic for this test
    QVERIFY2(ok, "MyClass didnt return expected answer");
}

//// Verify foo was invoked at least once. (The four lines do exactly the same)
//Verify(Method(mock,foo));
//Verify(Method(mock,foo)).AtLeastOnce();

//Mock<SomeInterface> mock;
//// Stub a method to return a value once
//When(Method(mock,foo)).Return(1);

//// Stub multiple return values (The next two lines do exactly the same)
//When(Method(mock,foo)).Return(1,2,3);
//When(Method(mock,foo)).Return(1).Return(2).Return(3);

//// Return the same value many times (56 in this example)
//When(Method(mock,foo)).Return(56_Times(1));

//// Return many values many times (First 100 calls will return 1, next 200 calls will return 2)
//When(Method(mock,foo)).Return(100_Times(1), 200_Times(2));

//// Always return a value (The next two lines do exactly the same)
//When(Method(mock,foo)).AlwaysReturn(1);
//Method(mock,foo) = 1;
//// Stub foo(1) to return the value '100' once (The next two lines do the same)
//When(Method(mock,foo).Using(1)).Return(100);
//When(Method(mock,foo)(1)).Return(100);
























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








