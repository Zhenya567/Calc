#ifndef IVIEWMODEL_H
#define IVIEWMODEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>
//#include "iviewmodeldelegate.h"
class IViewModelDelegate;
class IViewModel
{
     struct State{virtual void response() = 0;};
     struct onNumberSelected:public State{ void response(double number);};
     struct onOperationSelected:public State{void response(QString operation);};
     struct onEqSelected:public State {void response();};
public:

 //IViewModel() : state(new onNumberSelected()) {}
    virtual ~IViewModel(){}
/*---------------------------*/
 void onNumberSelected1(){}//Context
 void onOperationSelected1(){}//Context}
void onEqSelected1(){}//Context}

//virtual void setDelegate(IViewModelDelegate* delegate) = 0;
/*-------------------------------------*/



};

#endif // IVIEWMODEL_H
