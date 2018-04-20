#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    matrizA(NULL),
    matrizB(NULL)

{
    ui->setupUi(this);
}



MainWindow::~MainWindow()

{
    if (matrizA)
        delete matrizA;
    if (matrizB)
        delete matrizB;
    delete ui;
}




//---------------------------------------------

//-----------------MATRIZ A--------------------

//---------------------------------------------




void MainWindow::on_pushButtonCriarA_clicked()

{
    try{
        int qLinhas = ui->lineEditLinhasA->text().toInt();
        int qColunas = ui->lineEditColunasA->text().toInt();

        this->matrizA = new MT::Matriz(qLinhas, qColunas);

        ui->tableWidgetMatrizA->setRowCount(qLinhas);
        ui->tableWidgetMatrizB->setColumnCount(qColunas);



    //Atribuição de valores

    for (int lin=0; lin<qLinhas; lin++) {
        for (int col=0; col<qColunas; col++) {
            int valor = QInputDialog::getInt(this, "Leitura de Dados", "Matriz A["+

            QString::number(lin)+", "+QString::number(col)+"]:");
            this->matrizA->setElemento(lin, col, valor);

            ui->tableWidgetMatrizA->setItem(lin, col, new QTableWidgetItem(QString::number(valor)));
        }
    }



    //Ativar Limpar

    ui->pushButtonLimparA->setEnabled(true);


    //Desativar Criar

    ui->pushButtonCriarA->setEnabled(false);



//---------------------------------------------

//--------------------BOTOES---------------------

//---------------------------------------------



    //Botões em comum para A e B

    if (this->matrizB){
        ui->pushButtonSomar->setEnabled(true);

    //Botões da Matriz A

    ui->pushButtonSubtrairA->setEnabled(true);
    ui->pushButtonMultiplicarA->setEnabled(true);

    //Botões da Matriz B

    ui->pushButtonSubtrairB->setEnabled(true);
    ui->pushButtonMultiplicarB->setEnabled(true);

    }

    ui->pushButtonPotenciaA->setEnabled(true);
    ui->pushButtonMultKA->setEnabled(true);
    ui->pushButtonTranspostaA->setEnabled(true);




//---------------------------------------------

//-----------------GRID---------------------------

//---------------------------------------------




    QString conversorBool;


    //Iguais

    if (matrizA && matrizB){
        conversorBool = (this->matrizA == this->matrizB) ? "Sim" : "Não";
                                                    //Retorna Sim ou Não

            //Setar Matriz A
        ui->tableWidgetBoolA->setItem(0, 0, new QTableWidgetItem(conversorBool));

            //Setar Matriz B
        ui->tableWidgetBoolB->setItem(0, 0, new QTableWidgetItem(conversorBool));

    }

    else
        ui->tableWidgetBoolA->setItem(0, 0, new QTableWidgetItem("---"));

    //
    //

    //Diferentes

    if (matrizA && matrizB){
        conversorBool = (this->matrizA != this->matrizB) ? "Sim" : "Não";
                                                    //Retorna Sim ou Não

            //Setar Matriz A
        ui->tableWidgetBoolA->setItem(0, 1, new QTableWidgetItem(conversorBool));

            //Setar Matriz B
        ui->tableWidgetBoolB->setItem(0, 1, new QTableWidgetItem(conversorBool));

    }

    else
        ui->tableWidgetBoolA->setItem(0, 1, new QTableWidgetItem("---"));

    //
    //

    //Triangular Superior

    conversorBool = this->matrizA->triangularSuperior() ? "Sim" : "Não";
                                                    //Retorna Sim ou Não
    ui->tableWidgetBoolA->setItem(0, 2, new QTableWidgetItem(conversorBool));

    //
    //

    //Triangular Inferior

    conversorBool = this->matrizA->triangularInferior() ? "Sim" : "Não";
                                                    //Retorna Sim ou Não
    ui->tableWidgetBoolA->setItem(0, 3, new QTableWidgetItem(conversorBool));

    //
    //

    //Simetrica

    conversorBool = this->matrizA->simetrica() ? "Sim" : "Não";
                                                    //Retorna Sim ou Não
    ui->tableWidgetBoolA->setItem(0, 4, new QTableWidgetItem(conversorBool));

    //
    //

    //Identidade

    conversorBool = this->matrizA->identidade() ? "Sim" : "Não";
                                                    //Retorna Sim ou Não
    ui->tableWidgetBoolA->setItem(0, 5, new QTableWidgetItem(conversorBool));

    //
    //

    //Ortogonal

    conversorBool = this->matrizA->ortogonal() ? "Sim" : "Não";
                                                    //Retorna Sim ou Não
    ui->tableWidgetBoolA->setItem(0, 6, new QTableWidgetItem(conversorBool));

    //
    //

    //Permutação

    conversorBool = this->matrizA->permutacao() ? "Sim" : "Não";
                                                    //Retorna Sim ou Não
    ui->tableWidgetBoolA->setItem(0, 7, new QTableWidgetItem(conversorBool));

    }
    catch (std::bad_alloc){
        QMessageBox::critical(this, "Erro do Sistema", "Memoria insuficiente para criar matriz");
    }
    catch (QString &erro){
        QMessageBox::critical(this, "Erro do Sistema", erro);
    }
}

void MainWindow::on_pushButtonLimparA_clicked()

{
//    delete[] this->matrizA;

//    int qLinhas = this->matrizA->quantidadeDeLinhas;
//    int qColunas = this->matrizA->quantidadeDeColunas;

//    for (int lin=0; lin<qLinhas; lin++) {
//       for (int col=0; col<qColunas; col++) {
//           delete ui->tableWidgetMatrizA->item(lin, col);

//       }
//    }
}

