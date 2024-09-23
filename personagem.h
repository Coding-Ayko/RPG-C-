#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include "mapa.h"
using namespace std;

class EngineMapa; // Declaração antecipada

class Personagem {
public:
  Personagem(const string& nomePersonagem, int vidaInicial, int forcaInicial, int defesaInicial);

  string Nome();
  int Vida();
  int Forca();
  int Defesa();
  int LocalEixoX();
  int LocalEixoY();

  void MoverNorte(EngineMapa& engine);
  void MoverSul(EngineMapa& engine);
  void MoverEsquerda(EngineMapa& engine);
  void MoverDireita(EngineMapa& engine);
  void aumentarVida(int pontos);

  bool estaVivo() const;

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
};

#endif // PERSONAGEM_H


//=======================================================================
// IMPLEMENTAR DEPOIS (quando criar o arquivo .h e .cpp de elemento)
//=========== Interação com elementos (cinto e mochila) =============
// void addCinto(Elemento* item); // Adiciona um item ao cinto
// void addMochila(Elemento* item); // Adiciona um item à mochila
// void discardMochila(); // Remove o item no topo da mochila
// void useCintoItem(); // Usa o item do cinto (remove e processa)
// int retornaPesoAtualCinto(); // Verifica o peso atual no cinto
//=======================================================================
