//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170

#ifndef INIMIGO_H
#define INIMIGO_H

#include <string>
#include "mapa.h"
#include "elemento.h"
#include "inventario.h"
using namespace std;

class EngineMapa; 

class Inimigo {
public:
    // Construtor
    Inimigo(const string& nomeInimigo, int vida, int forca, int defesa);

    // Metodos de acesso
    string Nome() const; 
    int Vida() const;
    int Forca() const; 
    int Dano() const; //ataque
    void receberDano(int dano); // Aplica dano ao Inimigo
    void aumentarVida(int pontos);

    // Criar funcao para desalocar o Inimigo do Mapa

    //Verificar se o Inimigo esta vivo
    bool estaVivo() const;

private:
    string nome;
    int vida;     // Atributo de vida (corrigido)
    int dano;     // Atributo de dano (corrigido)
    int forca;
    int defesa;
};

#endif