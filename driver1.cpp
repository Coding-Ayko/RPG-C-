#include <iostream>
#include <string>
#include <cstdlib>  // Para usar rand()
#include "mapa.h"
#include "personagem.h"
#include "inventario.h"
#include "elemento.h"

using namespace std;

// Função para simular o encontro de um item
void encontrarItem(Mochila& mochila, Cinto& cinto) {
    int tipo = rand() % 2;  // 0 para Arma, 1 para Poção
    Elemento* itemEncontrado = nullptr;

    if (tipo == 0) {
        // Criando uma arma
        itemEncontrado = new Arma("Espada Longa", 5, 10);
        cout << "Você encontrou uma arma!" << endl;
        cout << "Nome: " << itemEncontrado->getNome() << endl;
        cout << "Peso: " << itemEncontrado->getPeso() << endl;
        // Obter o poder de ataque sem dynamic_cast
        Arma* arma = static_cast<Arma*>(itemEncontrado); // Pode ser usado static_cast aqui
        cout << "Poder de Ataque: " << arma->getPoderAtaque() << endl;
    } else {
        // Criando uma poção
        itemEncontrado = new Pocao("Poção de Cura", 1, 20);
        cout << "Você encontrou uma poção!" << endl;
        cout << "Nome: " << itemEncontrado->getNome() << endl;
        cout << "Peso: " << itemEncontrado->getPeso() << endl;
        // Obter a capacidade de cura sem dynamic_cast
        Pocao* pocao = static_cast<Pocao*>(itemEncontrado); // Pode ser usado static_cast aqui
        cout << "Capacidade de Cura: " << pocao->getCura() << endl;
    }

    // Perguntar onde armazenar o item
    char escolha;
    cout << "Onde você quer guardar esse item? (M para Mochila, C para Cinto): ";
    cin >> escolha;

    if (escolha == 'M' || escolha == 'm') {
        mochila.Push(itemEncontrado);
        cout << "Item guardado na mochila!" << endl;
    } else if (escolha == 'C' || escolha == 'c') {
        int pos;
        cout << "Escolha uma posição para armazenar o item (0 a " << cinto.getSlots() - 1 << "): ";
        cin >> pos;

        if (cinto.Insert(itemEncontrado, pos)) {
            cout << "Item guardado no cinto!" << endl;
        } else {
            cout << "Não foi possível guardar o item no cinto (pode estar cheio ou posição inválida)." << endl;
            delete itemEncontrado; // Limpa se não conseguir armazenar
        }
    } else {
        cout << "Escolha inválida. O item foi descartado." << endl;
        delete itemEncontrado; // Limpa se a escolha for inválida
    }
}

int main() {
    // Configurando o mapa
    Mapa mapa(5, 5); // Cria um mapa de 5x5

    // Solicita o nome do herói
    string nomeHeroi;
    cout << "Digite o nome do seu herói: ";
    getline(cin, nomeHeroi);

    // Cria o personagem com o nome escolhido
    Personagem heroi(nomeHeroi, 100, 10, 5); // Nome, vida, ataque, defesa
    EngineMapa engine(mapa, heroi);

    // Define a dificuldade inicial e inicia o nível
    engine.declararDificuldade(1); // Dificuldade inicial
    cout << "Bem-vindo ao RPG, " << nomeHeroi << "! Prepare-se para a aventura!" << endl;

    // Criar elementos para adicionar na mochila e no cinto
    Elemento espada("Espada de Ferro", 10);
    Elemento escudo("Escudo de Madeira", 15);
    Elemento pocaoVida("Poção de Vida", 2);
    Elemento pocaoMana("Poção de Mana", 1);

    // Adicionando itens à mochila do personagem
    cout << "\nAdicionando itens à mochila..." << endl;
    heroi.addMochila(&espada);
    heroi.addMochila(&escudo);

    // Exibir os itens na mochila
    cout << "Itens na mochila: " << endl;
    heroi.exibirMochila();

    // Adicionando itens ao cinto
    cout << "\nAdicionando itens ao cinto..." << endl;
    heroi.addCinto(&pocaoVida);
    heroi.addCinto(&pocaoMana);

    // Exibir os itens no cinto
    cout << "Itens no cinto: " << endl;
    heroi.exibirCinto();

    // Loop principal do jogo
    while (true) {
        // Exibe o mapa e status do herói
        mapa.exibirMapa(engine.getPosHeroiX(), engine.getPosHeroiY());
        engine.mostrarLegenda();
        engine.retornarStatus();
        cout << "Pontuação atual: " << engine.retornarScore() 
             << " | Nível: " << engine.getNivelAtual() 
             << " | Vida: " << heroi.Vida() << endl;

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
            cout << "Comando inválido! Tente novamente." << endl;
            continue;
        }

        // Interação com mapa - Encontrar item
        if (rand() % 100 < 30) { // 30% de chance de encontrar um item
            cout << "Você encontrou um item!" << endl;
            encontrarItem(heroi.getMochila(), heroi.getCinto());
        }

        // Checar condição de Game Over
        if (engine.gameOver()) {
            cout << "Game Over! Seu herói caiu em batalha." << endl;
            break;
        }
    }

    return 0;
}
