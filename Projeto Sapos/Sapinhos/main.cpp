#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "sapos.hpp"
#include "pistas.hpp"
#include "sapos.cpp"
#include "pistas.cpp"

using namespace std;

int main()
{
    Sapo S;
    Pista P;
    string nomeS,ident,nomeP,op;
    int capac,tam,numpart,pos1,pos2,siz1,siz2,i=0,x=0,y=0,pos[i];
    vector<Sapo> frogs;
    vector<Pista> streets;
    vector<Sapo>::iterator it1;
    vector<Pista>::iterator it2;

    do{
      cout << "Opcoes: " << endl;
      cout << "1 -> Ver estatisticas dos sapos" << endl;
      cout << "2 -> Ver estatisticas das pistas" << endl;
      cout << "3 -> Iniciar uma corrida" << endl;
      cout << "4 -> Criar sapo" << endl;
      cout << "5 -> Criar pista" << endl;
      cout << "sair -> Sair do programa" << endl << endl;
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
              cin >> pos2;
              siz2 = frogs.size();

                if(pos2 >= siz2 || pos2 < 0)
                  cout << "Nao ha sapo armazenado nesta posicao" << endl << endl;

                else{
                  pos[i] = pos2;
                  cout << "Sapo escolhido: " << frogs[pos2].getNome() << " com o numero " << frogs[pos2].getIdentificador() << endl << endl;
                  i++;

                  do{
                    cin >> pos2;
                    pos[i] = pos2;

                    if(pos2 >= siz2 || pos2 < 0)
                    cout << "Nao ha sapo armazenado nesta posicao" << endl << endl;

                    else if(pos2 < siz2 && pos2 > 0){

                      if(pos[i-1] == pos[i])
                        cout << "ERRO: Esse sapo ja foi escolhido....." << endl << endl;

                      else{
                        cout << "Sapo escolhido: " << frogs[pos2].getNome() << " com o numero " << frogs[pos2].getIdentificador() << endl << endl;
                        i++;
                                        }
                                    }
                                }while(i <= streets[pos1].getNumeroparticipantes());

                cout << "Digite PEI para iniciar(start) a corrida: " << endl << endl;
                cin >> op;
                  if(op == "PEI"){
                    i = 0;
                      do{
                        frogs[pos[i]].pular();
                          cout << "Sapo " << frogs[pos[i]].getNome() << " pulou " << frogs[pos[i]].incrementar() << endl << endl;

                          if(frogs[pos[i]].getDistanciapercorrida() >= streets[pos1].getTamanho()){
                            cout << "O sapo " << frogs[pos[i]].getNome() << " eh o campeao" << endl;
                            cout << "Seu numero " << frogs[pos[i]].getIdentificador() << endl;
                            cout << "Pulou " << frogs[pos[i]].getQtdpulostotal() << " vezes" << endl << "Com uma capacidade de " << frogs[pos[i]].getCapacidade() << " unidades por pulo com obstaculos e imprevistos pelo caminho" << endl << endl;
                            frogs[pos[i]].ganhar();
                                  }
                      i++;

                        if(i == streets[pos1].getNumeroparticipantes())
                          i = 0;

                              }while(frogs[pos[i]].getDistanciapercorrida() != streets[pos1].getTamanho());

                          for(i = 0; i < streets[pos1].getNumeroparticipantes(); i++){
                            cout << "O sapo " << frogs[pos[i]].getNome() << " de numero " << frogs[pos[i]].getIdentificador() << " pulou " << frogs[pos[i]].getQtdpulostotal() << " vezes com uma capacidade de " << frogs[pos[i]].getCapacidade() << " unidades por pulo" << endl << endl;
                            frogs[pos[i]].provas();
                                }

                          streets[pos1].corridas();

                            }
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
        cout << "Digite o identificador do sapo: "; cin >> ident;
        S.setIdentificador(ident);
        cout << "Digite a capacidade por pulo do sapo: "; cin >> capac;
        S.setCapacidade(capac);
        frogs.push_back(S);
        cout << "Sapo criado com sucesso!!" << endl << endl;
        x++;
        }

      else if(op == "5"){
        cout << "Criando a pista: " << endl;
        cout << "Digite o nome da pista: "; cin >> nomeP;
        P.setNome(nomeP);
        cout << "Digite o tamanho da pista em metros: "; cin >> tam;
        P.setTamanho(tam);
        cout << "Digite a capacidade de participantes na pista em uma corrida: "; cin >> numpart;
        P.setNumeroparticipantes(numpart);
        streets.push_back(P);
        cout << "Pista criada com sucesso!!" << endl << endl;
        y++;
        }
    }while(op != "sair");

    cout << endl << endl << "Saindo...." << endl << endl;

    return 0;
}
