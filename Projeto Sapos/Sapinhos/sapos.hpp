#ifndef SAPOS_HPP_INCLUDED
#define SAPOS_HPP_INCLUDED

using namespace std;

class Sapo{
    private:
        string nome,identificador;
        int capacidade,qtdpulostotal,distanciapercorrida,qtdprovas,qtdvitorias,qtdempates;

    public:
        Sapo();
        string getNome();
        string getIdentificador();
        int getCapacidade();
        int getQtdpulostotal();
        int getQtdprovas();
        int getQtdvitorias();
        int getQtdempates();
        int getDistanciapercorrida();
        void setNome(string nome);
        void setIdentificador(string identificador);
        void setCapacidade(int capacidade);
        void pular();
        int incrementar();
        void ganhar();
        void provas();
        void empatar();
        static int disttotal;
        friend ostream& operator << (ostream &o, Sapo &s);
};

#endif // SAPOS_HPP_INCLUDED
