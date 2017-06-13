#include "logman.h"
#include "man.h"

#include <QMessageBox>
#include <QtDebug>

//-----------------------------------------
tLogMan::tLogMan(tMan * Man)
    :_Man(Man)
{

}
//-----------------------------------------
void tLogMan::mesg(QString Title, QString Mesg)
{
    mesgConsole(Title, Mesg);
    mesgUi(Title, Mesg);
}
//-----------------------------------------
void tLogMan::mesgUi(QString Title, QString Mesg)
{
    QMessageBox::information(nullptr, Title, Mesg, QMessageBox::Ok);
}
//-----------------------------------------
void tLogMan::mesgConsole(QString Title, QString Mesg)
{
    qDebug()<<" --- " << Title << " ... " <<Mesg;
    // could also write to a log file
}
//-----------------------------------------
void tLogMan::mesgConsole(QString Mesg)
{
    mesgConsole(QString(), Mesg);
}
//-----------------------------------------
