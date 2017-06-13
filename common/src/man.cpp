#include "man.h"
#include "dialog.h"
#include "dataman.h"
#include "logman.h"
#include "localeman.h"

//----------------------------------
tMan::tMan()
{
    _LocaleMan = new tLocaleMan(this);
    _DataMan = new tDataMan(this);
    _LogMan = new tLogMan(this);
    _Dialog = new tDialog(this);

    showUi();
}
//--------------------------------
tMan::~tMan()
{
    delete _Dialog;
    delete _LogMan;
    delete _DataMan;
    delete _LocaleMan;
}
//--------------------------------
void tMan::showUi()
{

    dialog()->exec();

}




