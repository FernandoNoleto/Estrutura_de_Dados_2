/*
 * TRABALHO DE ESTRUTURA DE DADOS II - ÁRVORE RUBRO-NEGRA
 * Acadêmico: FERNANDO BARROSO NOLETO
 * Data: 07/05/2017
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "arn.h"

int main(){

	arn* t = NULL;

	inserir(&t, 10);
	inserir(&t, 5);
	inserir(&t, 15);
	inserir(&t, 8);
	inserir(&t, 3);
	remover(&t, 15);


	preOrdem(t);


	return 0;
}


