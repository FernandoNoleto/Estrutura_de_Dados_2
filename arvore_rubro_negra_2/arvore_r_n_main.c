#include <stdio.h>
#include <stdlib.h>


typedef struct no

{
    int num;
    char cor;
    struct no *pai;
    struct no *esquerda;
    struct no *direita;

}NoRB;

void inserirCor(NoRB **Arv, NoRB *no){
    NoRB *y;
    while(no->pai->cor == 'V'){
	    if(no->pai == no->pai->pai->esquerda){
	    	y = no->pai->pai->direita;
	    	if(y->cor == 'V'){
	    		no->pai->cor = 'P';
	    		y->cor = 'P';
	    		no->pai->pai->cor = 'V';
	    		no = no->pai->pai;
	    	}
	        else{
	        	if(no == no->pai->direita){
	                no = no->pai;
	                //rotacaoEsquerda(&(*Arv), no);

	            }
                no->pai->cor = 'P';
	            no->pai->pai->cor = 'V';
	            //rotacaoDireita(&(*Arv), no->pai->pai);
            }
	    }
	    else{
	        y = no->pai->pai->esquerda;
            if(y->cor == 'V'){
	            no->pai->cor = 'P';
	            y->cor = 'P';
	            no->pai->pai->cor = 'V';
	            no = no->pai->pai;
	        }

	        else{
	            if(no == no->pai->esquerda){
	                no = no->pai;
	                rotacaoDireita(&(*Arv), no);
                }
	            no->pai->cor = 'P';
	            no->pai->pai->cor = 'V';
	            rotacaoEsquerda(&(*Arv), no->pai->pai);

	        }
	    }
	}
    (*Arv)->cor = 'P';
    NoRB *x;

    if((no->esquerda == NULL) || (no->direita == Null)){
    	y = no;
    }
    else{
        y = prox(no);
    }
    if(y->esquerda != NULL){
        x = y->esquerda;
    }
    else{
        x = y->direita;
    }
    x->pai = y->pai;
    if(y->pai == NULL){
        *Arv = x;
    }
    else if(y == y->pai->esquerda){
        y->pai->esquerda = x;
    }
    else{
        y->pai->direita = x;
    }
    if(y != no){
        no->num = y->num;
    }
    if(y->cor == 'P'){
        if((*Arv)->direita == NULL && (*Arv)->esquerda->direita != NULL){
			rotacaoEsquerda(&(*Arv), (*Arv)->esquerda);
            removerCor(&(*Arv), (*Arv)->esquerda);
            rotacaoDireita(&(*Arv), (*Arv));
        }
        else{
            if((*Arv)->esquerda == NULL && (*Arv)->direita->esquerda != NULL){
                rotacaoDireita(&(*Arv), (*Arv)->direita);
                removerCor(&(*Arv), (*Arv)->direita);
                rotacaoEsquerda(&(*Arv), (*Arv));
            }
        }
        removerCor(&(*Arv, x);
    }
    return y;
    free(y);
    free(x);
}


void removerCor(NoRB **Arv, NoRB *no){
    NoRB *aux;
    while(((*Arv) != no) && (no->cor == 'P')){
        if(no == no->pai->esquerda){
		    aux = no->pai->direita;
		    if(aux->cor == 'V'){
		        aux->cor = 'P';
		        no->pai->cor = 'V';
		        rotacaoEsquerda(&(*Arv), no->pai);
		        aux = no->pai->direita;
		    }
		    if((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P')){
		        aux->cor = 'V';
		        no = no->pai;
		    }
		    else if(aux->direita->cor == 'P'){
		        aux->esquerda->cor = 'P';
		        aux->cor = 'V';
		        rotacaoDireita(&(*Arv), aux);
		        aux = no->pai->direita;
		        aux->cor = no->pai->cor;
		        no->pai->cor = 'P';
		        aux->direita->cor = 'P';
		        rotacaoEsquerda(&(*Arv), no->pai);
		        no = *Arv;
		    }
		}
		else{
		    aux = no->pai->esquerda;
			if(aux->cor == 'V'){
			    aux->cor = 'P';
				no->pai->cor = 'V';
				rotacaoDireita(&(*Arv), no->pai);
				aux = no->pai->esquerda;
			 }
			if((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P')){
				aux->cor = 'V';
				no = no->pai;
			}
			else if(aux->esquerda->cor == 'P'){
			    aux->direita->cor = 'P';
			    aux->cor = 'V';
			    rotacaoEsquerda(&(*Arv), aux);
			    aux = no->pai->esquerda;
			    aux->cor = no->pai->cor;
			    no->pai->cor = 'P';
			    aux->esquerda->cor = 'P';
				rotacaoDireita(&(*Arv), no->pai);
			    no = *Arv;
			}
        }
    }
	no->cor = 'P';

    if ((no == NULL)  || (no->num == n)){
		return no;
	}
    if (n  < no->num){
	    return busca(no->esquerda, n);
	}
	else{
	    return busca(no->direita, n);
	}
}

