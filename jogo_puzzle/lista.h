#ifndef LISTA_H
#define LISTA_H

typedef struct nol{
    int info;
    struct nol* prox;
}tno;

typedef struct{
    tno* inicio;
}lista;


void inserir_lista(lista* l, int x){

    tno* no = (tno*) malloc (sizeof(tno));
    no->info = x;
    no->prox = NULL;

    if(!l->inicio){
        l->inicio = no;
    }
    else{
        tno* aux = l->inicio;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
}

void remover_lista(lista* l, int x){
    if(!l->inicio){
        return;
    }
    else{
        tno* aux = l->inicio;
        if(aux->info == x){
            l->inicio = aux->prox;
            free(aux);
            return;
        }
        tno* aux2 = aux->prox;
        while(aux2->prox != NULL){
            if(aux2->info == x)
                break;
            aux = aux2;
            aux2 = aux2->prox;
        }
        aux->prox = aux2->prox;
        free(aux2);
    }

}

void imprimir_lista(lista* l){
    tno* aux = l->inicio;
    puts("Lista");
    while(aux){
        printf("%d| ", aux->info);
        aux = aux->prox;
    }
}

#endif // LISTA_H
