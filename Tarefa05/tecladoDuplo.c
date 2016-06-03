#include <stdio.h>
#include <stdlib.h>
//Tad
typedef struct letra
{
    char c;
    struct letra *ante,*prox;
}TLetra;
typedef struct lista
{
    int tam;
    TLetra *primeiro,*cursor;
}TLista;
void iniciaLista(TLista *x)
{
    (*x).tam = 0;
    (*x).primeiro = (TLetra *) malloc(sizeof(TLetra));//Cabeça
    (*(*x).primeiro).prox =(struct letra *) (*x).primeiro;//circular em prox
    (*(*x).primeiro).ante =(struct letra *) (*x).primeiro;//circular em ante
    (*x).cursor = (*x).primeiro;
}
TLetra * iniciaLetra(char c)
{
    TLetra *novo = (TLetra*)malloc(sizeof(TLetra));
    if(novo==NULL)return NULL;
    (*novo).c = c;
    (*novo).ante = (*novo).prox =  NULL;
    return novo;
}
int insereLista(TLista *x, TLetra *y)
{
    if(x==NULL||y==NULL)return 0;
    (*y).prox = (*(*x).cursor).prox;
    (*(*(*x).cursor).prox).ante = y;
    (*(*x).cursor).prox = y;
    (*y).ante = (*x).cursor;
    (*x).cursor = y;
    (*x).tam++;
    return 1;
}
void teclaHome(TLista * x)
{
    (*x).cursor = (*x).primeiro;
}
void teclaEnd(TLista * x)
{
    (*x).cursor = (*(*x).primeiro).ante;
}
void teclaEsquerda(TLista * x)
{
    if((*x).cursor!=(*x).primeiro)//Se nao for o primeiro
        (*x).cursor=(*(*x).cursor).ante;
}
void teclaDireita(TLista *x)
{
    if((*x).cursor !=(*(*x).primeiro).ante)//se nao for o ultimo
        (*x).cursor = (*(*x).cursor).prox;
}
int teclaDelete(TLista *x)
{
    TLetra *aux;
    if((*x).cursor==(*x).primeiro)return 0;
    aux = (*x).cursor;
    (*(*(*x).cursor).ante).prox = (*(*x).cursor).prox;
    (*(*(*x).cursor).prox).ante = (*(*x).cursor).ante;
    (*x).cursor = (*(*x).cursor).ante;
    (*x).tam--;
    free(aux);
    return 1;
}
void imprimeLista(TLista * x) {
	TLetra *aux;
	for(aux = (*(*x).primeiro).prox; aux != (*x).primeiro; printf("%c", (*aux).c), aux = (*aux).prox); //Imprime lista
}
void liberaLista(TLista *x)
{
    TLetra *aux,*aux2;
    for(aux = (*(*x).primeiro).prox;aux!=(*x).primeiro;aux = aux2)
    {
        aux2 = (*aux).prox;
        free(aux);
    }
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
//Main
int main(void) {
	char c;
	TLista *lista = (TLista *)malloc(sizeof(TLista));
	iniciaLista(lista);
	while((c = getchar()) != '\n') {
		teclado(lista, c);
	}
	imprimeLista(lista);
    liberaLista(lista);
	free(lista);
	return 0;
}
