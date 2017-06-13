#pragma once

class tMan;
//-------------------------
#include <QList>
class tDataElem;
using tDataElems = QList<tDataElem*>;
//---------------------------
#include <functional>
//----------------------------------------------
// Sorting function.
// returns ​true if the first argument is less than (i.e. is ordered before) the second.
using tSortFun = std::function<bool (const tDataElem * Elem1, const tDataElem * Elems2) >;
//----------------------------------------------
// Owner of data.
// Decouples eg lifetime/storage of data from nay view that shows/edits it
//-----------------------------------------
class tDataMan
{
public:
    explicit tDataMan(tMan * Man);
    ~tDataMan();
    tMan * man(){ return _Man;}

    //"Strategy Pattern". Caller can specify (alternate) sorting function
    static tDataElems elemsSorted(tDataElems Elems, tSortFun sortFun);
    tDataElems elemsSortedAscending();

    tDataElems * elems(){ return _Elems;}
    void freeElems();
    void addElem(tDataElem  *Elem);
protected:
    tMan * _Man;
    tDataElems * _Elems;
};


