#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sapos.hpp"

using namespace std;

Sapo::Sapo(){
    this->nome = "";
    this->identificador = "";
    this->capacidade = 0;
    this->qtdpulostotal = 0;
    this->qtdprovas = 0;
    this->qtdvitorias = 0;
    this->qtdempates = 0;
    this->distanciapercorrida = 0;
}

string Sapo::getNome(){
    return this->nome;
}

string Sapo::getIdentificador(){
    return this->identificador;
}

int Sapo::getCapacidade(){
    return this->capacidade;
}

int Sapo::getQtdpulostotal(){
    return this->qtdpulostotal;
}

int Sapo::getQtdprovas(){
    return this->qtdprovas;
}

int Sapo::getQtdvitorias(){
    return this->qtdvitorias;
}

int Sapo::getQtdempates(){
    return this->qtdempates;
}

int Sapo::getDistanciapercorrida(){
    return this->distanciapercorrida;
}

void Sapo::setNome(string nome){
    this->nome = nome;
}

void Sapo::setIdentificador(string identificador){
    this->identificador = identificador;
}

void Sapo::setCapacidade(int capacidade){
    this->capacidade = capacidade;
}

void Sapo::pular(){
    this->distanciapercorrida += incrementar();

    this->qtdpulostotal++;
}

int Sapo::incrementar(){
    srand(time(NULL));
    int incremento = rand()%this->capacidade;

    return incremento;
}

void Sapo::ganhar(){
    qtdvitorias++;
}

void Sapo::empatar(){
    qtdempates++;
}

void Sapo::provas(){
    qtdprovas++;
}

ostream& operator << (ostream &o, Sapo &s){
    o << "Nome do sapo: " << s.nome << endl << "Identificador do sapo: " << s.identificador << endl << "Capacidade por pulo do sapo: " << s.capacidade << endl << "Quantidade de corridas participadas: " << s.qtdprovas << endl << "Quantidade de empates: " << s.qtdempates << endl << "Quantidade de vitorias: " << s.qtdvitorias << endl;
    return o;
}
