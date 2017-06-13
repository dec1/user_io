#include "viewmain.h"
#include "dataelem.h"
#include "dataviewelem.h"
#include "dataio.h"
#include "dataman.h"
#include "man.h"

#include <QLabel>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QFormLayout>
#include <QToolTip>

//------------------------------------------------
tDataMan * tViewMain::dataMan(){ return man()? man()->dataMan(): nullptr;}
//------------------------------------------------
//------------------------------------------------
tViewMain::tViewMain(tMan * Man, QWidget *Parent)
    : QWidget(Parent), _Man(Man)
{

    init();
}
//------------------------------------------------
QDoubleSpinBox * tViewMain::newSpinBoxDouble(int decimalPrecision)
{
    QDoubleSpinBox * Ret = new QDoubleSpinBox(this);
    Ret->setDecimals(decimalPrecision);

    // Perhaps it doesnt make sense to allow such extreme values?
    // Maybe use case would dictate it best to pass values as parm on individual basis (like decimalPrecision)
    // Adapt as necessary...
    double max = std::numeric_limits<double>::max();
    double min = std::numeric_limits<double>::lowest();

    Ret->setMaximum(max);
    Ret->setMinimum(min);

    return Ret;
}
//------------------------------------------------
QSpinBox * tViewMain::newSpinBox()
{
    QSpinBox * Ret = new QSpinBox(this);

    // Perhaps it doesnt make sense to allow such extreme values?
    // Maybe use case would dictate it best to pass values as parm on individual basis (like decimalPrecision)
    // Adapt as necessary...
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::lowest();

    Ret->setMaximum(max);
    Ret->setMinimum(min);

    return Ret;
}
//------------------------------------------------
tDataElem * tViewMain::newDataElem(NsDataElem::etId id,  QVariant::Type Type)
{
    tDataElem *Elem = new tDataElem(id, Type);

    // DataMan takes ownership pf Elems (and deletes when appropriate)
    // allows data to outlive view
    if(dataMan())
        dataMan()->addElem(Elem);

    return Elem;
}
//------------------------------------------------
void tViewMain::updateData()
{
    foreach(tDataViewElem * Dv, *elems())
    {
        if(Dv)
            Dv->updateData();
    }
}
//------------------------------------------------
tDataElems tViewMain::dataElems()
{
    tDataElems Ret;
    foreach(tDataViewElem * Dv, *elems())
    {
        if(Dv)
        {
            tDataElem * Data = Dv->data();
            if(Data)
                Ret<<Data;
        }
    }

    return Ret;
}
//---------------------------------------------------------
void tViewMain::init()
{
    QFormLayout * LayMain = new QFormLayout(this);

    using NsDataElem::id1;
    using NsDataElem::id2;
    using NsDataElem::id3;

    QDoubleSpinBox * Spin1  = newSpinBoxDouble();
    QDoubleSpinBox * Spin2  = newSpinBoxDouble();
    QSpinBox * Spin3        = newSpinBox();


    tDataElem * Data1 = newDataElem(id1, QVariant::Type::Double);
    tDataElem * Data2 = newDataElem(id2, QVariant::Type::Double);
    tDataElem * Data3 = newDataElem(id3, QVariant::Type::Int);

    _Elems.append(new tDataViewElemDouble(Spin1, Data1));
    _Elems.append(new tDataViewElemDouble(Spin2, Data2));
    _Elems.append(new tDataViewElemInt   (Spin3, Data3));

    //------------------------

    LayMain->addRow(QObject::tr("Value 1"), Spin1);
    LayMain->addRow(QObject::tr("Value 2"), Spin2);
    LayMain->addRow(QObject::tr("Value 3"), Spin3);

    // Let uppermost SpinBox have initial focus on startup
    Spin1->setFocus();
}
