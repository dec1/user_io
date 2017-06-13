// #pragma once

#include <QDialog>

//----------------------------------------------
class tMan;
class tDataMan;
class tViewMain;
class QWidget;
//----------------------------------------------
// The main dialog
//----------------------------------------------
class tDialog : public QDialog
{
    Q_OBJECT
public:
   // explicit
    tDialog(tMan * Man, QWidget * Parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    tDialog();

    tMan * man(){ return _Man;}
    tViewMain * viewMain(){ return _ViewMain;}
    tDataMan  * dataMan();

public slots:
    void slotSave();
    void slotHelp();

protected:

    void updateViewData();
    bool writeViewData();
    bool readData();

    tMan * _Man;
    tViewMain * _ViewMain;
};
//----------------------------------------------

