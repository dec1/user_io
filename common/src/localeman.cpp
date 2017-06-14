#include "localeman.h"

#include <QCoreApplication>
#include <QTranslator>
#include <QLocale>
#include <QtDebug>

#include <QFile>
//------------------------------
tLocaleMan::tLocaleMan(tMan * Man)
    : _Man(Man)
{

    _Translator  = new QTranslator();

    Q_INIT_RESOURCE(res);

    QLocale Loc;
    if(Loc.language() == QLocale::German)
    {
        bool load = _Translator->load(QLocale(), ":/translation.de.qm");
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
