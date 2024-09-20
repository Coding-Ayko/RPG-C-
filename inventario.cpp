#ifndef INVENTORY_H
#define INVENTORY_H

#include "inventory.h"
#include "../elements/elements.h" // Corrigido para caminho relativo
#include <iostream>
using namespace std;

// ------------ Implementação da Mochila (Pilha Estática) ------------ //

Mochila::Mochila() : topoIndice(-1) {}

bool Mochila::vazia() const {
    return topoIndice == -1;
}

bool Mochila::cheia() const {
    return topoIndice == CAPACIDADE - 1;
}

void Mochila::adicionar(Elemento* item) {
    if (cheia()) {
        cout << "Mochila cheia! Não é possível adicionar o item." << endl;
        return;
    }
    itens[++topoIndice] = item;
}

void Mochila::remover(Elemento* &item) {
    if (vazia()) {
        cout << "Mochila vazia! Não há itens para remover." << endl;
        return;
    }
    item = itens[topoIndice--];
}

Elemento* Mochila::topo() const {
    if (vazia()) {
        cout << "Mochila vazia! Não há itens no topo." << endl;
        return nullptr;
    }
    return itens[topoIndice];
}

void Mochila::limpar() {
    topoIndice = -1;
}

int Mochila::tamanho() const {
    return topoIndice + 1;
}

// ------------ Implementação do Cinto (Fila Dinâmica) ------------ //

Cinto::Cinto() : inicio(nullptr), fim(nullptr), pesoTotal(0) {}

Cinto::~Cinto() {
    limpar();
}

bool Cinto::vazio() const {
    return inicio == nullptr;
}

bool Cinto::cheio() const {
    return pesoTotal >= CAPACIDADE_PESO;
}

void Cinto::adicionar(Elemento* item) {
    int pesoItem = item->getPeso(); // Supondo que Elemento tenha um método getPeso()
    if (pesoTotal + pesoItem > CAPACIDADE_PESO) {
        cout << "Cinto cheio! Não é possível adicionar o item." << endl;
        return;
    }

    NoCinto* novoNo = new NoCinto;
    novoNo->item = item;
    novoNo->proximo = nullptr;

    if (vazio()) {
        inicio = fim = novoNo;
    } else {
        fim->proximo = novoNo;
        fim = novoNo;
    }
    pesoTotal += pesoItem;
}

void Cinto::usar() {
    if (vazio()) {
        cout << "Cinto vazio! Não há itens para usar." << endl;
        return;
    }

    NoCinto* temp = inicio;
    inicio = inicio->proximo;
    pesoTotal -= temp->item->getPeso();
    delete temp;

    if (inicio == nullptr) {
        fim = nullptr;
    }
}

void Cinto::limpar() {
    while (inicio != nullptr) {
        usar();  // Remove e usa todos os itens até a fila ficar vazia
    }
}

int Cinto::pesoAtual() const {
    return pesoTotal;
}


#endif
