#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	struct no* dir;
	struct no* esq;
	char cor;
};

typedef struct no arn;

void inserir(arn**, int);
void preOrdem(arn*);
void balancear(arn**, arn**);
void RD(arn**);
void RE(arn**);
void RDD(arn**);
void RDE(arn**);
int altura(arn*);
int fator_balanceamento(arn*);
arn* verificar_arvore(arn*);
arn* maiorDireita(arn**);
void mudarCor(arn*);


int main(){

	arn* t = NULL;

	inserir(&t, 10);
	inserir(&t, 15);
	inserir(&t, 20);
	inserir(&t, 50);
	preOrdem(t);

	return 0;
}

void inserir(arn** t, int x){

	arn* aux;
	arn* pai;
	arn* avo;

	if(*t == NULL){
		arn* novo = (arn*) malloc (sizeof(arn));
		arn* esq = (arn*) malloc (sizeof(arn));
		arn* dir = (arn*) malloc (sizeof(arn));
		novo->info = x;
		novo->cor = 'N';
		novo->dir = dir;
		novo->dir->cor = 'N';
		novo->dir->info = -1;
		novo->esq = esq;
		novo->esq->cor = 'N';
		novo->esq->info = -1;
		*t = novo;
	}

	else{
		aux = *t;
		pai = NULL;
		avo = NULL;

		while(aux->info != -1){

			if(x < aux->info){
				if(pai!=NULL)
					avo = pai;
				pai = aux;
				aux = aux->esq;

			}
			else{
				if(pai!=NULL)
					avo = pai;
				pai = aux;
				aux = aux->dir;
			}

		}

		arn* esq = (arn*) malloc (sizeof(arn));
		arn* dir = (arn*) malloc (sizeof(arn));

		aux->info = x;
		aux->cor = 'R';
		aux->dir = dir;
		aux->dir->cor = 'N';
		aux->dir->info = -1;
		aux->esq = esq;
		aux->esq->cor = 'N';
		aux->esq->info = -1;

		arn* aux2 = pai;

		if(aux2->info < aux->info)
			aux2->dir = aux;
		else
			aux2->esq = aux;

	}


	*t = verificar_arvore(*t);

}

void preOrdem(arn* t){
	if(t!=NULL && t->info != -1){
		printf("%i,%c\n",t->info, t->cor);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}
}

void balancear(arn** t, arn** pai){

}

void RD(arn** t){
	arn* u;
	u = (*t)->esq;
	(*t)->esq = u->dir;
	u->dir = (*t);
	(*t) = u;
}

void RE(arn** t){
	arn* u;
	u = (*t)->dir;
	(*t)->dir = u->esq;
	u->esq = (*t);
	(*t) = u;
}

void RDD(arn** t){
	arn* u = (*t)->esq;
	arn* v = u->dir;

	u->dir = v->esq;
	v->esq = u;
	(*t)->esq = v->dir;
	v->dir = (*t);
	(*t) = v;

}

void RDE(arn** t){
	arn* u = (*t)->dir;
	arn* v = u->esq;

	u->esq = v->dir;
	v->dir = u;
	(*t)->dir = v->esq;
	v->esq = (*t);

	(*t) = v;
}

int altura(arn* t){
	int lh, rh;
	if (t == NULL) return 0;
	else{
		lh = altura (t->esq);
		rh = altura (t->dir);
		if (lh > rh)
			return (lh+1);
		else
			return (rh+1);
	}
}

int fator_balanceamento(arn* t){
	if(!t) return 0;
	return (altura(t->esq) - altura(t->dir));
}

arn* verificar_arvore(arn* t){

	if(t != NULL){

		int fbt = fator_balanceamento(t);
		int fbe = fator_balanceamento(t->esq);
		int fbd = fator_balanceamento(t->dir);


		if(fbt < -1){
			if(fbd == -1){
				RE(&t);
				return t;
			}
			if(fbd == 1){
				RDE(&t);
				return t;
			}
		}

		if(fbt > 1){

			if(fbe == 1){
				RD(&t);
				return t;
			}
			if(fbe == -1){
				RDD(&t);
				return t;
			}
		}
		verificar_arvore(t->dir);
		verificar_arvore(t->esq);
	}

	return t;
}

arn* maiorDireita(arn** t){

	arn* pAux;

	if((*t)->dir != NULL)
		return maiorDireita(&((*t)->dir));
	else{
		//arn *pAux;
		pAux = *t;

		if ((*t)->esq != NULL)
			*t = (*t)->esq;
		else
			*t = NULL;
	}
	return pAux;
}

void mudarCor(arn* t){

}




