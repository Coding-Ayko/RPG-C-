//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170

#include "elemento.h"

// Construtor da classe Elemento
Elemento::Elemento(const string& nome, int peso) : nome(nome), peso(peso), next(nullptr) {}

// Retorna o nome do item
string Elemento::getNome() const {
    return nome;
}

// Retorna o peso do item
int Elemento::getPeso() const {
    return peso;
}

// Retorna o próximo elemento
Elemento* Elemento::getNext() const {
    return next;
}

// Define o próximo elemento
void Elemento::setNext(Elemento* nextElemento) {
    next = nextElemento;
}

// Construtor da classe Arma
Arma::Arma(const string& nome, int peso, int poderAtaque) 
    : Elemento(nome, peso), poderAtaque(poderAtaque) {}

// Retorna o poder de ataque da arma
int Arma::getPoderAtaque() const {
    return poderAtaque;
}

// Construtor da classe Pocao
Pocao::Pocao(const string& nome, int peso, int cura) 
    : Elemento(nome, peso), cura(cura) {}

// Retorna a capacidade de cura da poção
int Pocao::getCura() const {
    return cura;
}
