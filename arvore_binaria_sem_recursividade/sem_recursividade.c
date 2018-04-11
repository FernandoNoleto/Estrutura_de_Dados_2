#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	struct no* esq;
	struct no* dir;
};

typedef struct no tno;

typedef struct _no{
	tno* dado;
	struct _no *prox;
}nodo;

typedef struct{
	nodo *inicio;
	nodo *fim;

}fila;

fila* create_queque(){
   fila *novo = (fila*)malloc(sizeof(fila));
   if(novo!=NULL){
     novo->inicio = NULL;
     novo->fim = NULL;

   }
   return (novo);
}

int Dfila_inserir(fila *Q, tno* info){

	nodo *novo = (nodo*) malloc (sizeof(nodo));

	if(novo){
		novo->dado = info;
		novo->prox = NULL;
		if(Q->inicio == NULL && Q->fim==NULL){
			Q->inicio = novo;
			Q->fim = novo;
			return 1;
		}else{
			Q->fim->prox = novo;
			Q->fim = novo;
			return 1;
		}
	}
	return 0;
}

void Dfila_remove(fila *Q){

	nodo *aux;
	aux = Q->inicio;


	if(Q->inicio==NULL){
		putenv("fila vazia");

	}else{
		if(Q->inicio->prox==NULL){
			Q->inicio=NULL;
			Q->fim= NULL;
			free(aux);

		}
		puts("ASDFG");

		Q->inicio = Q->inicio->prox;
//		puts("ASDFG");

		free(aux);

	}

}

tno* primeiro(fila *f){
	return f->inicio->dado;

}

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

tno *maiorDireita(tno **t)
{
   if ((*t)->dir != NULL)
      return maiorDireita(&((*t)->dir));
   else
   {
      tno *pAux;
      pAux = *t;
      if ((*t)->esq != NULL)
         *t = (*t)->esq;
      else
         *t = NULL;
      return pAux;
   }
}

void atualizar(tno** t, int v, int n){

}

void remover(tno **t, int x)
{
   if (*t != NULL)
   {
      if (x < (*t)->info)
         remover(&((*t)->esq),x);
      else if (x > (*t)->info)
         remover(&((*t)->dir),x);
      else
      {
         tno *pAux;
         pAux = *t;
         if ( (*t)->esq == NULL && (*t)->dir == NULL)
         {
            free(pAux);
            (*t) = NULL;
         }
         else if ((*t)->esq == NULL)
         {
            (*t) = (*t)->dir;
            pAux->dir = NULL;
            free(pAux);
         }
         else if ((*t)->dir == NULL)
         {
            (*t) = (*t)->esq;
            pAux->esq = NULL;
            free(pAux);
         }
         else
         {
            pAux = maiorDireita(&(*t)->esq);
            pAux->esq = (*t)->esq;
            pAux->dir = (*t)->dir;
            (*t)->esq = (*t)->dir = NULL;
            free((*t));
            *t = pAux;
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

	if(*t != NULL){

		tno* aux = *t;
		tno* aux2;

		while(aux != NULL){

			aux2 = aux;

			if(x > aux->info)
				aux = aux->dir;

			if(x < aux->info)
				aux = aux->esq;

			if(aux->info == x) break;

		}

		if((aux->dir == NULL) && (aux->esq == NULL)){
			free(aux);
			return;
		}
		if(aux->dir == NULL && aux->esq != NULL){
			aux2->dir = aux->esq;
			free(aux);
			return;
		}
		if(aux->dir != NULL && aux->esq == NULL){
			aux2->dir = aux->dir;
			free(aux);
			return;
		}

		if(aux->dir != NULL && aux->esq != NULL){

			tno* aux3 = maiorDireita(&aux);

			aux2->dir = aux3;
			aux3->esq = aux->esq;
			aux3->dir = aux->dir;


			free(aux);
			return;
		}
	}
}

/*

void imprimirNivel(tno* t){

	fila* q = create_queque();
	int aux;

	if(t==NULL)
		return;

	Dfila_inserir(q, t->info);
	imprimirNivel(t->esq);
	imprimirNivel(t->dir);
	printf("%i", t->info);
	Dfila_remove(q, &aux);

	printf("%d\n", aux);

}

void imprimirNivel(tno* t){
	fila* f = create_queque();
	int aux;

	if(t != NULL){
		Dfila_inserir(f, t->info);
		while(f != NULL){
			Dfila_remove(f, &aux);
			if(t->esq != NULL){
				Dfila_inserir(f, t->esq->info);
				t = t->esq;
			}
			if(t->dir != NULL){
				Dfila_inserir(f, t->dir->info);
				t = t->dir;
			}

			printf("%i\n", aux);
		}
	}
}
*/

void imprimirNivel(tno* t){
	fila* f = create_queque();
	tno* aux = t;

	Dfila_inserir(f, aux);
	while(f != NULL){
		aux = primeiro(f);
		Dfila_remove(f);

		if(aux->esq != NULL){

			Dfila_inserir(f, aux->esq);
		}
		if(aux->dir != NULL){
			//puts("ASDF");
			Dfila_inserir(f, aux->dir);
		}

		printf("%i\n", aux->info);
	}


}

int main(){

	tno* t = NULL;

	inserirSemRecursividade(&t, 20);
	inserirSemRecursividade(&t, 35);
	inserirSemRecursividade(&t, 40);
	inserirSemRecursividade(&t, 10);
	inserirSemRecursividade(&t, 15);
	inserirSemRecursividade(&t, 5);
	inserirSemRecursividade(&t, 12);
	inserirSemRecursividade(&t, 17);
	inserirSemRecursividade(&t, 11);

	removerSemRecursividade(&t, 15);

	//remover(&t, 15);

	puts("PREOrdem");
	preOrdem(t);


	return 0;
}
