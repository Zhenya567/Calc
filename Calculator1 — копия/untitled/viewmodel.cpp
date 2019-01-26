#include "viewmodel.h"
#include "mainwindow.h"

/*ViewModel::ViewModel()
{

}*/
void ViewModel::onNumberSelected::response(double num){
    MainWindow numbers;//чтобы получить доступ к sender
    QPushButton *button=(QPushButton *) numbers.getsender();//для проверки на какое число ввел пользователь
        if(button->text()=="+" || button->text()=="-" || button->text()=="/" || button->text()=="*"){
            second=num;
            //second=(button->text().toDouble());
        }
        else if(!(button->text()=="+" || button->text()=="-" || button->text()=="/" || button->text()=="*")){
            first=num;
            //first=(button->text().toDouble());
        }
}
void ViewModel::onOperationSelected::response(QString operation){
    MainWindow operatorion1;//чтобы получить доступ к sender
    QPushButton *button=(QPushButton *) operatorion1.getsender();//для проверки на какое число ввел пользователь
        if(button->text()=="+"){
            operations=operation;
            //operations=(button->text());
        }
        else if(button->text()=="-"){
            operations=operation;
            //operations=(button->text());
        }
        else if(button->text()=="/"){
            operations=operation;
            //operations=(button->text());
        }
        else if(button->text()=="*"){
            operations=operation;
            //operations=(button->text());
        }
}
void ViewModel::onEqSelected::response(){
    MainWindow Eq;//чтобы получить доступ к sender
    QPushButton *button=(QPushButton *) Eq.getsender();//для проверки на какое число ввел пользователь
        if(button->text()=="="){
            if(operations=="+"){first=first+second;}
            if(operations=="-"){first=first-second;}
            if(operations=="/"){first=first/second;}
            if(operations=="*"){ first=first+second;}
}
}
/*void ViewModel::setDelegate(IViewModelDelegate* delegate){
    this->delegate=delegate;
}*/
