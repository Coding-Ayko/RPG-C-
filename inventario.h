//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170

#ifndef INVENTARIO_H  
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
    void Exibir();
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
private:
    struct Slot {
        Elemento* item;
        Slot* next;
    };
    Slot* head;
    int pesoTotal;
    int capacidade;
    int slots;
public:
    Cinto(int numeroSlots, int capacidadeTotal);
    ~Cinto();
    bool Empty() const;
    bool Insert(Elemento* item, int pos);
    bool Delete(int pos, Elemento*& item);
    Elemento* obter(int pos) const; 
    int obterPesoTotal() const;
    int getCapacidade() const;
    int getSlots() const;
    void Exibir() const;
    void setPosition(int pos, Slot*& current) const;

};


#endif 
