#include <stdio.h>
#include <stdlib.h>
typedef struct no {
	int id;
	struct no *esquerda, *direita;
} TNo;
TNo * iniciaNo(int id) {
	TNo * novo = (TNo*)malloc(sizeof(TNo));
	(*novo).id = id;
	(*novo).esquerda = (*novo).direita = NULL;
	return novo;
}

void insereArvore(TNo *pai, TNo *filho) {
	if((*filho).id > (*pai).id)
		if((*pai).direita == NULL) (*pai).direita = filho;
		else return insereArvore((*pai).direita, filho);
	else if((*filho).id < (*pai).id)
		if((*pai).esquerda == NULL) (*pai).esquerda = filho;
		else return insereArvore((*pai).esquerda, filho);
    else free(filho);//Inserir duplicata
}

TNo * pesquisaArvore(TNo *x, int id) {
	if(x == NULL) return NULL;
	if(id > (*x).id) return pesquisaArvore((*x).direita, id);
	else if(id < (*x).id) return pesquisaArvore((*x).esquerda, id);
	else return x;
}

void imprimeArvore(TNo *x) {
	printf("(");
	if(x != NULL) {
		printf("C%d", (*x).id);
		imprimeArvore((*x).esquerda);
		imprimeArvore((*x).direita);
		free(x);
	}
	printf(")");
}

void reinsereArvore(TNo *raiz, TNo *y) {
	insereArvore(raiz, iniciaNo((*y).id));
	if((*y).esquerda != NULL) reinsereArvore(raiz, (*y).esquerda);
	if((*y).direita != NULL) reinsereArvore(raiz, (*y).direita);
	free(y);
}

void removeArvore(TNo *raiz, TNo *x) {
	TNo * aux = NULL, * aux2 = NULL;
	if((*x).direita != NULL) {
		for(aux = (*x).direita; aux->esquerda != NULL; aux = (*aux).esquerda);
		(*x).id = (*aux).id;
		aux2 = (*x).direita;
		(*x).direita = NULL;
		reinsereArvore(raiz, aux2);
	} else if((*x).esquerda != NULL) {
	    for(aux = (*x).esquerda; aux->direita != NULL; aux = (*aux).direita);
		(*x).id = (*aux).id;
		aux2 = (*x).esquerda;
		(*x).esquerda = NULL;
		reinsereArvore(raiz, aux2);
	}
	else {
		aux = raiz;
		while(aux != x) {
			aux2 = aux;
			if((*x).id > (*aux).id)
				aux = (*aux).direita;
			else aux = (*aux).esquerda;
		}
		if((*x).id > (*aux2).id) {
			free((*aux2).direita);
			(*aux2).direita = NULL;
		} else {
			free((*aux2).esquerda);
			(*aux2).esquerda = NULL;
		}
	}
}

int main(void) {
	TNo *raiz = NULL, *remove = NULL;
	int n, i, id;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &id);
		if(raiz == NULL) raiz = iniciaNo(id);
		else insereArvore(raiz, iniciaNo(id));
	}
	scanf("%d", &id);
	if((remove = pesquisaArvore(raiz, id)) == NULL) insereArvore(raiz, iniciaNo(id));
	else removeArvore(raiz, remove);
	imprimeArvore(raiz);
	return 0;
}
