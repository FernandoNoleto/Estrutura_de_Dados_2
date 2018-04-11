/*
 * Acadêmico: Fernando Barroso Noleto
 * Estrutura de Dados II - Árvore AVL
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	struct no* esq;
	struct no* dir;
};

typedef struct no tavl;

void inserir(tavl**, int);
void preOrdem(tavl*);
void ordem(tavl*);
void posOrdem(tavl*);
void inserir_balanceado(tavl**, int);
void RD(tavl**);
void RE(tavl**);
void RDD(tavl**);
void RDE(tavl**);
int altura(tavl*);
int fator_balanceamento(tavl*);
tavl* verificar_arvore(tavl*);
void remover(tavl**, int);
tavl* maiorDireita(tavl**);

int main(){

	tavl* t = NULL;

	inserir_balanceado(&t, 5);
	inserir_balanceado(&t, 8);
	inserir_balanceado(&t, 6);
	inserir_balanceado(&t, 10);
	inserir_balanceado(&t, 11);


	puts("PreOrdem");
	preOrdem(t);


	remover(&t, 5);

	puts("PreOrdem");
	preOrdem(t);
	puts("Ordem");
	ordem(t);


	return 0;
}

void inserir(tavl** t, int x){

	if(*t == NULL){
		tavl* novo = (tavl*) malloc (sizeof(tavl));
		novo->info = x;
		novo->dir = NULL;
		novo->esq = NULL;
		*t = novo;
	}else{
		tavl* aux = *t;
		if(x < aux->info) inserir(&(aux->esq), x);
		else inserir(&(aux->dir), x);
	}

}

void preOrdem(tavl* t){

	if(t != NULL){
		printf("%i\n", t->info);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}

}

void ordem(tavl *t){
	if(t){
		ordem(t->esq);
		printf("%i\n", t->info);
		ordem(t->dir);
	}
}

void posOrdem(tavl* t){
	if(t!=NULL){
		posOrdem(t->esq);
		posOrdem(t->dir);
		printf("%i\n", t->info);
	}
}

void inserir_balanceado(tavl** t, int x){
	if(*t == NULL){
		tavl* novo = (tavl*) malloc(sizeof(tavl));
		novo->info = x;
		novo->dir = NULL;
		novo->esq = NULL;
		*t = novo;
	}else{
		tavl* aux = *t;
		if(x < aux->info) inserir_balanceado(&(aux->esq), x);
		else inserir_balanceado(&(aux->dir), x);
	}

	*t = verificar_arvore(*t);

}

//Rotação a direita
void RD(tavl** t){
	tavl* u;
	u = (*t)->esq;
	(*t)->esq = u->dir;
	u->dir = (*t);
	(*t) = u;
}

//Rotação a esquerda
void RE(tavl** t){
	tavl* u;
	u = (*t)->dir;
	(*t)->dir = u->esq;
	u->esq = (*t);
	(*t) = u;
}

//Rotação dupla a direita
void RDD(tavl** t){
	tavl* u = (*t)->esq;
	tavl* v = u->dir;

	u->dir = v->esq;
	v->esq = u;
	(*t)->esq = v->dir;
	v->dir = (*t);
	(*t) = v;

}

//Rotação dupla a esquerda
void RDE(tavl** t){
	tavl* u = (*t)->dir;
	tavl* v = u->esq;

	u->esq = v->dir;
	v->dir = u;
	(*t)->dir = v->esq;
	v->esq = (*t);

	(*t) = v;
}

//Verifica altura do nó
int altura(tavl* t){
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

int fator_balanceamento(tavl* t){
	if(!t) return 0;
	return (altura(t->esq) - altura(t->dir));
}

tavl* verificar_arvore(tavl* t){

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

//Função de remover sem recursividade
void remover(tavl **t, int x){
   if (*t != NULL){
      if (x < (*t)->info)
         remover(&((*t)->esq),x);
      else if (x > (*t)->info)
         remover(&((*t)->dir),x);
      else{
         tavl *pAux;
         pAux = *t;

         if ( (*t)->esq == NULL && (*t)->dir == NULL){
            free(pAux);
            (*t) = NULL;
         }

         else if ((*t)->esq == NULL){
            (*t) = (*t)->dir;
            pAux->dir = NULL;
            free(pAux);
         }

         else if ((*t)->dir == NULL){
            (*t) = (*t)->esq;
            pAux->esq = NULL;
            free(pAux);
         }

         else{
            pAux = maiorDireita(&(*t)->esq);
            pAux->esq = (*t)->esq;
            pAux->dir = (*t)->dir;
            (*t)->esq = (*t)->dir;
            free((*t));
            *t = pAux;
         }
      }
   }
   *t = verificar_arvore(*t);
}

tavl* maiorDireita(tavl** t){

	tavl* pAux;

	if((*t)->dir != NULL)
		return maiorDireita(&((*t)->dir));
	else{
		//tavl *pAux;
		pAux = *t;

		if ((*t)->esq != NULL)
		         *t = (*t)->esq;
		      else
		         *t = NULL;
	}
	return pAux;
}
