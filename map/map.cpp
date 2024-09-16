// ====================       SEÇÃO DE IMPLEMENTAÇÃO   ==================== //


#include "map.h"
#include "../elements/elements.h" // Corrigido para caminho relativo
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef MAP_H
#define MAP_H

// ==================== IMPLEMENTAÇÃO DA CLASSE SQM ==================== //

Sqm::Sqm() : type('E') {
    srand(time(0));
}

char Sqm::getType() const {
    return type;
}

void Sqm::setType(char newType) {
    type = newType;
}

void Sqm::generateRandomContent() {
    int randomValue = rand() % 3;
    switch (randomValue) {
        case 0:
            type = 'V'; // Vazio
            break;
        case 1:
            type = 'E'; // Elemento
            break;
        case 2:
            type = 'I'; // Inimigo
            break;
    }
}

// ==================== IMPLEMENTAÇÃO DA CLASSE ENGINE MAP ==================== //

EngineMap::EngineMap() : heroPosition(0), currentLevel(1), difficulty(1), score(0) {
    generateMap(); // Gera o mapa inicial
}

void EngineMap::setDifficulty(int level) {
    difficulty = level;
    generateMap(); // Regenera o mapa baseado na nova dificuldade
}

void EngineMap::generateMap() {
    for (int i = 0; i < MAP_SIZE; ++i) {
        map[i].generateRandomContent(); // Gera conteúdo aleatório para cada Sqm

        // Ajuste o conteúdo com base na dificuldade e no nível
        if (difficulty > 1) {
            int randomValue = rand() % (3 + difficulty); // Aumenta a gama de tipos de espaço
            switch (randomValue) {
                case 0:
                    map[i].setType('V');
                    break;
                case 1:
                    map[i].setType('E');
                    break;
                default:
                    map[i].setType('I');
                    break;
            }
        }
    }
}

void EngineMap::moveHero() {
    if (heroPosition >= 0 && heroPosition < MAP_SIZE - 1) {
        ++heroPosition; // Move o herói para o próximo sqm

        // Aumenta a pontuação ao mover o herói
        increaseScore(10);

        // Adiciona pontos baseados no tipo de espaço
        char sqmType = map[heroPosition].getType();
        if (sqmType == 'E') {
            increaseScore(20); // Exemplo: 20 pontos para encontrar um elemento
        } else if (sqmType == 'I') {
            increaseScore(30); // Exemplo: 30 pontos para derrotar um inimigo
        }

        if (isLevelEnd(heroPosition)) {
            nextLevel(); // Avança para o próximo nível se o herói alcançou o fim do nível
        }
    } else {
        cerr << "Erro: Movimento fora dos limites do mapa!" << endl;
    }
}

void EngineMap::nextLevel() {
    ++currentLevel;
    setDifficulty(currentLevel); // Ajusta a dificuldade com base no nível
    heroPosition = 0; // Reinicia a posição do herói para o início do novo nível
}

void EngineMap::printStatus() const {
    cout << "Posição do Herói: " << heroPosition << endl;
    for (int i = 0; i < MAP_SIZE; ++i) {
        cout << "Sqm " << i << ": ";
        switch (map[i].getType()) {
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

bool EngineMap::gameOver() const {
    return heroPosition == MAP_SIZE - 1;
}

bool EngineMap::isLevelEnd(int position) const {
    // Adapte os pontos de fim de nível conforme a dificuldade ou o nível atual
    if (position == MAP_SIZE - 1) {
        return true; // O último espaço do mapa indica o fim do jogo
    }
    // Exemplo simples: mudar o final do nível a cada 10 espaços
    return position % (10 + difficulty) == 0;
}

void EngineMap::increaseScore(int points) {
    score += points; // Adiciona pontos à pontuação
    cout << "Pontuação Atual: " << score << endl;

    // Verifica se a pontuação atingiu um limite para desbloquear algo
    if (score >= 100) { // Exemplo: 100 pontos para desbloquear um bônus
        cout << "Parabéns! Você desbloqueou um bônus!" << endl;
        // Aqui você pode adicionar a lógica para o bônus desbloqueado
    }
}

int EngineMap::getScore() const {
    return score;
}


#endif