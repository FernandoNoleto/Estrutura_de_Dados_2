/*
 * TRABALHO DE ESTRUTURA DE DADOS II - ÁRVORE RUBRO-NEGRA
 * Acadêmico: FERNANDO BARROSO NOLETO
 * Data: 07/05/2017
 *
 */

#ifndef H_ARN_H
#define H_ARN_H

struct no{
	int info;
	struct no* dir;
	struct no* esq;
	char cor;
};

typedef struct no arn;

void inserir(arn** raiz, int x);
arn* insereno(arn* no, int x);
void remover(arn** raiz, int x);
arn* removerno(arn* no, int x);
char cor(arn* no);
arn* RE(arn* no);
arn* RD(arn* no);
void trocaCor(arn* no);
void preOrdem(arn* no);
arn* moveNoEsqRubro(arn* no);
arn* moveNoDirRubro(arn* no);
arn* balancear(arn* no);
arn* removerMenor(arn* no);
arn* procuraMenor(arn* no);

#endif
