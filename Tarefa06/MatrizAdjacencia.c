#include <stdio.h>
#include <stdlib.h>
typedef struct grafo {
	int **matriz, nVertice, nAresta;
} TGrafo;
TGrafo * iniciaGrafo(int nV, int nA) {
	int i;
	TGrafo * novo = (TGrafo *)malloc(sizeof(TGrafo));
	(*novo).matriz = calloc(nV, sizeof(int));
	for(i = 0; i < nV; i++) {
		*((*novo).matriz + i) = calloc(nV, sizeof(int));
	}
	(*novo).nVertice = nV;
	(*novo).nAresta = nA;
	return novo;
}
void insereAresta(TGrafo *x, int y, int z) {
	*(*((*x).matriz + y - 1) + z - 1) = 1;
}
void liberaGrafo(TGrafo *x) {
	int i;
	for(i = 0; i < (*x).nVertice; i++) {
		free(*((*x).matriz + i));
	}
	free((*x).matriz);
}
void imprimeGrafo(TGrafo *x) {
	int i, j, cont = 0;
	for(i = 0; i < (*x).nVertice; i++) {
		printf("%d", i + 1);
		for(j = 0; j < (*x).nVertice; j++)
			if((*(*((*x).matriz + j) + i)) == 1)cont++;
		printf(" %d", cont);
		cont = 0;
		for(j = 0; j < (*x).nVertice; j++)
			if((*(*((*x).matriz + i) + j)) == 1)cont++;
		printf(" %d", cont);
		for(j = 0; j < (*x).nVertice; j++)
			if((*(*((*x).matriz + i) + j)) == 1)
                printf(" %d",j+1);
		printf("\n");
		cont = 0;
	}
}
int main(void) {
	TGrafo *grafo1;
	int n, d, i, j, x, y;
	scanf("%d %d", &n, &d);
	grafo1 = iniciaGrafo(n, d);
	for(i = 0; i < d; i++) {
		scanf("%d %d", &x, &y);
		insereAresta(grafo1, x, y);
	}
	imprimeGrafo(grafo1);
	liberaGrafo(grafo1);
	return 0;
}
