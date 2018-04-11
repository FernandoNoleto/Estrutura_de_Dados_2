//Aula 2

#include "abb.h"
#include <stdio.h>

int main(){
	tno* t;
	inicializar(&t);
	//insere(&t, 10);
	//insere(&t, 5);
	//insere(&t, 15);
	//insere(&t, 8);

	//insere(&t, 3);

	//preOrdem(t);

	//busca(t, 5);

	//remover(&t, 5);

	//preOrdem(t);

	inserirSemRecursividade(&t, 10);
	inserirSemRecursividade(&t, 5);
	inserirSemRecursividade(&t, 15);
	inserirSemRecursividade(&t, 7);
	inserirSemRecursividade(&t, 8);
	inserirSemRecursividade(&t, 20);
	inserirSemRecursividade(&t, 21);
	inserirSemRecursividade(&t, 10);

	preOrdem(t);



	return 0;
}

