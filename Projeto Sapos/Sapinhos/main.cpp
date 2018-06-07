#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include "sapos.hpp"
#include "pistas.hpp"
#include "sapos.cpp"
#include "pistas.cpp"

/**
*  @file main.cpp
*  @brief Corrida dos sapos
*  @since 29/05/2018
*  @date 06/06/2018
*/

using namespace std;

/** @brief Imprime o menu de opcoes */
void menu();

int main()
{
/** @brief Objeto de Sapo */
    Sapo S;

/** @brief Objeto de Pista */
    Pista P;

/** @brief Objeto ofstream para escrever em arquivos sobre as caracteristicas dos sapos */
    ofstream arquivoSapos;

/** @brief Objeto ofstream para escrever em arquivos sobre as caracteristicas das pistas */
    ofstream arquivoPistas;

/** @brief Objeto ofstream para escrever em arquivos sobre as caracteristicas das corridas(resultados) */
    ofstream arquivoCorridas;

/** @brief Objeto ifstream para ler linha a linha o conteudo dos arquivos */
    ifstream arquivoL;
    string nomeS,ident,nomeP,op,linha;
    int capac,tam,numpart,inc,pos1=0,pos2=0,siz1=0,siz2=0,cont=0,i=0,x=0,y=0,pos[100];

/** @brief Vector de objetos de Sapos */
    vector<Sapo> frogs;

/** @brief Vector auxiliar */
    vector<Sapo> result;

/** @brief Vector de objetos de Pista */
    vector<Pista> streets;

/** @brief iteradores de Sapo */
    vector<Sapo>::iterator it1,it;

/** @brief iteradores de Pista */
    vector<Pista>::iterator it2;

/** @brief Abrindo os Arquivos */
    arquivoSapos.open("Sapinhos.txt",ios::app);
    arquivoPistas.open("Pistas.txt",ios::app);
    arquivoCorridas.open("Corridas.txt",ios::app);

    do{
      menu();
      cin >> op;

/**
*  @brief Opcao 1.
*  Se op for igual a 1, ira mostrar quantos sapos(e se) existem armazenados no vector frogs.
*  Mostra-se tambem as caracteristicas e estatisticas de cada um.
*/
      if(op == "1"){
        if(frogs.empty())
          cout << endl << "Nao ha sapos armazenados" << endl << endl;

        else{
          cout << "Existe(m) " << x << " sapo(s) armazenados" << endl << endl;

          for(it1 = frogs.begin(); it1 != frogs.end(); ++it1)
            cout << *it1 << endl;
        }
    }

/**
*  @brief Opcao 2.
*  Se op for igual a 2, quantas pistas(e se) existem armazenadas no vector streets.
*  Mostra as caracteristicas e estatisticas de cada uma.
*/
      else if(op == "2"){
        if(streets.empty())
          cout << endl << "Nao ha pistas armazenadas" << endl << endl;

        else{
          cout << "Existe(m) " << y << " pista(s) armazenadas" << endl << endl;

          for(it2 = streets.begin(); it2 != streets.end(); ++it2)
            cout << *it2 << endl;
        }
    }

/**
*  @brief Opcao 3.
*  Se op for igual a 3, inicia o processo para comecar uma corrida.
*  Se o numero de sapos e pistas forem o suficiente para iniciar a corrida, o usuario deve liberar o PEI(start) da corrida.
*  Cada sapo pula uma vez separada, ate chegar no final.
*  A medida que os sapos chegam, eles vao parando de pular, ate todos estarem na linha de chegada.
*  Apos a corrida, o rank com as posicoes eh demonstrado.
*/
      else if(op == "3"){
        if(streets.empty())
          cout << "Nao ha pistas armazenadas. Crie algumas para iniciar uma corrida" << endl << endl;

/** @brief O usuario escolhe uma pista para a corrida */
        else{
          cout << "Escolha uma pista digitando sua posicao(escolha de 0(esta eh a primeira pista) ate TOTAL-1(Total menos um, esta eh a ultima pista) de pistas criadas): " << endl << endl;
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
                cout << "Escolha os sapos disponiveis digitando suas posicoes(escolha de 0(este eh o primeiro sapo) ate TOTAL-1(Total menos um, este eh o ultimo sapo) de sapos criados), ate todos serem utilizados na corrida: " << endl << endl;
                for(it1 = frogs.begin(); it1 != frogs.end(); ++it1)
                  cout << *it1 << endl;

              i = 0;
/** @brief O usuario escolhe os sapos ja criados para a corrida */
                  do{
                    siz2 = frogs.size();
                    cout << "Escolha um sapo: "; cin >> pos2;
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
                        it1 = frogs.begin();

                        if(i >= streets[pos1].getNumeroparticipantes())
                          i = 0;

                        inc = frogs[pos[i]].pular();
                          cout << "Sapo " << frogs[pos[i]].getNome() << "[" << frogs[pos[i]].getIdentificador() << "] pulou " << inc << " unidade(s)" << endl << endl;

                          if(frogs[pos[i]].getDistanciapercorrida() >= streets[pos1].getTamanho()){
                            advance(it1, pos[i]);
                            it = result.begin()+cont;
                            result.insert(it, *it1);
                            frogs.erase(it1);
                            streets[pos1].diminuir();
                            cont++;
                                  }
                        i++;

                              }while(!frogs.empty());
/**
*  @brief Funcionamento da corrida.
*  Apos escolher a pista e os sapos, o usuario digita PEI.
*  Apos o PEI, os sapos comecarao a pular.
*  A medida que um sapo chega no final antes dos outros, ele eh inserido no vector auxiliar e este eh apagado no vector principal(frogs).
*  Este processo ocorre com todos os sapos do vector frogs, ate este ficar vazio.
*  Apos isso, o rank eh mostrado a partir do vector auxiliar.
*  Por fim, o swap entre vector eh utilizado e os sapos retornam a frogs.
*  As caracteristicas como distancia percorrida e numero de pulos sao zeradas.
*  Os arquivos sao atualizados e as estatisticas tambem.
*/
                          cout << "Campeao: " << result[0].getNome() << endl << endl;
                          result[0].ganhar();

                          arquivoCorridas << "---------- Arquivo depois de uma corrida em " << streets[pos1].getNome() << " ----------" << endl << endl;
                          cout << "Pista escolhida: " << streets[pos1].getNome() << endl << endl;
                          arquivoCorridas << "Pista escolhida: " << streets[pos1].getNome() << endl << endl;
                          cout << "Resultado da corrida: " << endl << endl;
                          arquivoCorridas << "Resultado da corrida: " << endl << endl;

                          for(i = 0; i < cont; i++){
                            cout << "Na posicao " << i+1 << " esta o sapo " << result[i].getNome() << " que pulou " << result[i].getQtdpulostotal() << " vezes" << endl;

                            arquivoCorridas << "Na posicao " << i+1 << " esta o sapo " << result[i].getNome() << " que pulou " << result[i].getQtdpulostotal() << " vezes" << endl;
                            }

                          frogs.swap(result);

                          for(i = 0; i < cont; i++){
                            frogs[i].setDistanciapercorrida(0);
                            frogs[i].setQtdpulostotal(0);
                            }

                          streets[pos1].setNumeroparticipantes(cont);

                          arquivoSapos << "---------- Arquivo depois de uma corrida em " << streets[pos1].getNome() << " ----------" << endl << endl;
                          for(i = 0; i < siz2; i++){
                            frogs[pos[i]].provas();
                            arquivoSapos << frogs[i].getNome()  << " -----> Nome do sapo." << endl;
                            arquivoSapos << frogs[i].getIdentificador() << " -----> Numero do sapo." << endl;
                            arquivoSapos << frogs[i].getCapacidade() << "m por pulo -----> Capacidade por pulo do sapo." << endl;
                            arquivoSapos << "Participou de " << frogs[i].getQtdprovas() << " corridas." << endl;
                            arquivoSapos << "Ganhou " << frogs[i].getQtdvitorias() << " corridas." << endl;
                            arquivoSapos << "Empatou " << frogs[i].getQtdempates() << " corridas." << endl;
                            arquivoSapos << endl;
                            }

                          arquivoPistas << "---------- Arquivo depois de uma corrida em " << streets[pos1].getNome() << " ----------" << endl << endl;
                          streets[pos1].corridas();
                          for(i = 0; i < siz1; i++){
                            arquivoPistas << streets[i].getNome() << " -----> Nome da pista." << endl;
                            arquivoPistas << streets[i].getTamanho() << "m -----> Tamanho da pista em metros." << endl;
                            arquivoPistas << streets[i].getNumeroparticipantes() << " participantes por corrida -----> Capacidade da pista." << endl;
                            arquivoPistas << "Foi(ram) realizada(s) " << streets[i].getNumerocorridas() << " corrida(s) nessa pista." << endl;
                            arquivoPistas << endl;
                            }

                          i = 0;
                          cont = 0;
                          pos1 = 0;
                          pos2 = 0;

                          for(i = 0; i < 100; i++)
                            pos[i] = 0;

                        }
                    }
                }
            }
        }
    }

