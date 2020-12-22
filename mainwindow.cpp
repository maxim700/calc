#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calccontrol.h"

CalcControl calc;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BNum1_clicked()
{
   calc.input("1");
   ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum2_clicked()
{
    calc.input("2");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum3_clicked()
{
    calc.input("3");
    ui->mainstring->setText(calc.get_s());
}


void MainWindow::on_BNum4_clicked()
{
    calc.input("4");
    ui->mainstring->setText(calc.get_s());
}


void MainWindow::on_BNum5_clicked()
{
    calc.input("5");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum6_clicked()
{
    calc.input("6");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum7_clicked()
{
    calc.input("7");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum8_clicked()
{
    calc.input("8");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum9_clicked()
{
    calc.input("9");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum0_clicked()
{
    calc.input("0");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNumPLUS_clicked()
{
    calc.input("+");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNum1MINUS_clicked()
{
    calc.input("-");
    ui->mainstring->setText(calc.get_s());
}


void MainWindow::on_BNummulti_clicked()
{
    calc.input("*");
    ui->mainstring->setText(calc.get_s());
}


void MainWindow::on_BNumdel_clicked()
{
    calc.del();
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNumcalc_clicked()
{
    calc.set_last_s(calc.get_s());
    ui->laststring->setText(calc.get_last_s());
    calc.tologic();
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNumpoint_clicked()
{
    calc.input(".");
    ui->mainstring->setText(calc.get_s());
}


void MainWindow::on_BNumdiv_clicked()
{
    calc.input("/");
    ui->mainstring->setText(calc.get_s());
}
