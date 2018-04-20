#ifndef MATRIZ_H
#define MATRIZ_H
#include <QString>

namespace MT{

class Matriz {

private:

    int quantidadeDeLinhas;
    int quantidadeDeColunas;
    int *array;

public:

    Matriz(int qLinhas, int qColunas);

    ~Matriz();

    int getQuantidadeDeLinhas() const{return quantidadeDeLinhas;}
    int getQuantidadeDeColunas() const{return quantidadeDeColunas;}
    QString getMatriz() const;
    int getElemento(int linha, int coluna) const{return *(array + linha * quantidadeDeColunas + coluna);}
    void setElemento(int linha, int coluna, int elemento) const;
    Matriz* operator - (Matriz const * const matriz) const;
    bool operator ==(Matriz const * const matriz) const;
    bool operator !=(Matriz const * const matriz) const;
    Matriz* operator + (const Matriz * const matriz) const;
    Matriz* operator * (const Matriz * const matriz) const;
    Matriz* transposta() const;
    bool triangularSuperior() const;
    bool simetrica() const;
    bool ortogonal() const;
    bool permutacao() const;
    Matriz* multiplicar(int k) const;
    bool triangularInferior() const;
    bool identidade() const;
    Matriz* potencia(int k) const;

};
}

#endif //MATRIZ_H
