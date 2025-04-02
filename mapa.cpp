//tauane carolina - 2194892
//Amanda -2217509
//Julio Fabio - 2165170


// ====================       SEcao DE IMPLEMENTAcao   ==================== //
#include "mapa.h"
#include "personagem.h"
#include "inimigo.h"
#include "inventario.h"
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
  gerarMapa();  // Gera o mapa no momento da criacão
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
        cout << "[x] "; // Representa a posicão do herói
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
  return '\0'; // Retorna um caractere nulo se a posicão for invalida
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

EngineMapa::EngineMapa(Mapa& mapa, Personagem& heroi, Inimigo& inimigo) 
    : mapa(mapa), heroi(heroi), inimigo(inimigo), posicaoHeroiX(0), posicaoHeroiY(0), 
      nivelAtual(1), dificuldade(1), score(0), 
      cinto(5, 80) {} 


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
  dificuldade++; // Pode incrementar a dificuldade, se necessario
  score += 50; // Adiciona um bônus ao score ao completar o nível

  // Aumentar a vida do herói 
  heroi.aumentarVida(20); // Aumenta a vida em 20

  // Gera um novo mapa para o próximo nível
  mapa.gerarMapa(); // Supondo que voce tenha um mehtodo para gerar um novo mapa

  // Reposiciona o herói na posicão inicial
  reposicionarHeroi(0, 0); // Supondo que a posicão inicial seja (0, 0)
}

void EngineMapa::declararDificuldade(int nivel) {
  dificuldade = nivel;
} //tau do futuro = verificar a necessidade de proporcões de aleatoriedade dos sqm de acordo com o nivel

void EngineMapa::aumentarScore(int pontos) {
  score += pontos;
}

int EngineMapa::retornarScore() const {
  return score;
}



void Esqueleto(){
    
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                           .----------------------------                                                                                           " << endl; 
    cout << "                                                                                           :%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                                                                           " << endl;
    cout << "                                                                                        :--=****************************---:                                                                                       " << endl;
    cout << "                                                                                        *%%#::::::::::::::::::::::::::::%%%=                                                                                       " << endl;
    cout << "                                                                                    .---++++::::::::::::::::::::::::::::+++=---                                                                                    " << endl; 
    cout << "                                                                                    :%%%-::::::::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%=--::::::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+==-:::::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+==----::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======::::::::::::::::::::::::::::+%%%                                                                                    " << endl; 
    cout << "                                                                                    :%%%+======::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======::::::::::::::::::::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======::::******+::::::::::=******#%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======:::-%%%%%%#::::::::::+%%%%%%%%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======:::-%%%%%%#::::::::::+%%%%%%%%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======:::-%%%%%%#::::::::::+%%%%%%%%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======::::======-:::=***:::-======*%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+======::::::::::::::*%%%::::::::::+%%%                                                                                    " << endl;
    cout << "                                                                                    .:::*##*===----::::::::::----:::::::***=:::                                                                                    " << endl;
    cout << "                                                                                        *%%#======-:::::::::::::::::::::%%%=                                                                                       " << endl; 
    cout << "                                                                                        .::-##########=:::###=:::###=:::%%%=                                                                                       " << endl;
    cout << "                                                                                           :%%%%%%%%%%=::-%%%=:::%%%+:::%%%=                                                                                       " << endl;
    cout << "                                                                                        +###%%%+======*###%%%####%%%####%%%=                                                                                       " << endl;
    cout << "                                                                                        *%%%%%%+======*%%%%%%%%%%%%%%%%%%%%=                                                                                       " << endl;
    cout << "                                                                                    :###-::::::-======--------------*%%%:::=###                                                                                    " << endl;
    cout << "                                                                                    :%%%-......-======::::::::::::::+%%%...=%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%=---...*%%#===::::::::::::::+%%%---*%%%                                                                                    " << endl;
    cout << "                                                                                    :%%%+==-...*%%#===::::::::::::::+%%%===*%%%                                                                                    " << endl;
    cout << "                                                                                        *%%%%%%+======::::::::::::::+%%%%%%=                                                                                       " << endl;  
    cout << "                                                                                        *%%%%%%+======::::::::::::::+%%%%%%=                                                                                       " << endl;  
    cout << "                                                                                           :%%%+===%%%%%%%%%%%%%%:::+%%%                                                                                           " << endl;
    cout << "                                                                                           :%%%+===%%%%%%%%%%%%%%:::+%%%                                                                                           " << endl;
    cout << "                                                                                           :%%%+===%%%-      +%%%:::+%%%                                                                                           " << endl;
    cout << "                                                                                           :%%%+===%%%-      +%%%:::+%%%                                                                                           " << endl;
    cout << "                                                                                           :%%%+===%%%-      +%%%:::+%%%                                                                                           " << endl;
    cout << "                                                                                           :%%%+==+%%%-      +%%%---*%%%                                                                                           " << endl;
    cout << "                                                                                           :%%%%%%%%%%-      +%%%%%%%%%%                                                                                           " << endl;
    cout << "                                                                                           :##########:      =#########*                                                                                           " << endl; 
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                                                                                                                                                   " << endl; 
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  
}

