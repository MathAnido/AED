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
	TLista **vetor;
} TGrafo;

void iniciaLista(TLista *x) {
	(*x).tam = 0;
	(*x).primeiro = (*x).ultimo = (TDp *) malloc(sizeof(TDp));
	if((*x).primeiro == NULL)exit(2);
	(*(*x).primeiro).n = 0;
	(*(*x).primeiro).prox = NULL;
}
void iniciaGrafo(TGrafo *x, int n) {
	int i;
	(*x).tam = n;
	(*x).vetor = (TLista **) malloc(sizeof(TLista*) * n);
	if((*x).vetor == NULL) exit(1);
	for(i = 0; i < n ; i++) {
		x->vetor[i] = (TLista*) malloc(sizeof(TLista));
		iniciaLista(x->vetor[i]);
	}
}
TDp * iniciaDp(int n) {
	TDp * novo = (TDp*)malloc(sizeof(TDp));
	(*novo).n = n;
	(*novo).prox = NULL;
	return novo;
}
int insereLista(TLista *x, TDp *y) {
	if(x == NULL || y == NULL)return 0;
	(*(*x).ultimo).prox = (struct dependencia *) y;
	(*x).ultimo = y;
	(*x).tam++;
	return 1;
}
void imprimeLista(TLista *x) {
	TDp *aux;
	printf(" %d %d", (*(*x).primeiro).n, (*x).tam);
	for(aux = (*(*x).primeiro).prox; aux != NULL; aux = aux->prox)
		printf(" %d", aux->n);
}
void imprimeGrafo(TGrafo *x) {
	int i;
	for(i = 0; i < (*x).tam; i++) {
		printf("%d", i + 1);
		imprimeLista(x->vetor[i]);
		printf("\n");
	}
}
void somaDp(TLista *x){
    (*(*x).primeiro).n++;
}
int main(void) {
	TGrafo * grafo1 = malloc(sizeof(TGrafo));
	int n, d, i, x, y;
	scanf("%d %d", &n, &d);
	iniciaGrafo(grafo1, n);
	for(i = 0; i < d; i++) {
		scanf("%d %d", &x, &y);
		if(x <= n && y <= n) {
			insereLista(grafo1->vetor[x - 1], iniciaDp(y));
			somaDp(grafo1->vetor[y-1]);
		}
	}
	imprimeGrafo(grafo1);
	return 0;
}
