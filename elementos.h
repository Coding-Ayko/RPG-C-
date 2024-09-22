#include <string>
using namespace std;

class Elemento {
public:
    enum Tipo { INIMIGO, ARMA, POTAO };

    Elemento();
    Elemento(const string& nome, int peso, int valor, Tipo tipo);

    string getNome() const;
    void setNome(const string& nome);

    int getPeso() const;
    void setPeso(int peso);

    int getValor() const;
    void setValor(int valor);

    Tipo getTipo() const;
    void setTipo(Tipo tipo);

private:
    string nome;
    int peso;
    int valor;
    Tipo tipo;
};

class Inimigo : public Elemento {
public:
    Inimigo(const string& nome, int peso, int valor, int forca);

    int getForca() const;
    void setForca(int forca);

private:
    int forca;
};

class Arma : public Elemento {
public:
    Arma(const string& nome, int peso, int valor, int dano);

    int getDano() const;
    void setDano(int dano);

private:
    int dano;
};

class Potao : public Elemento {
public:
    Potao(const string& nome, int peso, int valor, int cura);

    int getCura() const;
    void setCura(int cura);

private:
    int cura;
};