void Cavaleiro(){
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                                                                                                                                   " << endl;
    cout << "                                                                                 .=========.                                                                                                                       " << endl;
    cout << "                                                                                 :@@@@@@@@@:                                                                                                                       " << endl;
    cout << "                                                                              :++*#########++++++++++++++++++++++.                                                                                                 " << endl;
    cout << "                                                                              =@@%*********%@@@@@@@@@@@@@@@@@@@@@:                                                                                                 " << endl;
    cout << "                                                                          -***#########***%@@####%%#***%%#+++#%#***:                                                                                               " << endl;
    cout << "                                                                          +@@%**#%%%%%%***%@@#***##*+++###---###@@@-                                                                                               " << endl;
    cout << "                                                                          +@@%##%@@@@@@%%%#**+++*##*+++###===###+==*##=     :###                                                                                   " << endl;
    cout << "                                                                          +@@%%%%@@@@@@@@@***+++*##*+++###+++###=--#@@=     :@@%                                                                                   " << endl;
    cout << "                                                                          +@@%%%%@@@@@@+++%@@#**++++++++++++++++===#@@=  -%%#::-%%%.                                                                               " << endl;
    cout << "                                                                          +@@%%%%@@@@@@+++%@@#**+++++++++++++++++++#@@=  -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                             =@@#  .@@@***+++%@@@@@@@@@@@@@@@@@@@@@-     -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                             -%%*  .@@@***+++#%%%%%%%%%%%%%%%@@@%%%-     -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                                   .@@@+++***=---------------@@@:        -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                                   .@@@+++***=---------------@@@:        -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                                   .@@@###***=--=**=::::::***@@@:        -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                                   .@@@***+++=--=**=::::::***@@@:        -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                                   .@@@++++++---=**+---:::***@@@:        -@@#..:@@@.                                                                               " << endl;
    cout << "                                                                                   .+++*##***=======---:::===@@@:        -@@#:::@@@.                                                                               " << endl;
    cout << "                                                                                       @@@###+++=------::::::%@@:        -@@#::-@@@.                                                                               " << endl;
    cout << "                                                                                .++++++@@@%%%###+======------@@@*+++++-  -@@#::-@@@.                                                                               " << endl;
    cout << "                                                                                :@@@@@@@@@@@@@@@#+++++=------@@@@@@@@@=  -@@#::-@@@.                                                                               " << endl;
    cout << "                                                                             -******+++++++++%@@#************@@@***++++**#@@#::-@@@.                                                                               " << endl;
    cout << "                                                                             =@@%=+=---------#@@%############@@@+++=--*@@@@@#::-@@@.                                                                               " << endl;
    cout << "                                                                             =@@%***===---#%%***++++++++++===@@@***+==#@@@@@#::-@@@.                                                                               " << endl;
    cout << "                                                                             =@@%###+++---%@@*+++++++++++=---@@@***+++#@@@@@#::-@@@.                                                                               " << endl;
    cout << "                                                                              ..-@@@%%%%%%@@@###***++++++=---===%@@%%%%@@%###++****%%%:                                                                            " << endl;
    cout << "                                                                                :@@@%%%%%%@@@###***++++++=------%@@@%%@@@%###******%@@:                                                                            " << endl;
    cout << "                                                                                :@@@%%%%%%#########****++=------#%%%%%%@@@@@%---@@@.                                                                               " << endl;
    cout << "                                                                             ...-@@@%%%%%%#########****+++------#%%%%%%@@@@@%---@@@.                                                                               " << endl;
    cout << "                                                                             =@@@@@@@@@@@@@@@@@@%######@@@+++---%@@%%%%%%%@@%---@@@.                                                                               " << endl;
    cout << "                                                                             =@@@%%%%%%%%%%%%@@@%######%%%***+==*##%%%%%%%@@%===@@@.                                                                               " << endl;
    cout << "                                                                             =@@%###*********%@@@@@@@@%+++@@@@@@:  *@@@@@@@@%###@@@.                                                                               " << endl;
    cout << "                                                                             =@@%###*********%@@@%%%%%#+++###@@@:  =*********%%#***.                                                                               " << endl;
    cout << "                                                                             =@@%###*********%@@%##****++=---@@@:           :@@%                                                                                   " << endl;
    cout << "                                                                             =@@%###*********%@@%##*++++++---@@@:           .++=                                                                                   " << endl;
    cout << "                                                                             =@@%###*********%@@%##*+++***---@@@:                                                                                                  " << endl;
    cout << "                                                                             =@@@###***######%@@%##*+++******@@@:                                                                                                  " << endl;
    cout << "                                                                             =@@@%%#***######%@@%##*******@@@@@@:                                                                                                  " << endl;
    cout << "                                                                             =@@@%%#***######%@@%%%####%#%@@@%%%***:                                                                                               " << endl;
    cout << "                                                                             =@@@%%#***######%@@@%%%###%%%%%%%%%@@@-                                                                                               " << endl;
    cout << "                                                                             .::=@@%***###%@@%%%%%%%%%%%%%%%%%%%@@@-                                                                                               " << endl;
    cout << "                                                                                :@@@***###@@@%%%%%%%%%%%%%%%%%%%@@@-                                                                                               " << endl;
    cout << "                                                                                ..:@@@@@@%%%*++#%%@@@@%%%%%%+++===#%%=                                                                                             " << endl;
    cout << "                                                                                  .@@@@@@%%%*++#%%%@@@%%%%%%+++---#@@=                                                                                             " << endl;
    cout << "                                                                                  .@@@%%%+++=--*@@+  :@@@@@@+++---#@@=                                                                                             " << endl;
    cout << "                                                                                  .@@@%%%+++===*%%+  :@@@%%%+=====*%%=                                                                                             " << endl;
    cout << "                                                                                  .@@@++++++%@@=     :@@@+++---%@@-                                                                                                " << endl;
    cout << "                                                                               .::-%%%++++***##-     :@@@+++===%@@-                                                                                                " << endl;
    cout << "                                                                               :@@@###***%@@-        :@@@###***%@@-                                                                                                " << endl;
    cout << "                                                                               :@@@###***%%%+--:     :@@@###***%%%+--:                                                                                             " << endl;
    cout << "                                                                               :@@@#########%@@=     :@@@#########%@@=                                                                                             " << endl;
    cout << "                                                                               .+++==========++:     .+++==========++:                                                                                             " << endl;
    cout << "                                                                                                                                                                                                                   " << endl; 
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Espada() {
    cout << "                                                                      ---...\n";
    cout << "                                                                   .-:===:::::\n";
    cout << "                                                                 ::-==-:-++=-.\n";
    cout << "                                                              ...++=::====++=\n";
    cout << "                                                              -=+::===+++=++=\n";
    cout << "                                                           .++--=--+++--**.:.\n";
    cout << "                                           +++=         ===-=--+++::**=::\n";
    cout << "                                          .****+      :---==:-++--+*+--.\n";
    cout << "                                          -*#**#*+  -:-==:-++==+*+-=:\n";
    cout << "                                            -##**+::++-:=+===*+===\n";
    cout << "                                            +##*###+:-===++==+*.\n";
    cout << "                                            #######+==++=-**-\n";
    cout << "                                             .###*#**=-=**\n";
    cout << "                                           -==###*###%#-\n";
    cout << "                                        .--*###########=\n";
    cout << "                                   .==--+#######-+#####%#.\n";
    cout << "                                   =#########++- :%%%%###*+\n";
    cout << "                                   *######***     .::-###%*\n";
    cout << "                                  .%######-          .%%%%=\n";
    cout << "                                  -#%%%%%#.\n";
    cout << "                                      \n";
    cout << "                              \n";
}

void PocaoA() {
    cout << "                                                                        -==============.\n";
    cout << "                                                                        -==============.\n";
    cout << "                                                                    ....:--------------:....\n";
    cout << "                                                                   .....:--------------:::::\n";
    cout << "                                                                   .....:--------------:::::\n";
    cout << "                                                                   .::::=**************:::::\n";
    cout << "                                                                   .::::=**************:::::\n";
    cout << "                                                                    ....:----:::::=++++.....\n";
    cout << "                                                                        .::::.    -====.\n";
    cout << "                                                                        .::::.    -====.\n";
    cout << "                                                                        .::::.    -====.....\n";
    cout << "                                                                        .::::.    -====.....\n";
    cout << "                                                                   ......         .::::-====\n";
    cout << "                                                                   .....          .....=====.\n";
    cout << "                                                                   .:::::....:::::-----+++++:::::\n";
    cout << "                                                              .....-====-----+**************=====.\n";
    cout << "                                                               ....-====-----+**************=====.\n";
    cout << "                                                          ....-****=----=====+*******************=====.\n";
    cout << "                                                          ....-****+----=====+*******************=====.\n";
    cout << "                                                          ....-****+----=====+*********+++++*****=====.\n";
    cout << "                                                          ....-****=----=====**********=====*****=====.\n";
    cout << "                                                          ....-****=----=====**********=====*****=====.\n";
    cout << "                                                         .::::=****+====+**************=----*****=====.\n";
    cout << "                                                         .::::=****+====+**************-----*****=====.\n";
    cout << "                                                         .----=*****+++++**************-----*****=====.\n";
    cout << "                                                         :====+************************=----*****=====.\n";
    cout << "                                                         :====+************************=----*****=====.\n";
    cout << "                                                              :====+**************=----*****=====.\n";
    cout << "                                                              :====+**************=----*****=====.\n";
    cout << "                                                              .::::=++++++++++++++=====+++++:::::\n";
    cout << "                                                                   :========================\n";
    cout << "                                                                   :========================\n";
}

void Tesouro(){
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                                  -----------------------------------------                                                                                         " << endl;
                cout << "                                                                                   \\                                       \\                                                                                       " << endl;
                cout << "                                                                                    \\                                       \\                                                                                      " << endl;
                cout << "                                                                                     \\                                       \\                                                                                     " << endl;
                cout << "                                                                                      \\                                       \\                                                                                    " << endl;
                cout << "                                                                                       ----------------------------------------                                                                                    " << endl;
                cout << "                                                                                      /|                                      /|                                                                                   " << endl;
                cout << "                                                                                     / |                                     / |                                                                                   " << endl;
                cout << "                                                                                    /  |   APENAS UM POUCO DE SUJEIRA       /  |                                                                                   " << endl;
                cout << "                                                                                   /   |            .....                  /   |                                                                                   " << endl;
                cout << "                                                                                  |----------------------------------------|   |                                                                                   " << endl;
                cout << "                                                                                  |                                        |   |                                                                                   " << endl;
                cout << "                                                                                  |                                        |   /                                                                                   " << endl;
                cout << "                                                                                  |                                        |  /                                                                                    " << endl;
                cout << "                                                                                  |                                        | /                                                                                     " << endl;
                cout << "                                                                                  |----------------------------------------|/                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                             NO ESPACO VAZIO VOCE PODE ACESSAR SUA MOCHILA E CINTO! "<< endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "                                                                                                                                                                                                                   " << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}    

void Coaracao(){

    cout << "                                                                                                                    " << endl;
    cout << "    ######    ######      " << endl;
    cout << "   ##     ####      ##      " << endl;
    cout << "   ##               ##        " << endl;
    cout << "    ##            ##         " << endl;
    cout << "      ##         ##          " << endl;
    cout << "        ##     ##               " << endl;
    cout << "          #####                  " << endl;
  
}

void MochilaDesenho(){
    cout << "            -----                 " << endl;
    cout << "           |     |        " << endl;
    cout << "         /--_____--\\                " << endl;
    cout << "         |         |            " << endl;
    cout << "        _|  _____  |_        " << endl;
    cout << "       | | |_____| | |            " << endl;
    cout << "       | | |  0  | | |            " << endl;
    cout << "       | | |_____| | |             " << endl;
}

void CintoDesenho(){
    cout << "                                                                " << endl;
    cout << "                            _______                 _______    " << endl;
    cout << "                             |__|__|______     ______|__|__|   " << endl;
    cout << "                            |     |__|__|_____|__|__|     |    " << endl;
    cout << "                            |  1  |     |__|__|     |  5  |    " << endl;
    cout << "                             \\_____|  2  |     |  4  |_____/   " << endl;
    cout << "                                  \\_____|  3  |_____/         " << endl;
    cout << "                                        \\_____/                " << endl;
}




bool EngineMapa::moverHeroi(int dx, int dy, Personagem& personagem) {
  int novaPosX = posicaoHeroiX + dx;
  int novaPosY = posicaoHeroiY + dy;

  // Verifica se a nova posição esta dentro dos limites do mapa
  if (novaPosX >= 0 && novaPosX < mapa.getLargura() && novaPosY >= 0 && novaPosY < mapa.getAltura()) {
    posicaoHeroiX = novaPosX;
    posicaoHeroiY = novaPosY; 
    char tipoSQM = mapa.obterTipoSQM(posicaoHeroiX, posicaoHeroiY);

    if (tipoSQM == 'V') {
      cout << "Voce encontrou um espaco vazio!" << endl;
      Tesouro();
      cout <<" ==========================" << endl;
      cout << "Escolha uma acao:\n1. Acessar mochila\n2. Manipular cinto\n3. Sair\nDigite o numero da acao: ";
      cout <<" ==========================" << endl;
      int p;
      cin >> p;

      switch (p) {
    case 1:
        acessarMochila(personagem);
        break;
      case 2:
        manipularCinto(personagem);
        break;
      case 3:
        cout << "Saindo..." << endl;
        break;
      default:
        cout << "Opcao invalida!" << endl;
        break;
      }
  } else if (tipoSQM == 'E') {
    cout <<" =========================" << endl;
    cout << "Voce encontrou um elemento!" << endl;
    aumentarScore(20);
    encontrarItem(mochila, cinto);
  } else if (tipoSQM == 'I') {
    cout <<" =========================" << endl;
    cout << "Voce encontrou um inimigo!" << endl;
    iniciarBatalha(heroi, mochila, cinto);
    aumentarScore(30);
  } else if (tipoSQM == 'F') {
    cout << "Voce encontrou o fim do nivel! Parabens voce sobreviveu ate aqui!" << endl;
    aumentarScore(50);
    proximoNivel();
    mapa.gerarMapa();
  }

    return true; // Movimento bem-sucedido
  }

  return false; // Movimento invalido
}

void EngineMapa::acessarMochila(Personagem& personagem) {
  if (mochila.Empty()) {
    cout << "Sua mochila esta vazia! Haha, volte mais tarde!" << endl;
  } else {
    Elemento* itemDaMochila;
    mochila.Top(itemDaMochila);  // Acessa o item no topo da mochila
    MochilaDesenho();
    if (itemDaMochila != nullptr) {
      cout << "O item no topo da sua mochila eh: " << itemDaMochila->getNome() << endl;
      cout << "============================="<< endl;
      int mochilaop;
      cout << "Escolha uma acao:\n1. Usar item\n2. Descartar item\n3. Cancelar\nDigite o numero da acao: " << endl;
      cout << "============================="<< endl;
      cin >> mochilaop;
      system("cls");
      
   
      switch (mochilaop) {
        case 1:
          if (Pocao* pocao = dynamic_cast<Pocao*>(itemDaMochila)) {
            PocaoA();
            cout << "Usando pocao! Recuperando " << pocao->getCura() << " pontos de vida." << endl;
            personagem.aumentarVida(pocao->getCura());
            cout << "Vida atual: " << personagem.Vida() << endl;
            mochila.Pop(itemDaMochila);
          } else if (Arma* arma = dynamic_cast<Arma*>(itemDaMochila)) {
            cout << "Equipando arma! Aumentando ataque em " << arma->getPoderAtaque() << " pontos." << endl;
            personagem.aumentarAtaque(arma->getPoderAtaque());
            cout << "Poder de ataque atual: " << personagem.Forca() << endl;
            mochila.Pop(itemDaMochila);
          }
          break;
      case 2:
        mochila.Pop(itemDaMochila);
          cout << "Voce descartou: " << itemDaMochila->getNome() << endl;
          delete itemDaMochila; 
      break;
      case 3:
        cout << " Operacao cancelada, seu elemento continua como esta..." << endl;
        break;
      default:
        cout << "Opcao invalida!" << endl;
        break;
      }
    }
  }
}

void EngineMapa::manipularCinto(Personagem& personagem) {
  if (cinto.Empty()) {
    cout << "Seu cinto esta vazio! Adicione alguns itens e retorne!" << endl;
  } else {
    CintoDesenho();
    cout << "Itens no cinto:" << endl;
    cinto.Exibir();

    char escolha;
    do {
      cout << "Deseja usar um item (u) ou descartar (d)? ";
      cin >> escolha;
      escolha = tolower(escolha);
    } while (escolha != 'u' && escolha != 'd');

    int indiceItem;
    cout << "Escolha o numero do item: ";
    cin >> indiceItem;

    if (indiceItem >= 0 && indiceItem < cinto.getSlots()) {
        Elemento* item;
        if (escolha == 'd') {
            if (cinto.Delete(indiceItem, item)) {
                cout << "Voce descartou o item: " << item->getNome() << endl;
                delete item;  // Libera a memória
            } else {
                cout << "Nao foi possível descartar o item." << endl;
            }
        } else if (escolha == 'u') {
            item = cinto.obter(indiceItem);
            if (item) {
                cout << "Voce usou o item: " << item->getNome() << endl;
                
                // Lógica para usar o item
                if (Pocao* pocao = dynamic_cast<Pocao*>(item)) {
                    cout << "Usando pocao! Recuperando " << pocao->getCura() << " pontos de vida." << endl;
                    personagem.aumentarVida(pocao->getCura());
                    cout << "Vida atual: " << personagem.Vida() << endl;
                } else if (Arma* arma = dynamic_cast<Arma*>(item)) {
                    cout << "Equipando arma! Aumentando ataque em " << arma->getPoderAtaque() << " pontos." << endl;
                    personagem.aumentarAtaque(arma->getPoderAtaque());
                    cout << "Poder de ataque atual: " << personagem.Forca() << endl;
                }
            } else {
                cout << "Nao foi possível usar o item." << endl;
            }
        }
    } else {
      cout << "indice invalido!" << endl;
    }
  }
}

void EngineMapa::encontrarItem(Mochila& mochila, Cinto& cinto) {
  Arma armas[] = {
    Arma("Adaga da Sombra Efemera", 3, 8),
    Arma("Espada Elemental", 7, 14),
    Arma("Arma Eboby", 2, 4),
    Arma("Espadas do Caos", 3, 12),
    Arma("Monster Killer", 5, 18),
    Arma("Lamina Oculta", 1, 4),
    Arma("Pocao da Furia", 2, 8), //8 na forca
    Arma("Pocao Ressonancia ", 1, 15) // da vida
  };

  Pocao pocoesCura[] = {
    Pocao("Pocao Minguante", 1, 8), //8 na forca
    Pocao("Pocao Calice do Renascimento", 1, 15) // da vida
  };

  int tipo = rand() % 2;  // 0 para Arma, 1 para Pocao
  Elemento* itemEncontrado = nullptr;

  if (tipo == 0) {
    // Criando uma arma aleatória
    int indiceArma = rand() % (sizeof(armas) / sizeof(armas[0]));
    itemEncontrado = new Arma(armas[indiceArma]);
    cout << "Seu achado eh.... uma arma!" << endl;
    Espada();
  } else {
    // Criando uma pocao aleatória
    int indicePocao = rand() % (sizeof(pocoesCura) / sizeof(pocoesCura[0]));
    itemEncontrado = new Pocao(pocoesCura[indicePocao]);
    cout << "Seu achado eh.... uma pocao!" << endl;
    PocaoA();
  }

  // Exibir detalhes do item encontrado
  cout << "Nome: " << itemEncontrado->getNome() << endl;
  cout << "Peso: " << itemEncontrado->getPeso() << endl;

  if (tipo == 0) {
    Arma* arma = static_cast<Arma*>(itemEncontrado);
    cout << "Poder de Ataque: " << arma->getPoderAtaque() << endl;
  } else {
    Pocao* pocao = static_cast<Pocao*>(itemEncontrado);
    cout << "Capacidade de Cura: " << pocao->getCura() << endl;
  }

  // Perguntar onde armazenar o item
  char escolha;
  cout << "Onde voce quer guardar esse item? (M para Mochila, C para Cinto, D para Descartar): ";
  cin >> escolha;

  if (escolha == 'M' || escolha == 'm') {
    mochila.Push(itemEncontrado);
    MochilaDesenho();
    mochila.Exibir();  // Exibe o conteúdo da mochila
  } else if (escolha == 'C' || escolha == 'c') {
    int pos;
    cout << "Escolha uma posicao para armazenar o item (0 a " << cinto.getSlots() - 1 << "): ";
    CintoDesenho();
    cin >> pos;

    cinto.Insert(itemEncontrado, pos);
    cout << "\nConteudo do Cinto apos insercoes:" << endl;
    cinto.Exibir();  // Exibe o conteúdo do cinto
  } else if (escolha == 'D' || escolha == 'd') {
    cout << "Voce descartou " << itemEncontrado->getNome() << "!" << endl;
    delete itemEncontrado;  // Libera memória do item descartado
  } else {
    cout << "Escolha invalida. O item foi descartado." << endl;
    delete itemEncontrado;  // Limpa se a escolha for invalida
  }
}

void EngineMapa::batalhar(Personagem& personagem, Inimigo& inimigo, Mochila& mochila, Cinto& cinto) {
  cout << "Iniciando a batalha!" << endl;

  while (personagem.estaVivo() && inimigo.estaVivo()) {
    // Exibir status do personagem e inimigo
    cout << personagem.Nome() << " (Vida: " << personagem.Vida() << ") enfrenta " 
         << inimigo.Nome() << " (Vida: " << inimigo.Vida() << ")" << endl;

    // O personagem escolhe uma ação
    int escolha;
    cout << "Escolha uma acao: " << endl;
    cout << "1. Pegar elemento do cinto" << endl;
    cout << "2. Pegar elemento da mochila" << endl;
    cout << "3. Atacar diretamente" << endl;
    cin >> escolha;

    switch (escolha) {
      case 1: {
        if(cinto.Empty()){
          cout << "Nada por aqui..." << endl;
          abort();
        }
        cinto.Exibir();
        int pos;
        cout << "Escolha a posicao do item no cinto (0 a " << (cinto.getSlots() - 1) << "): ";
        cin >> pos;
        
        Elemento* itemDoCinto = nullptr;
        if (cinto.Delete(pos, itemDoCinto)) {
          if (Pocao* pocao = dynamic_cast<Pocao*>(itemDoCinto)) {
            personagem.aumentarVida(pocao->getCura());
            cout << "Você pegou uma pocao!" << endl;
            cout << "Vida aumentada em " << pocao->getCura() << " pontos!" << endl;
          } else if (Arma* arma = dynamic_cast<Arma*>(itemDoCinto)) {
            personagem.aumentarAtaque(arma->getPoderAtaque());
            cout << "Você pegou uma Arma!" << endl;
            cout << "Ataque aumentado em " << arma->getPoderAtaque() << " pontos!" << endl;
          }
          delete itemDoCinto;  // Libera a memória
        } else if (cinto.Empty()) {
          cout << "Seu cinto está vazio!" << endl;
        } else {
          cout << "Posição inválida!" << endl;
        }
        break;
      }
      case 2: {

        // Pegar elemento da mochila (apenas o topo)
        Elemento* itemDaMochila;
        mochila.Top(itemDaMochila);
        if (itemDaMochila != nullptr) {
          if (Pocao* pocao = dynamic_cast<Pocao*>(itemDaMochila)) {
            personagem.aumentarVida(pocao->getCura());
            cout << "Vida aumentada em " << pocao->getCura() << " pontos!" << endl;
          } else if (Arma* arma = dynamic_cast<Arma*>(itemDaMochila)) {
            personagem.aumentarAtaque(arma->getPoderAtaque());
            cout << "Ataque aumentado em " << arma->getPoderAtaque() << " pontos!" << endl;
          }
          mochila.Pop(itemDaMochila);  // Remove o item da mochila
        } else {
          cout << "Mochila vazia!" << endl;
        }
        break;
      }
      case 3: {
        // Ataque direto
        cout << personagem.Nome() << " ataca " << inimigo.Nome() << "!" << endl;
        inimigo.receberDano(personagem.Forca());
        break;
      }
      default: {
        cout << "Escolha inválida!" << endl;
        break;
      }
    }

    // Verifica se o inimigo foi derrotado
    if (!inimigo.estaVivo()) {
      cout << inimigo.Nome() << " foi derrotado!" << endl;
      break;
    }

    // Ataque do inimigo
    cout << inimigo.Nome() << " ataca " << personagem.Nome() << "!" << endl;
    personagem.receberDano(inimigo.Forca());

    if (!personagem.estaVivo()) {
      cout << personagem.Nome() << " foi derrotado!" << endl;
    }
  }
}






void EngineMapa::iniciarBatalha(Personagem& heroi, Mochila& mochila, Cinto& cinto) {
  // Array de inimigos possíveis com defesa inicial
  Inimigo inimigos[] = {
    Inimigo("Lorde Vornak", 30, 5, 2),  // Nome, Vida, Forca, Defesa
    Inimigo("Esqueleto de Esgaroth", 50, 10, 5), 
    Inimigo("Kalazar Druida ", 100, 20, 10),
    Inimigo("Lorde Vesano", 100, 20, 10),
    Inimigo("Cavaleiro da Perdicao", 100, 20, 10),
  };

  srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador
  int indiceInimigo = rand() % (sizeof(inimigos) / sizeof(inimigos[0]));
  
  Inimigo& inimigo = inimigos[indiceInimigo]; // Passa como referencia

  cout << "Voce encontrou um " << inimigo.Nome() << "!" << std::endl;
  if(inimigo.Nome() == "Esqueleto de Esgaroth"){
    Esqueleto();
  }else{
    Cavaleiro();
  }
  batalhar(heroi, inimigo, mochila, cinto);
}

void EngineMapa::retornarStatus() {
  cout << "Score atual: " << score << endl;
  cout << "Posicao do heroi: (" << posicaoHeroiX << ", " << posicaoHeroiY << ")" << endl;
}

bool EngineMapa::gameOver() {
  return heroi.Vida() <= 0; // Supondo que a classe Personagem tenha um mehtodo getVida()
}

bool EngineMapa::finalNivel(int posicaoHeroiX, int posicaoHeroiY) const {
  // Define o ponto de fim do nível como o canto inferior direito do mapa
  int fimNivelX = mapa.getLargura() - 1; // Última coluna
  int fimNivelY = mapa.getAltura() - 1;  // Última linha

  // Verifica se a posicao do herói corresponde ao fim do nível
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

void EngineMapa::exibirMochila() {
  if (mochila.Empty()) {
    cout << "mochila vazia." << endl;
  } else {
    cout << "mochila:" << endl;
    mochila.Exibir();  // Supondo que já exista um método Exibir na classe Mochila
    cout << "" << endl;
  }
}

// Método para exibir os itens do cinto
void EngineMapa::exibirCinto() {
  if (cinto.Empty()) {
    cout << "cinto vazio." << endl;
  } else {
    cout << "cinto: " << endl;
    cinto.Exibir();  // Supondo que já exista um método Exibir na classe Cinto
    cout << " " << endl;
  }
}




