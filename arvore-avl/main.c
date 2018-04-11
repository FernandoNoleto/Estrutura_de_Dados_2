#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	int fb;
	struct no* esq;
	struct no* dir;
};

typedef struct no tavl;

void caso1(tavl**, int*);

void caso2(tavl**, int*);

void RD(tavl**);

void RDD(tavl**);

void RE(tavl**);

void RDE(tavl**);

void insAVL(tavl**, int, int*);

void preOrdem(tavl*);

int main(){

	tavl* p;
	int* h = 0;

	insAVL(&p, 10, h);
	insAVL(&p, 5, h);
	insAVL(&p, 8, h);
	insAVL(&p, 12, h);
	preOrdem(p);


	return 0;
}

void caso1(tavl** p, int* h){
	tavl* u;
	u = (*p)->esq;
	if(u->fb == -1) RD(p);

	else RDD(p);

	(*p)->fb = 0;
	*h = 0;
}

void caso2(tavl** p, int* h){
	tavl* z;
	z = (*p)->dir;
	if(z->fb == 1) RE(p);

	else RDE(p);

	(*p)->fb = 0;
	*h = 0;
}

void RD(tavl** p){
	tavl* u;
	u = (*p)->esq;
	(*p)->esq = u->dir;
	u->dir = *p;
	(*p)->fb = 0;
	(*p) = u;
}

void RDD(tavl** p){
	/*definindo u e v*/
	tavl* u;
	tavl* v;
	u = (*p)->esq;
	v = u->dir;
	/*--------------*/

	u->dir = v->esq;
	v->esq = u;
	(*p)->esq = v->dir;
	v->dir = *p;

	//Atualizando os FB
	u->fb = (v->fb == 1)? -1:0;
	(*p)->fb = (v->fb == -1)? 1:0;

	*p = v;

}

void RE(tavl** p){
	tavl* u;
	u = (*p)->dir;
	(*p)->dir = u->esq;
	u->esq = *p;
	(*p) = u;
	(*p)->fb = 0;
}

void RDE(tavl** p){
	/*definido u e v*/
	tavl* u;
	tavl* v;
	u = (*p)->dir;
	v = u->esq;
	/*--------------*/

	u->esq = v->dir;
	v->dir = u;
	(*p)->dir = v->esq;
	v->esq = *p;

	//Atualizando os FB
	u->fb = (v->fb == 1)? -1:0;
	(*p)->fb = (v->fb == -1)? 1:0;

	*p = v;

}

void insAVL(tavl** p, int x, int *h){

	if(*p == NULL){
		 tavl *novo;
		 novo = (tavl*) malloc(sizeof(tavl));
		 novo->info = x;
		 novo->dir = NULL;
		 novo->esq = NULL;
		 novo->fb = 0;
		 *h = 1;
		 *p = novo;

	}

	else{
		if(x < (*p)->info){
			insAVL(&((*p)->esq), x, h);
			if(*h){
				switch((*p)->fb){
					case  1: (*p)->fb = 0; *h = 0; break;
					case  0: (*p)->fb = -1; break;
					case -1: caso1(p,h);

				}
			}
		}
		else{
			if(x <= (*p)->info){
				insAVL(&((*p)->dir), x, h);
				if(*h){
					switch ((*p)->fb) {
						case -1: (*p)->fb = 0; *h = 0; break;
						case  0: (*p)->fb = 1; break;
						case  1: caso2(p, h);
					}
				}
			}
		}
	}

}


void preOrdem(tavl* t){
	if(t!=NULL){
		printf("%i\n",t->info);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}
}
