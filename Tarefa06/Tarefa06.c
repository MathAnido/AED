#include <stdio.h>
#include <stdlib.h>
typedef struct dependencia {
	int n;
	struct dependencia * prox;
} TDp;
typedef struct lista {
	int tam;
	TDp *primeiro, *ultimo;
} TLista;
typedef struct grafo {
    int tam;
	TLista *vetor;
} TGrafo;
void iniciaGrafo(TGrafo *x, int n) {
    (*x).tam = n;
	(*x).vetor = malloc(sizeof(TLista) * n);
	if((*x).vetor == NULL) exit(1);
}
void iniciaLista(TLista *x) {
	(*x).tam = 0;
	(*x).primeiro = (*x).ultimo = (TDp *) malloc(sizeof(TDp));
	(*(*x).primeiro).prox = (*x).primeiro;
}
TDp * iniciaDp(int n) {
	TDp * novo = (TDp*)malloc(sizeof(TDp));
	(*novo).n = n;
	(*novo).prox = NULL;
	return novo;
}
int insereLista(TLista *x, TDp *y) {
	if(x == NULL || y == NULL)return 0;
	(*y).prox = (*(*x).ultimo).prox;
	(*(*x).ultimo).prox = y;
	(*x).ultimo = y;
	(*x).tam++;
	return 1;
}
void imprimeLista(TLista *x)
{
    TDp *aux;
    printf(" %d",(*x).tam);
    for(aux=(*(*x).primeiro).prox;aux!=(*x).primeiro;aux = (*aux).prox);
    {
        printf(" %d",(*aux).n);
    }
}
void imprimeGrafo(TGrafo *x)
{
    int i;
    for(i=0;i<(*x).tam;i++)
    {
        imprimeLista((*x).vetor + i);
        printf("\n");
    }
}
int main(void) {
    TGrafo * grafo1 = malloc(sizeof(TGrafo));
	int n, d, i, x, y;
	scanf("%d %d", &n, &d);
	iniciaGrafo(grafo1,n);
	for(i = 0; i < d; i++) {
		scanf("%d %d", &x, &y);
		if(x <= n) {
			insereLista(((*grafo1).vetor + i), iniciaDp(y));
		}
	}
	imprimeGrafo(grafo1);
	return 0;
}
