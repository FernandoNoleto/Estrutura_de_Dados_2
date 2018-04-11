#ifndef H_ABB_H
#define H_ABB_H

struct no{
	int info;
	struct no* esq;
	struct no* dir;
};

typedef struct no tno;

void inicializar(tno** t);
void insere(tno **t, int x);
void preOrdem(tno *t);
void Ordem(tno *t);
void posOrdem(tno *t);


tno* busca(tno* t, int x);

void remover(tno**t, int x);

void atualizar(tno** t, int v, int n);

void inserirSemRecursividade(tno** t, int x);

#endif
