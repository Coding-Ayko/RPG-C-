// ==================== DEFINIÇÃO DA CLASSE SQM ==================== //
// Classe interna que representa um espaço no mapa. Pode ser vazio, 
// conter um elemento ou um inimigo. O conteúdo do espaço é gerado 
// aleatoriamente.
class Sqm {
  public:
    Sqm();
   
    char tipoSQM() const; // Método correto
    void declararTipoSQM(char newType); // Método correto
    void gerarSQMAleatorio(); 

  private:
    char tipoSQM; 
};

// verificar essa classe dps... DEFINIÇÃO DE LIMITE DO MAPA
class Mapa {
private:
    int largura, altura;

public:
    Mapa(int larguraMapa, int alturaMapa) : largura(larguraMapa), altura(alturaMapa) {}

    bool posicaoValida(int x, int y) const {
        return x >= 0 && x < largura && y >= 0 && y < altura;
    }
};

//============== DEFINIÇÃO  ENGENHARIA DE MAPAS E NIVEIS DO JOGO ===========//
// definição da classe EngineMap que vai controlar o mapa, o herói e o progresso pelo mapa. 
// escolhemos usar um array fixo para o mapa e uma variável para saber a posição do herói.

class EngenhariaMapa{
  public: 

    EngenhariaMapa(); 
    void gerarMapa(); // Gera o mapa baseado na dificuldade
    void MoverHeroi();
    void RetornarStatus();
    bool gameOver();
    void proximoNivel(); // Avança para o próximo nível
    void declararDificuldade(int nivel); // Define o nível de dificuldade
    void aumentarScore(int pontos); // Adiciona pontos à pontuação
    int retornarScore() const; // Retorna a pontuação atual
  private: 
    static const int TAMANHO_MAPA = 80;
    int posicaoHeroi;
    int nivelAtual;
    int dificuldade; // Representa a dificuldade atual
    int score; // Pontuação atual
    Sqm mapa[TAMANHO_MAPA]; 
    bool finalNivel(int posicao) const;
   
};
