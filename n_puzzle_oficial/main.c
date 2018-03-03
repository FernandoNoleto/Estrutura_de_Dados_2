/**
  * Trabalho de Estrutura de Dados II
  * Acadêmicos: Andre Ferreira Amaral, Fernnado Barroso Noleto e Vitor Gonçalves Rosa
  *	Resolver o jogo "N_Puzzle" usando árvores
  */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estruturas.h"
#include "heuristica.h"

int main(){

    arvore raiz;
    int tam, i, j;
    int** matriz_resultado;

    printf("INSIRA O TAMANHO DA MATRIZ: ");
    scanf("%d", &tam);

    raiz.cima = NULL;
    raiz.baixo = NULL;
    raiz.esquerda = NULL;
    raiz.direita = NULL;

    matriz_resultado = (int**) malloc (tam * sizeof(int*));
    raiz.matriz = (int**) malloc (tam * sizeof(int*));

    //Preenchendo e alocando matriz resultado
    for(i = tam-1; i >= 0; i--){
        raiz.matriz[i] = (int*) malloc (tam * sizeof(int));
        matriz_resultado[i] = (int*) malloc (tam * sizeof(int));
    }

    int* aux = (int*) malloc( (tam * tam) * sizeof(int));
    comparar_resultado (&matriz_resultado, &raiz.matriz, &aux, tam, &i, &j);

    strcpy(raiz.mov,"raiz");
    preencher_arvore(&raiz, matriz_resultado, tam, i, j);

    printf("\nMATRIZ INICIAL:\n");

    imprimir_matriz(raiz.matriz, tam);


    printf("\n");
    printf("Quantidade de Movimetos: %d\n\n", count);


    puts("MATRIZ RESULTADO");
    int** matrizFinal = matriz_final(tam);
    imprimir_matriz (matrizFinal, tam);

    return 0;
}
