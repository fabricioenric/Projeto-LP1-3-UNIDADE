#ifndef PISTAS_HPP_INCLUDED
#define PISTAS_HPP_INCLUDED

using namespace std;

class Pista{
    private:
        string nome;
        int tamanho;
        int numeroparticipantes;
        int numerocorridas;

    public:
        Pista();
        string getNome();
        int getTamanho();
        int getNumeroparticipantes();
        int getNumerocorridas();
        void setNome(string nome);
        void setTamanho(int tamanho);
        void setNumeroparticipantes(int numeroparticipantes);
        void corridas();
        friend ostream& operator << (ostream &o, Pista &p);
};

#endif // PISTAS_HPP_INCLUDED
