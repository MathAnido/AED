#include <stdio.h>
#include <stdlib.h>
typedef struct grafo {
	int **matriz, nVertice, nAresta;
} TGrafo;
TGrafo * iniciaGrafo(int nV, int nA) {
	int i;
	TGrafo * novo = (TGrafo *)malloc(sizeof(TGrafo));
	(*novo).matriz =(int **) calloc(nV, sizeof(int*));
	for(i = 0; i < nV; i++) {
		*((*novo).matriz + i) = (int *) calloc(nV, sizeof(int));
	}
	(*novo).nVertice = nV;
	(*novo).nAresta = nA;
	return novo;
}
void insereAresta(TGrafo *x, int y, int z) {
	if(y <= (*x).nVertice && z <= (*x).nVertice)
		*(*((*x).matriz + y - 1) + z - 1) = 1;
}
void imprimeGrafo(TGrafo *x) {
	int i, j, contA = 0, contB = 0;
	for(i = 0; i < (*x).nVertice; i++) {
		printf("%d", i + 1);
		for(j = 0; j < (*x).nVertice; j++) {
			if((*(*((*x).matriz + j) + i)) == 1)
				contA++;
			if((*(*((*x).matriz + i) + j)) == 1)
				contB++;
		}
		printf(" %d %d", contA, contB);
		if(contB > 0) {
			for(j = 0; j < (*x).nVertice; j++)
				if((*(*((*x).matriz + i) + j)) == 1)
					printf(" %d", j + 1);
		}
		printf("\n");
		contA = contB = 0;
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
	free(grafo1);
	return 0;
}
