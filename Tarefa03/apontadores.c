#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct tipoLutador {
	int id, f, fmax;
	struct tipoLutador *prox;
} TLutador;
typedef struct tipoFila {
	int tam;
	TLutador *primeiro, *ultimo;
} TFila;
void iniciaFila(TFila *fila) {
	(*fila).tam = 0;
	(*fila).primeiro = (*fila).ultimo = NULL;
}
TLutador * novoLutador(int id, int forca) {
	TLutador * novo = (TLutador*)malloc(sizeof(TLutador));
	if (novo == NULL)return 0;
	(*novo).id = id;
	(*novo).f = (*novo).fmax = forca;
	(*novo).prox = NULL;
	return novo;
}
int insereFila(TFila *fila, TLutador *lutador) {
	if (lutador == NULL)return 0;
	if ((*fila).primeiro == NULL)(*fila).primeiro = lutador;
	else (*(*fila).ultimo).prox = lutador;
	(*fila).ultimo = lutador;
	(*fila).tam++;
	return 1;
}
int tamanhoFila(TFila *fila) {
	return (*fila).tam;
}
TLutador * removeFila(TFila *fila) {
	TLutador *aux;
	if (tamanhoFila(fila) == 0)return NULL;
	aux = (*fila).primeiro;
	if (tamanhoFila(fila) > 1)(*fila).primeiro = (*aux).prox;
	else (*fila).primeiro = (*fila).ultimo = NULL;
	(*fila).tam--;
	return aux;
}
int main(void) {
	TLutador *lut1 = NULL, *lut2 = NULL;
	int n, k, i, f;
	TFila *fila1 = (TFila*)malloc(sizeof(TFila));
	iniciaFila(fila1);
	scanf("%d %d", &n, &k);
	for (i = 0; i < pow(2, n); i++) {
		scanf("%d", &f);
		insereFila(fila1, novoLutador(i + 1, f));
	}
	while (tamanhoFila(fila1) > 1) {
		lut1 = removeFila(fila1);
		lut2 = removeFila(fila1);
		if ((*lut1).f >= (*lut2).f) {
			(*lut1).f -= ((*lut2).f - k);
			if ((*lut1).f > (*lut1).fmax)(*lut1).f = (*lut1).fmax;
			insereFila(fila1, lut1);
			free(lut2);
		} else {
			(*lut2).f -= ((*lut1).f - k);
			if ((*lut2).f > (*lut2).fmax)(*lut2).f = (*lut2).fmax;
			insereFila(fila1, lut2);
			free(lut1);
		}
		lut1 = lut2 = NULL;
	}
	lut1 = removeFila(fila1);
	printf("%d", (*lut1).id);
	free(lut1);
	free(fila1);
	return 0;
}
