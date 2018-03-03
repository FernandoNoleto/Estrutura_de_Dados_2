/**
  * Estrutura de Dados II
  * Trabalho sobre tabela Hash
  * Acadêmico: Fernando Barroso Noleto
  */

#include <stdio.h>
#include "hash.h"

void notas (int* n1, int* n2) {
    int x1, x2;
    printf("Insira a nota n1 do aluno: ");
    scanf("%d", &x1);
    printf("Insira a nota n2 do aluno: ");
    scanf("%d", &x2);
    *n1 = x1;
    *n2 = x2;
    puts("");
}

int main() {
    // escolher sempre numeros primos para o tamanho ao iniciar a hash
    struct aluno a;
    a.mat = 123;

    int n1, n2;

    notas(&n1, &n2);

    a.n1 = n1;
    a.n2 = n2;
    a.nome[0] = 'z';
    a.nome[1] = 'e';
    hash* h = criar(1427);

    int x = insere(h, a);
    if(x == 0) {
        puts("Erro ao inserir");
        return EXIT_FAILURE;
    }

    int x1 = busca(h, 123, &a);
    int x2 = busca(h, 123, &a);

    printf("Nota n1 do aluno: %.2f\n", a.n1);
    printf("Elemento está na posição: %i\n", x1);
    printf("Nota n2 do aluno: %.2f\n", a.n2);
    printf("Elemento está na posição: %i\n", x2);
    puts("");

    return EXIT_SUCCESS;
}
