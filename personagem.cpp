#include "personagem.h"
#include <iostream>
using namespace std;

Personagem::Personagem(const string& nomePersonagem, int vidaInicial, int forcaInicial, int defesaInicial)
  : nome(nomePersonagem), vida(vidaInicial), forca(forcaInicial), defesa(defesaInicial), x(0), y(0) {}

string Personagem::Nome() {
  return nome;
}

int Personagem::Vida() {
  return vida;
}

int Personagem::Forca() {
  return forca;
}

int Personagem::Defesa() {
  return defesa;
}

int Personagem::LocalEixoX() {
  return x;
}

int Personagem::LocalEixoY() {
  return y;
}

void Personagem::MoverNorte(EngineMapa& engine) {
  if (y > 0) {
    y--;  
  } else {
    cout << "Movimento invalido! Fim do mapa." << endl;
  }
}

void Personagem::MoverSul(EngineMapa& engine) {
  if (y < engine.getMapa().getAltura() - 1) {
    y++;
  } else {
    cout << "Movimento invalido! Fim do mapa." << endl;
  }
}

void Personagem::MoverEsquerda(EngineMapa& engine) {
  if (x > 0) {
    x--;
  } else {
    cout << "Movimento invalido! Fim do mapa." << endl;
  }
}

void Personagem::MoverDireita(EngineMapa& engine) {
  if (x < engine.getMapa().getLargura() - 1) {  
    x++;  
  } else {
    cout << "Movimento invalido! Fim do mapa." << endl;
  }
}

void Personagem::aumentarVida(int pontos) {
    vida += pontos; // Incrementa a vida atual
}


bool Personagem::estaVivo() const {
  return vida > 0;  // Verifica se o personagem ainda está vivo
}



// O CODIGO ESTÁ FUNCIONANDO SEM A IMPLEMENTAÇÃO DE MOCHILA E CINTO
//CUIDADO AO DESCOMENTAR

//============================================================================================//
// IMPLEMENTAR DEPOIS (quando criar o arquivo .h e .cpp de elemento)
//==============Interação com elementos (cinto e mochila) ==================//
// void Personagem::addCinto(Elemento* item) {
//     if (!cinto.cheio()) {
//         cinto.adicionar(item);
//     } else {
//         cout << "Cinto cheio! Não é possível adicionar o item." << endl;
//     }
// }
//mochila não tem limite, por isso não tem verificação de cheio 
// void Personagem::addMochila(Elemento* item) {
//     mochila.adicionar(item);
// }

//pensar numa validação para retornar ao usuário para caso a alocação dê certo

// void Personagem::DescartarItemMochila() {
//     Elemento* item;
//     mochila.remover(item);
//     delete item;  // o item deve ser deletado após ser removido
// }

// void Personagem::DescartarItemCinto() {
//     cinto.usar();
// }

// int Personagem::retornaPesoAtualCinto() const {
//     return cinto.pesoAtual();  //a função pesoAtual() retorna o peso total dos itens no cinto
// }
//==========================================================================================//