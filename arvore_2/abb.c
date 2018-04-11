#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

typedef tno** arvore;

void inicializar(tno** t){
	*t = NULL;
}

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
	if(t!=NULL){
		printf("%i\n",t->info);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}
}
void ordem(tno *t){
	if(t!=NULL){
		ordem(t->esq);
		printf("%i\n", t->info);
		ordem(t->dir);
	}
}
void posOrdem(tno *t){
	if(t!=NULL){
		posOrdem(t->esq);
		posOrdem(t->dir);
		printf("%i\n", t->info);
	}
}

tno *busca(tno* t, int x){


	if(t!=NULL){

		if(t->info == x){

			printf("\nNumero Buscado: %i\n", t->info);
			return t;
		}
		busca(t->esq, x);
		busca(t->dir, x);
	}
	return NULL;

}

tno* maiorDireita(tno** t){
	tno* pAux;
	if((*t)->dir != NULL)
		maiorDireita(&((*t)->dir));
	else{
		//tno *pAux;
		pAux = *t;

		if ((*t)->esq != NULL)
		         *t = (*t)->esq;
		      else
		         *t = NULL;
	}
	return pAux;
}

void atualizar(tno** t, int v, int n){

}

void remover(tno **T, int x)
{
   if (*T != NULL)
   {
      if (x < (*T)->info)
         remover(&((*T)->esq),x);
      else if (x > (*T)->info)
         remover(&((*T)->dir),x);
      else
      {
         tno *pAux;
         pAux = *T;
         if ( (*T)->esq == NULL && (*T)->dir == NULL)
         {
            free(pAux);
            (*T) = NULL;
         }
         else if ((*T)->esq == NULL)
         {
            (*T) = (*T)->dir;
            pAux->dir = NULL;
            free(pAux);
         }
         else if ((*T)->dir == NULL)
         {
            (*T) = (*T)->esq;
            pAux->esq = NULL;
            free(pAux);
         }
         else
         {
            pAux = maiorDireita(&(*T)->esq);
            pAux->esq = (*T)->esq;
            pAux->dir = (*T)->dir;
            (*T)->esq = (*T)->dir = NULL;
            free((*T));
            *T = pAux;
         }
      }
   }
}

void inserirSemRecursividade(tno** t, int x){

	tno* novo = (tno*) malloc (sizeof(tno));
	novo->info = x;
	novo->esq = NULL;
	novo->dir = NULL;

	if(*t == NULL){
		*t = novo;
	}
	else{
		tno *aux = *t;

		while((aux->esq != NULL && x <= aux->info) || (aux->dir != NULL && x > aux->info)){
			if(x < aux->info){
				aux = aux->esq;
			}
			else{
				aux = aux->dir;
			}
		}

		if(x < aux->info){
			aux->esq = novo;
		}
		else{
			aux->dir = novo;
		}

	}
}

void removerSemRecursividade(tno** t, int x){

}
