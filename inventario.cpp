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

// ------------ Implementação do Cinto (Fila Estática) ------------ //

Cinto::Cinto(int slots, int capacidade) : tamanho(slots), capacidade(capacidade), pesoTotal(0) {
    this->slots = new Slot[tamanho]; // Aloca memória para os slots
    for (int i = 0; i < tamanho; i++) {
        this->slots[i].ocupado = false; // Inicializa todos os slots como vazios
        this->slots[i].item = nullptr;
    }
}

Cinto::~Cinto() {
    for (int i = 0; i < tamanho; i++) {
        delete slots[i].item; // Libera a memória dos itens, se necessário
    }
    delete[] slots; // Libera a memória do array de slots
}

bool Cinto::vazio() const {
    for (int i = 0; i < tamanho; i++) {
        if (slots[i].ocupado) return false; // Se algum slot estiver ocupado
    }
    return true;
}

bool Cinto::adicionar(Elemento* item) {
    if (pesoTotal + item->peso > capacidade) {
        return false; // Não pode adicionar devido à capacidade total
    }
    for (int i = 0; i < tamanho; i++) {
        if (!slots[i].ocupado) {
            slots[i].item = item; // Adiciona o item ao slot
            slots[i].ocupado = true; // Marca o slot como ocupado
            pesoTotal += item->peso; // Atualiza o peso total
            return true; // Adicionado com sucesso
        }
    }
    return false; // Cinto cheio
}

bool Cinto::remover(int slotIndex, Elemento* &item) {
    if (slotIndex < 0 || slotIndex >= tamanho || !slots[slotIndex].ocupado) {
        item = nullptr; // Slot inválido ou vazio
        return false;
    }
    item = slots[slotIndex].item; // Pega o item
    slots[slotIndex].item = nullptr; // Limpa o slot
    slots[slotIndex].ocupado = false; // Marca o slot como vazio
    pesoTotal -= item->peso; // Atualiza o peso total
    return true; // Removido com sucesso
}

Elemento* Cinto::obter(int slotIndex) const {
    if (slotIndex < 0 || slotIndex >= tamanho) {
        return nullptr; // Slot inválido
    }
    return slots[slotIndex].ocupado ? slots[slotIndex].item : nullptr; // Retorna o item, se houver
}

int Cinto::obterPesoTotal() const {
    return pesoTotal; // Retorna o peso total dos itens
}

int Cinto::getSlots() const {
    return tamanho; // Retorna o número total de slots
}

int Cinto::getSlotsUsados() const {
    int usados = 0;
    for (int i = 0; i < tamanho; i++) {
        if (slots[i].ocupado) usados++; // Conta slots ocupados
    }
    return usados;
}

int Cinto::getCapacidade() const {
    return capacidade; // Retorna a capacidade total de peso
}



#endif
