#include "hash.h"

hash* criar(int tam) {

    struct aluno** a =  malloc(tam * sizeof(struct aluno*));
    hash* h = (hash*) malloc(sizeof(hash));
    if(h != NULL) {
        int i;
        h->tam = tam;
        h->elem = a;
        if(h->elem == NULL) {
            free(h);
            return h;
        }
        h->qtd = 0;
        for (i=0;i< h->tam; i++) {
            h->elem [i] = NULL;
        }
    }
    return h;
}

void liberar ( hash * h) {

    if(h != NULL) {
        for(int i =0; i < h->tam; i++) {
            if(h->elem[i] != NULL)
                free(h->elem[i]);
        }
        free(h->elem);
        free(h);
    }
}

int hashing (int c, int tam) {
    float a = 0.6180339887;
    float v = c * a;
    v = v -(int) v;
    return (int) (tam * v);
}

int insere(hash * h, struct aluno a ) {
    if(h == NULL || h->qtd == h->tam)
        return 0;

    int c = a.mat;
    int p = hashing(c,h->tam);
    struct aluno* n;

    n = (struct aluno*) malloc (sizeof(struct aluno));

    if(n == NULL)
        return 0;
    *n = a;
    h->elem[p] = n;
    h-> qtd ++;
    return 1;
}

int busca(hash * h, int mat, struct aluno* a) {

    if(h == NULL)
        return 0;

    int p = hashing (mat,h->tam);
    *a = *(h->elem[p]);
    return p;
}
