#pragma once

class tMan;
class QTranslator;

//----------------------------------------------
// Locale (esp language) Manager
// Sees to it eg that correct translation file gets loaded on startup.
// According to language settings on host system. But could be used to dynamically switch languages at runtime too.
//----------------------
class tLocaleMan
{
public:
    tLocaleMan(tMan * Man);
    ~tLocaleMan();

    tMan * man(){ return _Man;}
    QTranslator* translator(){ return _Translator;}
protected:
    tMan * _Man;
    QTranslator* _Translator;
};

//------------------------------
