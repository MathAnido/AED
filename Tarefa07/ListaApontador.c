#include <stdio.h>
#include <stdlib.h>
typedef struct no {
	int n;
	struct no *esquerda, *direita;
} TNo;
typedef struct arvore {
	TNo * raiz;
} TArvore;

TNo * iniciaNo(int n) {
	TNo * novo = (TNo *) malloc(sizeof(TNo));
	(*novo).n = n;
	(*novo).esquerda = (*novo).direita = NULL;
	return novo;
}
void iniciaArvore(TArvore *x) {
	(*x).raiz = iniciaNo(1);
}
void insereNo(TNo * x, int p, TNo *f) { // (p) Nó Pai | (f) Nó Filho
	if((*x).n == p) { //verifica se eh o no pai
		if((*x).esquerda == NULL)//verifica esquerda
			(*x).esquerda = f;
		else if((*x).direita == NULL)//verifica direita se tiver esquerda
			(*x).direita = f;
	} else {
		if((*x).esquerda != NULL) {
			insereNo((*x).esquerda, p, f);
			if((*x).direita != NULL)
				insereNo((*x).direita, p, f);
		}
	}
}
void imprimeArvore(TNo *x) {
	printf("(%d", (*x).n);
	if((*x).esquerda != NULL) {
		imprimeArvore((*x).esquerda);
		if((*x).direita != NULL)
			imprimeArvore((*x).direita);
	}
	printf(")");
}
void liberaArvore(TNo *x)
{
    if((*x).esquerda != NULL) {
		liberaArvore((*x).esquerda);
		if((*x).direita != NULL)
			liberaArvore((*x).direita);
	}
    free(x);
}
int main(void) {
	TArvore *arvore1 = (TArvore*) malloc(sizeof(TArvore));
	int n, m, i, p, f;
	scanf("%d %d", &n, &m);
	iniciaArvore(arvore1);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &p, &f);
		insereNo((*arvore1).raiz, p, iniciaNo(f));
	}
	imprimeArvore((*arvore1).raiz);
	liberaArvore((*arvore1).raiz);
	return 0;
}
