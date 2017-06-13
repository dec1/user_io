#include "localeman.h"

#include <QCoreApplication>
#include <QTranslator>
#include <QLocale>
#include <QtDebug>

//------------------------------
tLocaleMan::tLocaleMan(tMan * Man)
    : _Man(Man)
{

    _Translator  = new QTranslator();

    QLocale Loc;
    if(Loc.language() == QLocale::German)
    {
        bool load = _Translator->load(QLocale(), ":/translation", ".");
        if(load)
        {
           QCoreApplication::installTranslator(_Translator);
        }
    }
}
//-----------------------------
tLocaleMan::~tLocaleMan()
{
    delete _Translator;
}
