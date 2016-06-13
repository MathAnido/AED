#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct arvore {
	int vetor[MAX], n;
} TArvore;
void iniciaArvore(TArvore *x, int n) {
	int i;
	for(i = 0; i < MAX; i++) {
		*((*x).vetor + i) = 0;
	}
	(*x).n = n;
}
int insereNo(TArvore *x, int p, int f) { // (p) Nó Pai | (f) Nó Filho
	//if(*((*x).vetor + p - 1) == 0) return 0; //verifica se existe nó pai
	if(*((*x).vetor + (2 * p) - 1) == 0) //verifica nó esquerdo vazio
		*((*x).vetor + (2 * p) - 1) = 1; //insere no esquerdo
	else if(*((*x).vetor + (2 * p + 1) - 1) == 0) //verifica nó direito vazio
		*((*x).vetor + (2 * p + 1) - 1) = 1; //insere no direito
	else return 0;
	return 1;
}
void imprimeArvore(TArvore *x, int n) {
	printf("(%d", n);
	if(*((*x).vetor + (2 * n) - 1) == 1) { //verifica existe nó esquerdo
		imprimeArvore(x, 2 * n);
		if(*((*x).vetor + (2 * n + 1) - 1) == 1) //verifica existe nó direito se existir o esquerdo
			imprimeArvore(x, 2 * n + 1);
	}
	printf(")");
}
int main(void) {
	TArvore *arvore1 = (TArvore*) malloc(sizeof(TArvore));
	int n, m, i, p, f;
	scanf("%d %d", &n, &m);
	iniciaArvore(arvore1, n);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &p, &f);
		insereNo(arvore1, p, f);
	}
	imprimeArvore(arvore1, 1);
	free(arvore1);
	return 0;
}
