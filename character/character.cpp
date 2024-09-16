
#include "character.h"
#include "../elements/elements.h" // Corrigido para caminho relativo
#include <iostream>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

Character::Character(const string& characterName, int initialHealth, int initialStrength, int initialDefense)
    : name(characterName), health(initialHealth), strength(initialStrength), defense(initialDefense), x(0), y(0) {}

std::string Character::getName() const {
    return name;
}

int Character::Health() const {
    return health;
}

int Character::Strength() const {
    return strength;
}

int Character::Defense() const {
    return defense;
}

int Character::localX() const {
    return x;
}

int Character::LocalY() const {
    return y;
}

void Character::mUp() {
    y++;
}

void Character::mDown() {
    y--;
}

void Character::mLeft() {
    x--;
}

void Character::mRight() {
    x++;
}

void Character::addCinto(Elemento* item) {
    if (!cinto.cheio()) {
        cinto.adicionar(item);
    } else {
        cout << "Cinto cheio! Não é possível adicionar o item." << std::endl;
    }
}

void Character::addToBackpack(Elemento* item) {
    mochila.adicionar(item);
}

void Character::discardMochila() {
    Elemento* item;
    mochila.remover(item);
    delete item;  // Assume que o item deve ser deletado após ser removido
}

void Character::useCintoItem() {
    cinto.usar();
}

bool Character::isAlive() const {
    return health > 0;
}

int Character::getCurrentCintoWeight() const {
    return cinto.pesoAtual();  // Assume que a função pesoAtual() retorna o peso total dos itens no cinto
}


#endif
