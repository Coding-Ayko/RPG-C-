//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170


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

void Personagem::aumentarVida(int quantidade) {
    vida += quantidade; // Incrementa a vida atual
}

void Personagem::aumentarAtaque(int quantidade) {
  forca += quantidade; 
}


bool Personagem::estaVivo() const {
  return vida > 0;  // Verifica se o personagem ainda está vivo
}


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




