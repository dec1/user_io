#include "dataviewelem.h"
#include "dataelem.h"

#include <QSpinBox>
#include <QDoubleSpinBox>

tDataViewElem::tDataViewElem( tDataElem * Data)
    : _Data(Data)
{}
//----------------------------------------
//----------------------------------------
tDataViewElemInt::tDataViewElemInt(QSpinBox * SpinBox, tDataElem * Data)
    : tDataViewElem(Data), _SpinBox(SpinBox)
{}
//----------------------------------------
QWidget * tDataViewElemInt::widget(){ return spinBox();}
//----------------------------------------
tDataElem * tDataViewElemInt::updateData()
{
    if(data() && spinBox())
        data()->setVal(spinBox()->value());

    return data();
}
//---------------------------------------
//----------------------------------------
tDataViewElemDouble::tDataViewElemDouble(QDoubleSpinBox * SpinBox, tDataElem * Data)
    : tDataViewElem(Data), _SpinBox(SpinBox)
{}
//----------------------------------------
QWidget * tDataViewElemDouble::widget(){ return spinBox();}
//----------------------------------------
tDataElem * tDataViewElemDouble::updateData()
{
    if(data() && spinBox())
        data()->setVal(spinBox()->value());

    return data();
}
