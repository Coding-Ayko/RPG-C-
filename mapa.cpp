// ====================       SEÇÃO DE IMPLEMENTAÇÃO   ==================== //


#include "mapa.h"
// #include "elemento.h" // implementar depois
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef MAPA_H
#define MAPA_H

// ==================== IMPLEMENTAÇÃO DA CLASSE SQM ==================== //

Sqm::Sqm() : tipo('E') {
    srand(time(0));
}

char Sqm::tipoSQM() const {
    return tipo;
}

void Sqm::declararTipoSQM(char novoTipo) {
    tipo = novoTipo;
}

void Sqm::gerarSQMAleatorio() {
    int numAleatorio = rand() % 3;
    switch (numAleatorio) {
        case 0:
            tipo = 'V'; // Vazio
            break;
        case 1:
            tipo = 'E'; // Elemento
            break;
        case 2:
            tipo = 'I'; // Inimigo
            break;
    }
}

// ==================== IMPLEMENTAÇÃO DA CLASSE ENGINE MAP ==================== //

EngenhariaMapa::EngenhariaMapa() : posicaoHeroi(0), nivelAtual(1), dificuldade(1), score(0) {
    gerarMapa(); // Gera o mapa inicial
}

void EngenhariaMapa::declararDificuldade(int nivel) {
    dificuldade = nivel;
    gerarMapa(); // Regenera o mapa baseado na nova dificuldade
}

void EngenhariaMapa::gerarMapa() {
    for (int i = 0; i < TAMANHO_MAPA; ++i) {
        mapa[i].gerarSQMAleatorio(); // Gera conteúdo aleatório para cada Sqm

        // Ajuste o conteúdo com base na dificuldade e no nível
        if (dificuldade > 1) {
            int numAleatorio = rand() % (3 + dificuldade); // Aumenta a gama de tipos de espaço
            switch (numAleatorio) {
                case 0:
                    mapa[i].declararTipoSQM('V');
                    break;
                case 1:
                    mapa[i].declararTipoSQM('E');
                    break;
                default:
                    mapa[i].declararTipoSQM('I');
                    break;
            }
        }
    }
}

void EngenhariaMapa::MoverHeroi() {
    if (posicaoHeroi >= 0 && posicaoHeroi < TAMANHO_MAPA - 1) {
        posicaoHeroi++; // Move o herói para o próximo sqm

        // Aumenta a pontuação ao mover o herói
        aumentarScore(10);

        // Adiciona pontos baseados no tipo de espaço
        char tipoSQM = mapa[posicaoHeroi].tipoSQM();
        if (tipoSQM == 'E') {
            aumentarScore(20); // Exemplo: 20 pontos para encontrar um elemento
        } else if (tipoSQM == 'I') {
            aumentarScore(30); // Exemplo: 30 pontos para derrotar um inimigo
        }

        if (finalNivel(posicaoHeroi)) {
            proximoNivel(); // Avança para o próximo nível se o herói alcançou o fim do nível
        }
    } else {
        cout << "Erro: Movimento fora dos limites do mapa!" << endl;
    }
}

void EngenhariaMapa::proximoNivel() {
    nivelAtual++;
    declararDificuldade(nivelAtual); // Ajusta a dificuldade com base no nível
    posicaoHeroi = 0; // Reinicia a posição do herói para o início do novo nível
}

void EngenhariaMapa::RetornarStatus() const {
    cout << "Posição do Herói: " << posicaoHeroi << endl;
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        cout << "Sqm " << i << ": ";
        switch (mapa[i].tipoSQM()) {
            case 'V':
                cout << "Vazio" << endl;
                break;
            case 'E':
                cout << "Elemento" << endl;
                break;
            case 'I':
                cout << "Inimigo" << endl;
                break;
        }
    }
}

bool EngenhariaMapa::gameOver() const {
    return posicaoHeroi == TAMANHO_MAPA - 1;
}

bool =EngenhariaMapa::finalNivel(int posicao) const {
    // Adapte os pontos de fim de nível conforme a dificuldade ou o nível atual
    if (posicao == TAMANHO_MAPA - 1) {
        return true; // O último espaço do mapa indica o fim do jogo
    }
    // Exemplo simples: mudar o final do nível a cada 10 espaços
    return posicao % (15 + dificuldade) == 0;
    //colocar essa parte aleatória
}

void EngenhariaMapa::aumentarScore(int pontos) {
    score += points; // Adiciona pontos à pontuação
    cout << "Pontuação Atual: " << score << endl;

    // Verifica se a pontuação atingiu um limite para desbloquear algo
    if (score >= 100) { // Exemplo: 100 pontos para desbloquear um bônus
        cout << "Parabéns! Você desbloqueou um bônus!" << endl;
        // Aqui você pode adicionar a lógica para o bônus desbloqueado
    }
}

int EngenhariaMapa::retornarScore() const {
    return score;
}


#endif