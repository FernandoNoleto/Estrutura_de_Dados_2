#ifndef HEURISTICA_H
#define HEURISTICA_H

#include "estruturas.h"
#define MODULO(x)(x>=0?(x):(x*(-1))) //Para calulcar distancias usamos o "modulo"

int comparar_matriz(int** matriz1, int** matriz2, int tam){
    int i, j;
    for(i=0; i < tam; i++){
        for(j = 0; j < tam; j++){
            if(matriz1[i][j] != matriz2[i][j]) return -1;
        }
    }
    return 1;//se for igual retorn 1
}

int buscar(int** vetor, int tam){
    fila* aux=primeiro;
    while (aux!=NULL) {
        if(comparar_matriz(aux->tipo_arvore->matriz, vetor, tam) == 1) return 1;//se for igual
        aux = aux->prox;
    }
    return 0;
}

void copiar_vetor(int*** vetor1, int** vetor2, int tam){
    int i, j;
    for (i = 0;i < tam; i++){
        for (j = 0; j < tam; j++)
            (*vetor1)[i][j] = vetor2[i][j];
    }
}

void encontrar_zero(int** raiz, int *i, int *j, int tam){
    for((*i) = 0; (*i) < tam; (*i)++){
        for((*j) = 0; (*j) < tam; (*j)++){
            if(raiz[(*i)][(*j)] == 0)
                goto A;
        }
    }
    A:
    printf(" ");
}

