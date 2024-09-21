#include "elementos.h"
//Mochila: Pilha Dinamica

class Mochila {
    public:
        Mochila();                // Construtor
        ~Mochila();               // Destrutor
        bool Empty() const;       // Verifica se a mochila está vazia
        void Push(Elemento* item);  // Push - Adiciona item no topo                    // pega o item da classe elemento
        void Pop(Elemento* &item);   // Pop - Remove item do topo                       // pega o item da classe elemento
        Elemento* topo() const;         // Top - Retorna o item no topo
        void Clear();                  // Remove todos os itens
        int Size() const;            // Retorna o tamanho atual da mochila
    private:
        // Estrutura de nó da pilha (mochila)
        struct MochilaNode {
            Elemento* item;           // Ponteiro para o item armazenado (classe Elemento)
            MochilaNode* next;        // Ponteiro para o próximo nó da pilha
        };

        MochilaNode* topoPilha;  // Ponteiro para o topo da pilha
        int tamanhoAtual;          // Contador de itens na pilha
    };

//Cinto: Lista Estatica
class Cinto {
    public:
        Cinto(int slots, int capacidade);   // Construtor com número de slots e capacidade total
        ~Cinto();                           // Destrutor
        bool Empty() const;                 // Verifica se o cinto está vazio
        bool Insert(Elemento* item);          // Adiciona um item a um slot disponível
        bool Delete(int slotIndex, Elemento* &item); // Remove um item de um slot específico
        Elemento* obter(int slotIndex) const;    // Retorna o item de um slot específico
        int obterPesoTotal() const;         // Retorna o peso total dos itens no cinto
        int getSlots() const;               // Retorna o número total de slots
        int getSlotsUsados() const;         // Retorna o número de slots usados
        int getCapacidade() const;          // Retorna a capacidade total de peso

    private:
        struct Slot {
            Elemento* item;   // Ponteiro para o item
            bool ocupado;     // Indica se o slot está ocupado
        };

        Slot* slots;          // Array de slots
        int tamanho;          // Número total de slots
        int pesoTotal;        // Peso total dos itens
        int capacidade;       // Capacidade total de peso
};
