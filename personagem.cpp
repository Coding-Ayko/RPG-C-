#include "personagem.h"
#include "mapa.h"
#include <iostream>
using namespace std;


Personagem::Personagem(const string& nomePersonagem, int vidaInicial, int forcaInicial, int defesaInicial)
  : nome(nomePersonagem), vida(100), forca(forcaInicial), defesa(defesaInicial), x(0), y(0),
    mochila(), cinto(5, 50) {  
}

string Personagem::Nome() const   {
  return nome;
}

int Personagem::Vida() const {
  return vida;
}

int Personagem::Forca() const {
  return forca;
}

int Personagem::Defesa() const {
  return defesa;
}

int Personagem::Dano() const {
    return dano;
}

// Aplicar dano ao personagem -> ADICIONAR NOS ARQUIVOS DE BATALHA
void Personagem::receberDano(int danoRecebido) {
    int danoFinal = danoRecebido - defesa;
    if (danoFinal > 0) {
        vida -= danoFinal;
        if (vida < 0) vida = 0;
    }
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


bool Personagem::addMochila(Elemento* item) {
    if (item) {
        mochila.Push(item);
        return true;
    }
    return false;
}

bool Personagem::remMochila(Elemento* &item) {
    if (!mochila.Empty()) {
        mochila.Pop(item);
        return true;
    }
    return false;
}

// void Personagem::exibirMochila() {
//     if (mochila.Empty()) {
//         cout << "Mochila vazia." << endl;
//     } else {
//         // Aqui você poderia implementar a lógica para exibir os itens da mochila.
//         // Sugiro iterar sobre a pilha, exibindo os itens.
//         Elemento* itemAtual = mochila.topo();
//         while (itemAtual) {
//             cout << itemAtual->getNome() << endl; // Supondo que Elemento tenha um método getNome()
//             itemAtual = itemAtual->getNext(); // Se houver um método para obter o próximo item
//         }
//     }
// }

void Personagem::exibirMochila() {
    mochila.exibir(); // Chama o método de exibir da própria classe Mochila
}

bool Personagem::addCinto(Elemento* item) {
    int pos = 0; // Defina a posição desejada. Pode ser calculada de outra maneira.
    return cinto.Insert(item, pos);
}

bool Personagem::remCinto(int slotIndex, Elemento* &item) {
    return cinto.Delete(slotIndex, item);
}

void Personagem::exibirCinto() const {
    cinto.exibir(); // Se o método `exibir` de `Cinto` já exibe os itens corretamente
}