void troca_valor (int *a, int *b) {
    //funções de mover matriz chama "troca_valor"
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void mover_cima(arvore **aux, int tam, int i, int j){

    int k;
    arvore* aux1 = (arvore*) malloc (sizeof(arvore));
    inicializar(&aux1);
    aux1->matriz = (int**) malloc (tam * sizeof(int*));
    for(k=0; k < tam; k++)
        aux1->matriz[k] = (int*) malloc(tam*sizeof(int));

    copiar_vetor(&(aux1->matriz),((*aux)->matriz), tam);

    strcpy((aux1)->mov,"acima");
    troca_valor(&(aux1->matriz[i][j]), &((aux1)->matriz[(i+1)][j]));
    (*aux)->cima=aux1;
}

void mover_baixo(arvore **aux, int tam, int i, int j){
    int k;
    arvore *aux1 = (arvore*) malloc(sizeof(arvore));

    inicializar(&aux1);

    aux1->matriz = (int**) malloc(tam * sizeof(int*));

    for(k=0; k < tam; k++)
        aux1->matriz[k] = (int*) malloc (tam*sizeof(int));

    copiar_vetor(&(aux1->matriz),((*aux)->matriz), tam);
    strcpy(aux1->mov,"abaixo");
    troca_valor(&((aux1->matriz)[(i-1)][j]), &(aux1->matriz[i][j]));
    (*aux)->baixo = aux1;
}

void mover_direita(arvore **aux, int tam, int i, int j){

    int k;
    arvore *aux1=(arvore*) malloc(sizeof(arvore));

    inicializar(&aux1);

    aux1->matriz = (int**) malloc (tam * sizeof(int*));

    for(k=0; k<tam;k++)
        aux1->matriz[k]=(int*) malloc(tam*sizeof(int));

    copiar_vetor(&(aux1->matriz),((*aux)->matriz), tam);

    strcpy((aux1->mov), "direita");

    troca_valor(&(aux1->matriz[i][(j-1)]),&(aux1->matriz[i][j]));
    (*aux)->direita=(aux1);
}

void mover_esquerda(arvore **aux, int tam, int i, int j){

    int k;
    arvore *aux1=(arvore*) malloc(sizeof(arvore));

    inicializar(&aux1);

    aux1->matriz=(int**) malloc(tam*sizeof(int*));
    for(k=0; k<tam;k++)
        aux1->matriz[k]=(int*) malloc(tam*sizeof(int));

    copiar_vetor(&(aux1->matriz),((*aux)->matriz), tam);

    strcpy((aux1->mov),"esquerda");
    troca_valor(&(aux1->matriz[i][j]),&(aux1->matriz[i][(j+1)]));
    (*aux)->esquerda=(aux1);
}

int distancia_Manhattan(int** matriz, int** matriz_resul, int tam){

    int i,j, k, l, h = 0
            ;
    for(i=0; i < tam; i++){
        for(j=0; j < tam; j++){
            if(matriz[i][j] != 0){
                for(k=0; k < tam; k++){
                    for(l = 0; l < tam; l++){

                        if(matriz[i][j] == matriz_resul[k][l])
                            goto p; //Goto 4ever
                    }
                }
                p:
                h += (MODULO((i-k))+MODULO((j-l)));
            }
        }
    }
    return h;
}

void preencher_arvore(arvore* raiz, int** matriz_resul, int tam, int i, int j){

    pilha* h = NULL;
    iter++;

    if(comparar_matriz(raiz->matriz, matriz_resul, tam) == -1){//se a matriz resultado não esta na raiz

        if(j+1 < tam){ // mover para esquerda
            mover_esquerda(&raiz, tam, i, j);
            push(&h, distancia_Manhattan((raiz->esquerda->matriz), matriz_resul,tam), raiz->esquerda);
        }
        if((j-1) >= 0){ // mover para direita
            mover_direita(&raiz, tam, i, j);
            push(&h, distancia_Manhattan((raiz->direita->matriz), matriz_resul,tam), raiz->direita);
        }
        if((i+1) < tam){ //mover para cima
            mover_cima(&raiz, tam, i, j);
            push(&h, distancia_Manhattan((raiz->cima->matriz), matriz_resul,tam), raiz->cima);

        }
        if((i-1) >= 0){ //mover para baixo
            mover_baixo(&raiz, tam, i, j);
            push(&h, distancia_Manhattan((raiz->baixo->matriz), matriz_resul,tam), raiz->baixo);
        }

        //faz todos os movimentos inserindo a prioridade do proximo movimento em uma pilha

        inserir_fila(raiz, h); //insere o moviento em uma fila a raiz, que sempre será o movimeto feito
       imprimir_matriz(raiz->matriz, tam);

        while(buscar(ultimo->tipo_pilha->tipo_arvore->matriz, tam) == 1) { //verifica se não há nenhum movimento anteriormente igual a esse já feito

            pop(&(ultimo->tipo_pilha));

            if(ultimo->tipo_pilha == NULL){
                remover_fila();
                pop(&(ultimo->tipo_pilha));
                raiz = ultimo->tipo_arvore;
                encontrar_zero(ultimo->tipo_arvore->matriz, &i, &j, tam);
                break;
            }
        }

        if(ultimo->tipo_pilha->tipo_arvore == raiz->esquerda) {
            j++;
            //para esquerda
            preencher_arvore(raiz->esquerda, matriz_resul, tam, i, j);
        }
        else if(ultimo->tipo_pilha->tipo_arvore==raiz->direita){
            j--;
            //para direita
            preencher_arvore(raiz->direita, matriz_resul, tam, i, j);
        }
        else if(ultimo->tipo_pilha->tipo_arvore==raiz->cima){
            i++;
            //para cima
            preencher_arvore(raiz->cima, matriz_resul, tam, i, j);
        }
        else if(ultimo->tipo_pilha->tipo_arvore==raiz->baixo){
            i--;
            //para baixo
            preencher_arvore(raiz->baixo, matriz_resul, tam, i, j);
        }
    }
    else {
        imprimir_fila();
        puts("");
    }
}

int* randon(int tam, int* raiz) { //Gerar numeros aleatorios
    srand((unsigned)time(NULL));

    int i = -1, value, j = -1;

    while (i < (tam * tam -1)) {
        value = (rand()%(tam*tam));

        for(j = 0; j <= i; j++){
            if(value == raiz[j]){
                j = -1;
                break;
            }
        }
        if(j != -1)
            raiz[++i]=value;
    }

    return raiz;
}

int movimentos(int** matriz, int tam) {
    int i, j, k, l, count = 0;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            if(matriz[i][j] != 0){
                l = j;
                for(k = i; k < tam; k++){
                    for(l = 0; l < tam; l++){
                        if(matriz[k][l] != 0 && matriz[i][j] > matriz[k][l]){
                            count++;
                        }
                    }
                    l = 0;
                }
            }

        }
    }

    return count;
}

