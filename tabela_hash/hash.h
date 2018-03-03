#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.c"	


/* Usando a struct aluno apenas como exemplo para popular a tabela,
 * porém pode-se utilar qualquer tipo de dados
 */

struct aluno {
    int mat;
    char nome[30];
    float n1,n2;
};

typedef struct Hash {
    int qtd, tam;
    struct aluno** elem;
}hash;

hash* criar(int);

void liberar(hash*);

int hashing (int, int);

int insere(hash*, struct aluno);

int busca(hash* , int, struct aluno*);

#endif // HASH_H
