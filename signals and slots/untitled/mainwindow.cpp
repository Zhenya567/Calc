#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Объявляем и инициализируем кнопки
     * */
    QPushButton *but_1 = new QPushButton(this);
    QPushButton *but_2 = new QPushButton(this);
    QPushButton *but_3 = new QPushButton(this);

    /* Устанавливаем номера кнопок
     * */
    but_1->setText("1");
    but_2->setText("2");
    but_3->setText("3");

    /* Добавляем кнопки на слой с вертикальной ориентацией
     * */
    ui->verticalLayout->addWidget(but_1);
    ui->verticalLayout->addWidget(but_2);
    ui->verticalLayout->addWidget(but_3);

    /* Подключаем к кнопкам индивидуальные слоты
     * */
    connect(but_1, SIGNAL(clicked()), this, SLOT(slotButton1()));
    connect(but_2, SIGNAL(clicked()), this, SLOT(slotButton2()));
    connect(but_3, SIGNAL(clicked()), this, SLOT(slotButton3()));

    /* Подключаем сигнал с передачей номера кнопки к слоту вывода сообщения
     * */
    connect(this, &MainWindow::signalFromButton, this, &MainWindow::slotMessage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Слоты для обработки нажатия кнопок
 * */
void MainWindow::slotButton1()
{
    emit signalFromButton(1);
}

void MainWindow::slotButton2()
{
    emit signalFromButton(2);
}

void MainWindow::slotButton3()
{
    emit signalFromButton(3);
}

/* Слоты вывода сообщения
 * */
void MainWindow::slotMessage(int buttonID)
{
   QMessageBox::information(this,
                             "Уведомление о нажатой кнопке",
                             "Нажата кнопка под номером " + QString::number(buttonID));
}
