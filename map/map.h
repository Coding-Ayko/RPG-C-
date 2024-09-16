// ==================== DEFINIÇÃO DA CLASSE SQM ==================== //
// Classe interna que representa um espaço no mapa. Pode ser vazio, 
// conter um elemento ou um inimigo. O conteúdo do espaço é gerado 
// aleatoriamente.
class Sqm {
  public:
    Sqm();
   
    char getType() const; // Método correto
    void setType(char newType); // Método correto
    void generateRandomContent(); 

  private:
    char type; 
};

//============== DEFINIÇÃO  ENGENHARIA DE MAPAS E NIVEIS DO JOGO ===========//
// definição da classe EngineMap que vai controlar o mapa, o herói e o progresso pelo mapa. 
// escolhemos usar um array fixo para o mapa e uma variável para saber a posição do herói.

class EngineMap{
  public: 

    EngineMap(); 
    void generateMap(); // Gera o mapa baseado na dificuldade
    void moveHero();
    void printStatus();
    bool gameOver();
    void nextLevel(); // Avança para o próximo nível
    void setDifficulty(int level); // Define o nível de dificuldade
    void increaseScore(int points); // Adiciona pontos à pontuação
    int getScore() const; // Retorna a pontuação atual
  private: 
    static const int MAP_SIZE = 80;
    int heroPosition;
    int currentLevel;
    int difficulty; // Representa a dificuldade atual
     int score; // Pontuação atual
    Sqm map[MAP_SIZE]; 
    bool isLevelEnd(int position) const;
   
};
