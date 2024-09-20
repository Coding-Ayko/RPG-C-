// #include "elemento.h"  ============ implementar depois
// #include "inventario.h"   ============ implementar depois
#include <string>
// Inclui a definição das classes Mochila e Cinto
using namespace std;  

class Personagem {
private:
    string nome;
    int vida;
    int forca;
    int defesa;
    int x, y;  // Posição no mapa
    //=========implemwntar depois==============//
    // Mochila mochila;  // Pilha estática para itens
    // Cinto cinto;      // Fila dinâmica para itens
    //=========================================//


public:
    // Construtor já inicia com nome 
    Personagem(const string& nomePersonagem, int vidaInicial, int forcaInicial, int defesaInicial);

    // Métodos para acessar as propriedades
    string Nome();
    int Vida();
    int Forca();
    int Defesa();
    int LocalEixoX();
    int LocalEixoY();

    // Movimentação
    void MoverNorte();
    void MoverSul();
    void MoverEsquerda();
    void MoverDireita();

    // Status
    bool estaVivo();

    // IMPLEMENTAR DEPOIS (quando criar o arquivo .h e .cpp de elemento)
    //=========== Interação com elementos (cinto e mochila) =============
    // void addCinto(Elemento* item); // Adiciona um item ao cinto
    // void addMochila(Elemento* item); // Adiciona um item à mochila
    // void discardMochila(); // Remove o item no topo da mochila
    // void useCintoItem(); // Usa o item do cinto (remove e processa)
    // int retornaPesoAtualCinto(); // Verifica o peso atual no cinto
    //=======================================================================

   
};

