#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	struct no* esq;
	struct no* dir;
};


typedef struct no tno;

void insere(tno **t, int x){
	if(*t == NULL){
		tno* novo = (tno*) malloc (sizeof(tno));
		novo->info = x;
		novo->esq = NULL;
		novo->dir = NULL;
		*t = novo;
	}
	else{
		tno *aux = *t;
		if(x < aux->info)
			insere(&(aux->esq),x);
		else
			insere(&(aux->dir),x);
	}
}

void preOrdem(tno *t){
	if(t){
		printf("%i\n",t->info);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}

}

void ordem(tno *t){
	if(t){
		ordem(t->esq);
		printf("%i\n", t->info);
		ordem(t->dir);
	}
}

void posOrdem(tno* t){
	if(t){
		posOrdem(t->esq);
		posOrdem(t->dir);
		printf("%i\n", t->info);
	}
}

void RE(tno** p){
	tno* u;
	u = (*p)->dir;
	(*p)->dir = u->esq;
	u->esq = *p;
	(*p) = u;
}

void RDE(tno** p){
	tno* u;
	u = (*p)->dir;
	tno* v;
	v = u->esq;

	(*p)->dir = v->esq;
	v->esq = (*p);
	u->esq = v->dir;
	v->dir = u;

	(*p) = v;
}

int altura(tno* root){
	if(root == NULL) return -1;

	int hesq = altura(root->esq);
	int hdir = altura(root->dir);

	if(hdir < hesq) return (hesq + 1);
	return (hdir +1);

}

int fBalanceamento (tno* t){
	if(t == NULL) return 0;
	return (altura(t->esq) - altura(t->dir));
}

int main(){
	tno *t = NULL;

	insere(&t,10);
	insere(&t,9);
	insere(&t,17);
	insere(&t,15);
	insere(&t,18);
	insere(&t,20);

	int h = altura(t);
	printf("altura %i\n", h);

	int fb = fBalanceamento(t);
	printf("fator de balanceamento %i\n", fb);


	puts("PRE Ordem:");
	preOrdem(t);

	//RDE(&(t)->dir);
	//puts("posOrdem:");
	//posOrdem(t);

}
