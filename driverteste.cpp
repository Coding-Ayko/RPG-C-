//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170

#include <iostream>
#include "inventario.h" // Inclui o seu arquivo de inventário
#include "elemento.h"   // Inclui o arquivo de Elemento
#include "mapa.h"       // Inclui o arquivo de Mapa (se necessário)
#include "personagem.h" // Inclui o arquivo de Personagem (se necessário)

using namespace std;

int main() {
    // Criação de alguns elementos para testes
    Elemento* espada = new Elemento("Espada", 5);
    Elemento* escudo = new Elemento("Escudo", 7);
    Elemento* pocaoVida = new Elemento("Pocao de Vida", 1);
    Elemento* escudoPesado = new Elemento("Escudo Pesado", 10);

    // Testando a Mochila
    Mochila mochila; // Ajuste o tipo se necessário
    mochila.Push(pocaoVida);
    mochila.Push(escudo);
    mochila.Push(espada);

    cout << "Conteudo da Mochila apos insercoes:" << endl;
    mochila.Exibir();  // Exibe o conteúdo da mochila
    // Removendo item da Mochila
    cout << "\nRemovendo o ultimo elemento adicionado"<< endl;
    mochila.Pop(pocaoVida);
    cout << "Conteudo da Mochila apos remocao:" << endl;
    mochila.Exibir();  // Exibe o conteúdo atualizado da mochila

    // Criar cinto e adicionar itens
    Cinto cinto(5, 50); // 5 slots no cinto
    cinto.Insert(espada, 2); // Adiciona espada na posição 0
    cinto.Insert(pocaoVida, 0); // Adiciona poção de vida na posição 2

    // Tentando adicionar um item que excede a capacidade do cinto
    cout << "\nTentando adicionar Escudo Pesado no cinto:" << endl;
    cinto.Insert(escudoPesado, 1); // Tenta adicionar o escudo pesado

    // Exibir conteúdo do cinto
    cout << "\nConteudo do Cinto apos insercoes:" << endl;
    cinto.Exibir();  // Exibe o conteúdo do cinto

    // Tentando inserir um item que excede o peso
    cout << "\nTentando inserir Escudo no cinto (excede capacidade):" << endl;
    cinto.Insert(escudo, 50);  // Este deve falhar devido ao peso

    // Exibindo conteúdo final do Cinto
    cout << "Conteudo final do Cinto:" << endl;
    cinto.Exibir();

    // Liberação de memória
    delete espada;
    delete escudo;
    delete pocaoVida;
    delete escudoPesado;

   return 0;
};