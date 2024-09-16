
#include <string>
#include "../elements/elements.h" // Corrigido para caminho relativo
#include "../inventory/inventory.h"
using namespace std;  // Inclui a definição das classes Mochila e Cinto

class Character {
private:
    string name;
    int health;
    int strength;
    int defense;
    int x, y;  // Posição no mapa
    Mochila mochila;  // Pilha estática para itens
    Cinto cinto;      // Fila dinâmica para itens

public:
    // Construtor
    Character(const string& characterName, int initialHealth, int initialStrength, int initialDefense);

    // Métodos para acessar as propriedades
    string Name() const;
    int Health() const;
    int Strength() const;
    int Defense() const;
    int localX() const;
    int localY() const;

    // Movimentação
    void mUp();
    void mDown();
    void mLeft();
    void mRight();

    // Interação com elementos (cinto e mochila)
    void addCinto(Elemento* item); // Adiciona um item ao cinto
    void addMochila(Elemento* item); // Adiciona um item à mochila
    void discardMochila(); // Remove o item no topo da mochila
    void useCintoItem(); // Usa o item do cinto (remove e processa)

    // Status
    bool isAlive() const;
    int getCurrentCintoWeight() const; // Verifica o peso atual no cinto
};

