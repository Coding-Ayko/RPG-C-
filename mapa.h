//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170


// ==================== DEFINIÇÃO DA CLASSE SQM ==================== //
// Classe interna que representa um espaço no mapa. Pode ser vazio, 
// conter um elemento ou um inimigo. O conteúdo do espaço é gerado 
// aleatoriamente.

#ifndef MAPA_H
#define MAPA_H

#include "personagem.h"
#include "inimigo.h"
#include "inventario.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Personagem; // Declaração antecipada
class Inimigo; // Declaração antecipada

class Sqm {
public:
  Sqm();                              // Construtor padrão
  char getSqmType() const;            // Método que retorna o tipo de SQM
  void setSqmType(char newType);      // Método para definir o tipo de SQM
  void generateRandomSqmType();       // Método para gerar um tipo aleatório de SQM

private:
  char sqmType;  // Atributo que armazena o tipo de SQM
};

// Classe Mapa
class Mapa {
public:
  Mapa(int larguraMapa, int alturaMapa); // Construtor que inicializa o mapa
  bool posicaoValida(int x, int y) const; // Verifica se a posição é válida
  void gerarMapa();                      // Gera o caminho fixo no mapa
  void exibirMapa(int posHeroiX, int posHeroiY) const; // Atualize a declaração
  char obterTipoSQM(int x, int y) const; // Obtém o tipo de SQM na posição
  int getLargura();
  int getAltura();
  string obterRepresentacaoSQM(int x, int y) const;


private:
  static const int MAX_LARGURA = 100;    // Limite máximo de largura
  static const int MAX_ALTURA = 100;     // Limite máximo de altura
  int largura, altura;                   // Dimensões do mapa
  Sqm grid[MAX_ALTURA][MAX_LARGURA];     // Grid de SQMs
};

//============== DEFINIÇÃO  ENGENHARIA DE MAPAS E NIVEIS DO JOGO ===========//
// definição da classe EngineMap que vai controlar o mapa, o herói e o progresso pelo mapa. 

class EngineMapa {
public:
  EngineMapa(Mapa& mapa, Personagem& heroi,  Inimigo& inimigo);
  void gerarMapa();                     // Gera o mapa baseado na lógica do jogo
  bool moverHeroi(int dx, int dy, Personagem& personagem);     // Mover o herói
  void retornarStatus();                // Retorna o status do jogo
  void encontrarItem(Mochila& mochila, Cinto& cinto);
  bool gameOver();                      // Verifica se o jogo acabou
  Mapa& getMapa() { return mapa; }      // Método para acessar o mapa
  void mostrarLegenda();
  int getPosHeroiX() const { return posicaoHeroiX; }
  int getPosHeroiY() const { return posicaoHeroiY; }
  bool finalNivel(int posicaoHeroiX, int posicaoHeroiY) const ;
  void reposicionarHeroi(int x, int y);
  void proximoNivel();                  // Avança para o próximo nível
  void declararDificuldade(int nivel);  // Define o nível de dificuldade
  void aumentarScore(int pontos);       // Adiciona pontos à pontuação
  int retornarScore() const;            // Retorna a pontuação atual
  int getNivelAtual() const { return nivelAtual; }  // Método para acessar o nível atual
  void batalhar(Personagem& personagem, Inimigo& inimigo, Mochila& mochila, Cinto& cinto);
  void iniciarBatalha(Personagem& personagem, Mochila& mochila,Cinto& cinto);
  void acessarMochila(Personagem& personagem);
  void manipularCinto(Personagem& personagem);
  void exibirMochila();
  void exibirCinto();
private:
  Mapa& mapa;     
  Personagem& heroi; // Adiciona uma referência ao herói        
  Inimigo& inimigo; // Adiciona uma referência ao herói        
  int posicaoHeroiX;                   // Posição X do herói
  int posicaoHeroiY;                   // Posição Y do herói
  int nivelAtual = 1;                       // Nível atual
  int dificuldade;                      // Dificuldade atual
  int score = 0;                            // Pontuação atual
  Mochila mochila;  // Mochila deve estar definida antes
  Cinto cinto;      // Cinto deve estar definido antes
  
};


#endif // MAPA_H
