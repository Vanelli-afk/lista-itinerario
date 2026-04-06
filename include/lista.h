#ifndef LISTA_H
#define LISTA_H

#include <string>
using namespace std;

struct Node {
    string nome;
    struct Node* prox;
    struct Node* ant;
};

struct Lista{
    Node* inicio;
    Node* fim;
    int cardinalidade;
};

void criarLista(Lista &lista);

void insereParadaInicio(Lista &lista, string nome);

void insereParadaFinal(Lista &lista, string nome);

void insereParadaPosicao(Lista &lista, string nome, int pos);

void removePrimeiraParada(Lista &lista);

void removeUltimaParada(Lista &lista);

void buscarParada(Lista lista, string nome);

void mostrarRota(Lista lista);

void mostrarRotaInversa(Lista lista);

int contarParadas(Lista lista);

#endif