void MainWindow::on_pushButtonSubtrairA_clicked()

{

    try{

        MT::Matriz *saida = (*matrizA) - matrizB;

        int qLinhas = saida->getQuantidadeDeLinhas();
        int qColunas = saida->getQuantidadeDeColunas();

        ui->tableWidgetResultado->setRowCount(qLinhas);
        ui->tableWidgetResultado->setColumnCount(qColunas);



        for (int lin=0; lin<qLinhas; lin++) {
            for (int col=0; col<qColunas; col++) {
                int valor = saida->getElemento(lin, col);

        ui->tableWidgetResultado->setItem(lin, col, new QTableWidgetItem(QString::number(valor)));
            }
        }

        delete saida;

    }
    catch (QString &erro) {
       QMessageBox::critical(this, "Erro do Sistema", erro);
    }
}

void MainWindow::on_pushButtonMultiplicarA_clicked()
{
    try{

        MT::Matriz *saida = (*matrizA) * matrizB;

        int qLinhas = saida->getQuantidadeDeLinhas();
        int qColunas = saida->getQuantidadeDeColunas();

        ui->tableWidgetResultado->setRowCount(qLinhas);
        ui->tableWidgetResultado->setColumnCount(qColunas);



        for (int lin=0; lin<qLinhas; lin++) {
            for (int col=0; col<qColunas; col++) {
                 int valor = saida->getElemento(lin, col);
                 ui->tableWidgetResultado->setItem(lin, col, new QTableWidgetItem(QString::number(valor)));
            }
        }

        delete saida;

    }
    catch (QString &erro) {
        QMessageBox::critical(this, "Erro do Sistema", erro);
    }
}

void MainWindow::on_pushButtonPotenciaA_clicked()
{

     try{
        int valor = QInputDialog::getInt(this, "Potênciação da Matriz A", "Quantidade a elevar Matriz:",0,0);

        MT::Matriz *saida = matrizA->potencia(valor);

        int qLinhas = saida->getQuantidadeDeLinhas();
        int qColunas = saida->getQuantidadeDeColunas();

        for(int lin=0; lin<qLinhas; lin++){
           for(int col=0; col<qColunas; col++){

                ui->tableWidgetResultado->setItem(lin, col, new QTableWidgetItem);

            }
        }

        delete saida;

    }
    catch (QString &erro){
        QMessageBox::critical(this, "Erro do Sistema", erro);
    }
}

void MainWindow::on_pushButtonMultKA_clicked()
{

    try{

        int numero = QInputDialog::getInt(this, "Leitura de Valor", "Insira o valor de K:", 0, 0);

        MT::Matriz *saida = matrizA->multiplicar(numero);

        int qLinhas = saida->getQuantidadeDeLinhas();
        int qColunas = saida->getQuantidadeDeColunas();

        ui->tableWidgetResultado->setRowCount(qLinhas);
        ui->tableWidgetResultado->setColumnCount(qColunas);



        for (int lin=0; lin<qLinhas; lin++){
            for (int col=0; col<qColunas; col++) {
                 int valor = saida->getElemento(lin, col);

                 ui->tableWidgetResultado->setItem(lin, col, new QTableWidgetItem(QString::number(valor)));

            }
        }

        delete saida;
        }

    catch (QString &erro) {
        QMessageBox::critical(this, "Erro do Sistema", erro);
    }
}

void MainWindow::on_pushButtonTranspostaA_clicked()
{
    try {
        MT::Matriz * saida = matrizA->transposta();

        int qLinhas = saida->getQuantidadeDeLinhas();
        int qColunas = saida->getQuantidadeDeColunas();

        ui->tableWidgetResultado->setRowCount(qLinhas);
        ui->tableWidgetResultado->setColumnCount(qColunas);

        for (int lin=0; lin<qLinhas; lin++){
             for(int col=0; col<qColunas; col++){

             ui->tableWidgetResultado->setItem(lin,col,new QTableWidgetItem);

             }
        }

        delete saida;

           }

    catch (QString &erro) {
          QMessageBox::critical(this, "Erro do Sistema", erro);
    }

}




//---------------------------------------------

//-----------------SOMAR-----------------------

//---------------------------------------------

void MainWindow::on_pushButtonSomar_clicked()

{

    try{
        MT::Matriz *saida = (*matrizA) + matrizB;

        int qLinhas = saida->getQuantidadeDeLinhas();
        int qColunas = saida->getQuantidadeDeColunas();

        ui->tableWidgetResultado->setRowCount(qLinhas);
        ui->tableWidgetResultado->setColumnCount(qColunas);

        for(int lin=0; lin<qLinhas; lin++){
              for(int col=0; col<qColunas; col){
                int valor = saida->getElemento(lin, col);

        ui->tableWidgetResultado->setItem(lin, col, new QTableWidgetItem(QString::number(valor)));


              }
        }
    }

    catch (QString &erro){
        QMessageBox::information (this, "ERRO NO SISTEMA", erro) ;
    }

}

//

//

//







//---------------------------------------------

//-----------------MATRIZ B--------------------

//---------------------------------------------



void MainWindow::on_pushButtonCriarB_clicked()

{



}



void MainWindow::on_pushButtonLimparB_clicked()

{



}



void MainWindow::on_pushButtonMultiplicarB_clicked()

{



}



void MainWindow::on_pushButtonSubtrairB_clicked()

{



}



void MainWindow::on_pushButtonPotenciaB_clicked()

{



}



void MainWindow::on_pushButtonMultKB_clicked()

{



}



void MainWindow::on_pushButtonTranspostaB_clicked()

{



}
