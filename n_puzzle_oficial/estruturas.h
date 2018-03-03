#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/*estrutura de arvore*/

typedef struct no_arv{
    int** matriz;
    char mov[9];
    struct no_arv* direita;
    struct no_arv* esquerda;
    struct no_arv* cima;
    struct no_arv* baixo;
}arvore;

/*estrutura de pilha*/

typedef struct no_pilha{
    int heuristica;
    arvore* tipo_arvore;
    struct no_pilha* prox;
}pilha;

/*estrutura de fila*/

typedef struct no_fila{
    arvore* tipo_arvore;
    pilha* tipo_pilha;
    struct no_fila *prox;
}fila;

/********************************************/

fila* primeiro = NULL;
fila* ultimo = NULL;
unsigned int count = 0, iter = 0;

/*funções arvore*/

void inicializar(arvore **t){
    (*t)->direita = NULL;
    (*t)->esquerda = NULL;
    (*t)->cima = NULL;
    (*t)->baixo = NULL;
}

/*funções fila*/

void inserir_fila(arvore *T, pilha *h){

    count++;
    fila* aux=(fila*) malloc(sizeof(fila));
    if(aux == NULL)
        printf("MEMORIA CHEIA\n");

    aux->prox = NULL;
    aux->tipo_arvore=T;
    aux->tipo_pilha=h;
    if(primeiro == NULL){
        primeiro = aux;
        ultimo = aux;
    }
    else{
        ultimo->prox = aux;
        ultimo = aux;
    }
}

void remover_fila() {
    count--;
    if(primeiro == ultimo) {
        free(primeiro);
        primeiro = NULL;
        ultimo = NULL;
    }
    else{
        fila* aux = primeiro;
        arvore* aux_T, *aux_T2;
        while (aux->prox != ultimo)
            aux = aux->prox;

        ultimo = aux;
        aux_T2 = aux->tipo_arvore;

        if (aux_T2->esquerda == ultimo->prox->tipo_arvore){
            aux_T = aux_T2->esquerda;
            aux_T2->esquerda = NULL;
        }

        else if(aux_T2->direita==ultimo->prox->tipo_arvore){
            aux_T = aux_T2->direita;
            aux_T2->direita = NULL;
        }
        else if(aux_T2->cima == ultimo->prox->tipo_arvore){
            aux_T = aux_T2->cima;
            aux_T2->baixo = NULL;
        }
        else if(aux_T2->baixo == ultimo->prox->tipo_arvore){
            aux_T = aux_T2->baixo;
            aux_T2->baixo = NULL;
        }

        free(aux_T);
        free(aux->prox);
        ultimo->prox = NULL;
    }
}

void imprimir_fila(){
    fila* aux = primeiro;
    while (aux != NULL){
        printf("\nMovimento: %s", aux->tipo_arvore->mov);
        aux = aux->prox;
    }
}

/*funções de pilha*/

void push(pilha** p, int valor, arvore* tree){
    pilha* aux = (pilha*) malloc (sizeof(pilha));
    if(aux == NULL)
        printf("MEMORIA CHEIA\n");
    aux->heuristica = valor;
    aux->tipo_arvore = tree;
    aux->prox = NULL;
    if((*p) == NULL)
        (*p) = aux;
    else if(aux->heuristica <= (*p)->heuristica){
        aux->prox = (*p);
        (*p)=aux;
    }
    else{
        pilha *aux2 = (*p);
        while (aux2->prox != NULL && aux2->prox->heuristica <= valor)
            aux2=aux2->prox;
        if(aux2->prox != NULL){
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
        else
            aux2->prox = aux;
    }
}

void pop(pilha** p){
    if((*p)->prox == NULL){
        free(*p);
        (*p) = NULL;
    }
    else{
        pilha *aux = (*p);
        (*p) = (*p)->prox;
        free(aux);
    }
}

void imprimir_pilha(pilha *p){
    while (p != NULL) {
        printf("HH: %d\n", p->heuristica);
        p = p->prox;
    }
}



#endif // ESTRUTURAS_H
