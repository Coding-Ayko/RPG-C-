#include "../elements/elements.h" // Corrigido para caminho relativo

// Classe Mochila - Pilha Estática
class Mochila {
public:
    Mochila();  // Construtor
    bool Empty() const;
    bool Full() const;
    void Push(Elemento* item); // Push - Adiciona item no topo
    void Pop(Elemento* &item);  // Pop - Remove item do topo
    Elemento* Top() const;         // Top - Retorna o item no topo
    void limpar();                  // Remove todos os itens
    int tamanho() const;

private:
    static const int CAPACIDADE = 10;  // Capacidade máxima da pilha (mochila)
    Elemento* itens[CAPACIDADE];       // Array estático para armazenar os elementos
    int topoIndice;                    // Índice do topo da pilha
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


