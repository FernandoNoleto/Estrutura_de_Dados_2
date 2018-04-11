/*
 * TRABALHO DE ESTRUTURA DE DADOS II - ÁRVORE RUBRO-NEGRA
 * Acadêmico: FERNANDO BARROSO NOLETO
 * Data: 07/05/2017
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "arn.h"


void inserir(arn** raiz, int x){
	*raiz = insereno(*raiz, x);
	if((*raiz) != NULL)
		(*raiz)->cor = 'n';
}

arn* insereno(arn* h, int x){
	if(h == NULL){
		arn* novo = (arn*) malloc (sizeof(arn));

		novo->info = x;
		novo->cor = 'r';
		novo->dir = NULL;
		novo->esq = NULL;
		return novo;

	}
	if(x == h->info)
		return NULL;
	else{
		if(x < h->info)
			h->esq = insereno(h->esq, x);
		else
			h->dir = insereno(h->dir, x);

	}

	if(cor(h->dir) == 'r' && cor(h->esq) == 'n')
		h = RE(h);

	if(cor(h->esq) == 'r' && cor(h->esq->esq) == 'r')
		h = RD(h);

	if(cor(h->esq) == 'r' && cor(h->dir) == 'r')
		trocaCor(h);

	return h;
}

char cor(arn* no){
	if (no == NULL)
		return 'n';
	else
		return no->cor;
}

arn* RE(arn* no){

	arn* aux = no->dir;
	no->dir = aux->esq;
	aux->esq = no;
	aux->cor = no->cor;
	no->cor = 'r';

	return aux;
}

arn* RD(arn* no){

	arn* aux = no->esq;
	no->esq = aux->dir;
	aux->dir = no;
	aux->cor = no->cor;
	no->cor = 'r';

	return aux;
}

void trocaCor(arn* no){
	if (no->cor == 'r')
		no->cor = 'n';
	else
		no->cor = 'r';

	if (no->esq != NULL){
		if (no->esq->cor == 'r')
			no->esq->cor = 'n';
		else
			no->esq->cor = 'r';
	}
	if(no->dir != NULL){
		if (no->dir->cor == 'r')
			no->dir->cor = 'n';
		else
			no->dir->cor = 'r';
	}

}

void preOrdem(arn* t){
	if(t!=NULL){
		printf("%i,%c\n",t->info, t->cor);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}
}

arn* moveNoEsqRubro(arn* no){

	trocaCor(no);

	if(cor(no->dir->esq) == 'r'){
		no->dir = RD(no->dir);
		no = RE(no);
		trocaCor(no);
	}

	return no;
}

arn* moveNoDirRubro(arn* no){

	trocaCor(no);

	if(cor(no->esq->esq) == 'r'){
		no = RD(no);
		trocaCor(no);
	}

	return no;

}

arn* balancear(arn* no){

	if(cor(no->dir) == 'r')
		no  = RE(no);

	if(no->esq != NULL && cor(no->dir) == 'r' && cor(no->esq->esq) == 'r')
		no = RD(no);

	if(cor(no->esq) == 'r' && cor(no->dir) == 'r')
		trocaCor(no);

	return no;
}

void remover(arn** raiz, int x){
	arn* no = *raiz;
	*raiz = removerno(no, x);
	if(*raiz != NULL)
		(*raiz)->cor = 'n';
}

arn* removerno(arn* no, int x){

	if(x < no->info){
		if(cor(no->esq) == 'n' && cor(no->esq->esq) == 'n')
			no = moveNoEsqRubro(no);

		no->esq = removerno(no->esq, x);
	}
	else{

		if(cor(no->esq) == 'r')
			no = RD(no);

		if((x = no->info) && (no->dir == NULL)){
			free(no);
			return NULL;
		}

		if((cor(no->dir) == 'n') && (cor(no->dir->esq) == 'n'))
			no = moveNoDirRubro(no);

		if(x == no->info){
			arn* aux = procuraMenor(no->dir);
			no->info = aux->info;
			no->dir = removerMenor(no->dir);
		}
		else
			no->dir = removerno(no->dir, x);
	}

	return balancear(no);

}

arn* removerMenor(arn* no){
	if(no->esq == NULL){
		free(no);
		return NULL;
	}
	if((cor(no->esq) == 'n') && (cor(no->esq->esq) == 'n'))
		no = moveNoEsqRubro(no);

	no->esq = removerMenor(no->esq);
	return balancear(no);

}

arn* procuraMenor(arn* no){

	arn* aux1 = no;
	arn* aux2 = no->esq;
	while(aux2 != NULL){
		aux1 = aux2;
		aux2 = aux2->esq;
	}

	return aux1;
}
