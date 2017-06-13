#pragma once

class tDataElem;
class QWidget;
class QSpinBox;
class QDoubleSpinBox;

//----------------------------------------------
// "Controller" in "MVC" Pattern
// tDataElem        : Model
// QWidget          : View
// Can be handed polymorphically so clients dont have to care what view exacly is used or how it displays data from model
//--------------------------
class tDataViewElem
{
public:
    explicit tDataViewElem(tDataElem * Data);

    virtual QWidget * widget() = 0;
    virtual tDataElem *  updateData() = 0;

    tDataElem * data(){ return _Data;}
protected:
    tDataElem * _Data;
};

//--------------------------
class tDataViewElemInt : public tDataViewElem
{
public:
    tDataViewElemInt(QSpinBox * SpinBox, tDataElem * Data);
    QSpinBox * spinBox() { return _SpinBox;}

    virtual QWidget * widget();
    virtual tDataElem * updateData();
protected:
    QSpinBox * _SpinBox;

};
//--------------------------
class tDataViewElemDouble: public tDataViewElem
{
public:
    tDataViewElemDouble(QDoubleSpinBox * SpinBox, tDataElem * Data);
    QDoubleSpinBox * spinBox() { return _SpinBox;}

    virtual QWidget * widget();
    virtual tDataElem * updateData();
protected:
    QDoubleSpinBox * _SpinBox;

};
