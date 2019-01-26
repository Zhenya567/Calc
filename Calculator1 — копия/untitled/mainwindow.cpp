#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include  "iviewmodel.h"
#include "viewmodel.h"
#include <QLabel>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));


    // Подключаем сигнал с передачей номера кнопки к слоту вывода сообщения*/
    QObject::connect(this,&ViewModel::setText1,this,&MainWindow::onSetTextLabel);




  //connect(setггText,SIGNAL(clicked()),this,SLOT(onNumberclicked(double number)));
  /* connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_precent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_devide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_devide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onSetTextLabel(QString text){
    ui->label->setText(text);
}

void MainWindow::onNumberclicked(double num){
  viewModel.onNumberSelected1();
  emit setText1(QString::number(num));
  }
void MainWindow::onOperationclicked(QString operation){
    viewModel.onOperationSelected1();
}
void MainWindow::onEqclicked(){
    viewModel.onEqSelected1();
}










