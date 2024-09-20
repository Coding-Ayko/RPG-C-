#include "elementos.h" 
// mochila, ela é uma pilha dinamica

class Mochila {
public:
    Mochila();                // Construtor
    ~Mochila();               // Destrutor
    bool vazio() const;       // Verifica se a mochila está vazia
    void adiciona(Elemento* item);  // Push - Adiciona item no topo                    // pega o item da classe elemento
    void remove(Elemento* &item);   // Pop - Remove item do topo                       // pega o item da classe elemento
    Elemento* topo() const;         // Top - Retorna o item no topo
    void limpar();                  // Remove todos os itens
    int tamanho() const;            // Retorna o tamanho atual da mochila
private:
    // Estrutura de nó da pilha (mochila)
    struct MochilaNode {
        Elemento* item;           // Ponteiro para o item armazenado (classe Elemento)
        MochilaNode* next;        // Ponteiro para o próximo nó da pilha
    };
  MochilaNode* topoPilha;  // Ponteiro para o topo da pilha
    int tamanhoAtual;          // Contador de itens na pilha
}

// IMPLEMENTAR cinnto com slots definidos e peso compartilhado  
//TESTAR 
class Cinto {
public:
    Cinto(int slots, int capacidade); // Construtor com número de slots e capacidade total
    ~Cinto();                          // Destrutor
    bool vazio() const;                // Verifica se o cinto está vazio
    bool adicionar(Elemento* item);    // Adiciona um item a um slot disponível
    bool remover(int slotIndex, Elemento* &item); // Remove um item de um slot específico
    Elemento* obter(int slotIndex) const; // Retorna o item de um slot específico
    int obterPesoTotal() const;        // Retorna o peso total dos itens no cinto
    int getSlots() const;              // Retorna o número total de slots
    int getSlotsUsados() const;        // Retorna o número de slots usados
    int getCapacidade() const;         // Retorna a capacidade total de peso

private:
    struct Slot {
        Elemento* item;  // Ponteiro para o item
        bool ocupado;     // Indica se o slot está ocupado
    };

    Slot* slots;          // Array de slots
    int tamanho;         // Número total de slots
    int pesoTotal;       // Peso total dos itens
    int capacidade;      // Capacidade total de peso
};









































// Classe Cinto - Fila Dinâmica
class Cinto {
public:
    Cinto();  // Construtor
    ~Cinto(); // Destrutor
    bool Empty() const;
    void Enqueue(Elemento* item);   // Enqueue - Adiciona item no final da fila
    void Dequeue();                      // Dequeue - Remove e usa o item no início
    void Clear();                    // Remove todos os itens
    int pesoAtual() const;
    bool Full() const;

private:
    struct NoCinto {
        Elemento* item;
        NoCinto* proximo;
    };

    NoCinto* inicio;   // Ponteiro para o início da fila (primeiro item)
    NoCinto* fim;      // Ponteiro para o final da fila (último item)
    int pesoTotal;     // Peso total dos itens no cinto
    static const int CAPACIDADE_PESO = 50;  // Capacidade máxima de peso no cinto
};


