#ifndef INVENTARIO_H  // Verifica se INVENTARIO_H não foi definido
#define INVENTARIO_H

#include "elemento.h"

// Mochila: Pilha Dinâmica
class Mochila {
public:
    Mochila();    // criado
    ~Mochila();   // criado
    bool Empty(); //criado 
    void Push(Elemento* item); // Adiciona um item na pilha (topo da mochila)  // criado
    void Pop(Elemento* &item);  // Remove o item do topo da pilha              // criado
    void Top(Elemento* &item);   // Retorna o item do topo da pilha            //criado
    void Clear();   // criado
    int Size();     //criado
    void exibir();
private:
    struct Node {
        Elemento* item;
        Node* next;
    };

    typedef Node* NodePointer;
    NodePointer top;
    int count;
};

// Cinto: Lista Encadeada
class Cinto {
public:
    Cinto(int numSlots, int capacidade); // Construtor com número de slots e capacidade total
    ~Cinto();                             // Destrutor
    bool Empty() const;                   // Verifica se o cinto está vazio
    bool Insert(Elemento* item, int pos); // Adiciona um item a um slot disponível
    bool Delete(int pos, Elemento*& item); // Remove um item de um slot específico
    Elemento* obter(int pos) const;      // Retorna o item em uma posição específica
    int obterPesoTotal() const;          // Retorna o peso total dos itens no cinto
    int getCapacidade() const;           // Retorna a capacidade total de peso
    int getSlots() const ;        // Retorna o número de slots
    void exibir() const;   
    

private:
    struct Slot {
        Elemento* item;                  // Ponteiro para o item
        Slot* next;                      // Ponteiro para o próximo slot
    };

    Slot* head;                          // Ponteiro para o primeiro slot
    int pesoTotal;                       // Peso total dos itens
    int capacidade;                      // Capacidade total de peso
    int slots; 
};

#endif // INVENTARIO_H  // Finaliza a guarda de inclusão
