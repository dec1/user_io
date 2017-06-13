#include "dialog.h"
#include "man.h"
#include "viewmain.h"
#include "dataio.h"
#include "dataviewelem.h"
#include "viewmain.h"
#include "datamarshal.h"
#include "dataman.h"
#include "logman.h"

#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QToolTip>

//----------------------------------------------------------------------
tDataMan  * tDialog::dataMan(){ return man()? man()->dataMan() : nullptr;}
//-----------------------------------------------------------------------
tDialog::tDialog(tMan * Man, QWidget * Parent, Qt::WindowFlags f)
    : QDialog(Parent, f), _Man(Man)
{
    QVBoxLayout * MainLay = new QVBoxLayout(this);

    _ViewMain = new tViewMain(Man, this);

    QDialogButtonBox * ButtBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel  | QDialogButtonBox::Help);

    connect(ButtBox, &QDialogButtonBox::accepted, this, &tDialog::slotSave);
    connect(ButtBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    connect(ButtBox, &QDialogButtonBox::helpRequested, this, &tDialog::slotHelp);

    MainLay->addWidget(_ViewMain);
    MainLay->addWidget(ButtBox);

    ButtBox->button(QDialogButtonBox::Ok)->setText(tr("Save"));
         ButtBox->button(QDialogButtonBox::Ok)->setToolTip(tr("Save to file"));
    ButtBox->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));
        ButtBox->button(QDialogButtonBox::Cancel)->setToolTip(tr("Quit without saving"));
    ButtBox->button(QDialogButtonBox::Help)->setText(tr("Help"));
        ButtBox->button(QDialogButtonBox::Help)->setToolTip(tr("Show some help"));

    // Dont allow user to resize dialog
    layout()->setSizeConstraint( QLayout::SetFixedSize );

    setWindowTitle(tr("Enter Data"));
}
//---------------------------------------------------
void tDialog::slotSave()
{
    updateViewData();
    writeViewData();

    accept();
}
//---------------------------------------------------
void tDialog::slotHelp()
{
    tLogMan::mesgUi("Help", "Enter some values and click the appropriate button if you want to save them to a file.");
}
//--------------------------------
void tDialog::updateViewData()
{
    viewMain()->updateData();
}
//--------------------------------
bool tDialog::writeViewData()
{
    if(!viewMain())
        return false;

    tDataMarshalJson Mar;
    tDataIoFile Io;
    return Io.writeData(dataMan()->elemsSortedAscending(), &Mar);
}
//--------------------------------
bool tDialog::readData()
{
    tDataMarshalJson Mar;
    tDataIoFile Io;
    tDataElems Elems =  Io.readData(&Mar);
    return !Elems.isEmpty();
}
