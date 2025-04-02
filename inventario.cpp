//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170

#include "inventario.h"
#include <iostream>
using namespace std;


Mochila::Mochila() {
    top = nullptr;
    count = 0;
}

//verifica isso aqui
Mochila::~Mochila() { 
    Clear();
}

bool Mochila::Empty() {
      return count == 0;
}

void Mochila::Push(Elemento* item) {
    NodePointer p = new Node;
    if (p == nullptr) {
        cout << "Memoria insuficiente!" << endl;
        abort();
    }
    p->item = item;
    p->next = top;
    top = p;
    cout << "Item guardado na mochila!"<< endl;
    count++;

}

void Mochila::Pop(Elemento* &item) {
    if (!Empty()) {  // Verifica se a mochila não está vazia
        NodePointer temp = top; // Salva o nó do topo
        item = top->item;  // Armazena o item do topo
        top = top->next;   // Move o topo para o próximo nó
        delete temp;       // Libera a memória do nó removido
        count--;           // Decrementa o contador de elementos
    } else {
        item = nullptr; // Se a mochila está vazia, define item como nullptr
        cout << "A mochila esta vazia, não há elementos para remover." << std::endl;
    }
}

void Mochila::Top(Elemento* &item) {
    if (Empty()) {
        cout << "Mochila vazia!" << endl;
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



void Mochila::Exibir() {
    if (Empty()) {
        cout << "Mochila vazia." << endl;
        return;
    }

    // Exibe apenas o item no topo da mochila
    cout << "Item no topo:" << endl;
    cout << "- " << top->item->getNome() 
         << " (Peso: " << top->item->getPeso() << ")" << endl;
}

//====================== Implementação Cinto =================================//

// Construtor do Cinto
Cinto::Cinto(int numeroSlots, int capacidadeTotal) 
    : head(nullptr), pesoTotal(0), capacidade(capacidadeTotal), slots(numeroSlots) {
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

void Cinto::setPosition(int pos, Slot*& current) const {
    current = head;  // Inicializa no início da lista
    for (int i = 0; i < pos && current != nullptr; ++i) {
        current = current->next;  // Avança para a posição desejada
    }

    // Se 'current' for nullptr, significa que a posição não existe
    if (current == nullptr && pos != 0) {
        cout << "Erro: Posição fora dos limites." << endl;
    }
}

bool Cinto::Insert(Elemento* item, int pos) {
    // Verifica se o item a ser inserido é nulo
    if (item == nullptr) {
        cout << "Erro: O item não pode ser nulo." << endl;
        return false;
    }

    // Verifica se o item a ser inserido excede a capacidade
    if (pesoTotal + item->getPeso() > capacidade) {
        cout << "Erro: O item excede a capacidade de peso do cinto." << endl;
        return false;
    }

    // Validação da posição
    if (pos < 0 || pos > slots) {  // Permite inserir na posição até slots 
        cout << "Posicao invalida. Escolha entre 0 e " << slots - 1 << "." << endl;
        return false;
    }

    // Cria um novo slot para o item a ser inserido
    Slot* newSlot = new Slot{item, nullptr};

    if (pos == 0) {
        // Caso de inserir no início (pos = 0)
        newSlot->next = head; // O novo slot aponta para o atual head
        head = newSlot;       // O novo slot se torna o novo head
    } else {
    Slot* current = nullptr;
    setPosition(pos, current);  // Navegar diretamente até a posição desejada

    if (current != nullptr && current->item != nullptr) {
        cout << "Erro: A posição " << pos << " já está ocupada." << endl;
        delete newSlot;
        return false;
    }

        // Inserir o item na posição desejada
        newSlot->next = current->next;  // A próxima posição do novo slot é a atual
        current->next = newSlot;         // O atual aponta para o novo slot
    }

    // Atualiza o peso total
    pesoTotal += item->getPeso();
    cout << "Item inserido no cinto no slot " << pos << endl;

    // Mostrar o peso restante no cinto após a inserção
    int pesoRestante = capacidade - pesoTotal;
    cout << "Peso restante no cinto: " << pesoRestante << " unidades." << endl;

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
void Cinto::Exibir() const {
    // verificar se ta vazio antes
    if( head == nullptr){
        cout << "Nada por aqui" << endl;
    }

    Slot* current = head;
    cout << "Itens no cinto:" << endl;
    while (current != nullptr) {
        if (current->item) {
            cout << "- " << current->item->getNome() << " (Peso: " << current->item->getPeso() << ")" << endl;
        }
        current = current->next;
    }
}



