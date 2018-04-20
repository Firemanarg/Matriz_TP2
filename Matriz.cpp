#include <QString>
#include <Matriz.h>
namespace MT{

Matriz::Matriz(int qLinhas, int qColunas):
    quantidadeDeColunas(0),
    quantidadeDeLinhas(0),
    array(NULL)

{

    try{
        if (qColunas <= 0)
            throw QString ("Número de Colunas deve ser maior que ZERO");

        if (qLinhas <= 0)
            throw QString ("Número de Linhas deve ser maior que ZERO");

        array = new int[qLinhas, qColunas];
        quantidadeDeColunas = qColunas;
        quantidadeDeLinhas = qLinhas;

    }

    catch(std::bad_alloc){
    throw QString("Memória Insuficiente para criar a Matriz");
    }

}

Matriz::~Matriz()
{
    delete[] array;
}

void Matriz::setElemento(int linha, int coluna, int elemento) const
{

    if (linha >= this->quantidadeDeLinhas || linha < 0)
        throw QString("Linha fora do intervalo");

    if ((coluna >= this->quantidadeDeColunas) || coluna < 0)
        throw QString("Coluna fora do intervalo");

    *(this->array + (linha * this->quantidadeDeColunas + coluna)) = elemento;

}



QString Matriz::getMatriz() const
{

    QString saida = "";

    int col = this->quantidadeDeColunas;
    int lin = this->quantidadeDeLinhas;

    for(int linR=0; linR<lin; linR++){
        for(int colR=0; colR<col; colR++){
            saida += QString::number(*(this->array + (linR * col + colR)));

            if(colR != col)
                saida += "|";

        }
    }

    return saida;

}

Matriz* Matriz::operator - (Matriz const * const matriz) const{

    try{
        int qColunas = this->quantidadeDeColunas;
        int qLinhas = this->quantidadeDeLinhas;

        if (qColunas != matriz->getQuantidadeDeColunas())
            throw QString ("Quantidade de Colunas deve ser comum para as duas matrizes");

        if (qLinhas != matriz->getQuantidadeDeLinhas())
            throw QString  ("Quantidade de Linhas deve comum para as duas matrizes");



        Matriz *saida = new Matriz(qLinhas, qColunas);

        for (int lin=0; lin<qLinhas; lin++){
             for(int col=0; col<qColunas; col++){
                 int elemento = *(this->array +(lin * qColunas + col)) - matriz->getElemento(lin, col);
                 saida->setElemento(lin, col, elemento);

             }
        }

        return saida;

    }

    catch(std::bad_alloc){
         throw QString ("Memória insuficiente para subtrair matrizes");
    }

}



bool Matriz::operator ==(Matriz const * const matriz) const
{

    int tamA = this->quantidadeDeLinhas * this->quantidadeDeColunas;
    int tamB = matriz->getQuantidadeDeLinhas() * matriz->getQuantidadeDeColunas();



    if (tamA != tamB)
        return false;

     for (int lin=0; lin<this->quantidadeDeLinhas; lin++){
          for (int col=0; col<this->quantidadeDeColunas; col++){
               int elemento = *(this->array + (lin * quantidadeDeColunas + col));

               if (elemento != matriz->getElemento(lin, col));

               return false;

          }

     }

     return true;

}

bool Matriz::operator !=(Matriz const * const matriz) const

{

    return !(this == matriz);

}

Matriz* Matriz::operator + (const Matriz * const matriz) const
{

    try{

        if (this->quantidadeDeLinhas != matriz->getQuantidadeDeLinhas()
                ||this->quantidadeDeColunas != matriz->getQuantidadeDeColunas())
            throw QString("As matrizes possuem tamanho diferente");

        Matriz *saida = new Matriz(this->quantidadeDeLinhas, this->quantidadeDeColunas);

        for (int lin=0; lin<this->quantidadeDeLinhas; lin++){
             for (int col=0; col<this->quantidadeDeColunas; col++){
                  int soma = *(this->array + (lin * this->quantidadeDeLinhas + col)) +

                  matriz->getElemento(lin, col);
                  saida->setElemento(lin, col, soma);

             }
        }

        return saida;

    }

    catch (std::bad_alloc){
        throw QString("Memoria insuficiente");
    }

}

Matriz* Matriz::transposta() const
{

    try{

        int qColunas = this->quantidadeDeColunas;
        int qLinhas = this->quantidadeDeLinhas;

        Matriz *saida = new Matriz(qColunas, qLinhas);

        for(int lin=0; lin<qLinhas; lin++){
            for(int col=0; col<qColunas; col++){
                int valor = *(this->array + lin*qColunas + col);

                saida->setElemento(col, lin, valor);

            }
        }

        return saida;

    }

    catch (std::bad_alloc){
        throw QString ("Memória insuficiente para calcular transposta");
    }

}



bool Matriz::triangularSuperior() const
{

    int qColunas = this->quantidadeDeColunas;
    int qLinhas = this->quantidadeDeLinhas;

    if (qLinhas != qColunas)
        return false;

    for (int lin=0; lin<qLinhas; lin++){
        for(int col=0; col<qColunas; col++){
            if (lin>col && getElemento(lin,col)!=0){

                return false;

            }
        }
    }

    return true;

}

bool Matriz::triangularInferior() const{

    int qLinhas = this->quantidadeDeLinhas;
    int qColunas = this->quantidadeDeColunas;

    if (qLinhas != qColunas)
        return false;

    for(int lin=0; lin<qLinhas; lin++){
        for(int col=0; col<qColunas; col++){
            if (lin< col && getElemento(lin,col) != 0){

            return false;

            }
        }
    }

    return true;

}

Matriz* Matriz::multiplicar(int k) const
{

    try{
        Matriz* saida = new Matriz(this->quantidadeDeLinhas, this->quantidadeDeColunas);

        for (int lin=0; lin<this->quantidadeDeLinhas; lin++){
            for (int col=0; col<this->quantidadeDeColunas; col++){
                int elemento = *(this->array + (lin * this->quantidadeDeColunas + col));

                    saida->setElemento(lin, col, elemento*k);

            }
        }

        return saida;

    }

    catch (std::bad_alloc){
        throw QString("Memoria insuficiente");
    }

}

bool Matriz::identidade() const
{

    int qColunas  = this->quantidadeDeColunas;
    int qLinhas = this->quantidadeDeLinhas;

    if (qLinhas != qColunas)
        return false;

    for (int lin=0; lin<qLinhas; lin++){
        for (int col=0; col<qColunas; col++){
            if (lin == col && getElemento(lin,col) != 1){
                return false;
            }

            if (lin!=col && getElemento(lin,col) != 0){
                return false;
            }
        }

    }

    return true;

}

bool Matriz::simetrica() const
{

    Matriz* comparar = this->transposta();
    bool saida = comparar == this;
    delete comparar;

    return saida;

}

Matriz* Matriz::potencia(int k) const
{

    if (this->quantidadeDeLinhas != this->quantidadeDeColunas)
        throw QString("A matriz deve ser quadrada");

    Matriz *saida = new Matriz(this->quantidadeDeLinhas, this->quantidadeDeColunas);

    if (k == 0) {                 //Retornar Identidade
        for (int lin=0; lin<this->quantidadeDeLinhas; lin++) {
            for (int col=0; col<this->quantidadeDeColunas; col++) {
                int valor;

                if (lin == col)
                    valor = 1;

                else

        valor = 0;

        saida->setElemento(lin, col, valor);

            }
        }
    }

    else {

    for (int lin=0; lin<this->quantidadeDeLinhas; lin++){
        for (int col=0; col<this->quantidadeDeColunas; col++){
            int valor = *(this->array + (lin * this->quantidadeDeColunas + col));

            saida->setElemento(lin, col, valor);

        }
    }

        if (k != 1) {
            for (int pot=0; pot<k-1; pot++) {        //Elevar k vezes
                Matriz *aux = (*this) * saida;

                delete saida;

                saida = aux;

            }
        }

    }

    return saida;

}

bool Matriz::permutacao() const
{

//Verificar linhas

    for (int lin=0; lin<this->quantidadeDeLinhas; lin++){

        int soma = 0;

            for (int col=0; col<this->quantidadeDeColunas; col++){
                int elemento = *(this->array + (lin * this->quantidadeDeColunas + col));

                if (elemento == 1 || elemento == 0)
                    soma += 1;

                else
                    return false;

            }

                    if (soma > this->quantidadeDeColunas)
                        return false;
    }

//Verificar colunas

    for (int col=0; col<this->quantidadeDeColunas; col++) {

        int soma = 0;

            for (int lin=0; lin<this->quantidadeDeLinhas; lin++) {
                int elemento = *(this->array + (lin * this->quantidadeDeColunas + col));

                if (elemento == 1 || elemento == 0)
                    soma += 1;

                else
                    return false;

            }

                    if (soma > this->quantidadeDeLinhas)
                        return false;

    }

    return true;

}

Matriz* Matriz::operator * (const Matriz * const matriz) const{

}

bool Matriz::ortogonal() const{

}



}
