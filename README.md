# Projeto-LP1-3-UNIDADE
Projeto da corrida de sapos

Seção 1:

    Funcionamento geral do programa:

*Primeiramente, criando as classes Sapo(com seus atributos e métodos) e Pista(com seus atributos e métodos), e o vectores necessários para a realização do objetivo final do programa(iniciar uma corrida de objetos, no caso estes serão os sapos).

*Depois, criando objetos ofstream e ifstream para a manipulacao de arquivos(escrever e ler os arquivos).
    
    int main(){
                            .
                            .
                            .
                    
                    {Declaração de Variáveis}
                    
                            .
                            .
                            .
       
    vector<Sapo> frogs; ----> Vector para armazenar objetos Sapo.
    vector<Sapo> result; ----> Vector auxiliar.
    vector<Pista> streets; ----> Vector para armazenar objetos Pista.
    
    ofstream arquivoSapos;
    ofstream arquivoPistas;
    ofstream arquivoCorridas;
    ifstream arquivoL;
                            .
                            .
                            .
                    
                    {Programa continua}
                           
                            .
                            .
                            .

    return 0;
    }

*Logo depois, declarando os iteradores e abrindo os arquivos para escrever:

                            .
                            .
                            .
    
    arquivoSapos.open("Sapinhos.txt",ios::app);
    arquivoPistas.open("Pistas.txt",ios::app);
    arquivoCorridas.open("Corridas.txt",ios::app);
    
                            .
                            .
                            .
                            
*Criando a sub-rotina menu() para imprimir na tela o respectivo menu de opções: 

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

*Cria-se um ciclo do while para o usuário sempre escolher uma nova ação, logo que outra tenha terminado.
*Existem basicamente seis opções para escolher.

Seção 2:
    
    Funcionalidades:
    
*Funcionalidade 1: Basicamente o usuário poderá visualizar a quantidade de sapos no vector frogs, e se existirem, visualizar suas principais características e estatísticas.

                            .
                            .
                            .
    if(op == "1"){
      if(frogs.empty())
        cout << endl << "Nao ha sapos armazenados" << endl << endl;

      else{
        cout << "Existe(m) " << x << " sapo(s) armazenados" << endl << endl;

        for(it1 = frogs.begin(); it1 != frogs.end(); ++it1)
          cout << *it1 << endl;
        }
    }
                            .
                            .
                            .
                            
*Funcionalidade 2: Basicamente o usuário poderá visualizar a quantidade de pistas no vector streets, e se existirem, visualizar suas principais características e estatísticas.    
                            
                            .
                            .
                            .
    else if(op == "2"){
      if(streets.empty())
        cout << endl << "Nao ha pistas armazenadas" << endl << endl;

      else{
        cout << "Existe(m) " << y << " pista(s) armazenadas" << endl << endl;

        for(it2 = streets.begin(); it2 != streets.end(); ++it2)
          cout << *it2 << endl;
        }
    }
                            . 
                            .
                            .
                            
*Funcionalidade 3: A principal funcionalidade do algoritmo, sendo necessariamente a corrida de sapos em si. A lógica usada basicamente se configura da seguinte forma:
    1)Verifica se o vector streets está vazio, se sim, não pode-se iniciar uma corrida, pois não existe pista. Caso oontrário, o usuário poderá escolher uuma pista para a corrida digitando sua posição de 0 até total-1.
    2)Verifica se o vector frogs está vazio, se sim, não pode-se iniciar uma corrida, pois não existe sapos para competir. Caso oontrário, o usuário poderá escolher sapos para a corrida digitando suas posições de 0 até total-1.(Nesse programa só é permitido para um bom funcionamento do mesmo, escolher os sapos em sequência de posições, ou seja, escolher primeiro o sapo 0, depois o sapo 1, sucessivamente e isso até o total de sapo existentes. A pista escolhida deve-se ter a capacidade de comportar exatamente em uma corrida um número igual ao total de sapos existentes no vector frogs).
    
    do{
    siz2 = frogs.size();
    cout << "Escolha um sapo: "; cin >> pos2;
    pos[i] = pos2; //o vetor pos[i] armazena todas as pos2 que o jogador escolher.

    if(pos2 >= siz2 || pos2 < 0)
    cout << "Nao ha sapo armazenado nesta posicao" << endl << endl;

    else{
    cout << "Sapo escolhido: " << frogs[pos2].getNome() << " com o numero " << frogs[pos2].getIdentificador() << endl << endl;
      i++;
                                        }
                                }while(i < streets[pos1].getNumeroparticipantes());
    
*3)Depois de escolher a pista e os sapos, quando o jogador digitar PEI, os sapos começarão a pular, o método pular() da classe Sapo, permite cada sapo percorrer uma certa quantidade de caminho da pista de acordo com sua capacidade de pulo. Cada sapo pula uma vez.
                            .
                            .
                            .
    
    i = 0;
      
    do{
      
    it1 = frogs.begin();
  
    if(i >= streets[pos1].getNumeroparticipantes())
        i = 0;

    inc = frogs[pos[i]].pular();
    cout << "Sapo " << frogs[pos[i]].getNome() << "[" << frogs[pos[i]].getIdentificador() << "] pulou " << inc << " unidade(s)" << endl <<      endl;

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
                            .
                            .
                            .
                              
*4)Cada Valor de pos[i] = pos2, ou seja, pos2 = as posições que o jogador escolheu. Cada sapo que está na pos2 do vector frogs vai pular(), até que o primeiro sapo chegue no final da pista.

*5)Quando o primeiro sapo chega no final da corrida, ele será inserido no vector auxiliar result, e no vector original frogs, ele será apagado. Este processo acontece até com todos os sapos, onde por fim o vector frogs ficará vazio.

*6)Quando frogs fica vazio, será impresso o rank da corrida:
                            .
                            .
                            .

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
    
                            .
                            .
                            .
                            
*7)No final os arquivos serão atualizados e os dados zerados para quando o jogador quiser iniciar outra corrida, não se acumule valores e cause erros de output.                            
    
*Funcionalidade 4: Basicamente serve como criação de objetos Sapo, armazenando-os no vector<Sapo> frogs, a partir da sobrecarga do operador << em sapos.hpp:
    
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
    
*Funcionalidade 5: Basicamente serve como criação de objetos Pista, armazenando-os no vector<Pista> streets, a partir da sobrecarga do operador << em pistas.hpp: 
    
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
    
*Funcionalidade 6: Esta é a leitura dos arquivos Sapinhos.txt(estatísticas dos sapos), Pistas.txt(estatísticas das pistas) e Corridas.txt(estatísticas dos ranks). Todos estes são atualizados depois de uma corrida.
  Basicamente se ler o arquivo linha por linha e imprime na tela os seus resultados:
  
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
  
*Por fim, o jogador tem a opção de sair do programa, ao digitar SAIR, dai, imprime-se na tela a mensagem "saindo...." e todos os arquivos envolvidos são fechados para desalocar a memory. 

*Em resumo, a corrida de sapos feita em C++, fornece utilizando o paradigma da orientação a objeto, meios para que se torne possível que uma sequência de objetos, possa ser utilizada para abstrair uma corrida entre eles, onde cada um possui um turno, e a medida que cada um chega no final, este não continue "correndo". Isso ocorre até que todos estejam no final. Será fornecio o rank, e envolve-se também a manipulação de arquivos. 

Seção 3:
    
    O Projeto está dividido nas seguintes pastas:
    /bin -> .exe.
    /docs -> documentação no doxygen.
    /src -> código fonte.
    README.md.
    
