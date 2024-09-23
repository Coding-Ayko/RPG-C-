#include <iostream>
#include <string>
#include "mapa.h"
#include "personagem.h"

using namespace std;

int main() {
  Mapa mapa(5, 5); // Cria um mapa de 5x5

  // Solicita o nome do herói
  string nomeHeroi;
  cout << "Digite o nome do seu heroi: ";
  getline(cin, nomeHeroi);

  // Cria o personagem com o nome escolhido
  Personagem heroi(nomeHeroi, 100, 10, 5); // Nome, vida, ataque, defesa
  EngineMapa engine(mapa, heroi);

  // Define dificuldade e inicia o nível
  engine.declararDificuldade(1); // Dificuldade inicial

  cout << "Bem-vindo ao RPG, " << nomeHeroi << "! Prepare-se para a aventura! (nada na verdade)" << endl;

  while (true) {
    // Exibe o mapa e status
    mapa.exibirMapa(engine.getPosHeroiX(), engine.getPosHeroiY());
    engine.mostrarLegenda();
    engine.retornarStatus();
    cout << "Pontuacao atual: " << engine.retornarScore() << " | Nivel: " << engine.getNivelAtual() << " | Vida: 100" << endl;
    //ver como trazer a vida

    // Recebe o comando de movimento
    string comando;
    cout << "Digite um comando (norte, sul, esquerda, direita) ou 'sair' para encerrar: ";
    cin >> comando;

    if (comando == "sair") {
      cout << "Saindo do jogo..." << endl;
      break;
    } else if (comando == "norte") {
      engine.moverHeroi(0, -1);
    } else if (comando == "sul") {
      engine.moverHeroi(0, 1);
    } else if (comando == "esquerda") {
      engine.moverHeroi(-1, 0);
    } else if (comando == "direita") {
      engine.moverHeroi(1, 0);
    } else {
      cout << "Comando invalido! Tente novamente." << endl;
      continue;
    }

    if (engine.gameOver()) {
      cout << "Game Over! Seu heroi caiu em batalha. ( ainda não temos batalha )" << endl;
      break;
    }
  }

  return 0;
}
