#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct crianca {
	char nome[20];
	struct crianca * prox;
} TCrianca;
typedef struct lista {
	int tam;
	TCrianca *primeiro, *vez;
} TLista;
int tamanhoLista(TLista *x) {
	return (*x).tam;
}
void iniciaLista(TLista *x) {
	(*x).tam = 0;
	(*x).primeiro = NULL; //(TCrianca *)malloc(sizeof(TCrianca));//Cabeça
	(*x).vez = NULL;
}
TCrianca * criaJogador(char *nome) {
	TCrianca * novo = (TCrianca *)malloc(sizeof(TCrianca)); //Aloca memória
	if(novo == NULL)return NULL; //Se NULL, entao n tem memoria disponivel
	strcpy((*novo).nome, nome); //Copia o nome
	(*novo).prox = NULL;
	return novo;
}
int insereLista(TLista *x, TCrianca *y, int p) {
	int i;
	TCrianca *aux;
	if(p < 0 || p > tamanhoLista(x))return 0; //Verifica se a posição eh valida
	if(tamanhoLista(x) == 0) { //Fila Vazia?
		(*x).primeiro = y;
	} else if(p == 0) { //Fila não vazia e Inserir na primeira posição
		y = (*x).primeiro;
		(*x).primeiro = y;
	} else { //Inserir em uma posição diferente da primeira
		aux = (*x).primeiro;
		for(i = 0; i < p - 1; i++, aux = (*aux).prox); //Acha o anterior
		(*y).prox = (*aux).prox;
		(*aux).prox = y;
	}
	(*y).prox = (*x).primeiro;
	(*x).tam++;
	return 1;
}
TCrianca * retiraLista(TLista *x) {
	TCrianca *aux, *saiu;
	for(aux = (*x).primeiro; (*aux).prox != (*x).vez; aux = (*aux).prox); //Acha anterior
	if((*x).primeiro == (*x).vez) {
		(*x).primeiro = aux;
	}
	saiu = (*x).vez;
	if(tamanhoLista(x) == 1) {
		(*x).primeiro = (*x).vez = NULL;
	} else {
		(*aux).prox = (*(*x).vez).prox;//conserta lista
		(*x).vez = (*saiu).prox;
	}
	(*x).tam--;
	return saiu;
}
void batata(TLista *x, int k) {
	int cont = 1;
	TCrianca *saiu = NULL;
	(*x).vez = (*x).primeiro; //Jogo começa na primeira criança
	while(tamanhoLista(x) > 0) {
		(*x).vez = (*(*x).vez).prox;
		if(cont % k == 0) {
			saiu = retiraLista(x);
			printf("%s\n", (*saiu).nome);
			free(saiu);
		}
		cont++;
	}
}
void imprimeLista(TLista *x) {
	TCrianca *aux = (*x).primeiro;
	for(aux = (*x).primeiro; aux != NULL; printf("%s\n", (*aux).nome), aux = (*aux).prox);
}
int main(void) {
	int n, k, i;// N -  Numero de jogadores / K - Numero de jogadas p sair um jogador / i - Indice do for / P - posição q deve ser retirada
	char nome[20];
	TLista *lista = (TLista *)malloc(sizeof(TLista));
	iniciaLista(lista);
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) {
		scanf("%s", nome); //Le o nome do novo jogador
		insereLista(lista, criaJogador(nome), i); //Insere jogador
	}
	batata(lista, k);
	free(lista);
	lista = NULL;
	return 0;
}
