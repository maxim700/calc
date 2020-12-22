#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BNum1_clicked();

    void on_BNum2_clicked();

    void on_BNum3_clicked();

    void on_BNum4_clicked();

    void on_BNum5_clicked();

    void on_BNum6_clicked();

    void on_BNum7_clicked();

    void on_BNum8_clicked();

    void on_BNum9_clicked();

    void on_BNum0_clicked();

    void on_BNumPLUS_clicked();

    void on_BNum1MINUS_clicked();



    void on_BNummulti_clicked();



    void on_BNumdel_clicked();

    void on_BNumcalc_clicked();

    void on_BNumpoint_clicked();

    void on_BNumdiv_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
