#include "inventario.h"
#include "elementos.h"
#include <iostream>

using namespace std;

#ifndef INVENTARIO_H
#define INVENTARIO_H

// ------------ Implementação da Mochila (Pilha Dinamica) ------------ //

Mochila::Mochila() : topoPilha(NULL), tamanhoAtual(0) {}

Mochila::~Mochila() {
    Clear();  // Limpa todos os elementos
}

bool Mochila::Empty() const {
    return topoPilha == NULL;
}

void Mochila::Push(Elemento* item) {
    MochilaNode* novoNode = new MochilaNode;
    novoNode->item = item;
    novoNode->next = topoPilha;
    topoPilha = novoNode;
    tamanhoAtual++;
}

void Mochila::Pop(Elemento* &item) {
    if (Empty()) {
        cout << "Mochila vazia!" << endl;
        return;
    }
    MochilaNode* temp = topoPilha;
    item = topoPilha->item;
    topoPilha = topoPilha->next;
    delete temp;
    tamanhoAtual--;
}

Elemento* Mochila::topo() const {
    if (Empty()) {
        return nullptr;
    }
    return topoPilha->item;
}

void Mochila::Clear() {
    while (!Empty()) {
        Elemento* temp;
        Pop(temp);  // Remove e deleta todos os nós
    }
}

int Mochila::Size() const {
    return tamanhoAtual;
}

// ------------ Implementação do Cinto (Lista Estatica) ------------ //
#include "inventario.h"
#include "elementos.h"
#include <iostream>

using namespace std;

Cinto::Cinto(int slots, int capacidade) : tamanho(slots), capacidade(capacidade), pesoTotal(0) {
    this->slots = new Slot[tamanho];  // Aloca memória para o array de slots
    for (int i = 0; i < tamanho; i++) {
        this->slots[i].ocupado = false;   // Inicializa todos os slots como vazios
        this->slots[i].item = nullptr;    // Inicializa os ponteiros como nulos
    }
}

Cinto::~Cinto() {
    for (int i = 0; i < tamanho; i++) {
        delete slots[i].item;  // Libera a memória dos itens, se necessário
    }
    delete[] slots;            // Libera a memória do array de slots
}

bool Cinto::Empty() const {
    for (int i = 0; i < tamanho; i++) {
        if (slots[i].ocupado) return false;  // Se algum slot estiver ocupado, o cinto não está vazio
    }
    return true;
}

bool Cinto::Insert(Elemento* item) {
    if (pesoTotal + item->getPeso() > capacidade) {  // Verifica se o peso total excederia a capacidade
        cout << "Capacidade do cinto excedida!" << endl;
        return false;
    }
    for (int i = 0; i < tamanho; i++) {
        if (!slots[i].ocupado) {  // Encontra o primeiro slot vazio
            slots[i].item = item;    // Adiciona o item ao slot
            slots[i].ocupado = true; // Marca o slot como ocupado
            pesoTotal += item->getPeso();  // Atualiza o peso total do cinto
            return true;             // Item adicionado com sucesso
        }
    }
    cout << "Cinto cheio!" << endl;
    return false;  // Cinto está cheio
}

bool Cinto::Delete(int slotIndex, Elemento* &item) {
    if (slotIndex < 0 || slotIndex >= tamanho || !slots[slotIndex].ocupado) {
        cout << "Slot inválido ou vazio!" << endl;
        item = nullptr;
        return false;  // Slot não contém nenhum item válido
    }
    item = slots[slotIndex].item;    // Pega o item do slot
    slots[slotIndex].item = nullptr; // Limpa o slot
    slots[slotIndex].ocupado = false; // Marca o slot como vazio
    pesoTotal -= item->getPeso();    // Atualiza o peso total do cinto
    return true;  // Item removido com sucesso
}

Elemento* Cinto::obter(int slotIndex) const {
    if (slotIndex < 0 || slotIndex >= tamanho) {
        cout << "Slot inválido!" << endl;
        return nullptr;  // Índice fora dos limites
    }
    return slots[slotIndex].ocupado ? slots[slotIndex].item : nullptr;  // Retorna o item no slot ou nullptr
}

int Cinto::obterPesoTotal() const {
    return pesoTotal;  // Retorna o peso total dos itens no cinto
}

int Cinto::getSlots() const {
    return tamanho;  // Retorna o número total de slots
}

int Cinto::getSlotsUsados() const {
    int usados = 0;
    for (int i = 0; i < tamanho; i++) {
        if (slots[i].ocupado) usados++;  // Conta quantos slots estão ocupados
    }
    return usados;
}

int Cinto::getCapacidade() const {
    return capacidade;  // Retorna a capacidade total de peso do cinto
}

#endif