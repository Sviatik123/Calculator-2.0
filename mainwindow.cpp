#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <calculator.h>
#include<string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString exp = ui->lineEdit->text();
    std::string expression = exp.toUtf8().constData();
    Calculator calcul(expression);
    calcul.calculate();
    QString res = QString::number(calcul.getResult());
    QMessageBox::information(this,"Result", res);
}
