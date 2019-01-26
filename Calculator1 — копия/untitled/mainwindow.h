#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewmodel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,public ViewModel
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QObject*  getsender() { return sender();}
private:
    Ui::MainWindow *ui;
    ViewModel viewModel;
    //QObject* obj = sender();
private slots:
    void onNumberclicked(double num);
    void onOperationclicked(QString operation);
    void onEqclicked();

    void onSetTextLabel(QString text);
};

#endif // MAINWINDOW_H
