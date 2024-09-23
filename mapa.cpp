// ====================       SEÇÃO DE IMPLEMENTAÇÃO   ==================== //
#include "mapa.h"
#include "personagem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ==================== IMPLEMENTAÇÃO DA CLASSE SQM ==================== //

Sqm::Sqm() : sqmType('V') {  // Inicializa sqmType como 'V'
  srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios
}

char Sqm::getSqmType() const {
  return sqmType;  // Retorna o valor do tipo de SQM
}

void Sqm::setSqmType(char newType) {
  sqmType = newType;  // Define um novo tipo de SQM
}

void Sqm::generateRandomSqmType() {
  int randomNum = rand() % 3;  // Gera números entre 0 e 2
  static char lastType = '\0'; // Inicialmente sem valor

  do {
    randomNum = rand() % 3;
  } while ((randomNum == 0 && lastType == 'V') ||
    (randomNum == 1 && lastType == 'E') ||
    (randomNum == 2 && lastType == 'I'));

  switch (randomNum) {
    case 0: sqmType = 'V'; break; // Vazio
    case 1: sqmType = 'E'; break; // Elemento
    case 2: sqmType = 'I'; break; // Inimigo
  }

  lastType = sqmType;
}

// ==================== IMPLEMENTAÇÃO DA CLASSE MAPA ==================== //

Mapa::Mapa(int larguraMapa, int alturaMapa)
  : largura(larguraMapa), altura(alturaMapa) {
  if (largura > MAX_LARGURA) largura = MAX_LARGURA;
  if (altura > MAX_ALTURA) altura = MAX_ALTURA;

  srand(static_cast<unsigned int>(time(0)));  // Inicializa o gerador aleatório
  gerarMapa();  // Gera o mapa no momento da criação
}

int Mapa::getLargura() {
  return largura; 
}

int Mapa::getAltura() {
  return altura; 
}

bool Mapa::posicaoValida(int x, int y) const {
  return (x >= 0 && x < largura && y >= 0 && y < altura);
}

void Mapa::gerarMapa() {
  for (int y = 0; y < altura; ++y) {
    for (int x = 0; x < largura; ++x) {
      grid[y][x].generateRandomSqmType();  // Gera SQMs aleatórios
    }
  }
  grid[altura - 1][largura - 1].setSqmType('F'); // Marca o fim do nível
}

void Mapa::exibirMapa(int posHeroiX, int posHeroiY) const {
  for (int y = 0; y < altura; ++y) {
    for (int x = 0; x < largura; ++x) {
      if (x == posHeroiX && y == posHeroiY) {
        cout << "[x] "; // Representa a posição do herói
      } else {
        cout << obterRepresentacaoSQM(x, y) << " "; // Representa o tipo do SQM
      }
    }
    cout << endl;
  }
}

char Mapa::obterTipoSQM(int x, int y) const {
  if (posicaoValida(x, y)) {
    return grid[y][x].getSqmType();
  }
  return '\0'; // Retorna um caractere nulo se a posição for inválida
}

string Mapa::obterRepresentacaoSQM(int x, int y) const {
  char tipo = obterTipoSQM(x, y);
  if (tipo == 'V') return "[]"; // Vazio
  if (tipo == 'E') return "[E]"; // Elemento
  if (tipo == 'I') return "[I]"; // Inimigo
  if (tipo == 'F') return "[F]"; // Fim
  return "[]"; // Caso padrão
}

// ==================== IMPLEMENTAÇÃO DA CLASSE ENGINEMAPA ==================== //

EngineMapa::EngineMapa(Mapa& mapa, Personagem& heroi) : mapa(mapa), heroi(heroi), posicaoHeroiX(0), posicaoHeroiY(0), nivelAtual(1), dificuldade(1), score(0) {}


void EngineMapa::gerarMapa() {
  mapa.gerarMapa();  // Gera o mapa
}

