#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>
using namespace std;

// Classe base para Elementos
class Elemento {
public:
    Elemento(const string& nome, int peso);
    string getNome() const;           // Retorna o nome do item
    int getPeso() const;              // Retorna o peso do item
    Elemento* getNext() const;        // Retorna o próximo elemento
    void setNext(Elemento* nextElemento); // Define o próximo elemento

private:
    string nome;                      // Nome do item
    int peso;                         // Peso do item
    Elemento* next;                   // Ponteiro para o próximo elemento
};

// Classe para Armas
class Arma : public Elemento {
public:
    Arma(const string& nome, int peso, int poderAtaque);
    int getPoderAtaque() const;       // Retorna o poder de ataque da arma

private:
    int poderAtaque;                  // Poder de ataque da arma
};

// Classe para Poções
class Pocao : public Elemento {
public:
    Pocao(const string& nome, int peso, int cura);
    int getCura() const;              // Retorna a capacidade de cura da poção

private:
    int cura;                         // Capacidade de cura da poção
};

#endif // ELEMENTO_H

