/*
 * main_rubro_negra_1.c
 *
 *  Created on: 4 de mai de 2017
 *      Author: fernando
 */


#include <stdio.h>
#include <stdlib.h>

struct _no{
	int info;
	struct _no* esq;
	struct _no* dir;
	char cor;
};

typedef struct _no arn;

void inserir(arn**, int);
void balancear(arn**, arn**, arn**);
void RE(arn**, arn**, arn**);
void preOrdem(arn*);


int main(){

	arn* t = NULL;

	inserir(&t, 10);
	inserir(&t, 15);
	inserir(&t, 5);
	inserir(&t, 20);

	preOrdem(t);

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

		printf("Pai de %i e %i  \n",aux->info, pai->info );
		if(avo != NULL)
			printf("Avo de %i eh %i\n", aux->info, avo->info);


	}

	balancear(&aux, &pai, &avo);

}

void preOrdem(arn* t){
	if(t!=NULL && t->info != -1){
		printf("%i,%c\n",t->info, t->cor);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}
}

void balancear(arn** t, arn** pai, arn** avo){

	if(((*t)->cor == 'R') && ((*pai)->cor == 'R')){
			printf("sfgfdhf\n");

			//RE(t, pai, avo);
		}

	}

void RE(arn** t, arn** pai, arn** avo){

	printf("Avo");
	(*pai)->dir = (*pai)->esq;

	(*pai)->esq = *avo;
	(*pai)->cor = 'N';
	(*t)->cor = 'N';
	(*pai) = (*avo);

}
