#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pistas.hpp"

using namespace std;

Pista::Pista(){
    this->nome = "";
    this->tamanho = 0;
    this->numeroparticipantes = 0;
    this->numerocorridas = 0;
}

string Pista::getNome(){
    return this->nome;
}

int Pista::getTamanho(){
    return this->tamanho;
}

int Pista::getNumeroparticipantes(){
    return this->numeroparticipantes;
}

int Pista::getNumerocorridas(){
    return this->numerocorridas;
}

void Pista::setNome(string nome){
    this->nome = nome;
}

void Pista::setTamanho(int tamanho){
    this->tamanho = tamanho;
}

void Pista::setNumeroparticipantes(int numeroparticipantes){
    this->numeroparticipantes = numeroparticipantes;
}

void Pista::diminuir(){
    this->numeroparticipantes--;
}

void Pista::corridas(){
    numerocorridas++;
}

ostream& operator << (ostream &o, Pista &p){
    o << "Nome da pista: " << p.nome << endl << "Tamanho da pista: " << p.tamanho << endl << "Numero de participantes na pista: " << p.numeroparticipantes << endl << "Numero de corridas realizadas: " << p.numerocorridas << endl;
    return o;
}