/**
*  @brief Opcao 4.
*  Se op for igual a 4.
*  Ira se mostrar o menu para a criacao de um sapo.
*  Eh necessario o usuario digitar suas principais caracteristicas.
*  Mostra-se apos o procedimento, uma mensagem de sucesso.
*/
      else if(op == "4"){
        cout << "Criando o sapo: " << endl;
        cout << "Digite o nome do sapo(string): "; cin >> nomeS;
        S.setNome(nomeS);
        arquivoSapos << S.getNome()  << " -----> Nome do sapo." << endl;
        cout << "Digite o identificador do sapo(string): "; cin >> ident;
        S.setIdentificador(ident);
        arquivoSapos << S.getIdentificador() << " -----> Numero do sapo." << endl;
        cout << "Digite a capacidade por pulo do sapo(inteiro): "; cin >> capac;
        S.setCapacidade(capac);
        arquivoSapos << S.getCapacidade() << "m por pulo -----> Capacidade por pulo do sapo." << endl;
        arquivoSapos << "Participou de " << S.getQtdprovas() << " corridas." << endl;
        arquivoSapos << "Ganhou " << S.getQtdvitorias() << " corridas." << endl;
        arquivoSapos << "Empatou " << S.getQtdempates() << " corridas." << endl;
        arquivoSapos << endl;
        frogs.push_back(S);
        cout << "Sapo criado com sucesso!!" << endl << endl;
        x++;
        }

