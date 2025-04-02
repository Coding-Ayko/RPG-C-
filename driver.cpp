//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170

#include "cgi.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <fstream>
#include "mapa.h"
#include "personagem.h"
#include "inimigo.h"
#include "inventario.h"
#include "elemento.h"

using namespace std;

void AddArquivoScore(const string& nomeHeroi, EngineMapa& enginemapa){
    fstream adicionaArquivo("high_scores.txt", ios::out | ios::app);
    adicionaArquivo << "Nome: "<< nomeHeroi << ' ' << "Nivel Maximo: "<< enginemapa.getNivelAtual() << ' ' << "Pontuacao Maxima: " << enginemapa.retornarScore() << endl;
    adicionaArquivo.close();
}

void exibirMenuAcao() {
    cout << "" << endl;
    cout << "==========================" << endl;
    cout << "Escolha uma acao:" << endl;
    cout << "1. Mover-se no mapa" << endl;
    cout << "2. Sair" << endl;
    cout << "Digite o numero da acao: "<< endl;
    cout << "==========================" << endl;
    cout << "" << endl;


}

int main() {
    TituloJogo();
    system("cls");  
    Pergaminho();
    system("cls"); 
    Mensagem();
    system("cls"); 
    Menu();
    int opcao;
    cout << "Digite a opcao do menu: ";
    cin >> opcao; // Obtém a opção do menu principal
    switch(opcao) {
        case 1: { // Novo Jogo
            // Configurando o mapa e personagem
            Mapa mapa(5, 5);  // Cria um mapa de 5x5
            string nomeHeroi;
         
            DigiteNome();
            cin >> nomeHeroi;
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            Personagem heroi(nomeHeroi, 100, 20, 5);  // Nome, vida, ataque, defesa
            Inimigo meuInimigo("NomeInimigo", 100, 15, 5); // Cria uma instância de Inimigo 
            EngineMapa engine(mapa, heroi, meuInimigo); // Cria a engine do mapa
            // Define a dificuldade inicial e inicia o nível
            engine.declararDificuldade(1);  // Dificuldade inicial
            cout << "                                                                       Bem-vindo ao RPG, " << nomeHeroi << "! Prepare-se para a aventura!                                                       " << endl;

            while (true) {
                // Menu de ações
                exibirMenuAcao();
                cin >> opcao;
                cout << "Pressione Enter";
                system("cls");
                switch(opcao) {
                    case 1: { // Mover-se no mapa
                    
                    cout << "Score: " << engine.retornarScore() << "                               | Nivel: " << engine.getNivelAtual() << endl;
                    cout <<" ---------------------------------------------------------------------------------------------------------------" << endl;
                    cout <<" " << endl;
                    cout << "    ## ##   ## ##                     |     |                        _______                 _______   " << endl;       
                    cout << "   ##    ####    ##                 /--_____--\\                      |__|__|______     ______|__|__|  " << endl;       
                    cout << "   ##            ##                 |         |                      |     |__|__|_____|__|__|     |   " << endl;       
                    cout << "    ##          ##                 _|  _____  |_                     |  1  |     |__|__|     |  5  |   " << endl;       
                    cout << "     ##        ##                 | | |_____| | |                    \\_____|  2  |     |  4  |_____/  " << endl;       
                    cout << "       ##    ##                   | | |    | | |                          \\_____|  3  |_____/        " << endl;       
                    cout << "         ####                     | | |_____| | |                                \\_____/              " << endl;       
                    cout << "                                  \\ -----------/ " << endl;
                    cout << "Vida: " << heroi.Vida() << endl; 
                    cout <<" " << endl;
                    engine.exibirCinto();
                    cout <<" " << endl;
                    engine.exibirMochila();
                    cout <<" ---------------------------------------------------------------------------------------------------------------" << endl;
                    
                        // Pergunta a direção
                    mapa.exibirMapa(engine.getPosHeroiX(), engine.getPosHeroiY());
                    engine.retornarStatus();
                    cout << "" << endl;
                    engine.mostrarLegenda();
                    string direcao;
                    cout << "Digite uma direcao (norte, sul, esquerda, direita): ";
                    cout << "" << endl;
                        cin >> direcao;
                        system("cls");
                        // Move o herói na direção escolhida
                        if (direcao == "norte") {
                            engine.moverHeroi(0, -1, heroi);
                        } else if (direcao == "sul") {
                            engine.moverHeroi(0, 1, heroi);
                        } else if (direcao == "esquerda") {
                            engine.moverHeroi(-1, 0, heroi);
                        } else if (direcao == "direita") {
                            engine.moverHeroi(1, 0, heroi);
                        } else {
                            cout << "Direcao invalida! Tente novamente." << endl;
                            continue;
                        }
                        break;
                    }
                    case 2: // Sair
                        cout << "Saindo do jogo..." << endl;
                        AddArquivoScore(nomeHeroi, engine);
                        return 0; // Finaliza o jogo
                    default:
                        cout << "Opcao invalida! Tente novamente." << endl;
                        break;
                }

                // Checar condição de Game Over
                if (engine.gameOver()) {
                    VoceMorreu();
                    AddArquivoScore(nomeHeroi, engine);
                    break;
                }
            }
            break;
        }
        case 2:
            Alunos();
            break;
        case 3:
            cout << "Saindo do jogo..." << endl;
            return 0;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
            break;
    }

    return 0;
}




