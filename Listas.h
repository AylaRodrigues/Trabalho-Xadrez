#include <stdlib.h>

struct Jogada {
    int deLinha,deColuna,paraLinha,paraColuna;
    struct Jogada *prox,*ant;
};

struct Peca {
    int codigo,linha,coluna,ataques;
    struct Peca *prox,*ant;
};

struct Jogada *CriaListaJogada() {
    struct Jogada *sentinela =(struct Jogada *)malloc(sizeof(struct Jogada));
    sentinela->prox = sentinela;
    sentinela->ant = sentinela;
    return sentinela;
}

struct Jogada *CriaJogada(int deLinha, int deColuna, int paraLinha, int paraColuna) {
    struct Jogada *jog =(struct Jogada *)malloc(sizeof(struct Jogada));
    jog->deLinha = deLinha;
    jog->deColuna = deColuna;
    jog->paraLinha = paraLinha;
    jog->paraColuna = paraColuna;
    jog->prox = NULL;
    jog->ant = NULL;
    
    return jog;
}

void *InsereJogada(struct Jogada *lista,int paraLinha,int paraColuna,int deLinha,int deColuna) {
    struct Jogada *novo = CriaJogada(deLinha,deColuna,paraLinha,paraColuna);
    novo->prox=lista;
    novo->ant=lista->ant;
    lista->ant->prox=novo;
    lista->ant=novo;
    
}

void *BuscaJogada(struct Jogada *lista,int paraLinha,int paraColuna,int deLinha,int deColuna) {
    struct Jogada *aux = lista->prox;
    while(aux != lista && (aux->deLinha != deLinha || aux->deColuna != deColuna || aux->paraLinha !=paraLinha || aux->paraColuna !=paraColuna)){
        aux= aux->prox;
    }
        if(aux!=lista){
            return aux;
        }else{
            return NULL;
        }
    } 
    
    struct Jogada *DestroiJogada(struct Jogada *lista) {
    struct Jogada *aux;
    lista->ant->prox=NULL;
    while(lista != NULL) {
        aux = lista-> prox;
        free(lista);
        lista=aux;
    }
    return NULL;
}

struct Peca *CriaListaPeca() {
    struct Peca *sentinela=(struct Peca *)malloc(sizeof(struct Peca));
    sentinela->prox=sentinela;
    sentinela->ant=sentinela;
    return sentinela;
}

struct Peca *CriaPeca(int codigo, int linha, int coluna) {
    struct Peca *resp = (struct Peca *) malloc(sizeof(struct Peca));
    resp->codigo = codigo;
    resp->linha=linha;
    resp->coluna=coluna;
    resp->ant = NULL;
    resp->prox = NULL;

    return resp;
}

void *InserePeca(struct Peca *lista,int codigo, int linha, int coluna) {
    struct Peca *novo = CriaPeca(codigo,linha,coluna);
    novo->prox=lista;
    novo->ant=lista->ant;
    lista->ant->prox=novo;
    lista->ant=novo;
    
    return novo;
}

struct Peca *DestroiListaPeca(struct Peca *lista){
    struct Peca *aux;
    lista->ant->prox=NULL;
    while(lista != NULL) {
        aux = lista-> prox;
        free(lista);
        lista=aux;
    }
    return NULL;
}
void RemovePeca(struct Peca *aux) { 
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
    free(aux);
}


