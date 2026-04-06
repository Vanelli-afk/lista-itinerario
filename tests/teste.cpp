#include "lista.h"
#include <iostream>
using namespace std;

int main() {    
    Lista lista;

    cout<<"Criando lista...\n";
    criarLista(lista);

    cout<<"Preenchendo lista...\n";

    insereParadaInicio(lista, "Santo Amaro");
    insereParadaFinal(lista, "Palhoca");
    insereParadaFinal(lista, "Sao Jose");
    insereParadaInicio(lista, "Rancho Queimado");
    insereParadaPosicao(lista, "Aguas Mornas", 1);

    cout<<"Mostrando rota...\n";
    mostrarRota(lista);

    cout<<"\nMostrando rota inversa...\n";
    mostrarRotaInversa(lista);

    cout<<"\nBuscando Parada...\n";
    buscarParada(lista, "Sao Jose");
    return 0;
}