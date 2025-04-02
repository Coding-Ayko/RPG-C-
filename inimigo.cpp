//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170

#include "inimigo.h"
#include "mapa.h"
#include <iostream>
using namespace std;


Inimigo::Inimigo(const string& nomeInimigo, int vidaInicial, int forcaInicial, int defesaInicial)
  : nome(nomeInimigo), vida(vidaInicial), forca(forcaInicial), defesa(defesaInicial) {
}

string Inimigo::Nome() const   {
  return nome;
}

int Inimigo::Vida() const {
  return vida;
}

int Inimigo::Forca() const {
  return forca;
}


int Inimigo::Dano() const {
    return dano;
}

// Aplicar dano ao Inimigo -> ADICIONAR NOS ARQUIVOS DE BATALHA
void Inimigo::receberDano(int danoRecebido) {
    int danoFinal = danoRecebido - defesa;
    if (danoFinal > 0) {
        vida -= danoFinal;
        if (vida < 0) vida = 0;
    }
}


void Inimigo::aumentarVida(int pontos) {
    vida += pontos; // Incrementa a vida atual
}


bool Inimigo::estaVivo() const {
  return vida > 0;  // Verifica se o Inimigo ainda está vivo
}




