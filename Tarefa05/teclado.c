#include <stdio.h>
#include <stdlib.h>
typedef struct letra {
	char c;
	struct letra *prox;
} TLetra;
typedef struct lista {
	int tam;
	TLetra *primeiro, *cursor;
} TLista;
void iniciaLista(TLista *x) {
	(*x).tam = 0;
	(*x).primeiro = (TLetra *) malloc(sizeof(TLetra));//Cabeça
	(*x).cursor = (*x).primeiro;//Cursor na primeira posição
	(*(*x).primeiro).prox = (*x).primeiro;//Lista Circular
}
TLetra * iniciaLetra(char c) {
	TLetra *x = (TLetra *)malloc(sizeof(TLetra));
	(*x).c = c;
	(*x).prox = NULL;
	return x;
}
void teclado(TLista *x, char c) {
	if(c == '[') {
		teclaHome(x);
	} else if(c == ']') {
		teclaEnd(x);
	} else if(c == '-') {
		teclaDelete(x);
	} else if(c == '>') {
		teclaDireita(x);
	} else if(c == '<') {
		teclaEsquerda(x);
	} else {
		insereLista(x,iniciaLetra(c));
	}
}
int insereLista(TLista * x, TLetra * y) {
	(*y).prox = (*(*x).cursor).prox;
	(*(*x).cursor).prox = y;
	(*x).cursor = y;
	(*x).tam++;
	return 1;
}
void imprimeLista(TLista * x) {
	TLetra *aux;
	for(aux = (*(*x).primeiro).prox; aux != (*x).primeiro; printf("%c", (*aux).c), aux = (*aux).prox); //Imprime lista
}
int teclaHome(TLista * x) {
	(*x).cursor = (*x).primeiro;
	return 1;
}
int teclaEnd(TLista * x) {
	TLetra *aux;
	for(aux = (*x).cursor; (*aux).prox != (*x).primeiro; aux = (*aux).prox); //acha o ultimo
	(*x).cursor = aux;
	return 1;
}
int teclaDelete(TLista * x) {
	TLetra *aux, *aux2;
	if((*x).cursor != (*x).primeiro && (*x).tam > 0) { //Verifica se nao esta no começo da linha e se nao esta vazia
		for(aux = (*(*x).primeiro).prox; (*aux).prox != (*x).cursor; aux = (*aux).prox);//Acha o anterior ao cursor
		aux2 = (*aux).prox;//Elemento a ser retirado
		(*x).cursor = aux;
		(*aux).prox = (*aux2).prox;//Arruma lista
		(*x).tam--;
		free(aux2);
	} else return 0;
	return 1;
}
int teclaEsquerda(TLista * x) {
	TLetra *aux;
	if((*x).cursor != (*x).primeiro) {//Verifica se eh a primeira posição
		for(aux = (*(*x).primeiro).prox; (*aux).prox != (*x).cursor; aux = (*aux).prox); //Acha o anterior ao cursor
		(*x).cursor = aux;//Move cursor pra esquerda
	} else return 0;
	return 1;
}
int teclaDireita(TLista * x) {
	if((*(*x).cursor).prox != (*x).primeiro) { //verifica se esta na ultima posição
		(*x).cursor = (*(*x).cursor).prox;//Move cursor pra direita
	} else return 0;
	return 1;
}
int main(void) {
	char c;
	TLista *lista = (TLista *)malloc(sizeof(TLista));
	iniciaLista(lista);
	while((c = getchar()) != '\n') {
		teclado(lista, c);
	}
	imprimeLista(lista);
	free(lista);
	return 0;
}
