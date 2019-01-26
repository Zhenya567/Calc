#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "iviewmodel.h"
class ViewModel:public IViewModel
{
private:
    Q_OBJECT
   // ViewModel();
    struct State {void response(){}};
    struct onNumberSelected:public State{ void response(double num);};
    struct onOperationSelected:public State{void response(QString operation);};
    struct onEqSelected:public State {void response();};
public:
    ViewModel() : state(new onNumberSelected()) {}
    void onNumberSelected1(){return state->response();}//Context
    void onOperationSelected1(){//Context
      delete state;
      state=new onOperationSelected;
    }
   void onEqSelected1(){//Context
    delete state;
    state=new onEqSelected;
   }
 signals:
  void setText1(QString text);
private:
    IViewModelDelegate* delegate;
    State *state;
};
static double first,second;
static QString operations;
#endif // VIEWMODEL_H