void comparar_resultado(int* (**matriz_resultado), int* (**matriz_inicial), int** matriz_aux, int tam, int *i, int *j){

    (*matriz_aux) = randon(tam, (*matriz_aux));
    for((*i) = 0; (*i) < tam; (*i)++){
        for ((*j) = 0; (*j) < tam; (*j)++){
            (*matriz_inicial)[*i][*j] = (**matriz_aux);
            (*matriz_aux)++;
        }
    }

    encontrar_zero((*matriz_inicial), i, j, tam);

    if(tam%2 == 0){
        if(((movimentos((*matriz_inicial), tam) + (*i)+1)%2) != 0){
            int b;
            for(b = 0; b < 1000000; b++);
            comparar_resultado(matriz_resultado, matriz_inicial, matriz_aux, tam, i, j);
        }
        else{
            int m, n, val = 1;
            for(m = 0; m < tam; m++) {
                for(n = 0; n < tam; n++){
                    if ( (m == (tam-1) ) && (n == (tam-1)) ) {
                        (*matriz_resultado)[m][n] = 0;
                        break;
                    }
                    (*matriz_resultado)[m][n] = val;
                    val++;
                }
            }
        }
    }
    else{
        if(movimentos((*matriz_inicial), tam)%2 == 0){
            int m, n, val = 1;
            for(m = 0; m < tam; m++){
                for(n = 0; n < tam; n++){
                    if(m == (tam-1) && n == (tam-1)) {
                        (*matriz_resultado)[m][n] = 0;
                        break;
                    }
                    (*matriz_resultado)[m][n]=val;
                    val++;
                }
            }
        }
        else if(tam==3) {//Faz comparação se chegou no resultado se a matriz for 3x3
            (*matriz_resultado)[0][0]=1;
            (*matriz_resultado)[0][1]=2;
            (*matriz_resultado)[0][2]=3;
            (*matriz_resultado)[1][0]=4;
            (*matriz_resultado)[1][1]=5;
            (*matriz_resultado)[1][2]=6;
            (*matriz_resultado)[2][0]=7;
            (*matriz_resultado)[2][1]=8;
            (*matriz_resultado)[2][2]=0;
        }
        else if(tam == 4) {//Faz comparação se chegou no resultado se a matriz for 4x4
            (*matriz_resultado)[0][0]=1;
            (*matriz_resultado)[0][1]=2;
            (*matriz_resultado)[0][2]=3;
            (*matriz_resultado)[0][3]=4;
            (*matriz_resultado)[1][0]=5;
            (*matriz_resultado)[1][1]=6;
            (*matriz_resultado)[1][2]=7;
            (*matriz_resultado)[1][3]=8;
            (*matriz_resultado)[2][0]=9;
            (*matriz_resultado)[2][1]=10;
            (*matriz_resultado)[2][2]=11;
            (*matriz_resultado)[2][3]=12;
            (*matriz_resultado)[3][0]=13;
            (*matriz_resultado)[3][1]=14;
            (*matriz_resultado)[3][2]=15;
            (*matriz_resultado)[3][3]=0;
        }

        else{ //Faz comparação se chegou no resultado para os demais tamamnhos de matrizes
            int b;
            for(b = 0; b < 1000000; b++)
                comparar_resultado(matriz_resultado, matriz_inicial, matriz_aux, tam, i, j);
        }
    }
}

/*funções especiais para matrizes*/

int** matriz_final(int tam) {
    int count = 1;
    int** matriz = (int**) malloc (tam * sizeof(int*));

    for (int i = 0; i < tam; i++){
        matriz[i] = (int*) malloc (tam * sizeof(int));
        for (int j = 0; j < tam; j++){
            if (count == tam*tam) count = 0;
            matriz[i][j] = count;
            count++;
        }
    }

    return matriz;
}

void imprimir_matriz(int** matriz, int tam){

    for(int i = 0; i < tam; i++)
        printf("----");

    puts("");

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(matriz[i][j] < 10)
                printf(" ");
            printf("|%d|", matriz[i][j]);
        }
        puts("");
        for(int k = 0; k < tam; k++)
            printf("----");
        puts("");
    }

}

#endif // HEURISTICA_H
