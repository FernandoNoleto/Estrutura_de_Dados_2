#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"
#include "arvore.h"
#include "lista.h"

int main(){
    tree* t = NULL;
    int tam;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tam);
    criar_novo_no_matriz(&t, tam);

    imprimir_arvore(t, tam);

    //int pos = possibilidades(t, tam);
    //printf("Pos: %d\n", pos);


    int i = 0;
    while(t->matriz[0][0] != 0){
        posicao_zero(&t, tam);
        i++;

        if(i > 8)
            break;
    }



    imprimir_arvore(t, tam);
    //imprimir_matriz(t->matriz, tam);
    //imprimir_matriz(t->left->matriz, tam);


    return 0;
}
