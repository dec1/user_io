#pragma once

class tMan;
class QString;

//----------------------------------------------
// Manager for messages that user should be shown to user, and/or writes log file
// Clients dont have to care about details (which log file?, where in the ui? - just messagebox, or append to text edit etc)?
//----------------------------------------
class tLogMan
{
public:
    explicit tLogMan(tMan * Man);
    tMan * man(){ return _Man;}

    // show mesg in ui only
    static void mesgUi(QString Title, QString Mesg);
    // show mesg in console only
    static void mesgConsole(QString Title, QString Mesg);
    static void mesgConsole(QString Mesg);
    // show mesg everywhere
    static void mesg(QString Title, QString Mesg);

protected:
    tMan * _Man;
};
//----------------------------------------------