/**
*  @brief Opcao 5.
*  Se op for igual a 5.
*  Ira se mostrar o menu para a criacao de uma pista.
*  Eh necessario o usuario digitar suas principais caracteristicas.
*  Mostra-se apos o procedimento, uma mensagem de sucesso.
*/
      else if(op == "5"){
        cout << "Criando a pista: " << endl;
        cout << "Digite o nome da pista(string): "; cin >> nomeP;
        P.setNome(nomeP);
        arquivoPistas << P.getNome() << " -----> Nome da pista." << endl;
        cout << "Digite o tamanho da pista em metros(inteiro): "; cin >> tam;
        P.setTamanho(tam);
        arquivoPistas << P.getTamanho() << "m -----> Tamanho da pista em metros." << endl;
        cout << "Digite a capacidade de participantes na pista em uma corrida(inteiro): "; cin >> numpart;
        P.setNumeroparticipantes(numpart);
        arquivoPistas << P.getNumeroparticipantes() << " participantes por corrida -----> Capacidade da pista." << endl;
        arquivoPistas << "Foi(ram) realizada(s) " << P.getNumerocorridas() << " corridas nessa pista." << endl;
        arquivoPistas << endl;
        streets.push_back(P);
        cout << "Pista criada com sucesso!!" << endl << endl;
        y++;
        }

/**
*  @brief Opcao 6.
*  Se op for igual a 6.
*  Ira se mostrar o menu para a leitura dos arquivos.
*  Eh necessario o usuario digitar 1, 2 ou 3.
*  1-> ler o arquivo dos sapos: Sapinhos.txt.
*  2-> ler o arquivo das pistas: Pistas.txt.
*  3-> ler o arquivo das corridas(ranks): Corridas.txt.
*/
      else if(op == "6"){
        cout << "1 -> Arquivo dos sapos" << endl << "2 -> Arquivo das pistas" << endl << "3 -> Arquivo dos resultados" << endl << endl;
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

        else if(op == "3"){
          arquivoL.open("Corridas.txt");

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
    }while(op != "SAIR");

/**
*  @brief Fechamento dos arquivos.
*  Para liberar a memoria, reservada para abri-los no inicio da execucao.
*/
    arquivoSapos.close();
    arquivoCorridas.close();
    arquivoPistas.close();

    cout << endl << endl << "Saindo...." << endl << endl;

    return 0;
}


/**
*  @brief iteradores de Sapo.
*  O usuario escolhera a opcao do menu.
*  De acordo com a escolha, o programa inicia uma de suas funcionalidades indicadas.
*  Como, criacao de sapos/pistas, vizualizacao de estatisticas e finalmente, criar uma corrida.
*/
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
