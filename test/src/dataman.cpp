#include "dataman.h"
#include "dataelem.h"

tDataMan::tDataMan(tMan * Man)
    : _Man(Man)
{
    _Elems = new tDataElems();
}
//---------------------------
tDataMan::~tDataMan()
{
    freeElems();
    delete _Elems;
}
//---------------------------
void tDataMan::addElem(tDataElem  *Elem)
{
    elems()->append(Elem);
}
//---------------------------
void tDataMan::freeElems()
{
    foreach(tDataElem * Elem, *_Elems)
        delete Elem;

   elems()->clear();
}
//---------------------------
tDataElems tDataMan::elemsSortedAscending()
{
    // C++11 Lambda notation
    tSortFun sortAscending =  [](const tDataElem * d1, const tDataElem * d2)
    { return d1->val() < d2->val();   };

    return elemsSorted(*elems(), sortAscending);
}

//---------------------------
tDataElems tDataMan::elemsSorted(tDataElems Elems, tSortFun sortFun)
{
    std::sort(Elems.begin(), Elems.end(),sortFun);
    return Elems;
}
