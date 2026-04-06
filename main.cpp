#include <iostream>
#include "lista.h"
using namespace std;

int main(){
    Lista lista;
    unsigned pos, op; 
    string nome;

    criarLista(lista);

    do{
        cout<<"\n==== Menu ===="<< endl;
        cout<<"1. Inserir Parada (Inicio)"<<endl;
        cout<<"2. Inserir Parada (Final)"<<endl;
        cout<<"3. Inserir Parada (Posicao)"<<endl;
        cout<<"4. Remover Parada (Primeira)"<<endl;
        cout<<"5. Remover Parada (Ultima)"<<endl;
        cout<<"6. Buscar Parada"<<endl;
        cout<<"7. Mostrar Rota"<<endl;
        cout<<"8. Mostrar Rota (Inversa)"<<endl;
        cout<<"9. Contar Paradas"<<endl;
        cout<<"0. Sair do Sistema"<<endl;
        cout<<"================"<<endl;

        do{ 
            cout<<"Insira a opcao (1 - 9): ";
            cin>>op;
            if(op < 0 or op > 9)
                cout<<"Valor Invalido!";
        }while(op < 0 or op > 9);

        cin.ignore();

        switch(op){
            case 1:
                try{
                    cout<<"\nInsira o nome da Parada: ";
                    getline(cin, nome);
                    insereParadaInicio(lista, nome);
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 2:
                try{
                    cout<<"\nInsira o nome da Parada: ";
                    getline(cin, nome);
                    insereParadaFinal(lista, nome);
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 3:
                try{
                    cout<<"\nInsira o nome da Parada: ";
                    getline(cin, nome);
                    cout<<"\nInsira a Posicao em que deseja adicionar: "; 
                    cin>>pos;
                    insereParadaPosicao(lista, nome, pos);
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 4:
                try{
                    cout<<"\nRemovendo primeira Parada...";
                    removePrimeiraParada(lista);
                    cout<<"\nParada Removida!";
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 5:
                try{
                    cout<<"\nRemovendo ultima Parada...";
                    removeUltimaParada(lista);
                    cout<<"\nParada Removida!";
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 6:
                try{
                    cout<<"\nInsira a Parada que deseja buscar: ";
                    getline(cin, nome);
                    buscarParada(lista, nome);
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 7:
                try{
                    cout<<"\nInicializando visualizacao de rota..."<<endl<<endl;
                    mostrarRota(lista);
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 8:
                try{
                    cout<<"\nInicializando visualizacao inversa de rota..."<<endl<<endl;
                    mostrarRotaInversa(lista);
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;

            case 9:
                try{
                    cout<<"\nQuantidade de Paradas: "<<contarParadas(lista);
                } catch(const exception &e){
                    cout<<"Erro: "<< e.what() << endl;
                }
                break;
        }
    }while(op != 0);

    return 0;
}