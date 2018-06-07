#ifndef PISTAS_HPP_INCLUDED
#define PISTAS_HPP_INCLUDED

using namespace std;

/**
*  @brief Classe Pista.
*  Esta que possui atributos e metodos publicos para abstrair objetos do tipo Pista.
*/

class Pista{
    private:

/**
*  @brief Atributo privado do tipo string.
*  Referentes ao nome das pistas.
*/
        string nome;

/**
*  @brief Atributo privado do tipo inteiro(int).
*  Referente ao tamanho das pistas.
*/
        int tamanho;

/**
*   @brief Atributo privado do tipo inteiro(int).
*   Referente a capacidade de sapos competidores nas pistas.
*/
        int numeroparticipantes;

/**
*  @brief Atributo privado do tipo inteiro(int).
*  Referente ao numero de corridas que aconteceram em uma pista.
*/
        int numerocorridas;

    public:

/**
*  @brief Contrutor padrao para inicializar os dados dos objetos Pista.
*/
        Pista();

/**
*  @brief Metodo getters para o atributo nome.
*  @return Atributo para main.
*/
        string getNome();

/**
*  @brief Metodo getters para o atributo tamanho.
*  @return Atributo para main.
*/
        int getTamanho();

/**
*  @brief Metodo getters para o atributo numeroparticipantes.
*  @return Atributo para main.
*/
        int getNumeroparticipantes();

/**
*  @brief Metodo getters para o atributo numerocorridas.
*  @return Atributo para main.
*/
        int getNumerocorridas();

/**
*  @brief Metodo setters para o atributo nome.
*  @param Parametro para atribuir valor ao atributo.
*/
        void setNome(string nome);

/**
*  @brief Metodo setters para o atributo tamanho.
*  @param Parametro para atribuir valor ao atributo.
*/
        void setTamanho(int tamanho);

/**
*  @brief Metodo setters para o atributo numeroparticipantes.
*  @param Parametro para atribuir valor ao atributo.
*/
        void setNumeroparticipantes(int numeroparticipantes);

/**
*  @brief Metodo para aumentar em 1 unidade, o numero de corridas em uma dada pista.
*/
        void corridas();

/**
*  @brief Metodo para diminuir em 1 unidade, o numero de capacidade de participantes em uma dada pista.
*/
        void diminuir();

/**
*  @brief Sobrecarga do operador de insercao(<<).
*/
        friend ostream& operator << (ostream &o, Pista &p);
};

#endif // PISTAS_HPP_INCLUDED
