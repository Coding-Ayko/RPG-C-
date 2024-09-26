#include "inventario.h"
#include <iostream>
using namespace std;


Mochila::Mochila() {
    top = nullptr;
    count = 0;
}

Mochila::~Mochila() { 
    Clear();
}

bool Mochila::Empty() {
    return top == nullptr;
}

void Mochila::Push(Elemento* item) {
    NodePointer p = new Node;
    if (p == nullptr) {
        cout << "Memória insuficiente!" << endl;
        abort();
    }
    p->item = item;
    p->next = top;
    top = p;
    count++;
}

void Mochila::Pop(Elemento* &item) {
    if (Empty()) {
        cout << "Mochila vazia! Não há itens para remover." << endl;
        abort();
    }
    NodePointer p = top;
    item = top->item;
    top = top->next;
    delete p;
    count--;
}

void Mochila::Top(Elemento* &item) {
    if (Empty()) {
        cout << "Mochila vazia! Não há itens no topo." << endl;
        abort();
    }
    item = top->item;
}

void Mochila::Clear() {
    Elemento* item;
    while (!Empty()) {
        Pop(item);
    }
}

int Mochila::Size() {
    return count;
}

void Mochila::exibir(){
    if (Empty()) {
        cout << "Mochila vazia." << endl;
        return;
    }
    
    cout << "Itens na mochila:" << endl;
    
    NodePointer current = top; // Começa do topo da mochila
    while (current != nullptr) {
        cout << "- " << current->item->getNome() 
             << " (Peso: " << current->item->getPeso() << ")" << endl; // Assumindo que Elemento tem getNome() e getPeso()
        current = current->next; // Move para o próximo item
    }
}

//====================== Implementação Cinto =================================//

// Construtor do Cinto
Cinto::Cinto(int numeroSlots, int capacidadeTotal) 
    : head(nullptr), pesoTotal(0), capacidade(capacidadeTotal) {
}

// Destrutor do Cinto (libera a memória dos slots)
Cinto::~Cinto() {
    Slot* current = head;
    while (current != nullptr) {
        Slot* next = current->next;
        delete current->item; // Supondo que Elemento é alocado dinamicamente
        delete current;
        current = next;
    }
}

// Verifica se o cinto está vazio
bool Cinto::Empty() const {
    return head == nullptr;
}

// Adiciona um item em uma posição específica
bool Cinto::Insert(Elemento* item, int pos) {
    if (pesoTotal + item->getPeso() > capacidade) {
        return false;  // Excede a capacidade
    }

    Slot* newSlot = new Slot{item, nullptr};

    // Caso de inserir no início
    if (pos == 0) {
        newSlot->next = head;
        head = newSlot;
        pesoTotal += item->getPeso();
        return true;
    }

    // Navegar até a posição desejada
    Slot* current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        delete newSlot;  // Libera a memória se a posição não existe
        return false;
    }

    newSlot->next = current->next;
    current->next = newSlot;
    pesoTotal += item->getPeso();
    return true;
}

// Remove um item de uma posição específica
bool Cinto::Delete(int pos, Elemento*& item) {
    if (Empty()) {
        return false;
    }

    Slot* current = head;

    // Caso de remover o primeiro slot
    if (pos == 0) {
        head = head->next;
        item = current->item;
        delete current;
        pesoTotal -= item->getPeso();
        return true;
    }

    // Navegar até a posição anterior ao slot que será removido
    for (int i = 0; i < pos - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        return false;  // Posição inválida
    }

    Slot* toDelete = current->next;
    current->next = toDelete->next;
    item = toDelete->item;
    delete toDelete;
    pesoTotal -= item->getPeso();
    return true;
}

// Retorna o item em uma posição específica
Elemento* Cinto::obter(int pos) const {
    Slot* current = head;
    for (int i = 0; i < pos && current != nullptr; ++i) {
        current = current->next;
    }
    return (current != nullptr) ? current->item : nullptr;
}

// Retorna o peso total dos itens no cinto
int Cinto::obterPesoTotal() const {
    return pesoTotal;
}

// Retorna a capacidade total de peso
int Cinto::getCapacidade() const {
    return capacidade;
}

int Cinto::getSlots() const {
     return slots;
 }        // Retorna o número de slots

// Exibe todos os itens no cinto
void Cinto::exibir() const {
    if (Empty()) {
        cout << "Cinto vazio." << endl;
    } else {
        cout << "Itens no cinto:" << endl;
        Slot* current = head; // Começa pelo primeiro slot do cinto
        while (current) {
            cout << "- " << current->item->getNome() << " (Peso: " << current->item->getPeso() << ")" << endl;
            current = current->next; // Avança para o próximo slot
        }
    }
}


