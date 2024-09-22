#include "elementos.h"
#include <string>

using namespace std;

#ifndef ELEMENTOS_H
#define ELEMENTOS_H

// Implementação da classe Elemento

Elemento::Elemento() : nome(""), peso(0), valor(0), tipo(INIMIGO) {}

Elemento::Elemento(const string& nome, int peso, int valor, Tipo tipo)
    : nome(nome), peso(peso), valor(valor), tipo(tipo) {}

string Elemento::getNome() const {
    return nome;
}

void Elemento::setNome(const string& nome) {
    this->nome = nome;
}

int Elemento::getPeso() const {
    return peso;
}

void Elemento::setPeso(int peso) {
    this->peso = peso;
}

int Elemento::getValor() const {
    return valor;
}

void Elemento::setValor(int valor) {
    this->valor = valor;
}

Elemento::Tipo Elemento::getTipo() const {
    return tipo;
}

void Elemento::setTipo(Tipo tipo) {
    this->tipo = tipo;
}

// Implementação da classe Inimigo
Inimigo::Inimigo(const string& nome, int peso, int valor, int forca)
    : Elemento(nome, peso, valor, Elemento::INIMIGO), forca(forca) {}

int Inimigo::getForca() const {
    return forca;
}

void Inimigo::setForca(int forca) {
    this->forca = forca;
}

// Implementação da classe Arma
Arma::Arma(const string& nome, int peso, int valor, int dano)
    : Elemento(nome, peso, valor, Elemento::ARMA), dano(dano) {}

int Arma::getDano() const {
    return dano;
}

void Arma::setDano(int dano) {
    this->dano = dano;
}

// Implementação da classe Potao
Potao::Potao(const string& nome, int peso, int valor, int cura)
    : Elemento(nome, peso, valor, Elemento::POTAO), cura(cura) {}

int Potao::getCura() const {
    return cura;
}

void Potao::setCura(int cura) {
    this->cura = cura;
}

#endif // ELEMENTO_H