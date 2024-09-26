#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include "mapa.h"
#include "elemento.h"
#include "inventario.h"
using namespace std;

class EngineMapa; 

class Personagem {
public:
    // Construtor
    Personagem(const string& nomePersonagem, int vidaInicial, int forcaInicial, int defesaInicial);

    // Métodos de acesso
    string Nome() const;
    int Vida() const;
    int Forca() const;
    int Defesa() const;
    int Dano() const;
    void receberDano(int dano);   // Aplica dano ao personagem
    int LocalEixoX();
    int LocalEixoY();

    // Métodos de movimento
    void MoverNorte(EngineMapa& engine);
    void MoverSul(EngineMapa& engine);
    void MoverEsquerda(EngineMapa& engine);
    void MoverDireita(EngineMapa& engine);
    void aumentarVida(int pontos);

    // Verifica se o personagem está vivo
    bool estaVivo() const;

    // Interação com inventário (mochila e cinto)
    bool addMochila(Elemento* item);  // Adiciona item na mochila (pilha)
    bool remMochila(Elemento* &item); // Remove o item do topo da mochila
    void exibirMochila();       // Exibe todos os itens na mochila
    bool addCinto(Elemento* item);    // Adiciona item no cinto (lista)
    bool remCinto(int slotIndex, Elemento* &item); // Remove item de um slot do cinto
    void exibirCinto() const;         // Exibe todos os itens no cinto
    Mochila& getMochila() { return mochila; }
    Cinto& getCinto() { return cinto; }

private:
    string nome;
    int vida;     // Atributo de vida (corrigido)
    int dano;     // Atributo de dano (corrigido)
    int forca;
    int defesa;
    int x, y;     // Posição no mapa
    
    // Mochila e cinto
    Mochila mochila;  // Pilha dinâmica para itens
    Cinto cinto;      // Lista estática para itens
};

#endif // PERSONAGEM_H
