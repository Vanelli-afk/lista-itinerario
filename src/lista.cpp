#include "lista.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void criarLista(Lista &lista){
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.cardinalidade = 0;
}

void insereParadaInicio(Lista &lista, string nome){
    Node* novo = new Node;
    if(novo == NULL) throw runtime_error("Erro de alocacao");

    novo->nome = nome;
    novo->ant = NULL;
    novo->prox = lista.inicio;

    if(lista.inicio != NULL){
        lista.inicio->ant = novo; // se nao vazia => antigo inicio .ant precisa apontar pro novo
    } else {
        lista.fim = novo; // pq se nao pode quebrar outras funcoes
    }

    lista.inicio = novo; // conecta nodos
    lista.cardinalidade++; //aumenta tam 
}

void insereParadaFinal(Lista &lista, string nome){
    Node* novo = new Node;
    if(novo == NULL) throw runtime_error("Erro de alocacao");

    novo->nome = nome;
    novo->prox = NULL;
    novo->ant = lista.fim;
    
    if(lista.fim != NULL){
        lista.fim->prox = novo; // antigo fim .prox aponta pro novo
    } else {
        lista.inicio = novo; // se nao pode quebrar outra funcao
    }

    lista.fim = novo;
    lista.cardinalidade++;
}


void insereParadaPosicao(Lista &lista, string nome, int pos){
    // validando posições especificas
    if(pos < 0 or pos > lista.cardinalidade){
        throw invalid_argument("POSICAO INVALIDA");
    }

    if(pos == 0){
        insereParadaInicio(lista, nome);
        return;
    }

    if(pos == lista.cardinalidade){
        insereParadaFinal(lista, nome);
        return;
    }

    // adicionando na posicao
    Node* novo = new Node;
    if(novo == NULL) throw runtime_error("Erro de alocacao");

    Node* aux = lista.inicio;
    novo->nome = nome;
    
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }

    // conecta nos polos do "C"
    novo->prox = aux;
    novo->ant = aux->ant;

    // reconecta "A" e "B" ao "C"
    aux->ant->prox = novo; // sem precisar fazer outro no, acessa o prox do anterior ao aux
    aux->ant = novo;

    lista.cardinalidade++;
}

void removePrimeiraParada(Lista &lista){
    if(lista.inicio == NULL){
        throw runtime_error("Lista vazia");
    }

    Node* aux = lista.inicio;
    lista.inicio = lista.inicio->prox;
    
    if(lista.inicio != NULL){
        lista.inicio->ant = NULL;
    } else {
        lista.fim = NULL; //evitar lixo
    }

    delete aux;
    lista.cardinalidade--;
}

void removeUltimaParada(Lista &lista){
    if(lista.fim == NULL){
        throw runtime_error("Lista vazia");
    }

    Node* aux = lista.fim;
    lista.fim = lista.fim->ant;

    if(lista.fim != NULL){
        lista.fim->prox = NULL;
    } else {
        lista.inicio = NULL; // lista vazia
    }

    delete aux;
    lista.cardinalidade--;
}

void buscarParada(Lista lista, string nome){
    Node* aux = lista.inicio;
    
    while(aux != NULL){
        if(aux->nome.find(nome) != string::npos){
            cout<<"Parada Encontrada: "<< aux->nome << endl;
            return;
        }
        aux = aux->prox;    
    } 

    throw runtime_error("Parada Inexistente");
}

void mostrarRota(Lista lista){
    Node* aux = lista.inicio;
    
    while(aux != NULL){
        cout << aux->nome << " | ";
        aux = aux->prox;
    }

    cout << endl;
}

void mostrarRotaInversa(Lista lista){
    Node* aux = lista.fim;

    while(aux != NULL){
        cout << aux->nome << " | ";
        aux = aux->ant;
    }

    cout << endl;
}

int contarParadas(Lista lista){
    return lista.cardinalidade; 
}