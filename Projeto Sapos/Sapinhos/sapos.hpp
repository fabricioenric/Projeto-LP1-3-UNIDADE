#ifndef SAPOS_HPP_INCLUDED
#define SAPOS_HPP_INCLUDED

using namespace std;

/**
*  @brief Classe Sapo.
*  Esta que possui atributos e metodos publicos para abstrair objetos do tipo Sapo.
*/

class Sapo{
    private:

/**
*  @brief Atributos privados do tipo string.
*  Referentes ao nome e numero dos sapos, respectivamente.
*/
        string nome,identificador;

/**
*  @brief Atributos privados do tipo inteiro(int).
*  Referentes as capacidades, distancias que percorreram nas corridas e suas estatisticas apos as corridas.
*/
        int capacidade,qtdpulostotal,distanciapercorrida,qtdprovas,qtdvitorias,qtdempates;

    public:
/**
*  @brief Contrutor padrao.
*  Para inicializar os dados dos objetos Sapo.
*/
        Sapo();

/**
*  @brief Metodo getters para o atributo nome.
*  @return Atributo para main.
*/
        string getNome();

/**
*  @brief Metodo getters para o atributo identificador.
*  @return Atributo para main.
*/
        string getIdentificador();

/**
*  @brief Metodo getters para o atributo capacidade.
*  @return Atributo para main.
*/
        int getCapacidade();

/**
*  @brief Metodo getters para o atributo qtdpulostotal.
*  @return Atributo para main.
*/
        int getQtdpulostotal();

/**
*  @brief Metodo getters para o atributo qtdprovas.
*  @return Atributo para main.
*/
        int getQtdprovas();

/**
*  @brief Metodo getters para o atributo qtdvitorias.
*  @return Atributo para main.
*/
        int getQtdvitorias();

/**
*  @brief Metodo getters para o atributo qtdempates.
*  @return Atributo para main.
*/
        int getQtdempates();

/**
*  @brief Metodo getters para o atributo distanciapercorrida.
*  @return Atributo para main.
*/
        int getDistanciapercorrida();

/**
*  @brief Metodo setters para o atributo nome.
*  @param Parametro para atribuir valor ao atributo.
*/
        void setNome(string nome);

/**
*  @brief Metodo setters para o atributo identificador
*  @param Parametro para atribuir valor ao atributo
*/
        void setIdentificador(string identificador);

/**
*  @brief Metodo setters para o atributo capacidade
*  @param Parametro para atribuir valor ao atributo
*/
        void setCapacidade(int capacidade);

/**
*  @brief Metodo setters para o atributo distanciapercorrida.
*  @param Parametro para atribuir valor ao atributo.
*/
        void setDistanciapercorrida(int distanciapercorrida);

/**
*  @brief Metodo setters para o atributo qtdpulostotal.
*  @param Parametro para atribuir valor ao atributo.
*/
        void setQtdpulostotal(int qtdpulostotal);

/**
*  @brief Metodo para fazerem os sapos pularem, cada um por vez ate o fim do tamanho da pista.
*  @return Valor por pulo entre 1 e a capacidade de um determinado sapo.
*/
        int pular();

/**
*  @brief Aumenta o numero de vitorias de um sapo campeao em 1.
*/
        void ganhar();

/**
*  @brief Aumenta o numero de ocorrencias em corridas em 1.
*/
        void provas();

/**
*  @brief Aumenta o numero de empates em corridas em 1.
*/
        void empatar();

/**
*  @brief Sobrecarga do operador de insercao(<<).
*/
        friend ostream& operator << (ostream &o, Sapo &s);
};

#endif // SAPOS_HPP_INCLUDED
