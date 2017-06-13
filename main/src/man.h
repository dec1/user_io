#pragma once

class tDataMan;
class tViewMain;
class tDialog;
class tDataIo;
class tDataViewElem;
class tDataElem;
class tLogMan;
class tLocaleMan;

//---------------------------------------
#include <QList>
using tDataViewElems = QList<tDataViewElem*>;
using tDataElems = QList<tDataElem*>;
//---------------------------------------

// Application-wide "Manager" object
// Combined Mediator & Inversion of Control Patterns
// This is the top level (Singleton) object in the app
// Other (singleton/manager) objects (dataMan etc) communicate via this obj
//----------------------------------------------
class tMan
{
public:
    tMan();
    ~tMan();

    tDataMan *   dataMan()  { return _DataMan;}
    tLogMan  *   logMan()   { return _LogMan;}
    tDialog  *   dialog()   { return _Dialog;}
    tLocaleMan * localeMan(){ return _LocaleMan;}

    void showUi();
protected:
    tDataMan    * _DataMan;
    tLogMan     * _LogMan;
    tLocaleMan  * _LocaleMan;
    tDialog     * _Dialog;


};
//----------------------------------------------