void EngineMapa::reposicionarHeroi(int x, int y) {
    posicaoHeroiX = x;
    posicaoHeroiY = y;
}

void EngineMapa::proximoNivel() {
  nivelAtual++;
  declararDificuldade(nivelAtual);
  dificuldade++; // Pode incrementar a dificuldade, se necessário
  score += 50; // Adiciona um bônus ao score ao completar o nível

  // Aumentar a vida do herói 
  heroi.aumentarVida(20); // Aumenta a vida em 20

  // Gera um novo mapa para o próximo nível
  mapa.gerarMapa(); // Supondo que você tenha um método para gerar um novo mapa

  // Reposiciona o herói na posição inicial
  reposicionarHeroi(0, 0); // Supondo que a posição inicial seja (0, 0)
}

void EngineMapa::declararDificuldade(int nivel) {
  dificuldade = nivel;
} //tau do futuro = verificar a necessidade de proporções de aleatoriedade dos sqm de acordo com o nivel

void EngineMapa::aumentarScore(int pontos) {
  score += pontos;
}

int EngineMapa::retornarScore() const {
  return score;
}


bool EngineMapa::moverHeroi(int dx, int dy) {
  int novaPosX = posicaoHeroiX + dx;
  int novaPosY = posicaoHeroiY + dy;

  // Verifica se a nova posição está dentro dos limites do mapa
  if (novaPosX >= 0 && novaPosX < mapa.getLargura() && novaPosY >= 0 && novaPosY < mapa.getAltura()) {
    posicaoHeroiX = novaPosX;
    posicaoHeroiY = novaPosY; 

    // Obter o tipo de SQM encontrado
    char tipoSQM = mapa.obterTipoSQM(posicaoHeroiX, posicaoHeroiY);
    if (tipoSQM == 'V') {
      cout << "Voce encontrou um espaço vazio!" << endl;
    } else if (tipoSQM == 'E') {
      cout << "Voce encontrou um elemento!" << endl;
      aumentarScore(20); // Aumenta pontuação ao encontrar um elemento
    } else if (tipoSQM == 'I') {
      cout << "Voce encontrou um inimigo!" << endl;
      aumentarScore(30); // Aumenta pontuação ao encontrar um inimigo
    } else if (tipoSQM == 'F') {
      cout << "Voce encontrou o fim do nível!" << endl;
      aumentarScore(50); // Bônus por concluir o nível
      proximoNivel(); // Avança para o próximo nível
      mapa.gerarMapa(); // Gerar um novo mapa para o próximo nível
    }

    return true; // Movimento bem-sucedido
  }

  return false; // Movimento inválido
}



void EngineMapa::retornarStatus() {
  cout << "Score atual: " << score << endl;
  cout << "Posicao do heroi: (" << posicaoHeroiX << ", " << posicaoHeroiY << ")" << endl;
}

bool EngineMapa::gameOver() {
  // temporario
  return (mapa.obterTipoSQM(posicaoHeroiX, posicaoHeroiY) == 'I'); // Jogo acaba se o herói encontra um inimigo
  // trocar pra quando o numero de vida do personagem acabar
}

bool EngineMapa::finalNivel(int posicaoHeroiX, int posicaoHeroiY) const {
    // Define o ponto de fim do nível como o canto inferior direito do mapa
    int fimNivelX = mapa.getLargura() - 1; // Última coluna
    int fimNivelY = mapa.getAltura() - 1;  // Última linha

    // Verifica se a posição do herói corresponde ao fim do nível
    return (posicaoHeroiX == fimNivelX && posicaoHeroiY == fimNivelY);
}

void EngineMapa::mostrarLegenda() {
  cout << "Legenda:" << endl;
  cout << "[ ] - Vazio" << endl;
  cout << "[E] - Elemento" << endl;
  cout << "[I] - Inimigo" << endl;
  cout << "[F] - Fim" << endl;
  cout << "[x] - Posico do Heroi" << endl;
}