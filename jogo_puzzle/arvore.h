#ifndef ARVORE_H
#define ARVORE_H
#include "funcoes_auxiliares.h"

typedef struct no{
    int** matriz;
    struct no* up;
    struct no* down;
    struct no* left;
    struct no* right;
}tree;

void imprimir_arvore(tree*, int);

void inserir_arvore(tree** t, int** x, char mov){
    if(*t == NULL){
        tree* novo = (tree*) malloc (sizeof(tree));
        novo->matriz = x;
        novo->up = NULL;
        novo->down = NULL;
        novo->left = NULL;
        novo->right = NULL;
        *t = novo;
    }
    else{
        tree* novo = (tree*) malloc (sizeof(tree));
        novo->matriz = x;
        novo->up = NULL;
        novo->down = NULL;
        novo->left = NULL;
        novo->right = NULL;


        if(mov == 'e')
            (*t)->left = novo;
        else if(mov == 'd')
            (*t)->right = novo;
        else if(mov == 'c')
            (*t)->up = novo;
        else if(mov == 'b')
            (*t)->down = novo;

    }
}

void imprimir_arvore(tree* t, int tam){
    if(t != NULL){
        puts("Nó:");
        imprimir_matriz(t->matriz, tam);
        imprimir_arvore(t->up, tam);
        imprimir_arvore(t->down, tam);
        imprimir_arvore(t->left, tam);
        imprimir_arvore(t->right, tam);
    }
}

#endif // ARVORE_H
