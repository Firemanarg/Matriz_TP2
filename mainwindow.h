#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Matriz.h>
#include <QTableWidget>

namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButtonCriarA_clicked();
    void on_pushButtonLimparA_clicked();
    void on_pushButtonSubtrairA_clicked();
    void on_pushButtonMultiplicarA_clicked();
    void on_pushButtonPotenciaA_clicked();
    void on_pushButtonMultKA_clicked();
    void on_pushButtonTranspostaA_clicked();
    void on_pushButtonSomar_clicked();
    void on_pushButtonCriarB_clicked();
    void on_pushButtonLimparB_clicked();
    void on_pushButtonMultiplicarB_clicked();
    void on_pushButtonSubtrairB_clicked();
    void on_pushButtonPotenciaB_clicked();
    void on_pushButtonMultKB_clicked();
    void on_pushButtonTranspostaB_clicked();

private:

    Ui::MainWindow *ui;
    MT::Matriz *matrizA;
    MT::Matriz *matrizB;

};

#endif // MAINWINDOW_H
