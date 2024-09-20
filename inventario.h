#include "elementos.h" 
// Refazer mochila, ela é uma pilha dinamica
class Mochila {
public:
    Mochila();  // Construtor
    bool vazio() const;
    bool cheio() const;
    void adiciona(Elemento* item); // Push - Adiciona item no topo                // pega o item da classe elemento
    void remove(Elemento* &item);  // Pop - Remove item do topo                   // pega o item da classe elemento
    Elemento* topo() const;         // Top - Retorna o item no topo
    void limpar();                  // Remove todos os itens
    int tamanho() const;

private:
    static const int CAPACIDADE = 10;  // Capacidade máxima da pilha (mochila)
    Elemento* itens[CAPACIDADE];       // Array estático para armazenar os elementos
    int topoIndice;                    // Índice do topo da pilha
};

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


