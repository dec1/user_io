#pragma once

#include <QWidget>
#include "dataelem.h"

class QDoubleSpinBox;
class QSpinBox;
class tMan;
class tDataViewElem;
class tDataElem;
class tDataMan;

#include <QList>
using tDataViewElems = QList<tDataViewElem*>;
using tDataElems = QList<tDataElem*>;

//--------------------------------------------
// Main view containing the imput widgets, which will form most of main tDialog
// Separating it out here, means view could be easily be embedded in a QWidget/QMainWindow etc instead/also of Dialog
//----------------------------------------------
class tViewMain : public QWidget
{
    Q_OBJECT
public:
    explicit tViewMain(tMan * Man, QWidget * Parent = nullptr);

    // how many decimal places of accuracy to use for displaying and interpreting doubles, by default
    //  ... avoid any ambiguity in static initialization order, by returning value from static function (https://isocpp.org/wiki/faq/ctors#static-init-order), rather than defining a static const
    static int defaultDecimalPrecision() { return 3;}

    tDataViewElems * elems() { return &_Elems;}
    void updateData();
    tDataElems dataElems();

    tMan * man(){ return _Man;}
    tDataMan * dataMan();

protected:
    void init();
    tDataElem * newDataElem(NsDataElem::etId id,  QVariant::Type Type);
    QDoubleSpinBox  * newSpinBoxDouble(int decimalPrecision = defaultDecimalPrecision());
    QSpinBox        * newSpinBox();

    tDataViewElems _Elems;
    tMan * _Man;

};
//--------------------------------------------
