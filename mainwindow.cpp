#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calccontrol.h"
#include <QKeyEvent>

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
    //calc.del();
    //ui->mainstring->setText(calc.get_s());
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

void MainWindow::on_BSin_clicked()
{
    calc.input("sin(");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BCos_clicked()
{
    calc.input("cos(");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_Btg_clicked()
{
    calc.input("tg(");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_Bpower_clicked()
{
    calc.input("^(");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BExp_clicked()
{
    calc.input("exp(");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BLn_clicked()
{
    calc.input("ln(");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BLeftparenthesis_clicked()
{
    calc.input("(");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BRightparenthesis_clicked()
{
    calc.input(")");
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::on_BNumdel_pressed()
{
    calc.del();
    ui->mainstring->setText(calc.get_s());
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{



    if (ev->key() == Qt::Key_Backspace)
        on_BNumdel_pressed();
    if (ev->key() == Qt::Key_0)
        on_BNum0_clicked();
    if (ev->key() == Qt::Key_1)
        on_BNum1_clicked();
    if (ev->key() == Qt::Key_2)
        on_BNum2_clicked();
    if (ev->key() == Qt::Key_3)
        on_BNum3_clicked();
    if (ev->key() == Qt::Key_4)
        on_BNum4_clicked();
    if (ev->key() == Qt::Key_5)
        on_BNum5_clicked();
    if (ev->key() == Qt::Key_6)
        on_BNum6_clicked();
    if (ev->key() == Qt::Key_7)
        on_BNum7_clicked();
    if (ev->key() == Qt::Key_8)
        on_BNum8_clicked();
    if (ev->key() == Qt::Key_9)
        on_BNum9_clicked();
    if (ev->key() == Qt::Key_Plus)
        on_BNumPLUS_clicked();
    if (ev->key() == Qt::Key_Minus)
        on_BNum1MINUS_clicked();
    if (ev->key() == Qt::Key_Asterisk)
        on_BNummulti_clicked();
    if (ev->key() == Qt::Key_Slash)
        on_BNumdiv_clicked();
    if (ev->key() == Qt::Key_Enter)
        on_BNumcalc_clicked();
    if (ev->key() == Qt::Key_Comma)
        on_BNumpoint_clicked();
    if (ev->text() == ".")
        on_BNumpoint_clicked();
    if (ev->key() == Qt::Key_S)
        on_BSin_clicked();
    if (ev->key() == Qt::Key_C)
        on_BCos_clicked();
    if (ev->key() == Qt::Key_T)
        on_Btg_clicked();
    if (ev->key() == Qt::Key_L)
        on_BLn_clicked();
    if (ev->key() == Qt::Key_ParenLeft)
        on_BLeftparenthesis_clicked();
    if (ev->key() == Qt::Key_ParenRight)
        on_BRightparenthesis_clicked();
    if (ev->text() == "^")
        on_Bpower_clicked();
    if (ev->key() == Qt::Key_E)
        on_BExp_clicked();



    // Выход из программы на Ctrl + Q
    //if (ev->modifiers() & Qt::ControlModifier){
    //    if (ev->key() == Qt::Key_Q){
    //        this->close();
    //    }
    //}
}
