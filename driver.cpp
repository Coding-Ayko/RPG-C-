#include "character/character.h"
#include "elements/elements.h"
#include "inventory/inventory.h"
#include "map/map.h"
#include <iostream>
using namespace std;

int main() {
    // Testando a classe Elemento e suas subclasses

    // Criando alguns elementos
    Elemento* espada = new Arma("Espada", 5, 100, 20);
    Elemento* cura = new Potao("Poção de Cura", 1, 50, 30);
    Elemento* dragao = new Inimigo("Dragão", 100, 0, 50);

    cout << "Teste Elementos:" << endl;
    cout << "Arma: " << espada->getNome() << ", Peso: " << espada->getPeso() 
         << ", Valor: " << espada->getValor() << ", Dano: " << dynamic_cast<Arma*>(espada)->getDano() << endl;
    cout << "Poção: " << cura->getNome() << ", Peso: " << cura->getPeso() 
         << ", Valor: " << cura->getValor() << ", Cura: " << dynamic_cast<Potao*>(cura)->getCura() << endl;
    cout << "Inimigo: " << dragao->getNome() << ", Peso: " << dragao->getPeso() 
         << ", Valor: " << dragao->getValor() << ", Força: " << dynamic_cast<Inimigo*>(dragao)->getForca() << endl;

    // Testando a classe Mochila (Pilha Estática)
    Mochila mochila;
    mochila.Push(espada);
    mochila.Push(cura);
    mochila.Push(dragao);

    cout << "\nTeste Mochila (Pilha Estática):" << endl;
    Elemento* item;
    while (!mochila.Empty()) {
        mochila.Top(item);
        cout << "Item no topo: " << item->getNome() << endl;
        mochila.Pop(item);
    }

    // Testando a classe Cinto (Fila Dinâmica)
    Cinto cinto;
    cinto.Enqueue(espada);
    cinto.Enqueue(cura);
    cinto.Enqueue(dragao);

    cout << "\nTeste Cinto (Fila Dinâmica):" << endl;
    while (!cinto.Empty()) {
        cinto.Dequeue(item);
        cout << "Item removido da fila: " << item->getNome() << endl;
    }

    // Testando a classe EngineMap
    EngineMap mapa;
    mapa.printStatus();

    // Movendo o herói pelo mapa
    cout << "\nMovendo o herói pelo mapa:" << endl;
    while (!mapa.gameOver()) {
        mapa.moveHero();
        mapa.printStatus();
    }

    cout << "\nFim do jogo. Pontuação final: " << mapa.getScore() << endl;

    // Limpeza de memória
    delete espada;
    delete cura;
    delete dragao;

    return 0;
}
