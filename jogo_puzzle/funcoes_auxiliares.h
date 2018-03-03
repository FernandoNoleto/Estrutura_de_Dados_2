#ifndef FUNCOES_AUXILIARES_H
#define FUNCOES_AUXILIARES_H
#include <time.h>
#include "lista.h"
#include "arvore.h"

void imprimir_matriz(int**, int);

int existe(lista* l, int x){

    for(tno* aux = l->inicio; aux != NULL; aux = aux->prox){
        if(aux->info == x){
            inserir_lista(l, x);
            return 1;
        }
    }
    inserir_lista(l, x);

    return 0;
}

int** alocarMatriz(int tam, lista* l){

    srand( (unsigned)time(NULL) );

    int tamv = tam*tam;

    int** m = (int**) malloc (tam * sizeof(int*));

    for (int i = 0; i < tam; i++){
        m[i] = (int*) malloc (tam * sizeof(int));
        for (int j = 0; j < tam; j++){

            int valor = (rand()%(tamv))+1;
            while(existe(l, valor)){
                valor = (rand()%(tamv))+1;
            }

            if (valor == tamv) valor = 0;

            m[i][j] = valor;
        }
    }
    puts("");
    return m;
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

void criar_novo_no_matriz(tree** t, int tam){
    lista* l = (lista*) malloc (sizeof(lista));
    int** matriz = alocarMatriz(tam, l);
    inserir_arvore(t, matriz, 'n');
}

int possibilidades(tree* t, int tam){
    int pos;
    int** matriz = t->matriz;
    int i, j;

    for(i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            if(matriz[i][j] == 1) break;
        }
        if(matriz[i][j] == 1) break;
    }

    pos = (i-0) + (j-0);


    return pos;
}

void move_esquerda(int** matriz, int lin, int col, tree** t){
    int x = matriz[lin][col-1];
    matriz[lin][col-1] = 0;
    matriz[lin][col] = x;
    //imprimir_matriz((*t)->matriz, tam);
    inserir_arvore(t, matriz, 'e');
}

void move_cima(int** matriz, int lin, int col, tree** t){
    int x = matriz[lin-1][col];
    matriz[lin-1][col] = 0;
    matriz[lin][col] = x;
    inserir_arvore(t, matriz, 'c');
}

void move_direita(int** matriz, int lin, int col, tree* t){
    int x = matriz[lin][col+1];
    matriz[lin][col+1] = 0;
    matriz[lin][col] = x;
    inserir_arvore(&t, matriz, 'd');

}

void move_baixo(int** matriz, int lin, int col, tree* t){
    int x = matriz[lin+1][col];
    matriz[lin+1][col] = 0;
    matriz[lin][col] = x;
    inserir_arvore(&t, matriz, 'b');

}

int** mat_aux(tree* t, int tam){
    int** matriz = (int**) malloc (tam * sizeof(int*));

    for (int i = 0; i < tam; i++){
        matriz[i] = (int*) malloc (tam * sizeof(int));
        for (int j = 0; j < tam; j++){
            matriz[i][j] = t->matriz[i][j];
        }
    }

    return matriz;
}

void posicao_zero(tree** t, int tam){

    int lin, col;
    int** matriz = mat_aux(*t, tam);

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(matriz[i][j] == 0){
                lin = i;
                col = j;
            }
        }
    }


    if(col!=0){
        move_esquerda(matriz, lin, col, t);
        return;
    }


    if(lin!=0){
        move_cima(matriz, lin, col, t);
        return;
    }

    //if(lin == 0) printf("Nao pode ir pra cima\n");
    //if(col == (tam-1)) printf("Nao pode ir pra direita\n");
    //if(lin == (tam-1)) printf("Nao pode ir pra baixo\n");
    //if(col != 0 && lin != 0 && col != (tam-1) && lin != (tam-1)) printf ("Pode ir pra qualquer lado carai!\n");

}

#endif // FUNCOES_AUXILIARES_H
