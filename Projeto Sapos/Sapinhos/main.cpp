#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include "sapos.hpp"
#include "pistas.hpp"
#include "sapos.cpp"
#include "pistas.cpp"

using namespace std;

void menu();

int main()
{
    Sapo S;
    Pista P;
    ofstream arquivoSapos;
    ofstream arquivoPistas;
    ifstream arquivoL;
    string nomeS,ident,nomeP,op,linha;
    int capac,tam,numpart,pos1,pos2,siz1,siz2,i=0,x=0,y=0,pos[]={0};
    vector<Sapo> frogs;
    vector<Pista> streets;
    vector<Sapo>::iterator it1;
    vector<Pista>::iterator it2;
    arquivoSapos.open("Sapinhos.txt",ios::app);
    arquivoPistas.open("Pistas.txt",ios::app);

    do{
      menu();
      cin >> op;

      if(op == "1"){
        if(frogs.empty())
          cout << "Nao ha sapos armazenados" << endl << endl;

        else{
          cout << "Existe(m) " << x << " sapo(s) armazenados" << endl << endl;

          for(it1 = frogs.begin(); it1 != frogs.end(); ++it1)
            cout << *it1 << endl;
        }
    }

      else if(op == "2"){
        if(streets.empty())
          cout << "Nao ha pistas armazenadas" << endl << endl;

        else{
          cout << "Existe(m) " << y << " pista(s) armazenadas" << endl << endl;

          for(it2 = streets.begin(); it2 != streets.end(); ++it2)
            cout << *it2 << endl;
        }
    }


      else if(op == "3"){
        if(streets.empty())
          cout << "Nao ha pistas armazenadas. Crie algumas para iniciar uma corrida" << endl << endl;

        else{
          cout << "Escolha uma pista digitando sua posicao: " << endl << endl;
            for(it2 = streets.begin(); it2 != streets.end(); ++it2)
              cout << *it2 << endl;

          if(frogs.empty())
            cout << "Nao ha sapos armazenados. Crie alguns para iniciar uma corrida" << endl << endl;

          else{
            it2 = streets.begin();
            cin >> pos1;
            siz1 = streets.size();
            advance(it2, pos1);
            if(pos1 > siz1 || pos1 < 0)
              cout << "Nao ha pista armazenada nesta posicao" << endl << endl;

            else{
              cout << "Pista escolhida: " << endl << *it2 << endl << endl;

              if(x < streets[pos1].getNumeroparticipantes())
                cout << "Crie mais sapos para realizar uma corrida nessa pista" << endl;

              else{
                cout << "Escolha os sapos disponiveis digitando suas posicoes: " << endl << endl;
                for(it1 = frogs.begin(); it1 != frogs.end(); ++it1)
                  cout << *it1 << endl;

              i = 0;

                  do{
                    siz2 = frogs.size();
                    cin >> pos2;
                    pos[i] = pos2;

                    if(pos2 >= siz2 || pos2 < 0)
                    cout << "Nao ha sapo armazenado nesta posicao" << endl << endl;

                    else{
                      cout << "Sapo escolhido: " << frogs[pos2].getNome() << " com o numero " << frogs[pos2].getIdentificador() << endl << endl;
                      i++;
                                        }
                                }while(i < streets[pos1].getNumeroparticipantes());

                cout << "Digite PEI para iniciar(start) a corrida: " << endl << endl;
                cin >> op;
                  if(op == "PEI"){
                    i = 0;
                      do{

                        if(i == streets[pos1].getNumeroparticipantes())
                          i = 0;

                        frogs[pos[i]].pular();
                          cout << "Sapo " << frogs[pos[i]].getNome() << " pulou " << frogs[pos[i]].incrementar() << " unidades"<< endl << endl;

                          if(frogs[pos[i]].getDistanciapercorrida() > streets[pos1].getTamanho() || frogs[pos[i]].getDistanciapercorrida() == streets[pos1].getTamanho()){
                            cout << "O sapo " << frogs[pos[i]].getNome() << " eh o campeao" << endl;
                            cout << "Seu numero " << frogs[pos[i]].getIdentificador() << endl;
                            cout << "Pulou " << frogs[pos[i]].getQtdpulostotal() << " vezes" << endl << "Com uma capacidade de " << frogs[pos[i]].getCapacidade() << " unidades por pulo com obstaculos e imprevistos pelo caminho" << endl << endl;
                            frogs[pos[i]].ganhar();
                                  }
                        i++;

                              }while(frogs[pos[i]].getDistanciapercorrida() < streets[pos1].getTamanho());

                          for(i = 0; i < streets[pos1].getNumeroparticipantes(); i++){
                            cout << "O sapo " << frogs[pos[i]].getNome() << " de numero " << frogs[pos[i]].getIdentificador() << " pulou " << frogs[pos[i]].getQtdpulostotal() << " vezes com uma capacidade de " << frogs[pos[i]].getCapacidade() << " unidades por pulo" << endl << endl;
                            frogs[pos[i]].provas();
                            frogs[pos[i]].setDistanciapercorrida(0);
                                }

                          streets[pos1].corridas();

                        }
                    }
                }
            }
        }
    }

      else if(op == "4"){
        cout << "Criando o sapo: " << endl;
        cout << "Digite o nome do sapo: "; cin >> nomeS;
        S.setNome(nomeS);
        arquivoSapos << S.getNome()  << " -----> Nome do sapo." << endl;
        cout << "Digite o identificador do sapo: "; cin >> ident;
        S.setIdentificador(ident);
        arquivoSapos << S.getIdentificador() << " -----> Numero do sapo." << endl;
        cout << "Digite a capacidade por pulo do sapo: "; cin >> capac;
        S.setCapacidade(capac);
        arquivoSapos << S.getCapacidade() << "m por pulo -----> Capacidade por pulo do sapo." << endl;
        arquivoSapos << "Participou de " << S.getQtdprovas() << " corridas." << endl;
        arquivoSapos << "Ganhou " << S.getQtdvitorias() << " corridas." << endl;
        arquivoSapos << "Empatou " << S.getQtdempates() << " corridas." << endl;
        arquivoSapos << endl;
        frogs.push_back(S);
        cout << "Sapo criado com sucesso!!" << endl << endl;
        x++;
        arquivoSapos.close();
        }

      else if(op == "5"){
        cout << "Criando a pista: " << endl;
        cout << "Digite o nome da pista: "; cin >> nomeP;
        P.setNome(nomeP);
        arquivoPistas << P.getNome() << " -----> Nome da pista." << endl;
        cout << "Digite o tamanho da pista em metros: "; cin >> tam;
        P.setTamanho(tam);
        arquivoPistas << P.getTamanho() << "m -----> Tamanho da pista em metros." << endl;
        cout << "Digite a capacidade de participantes na pista em uma corrida: "; cin >> numpart;
        P.setNumeroparticipantes(numpart);
        arquivoPistas << P.getNumeroparticipantes() << " participantes por corrida -----> Capacidade da pista." << endl;
        arquivoPistas << "Foi(ram) realizada(s) " << P.getNumerocorridas() << " corridas nessa pista." << endl;
        arquivoPistas << endl;
        streets.push_back(P);
        cout << "Pista criada com sucesso!!" << endl << endl;
        y++;
        arquivoPistas.close();
        }

      else if(op == "6"){
        cout << "1 -> Arquivo dos sapos" << endl << "2 -> Arquivo das pistas" << endl << endl;
        cin >> op;

        if(op == "1"){
          arquivoL.open("Sapinhos.txt");

          if(arquivoL.is_open()){
            while(getline(arquivoL,linha))
              cout << linha << endl;

              arquivoL.close();
                    }
          else{
            cout << "Nao foi possivel abrir o arquivo" << endl << endl;
                }
            }

        else if(op == "2"){
          arquivoL.open("Pistas.txt");

          if(arquivoL.is_open()){
            while(getline(arquivoL,linha))
              cout << linha << endl;

              arquivoL.close();
                    }
          else{
            cout << "Nao foi possivel abrir o arquivo" << endl << endl;
                }
            }
        }

      else if(op == "7"){
        arquivoSapos.clear();
        arquivoPistas.clear();
      }

    }while(op != "SAIR");

    cout << endl << endl << "Saindo...." << endl << endl;

    return 0;
}

void menu(){
      cout << "Opcoes: " << endl;
      cout << "1 -> Ver estatisticas dos sapos" << endl;
      cout << "2 -> Ver estatisticas das pistas" << endl;
      cout << "3 -> Iniciar uma corrida" << endl;
      cout << "4 -> Criar sapo" << endl;
      cout << "5 -> Criar pista" << endl;
      cout << "6 -> Ler arquivos" << endl;
      cout << "SAIR -> Sair do programa" << endl << endl;
}
