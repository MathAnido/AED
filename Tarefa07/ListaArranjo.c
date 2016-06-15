#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct lista
{
    int primeiro,ultimo,tam;
    struct no *vetor[max];
} TLista;
typedef struct no
{
    int n;
    TLista filhos;
} TNo;
void iniciaLista(TLista *x)
{
    (*x).primeiro = (*x).ultimo = -1;
    (*x).tam = 0;
}
TNo * iniciaNo(int n)
{
    TNo * novo = (TNo *) malloc(sizeof(TNo));
    (*novo).n = n;
    iniciaLista(&(*novo).filhos);
    return novo;
}
int insereLista(TLista *x, TNo * y)
{
    if((*x).tam == 0) ///lista esta vazia
    {
        (*x).primeiro = (*x).ultimo = 0;
        *((*x).vetor + (*x).primeiro)= y;
    }
    else
    {
        (*x).ultimo++;
        *((*x).vetor + (*x).ultimo)= y;
    }
    (*x).tam++;
}
void insereNo(TNo *x, int p,TNo * f)/// (x) No atual | (p) N do Pai | (f) Nó filho
{
    int aux;///Primeiro No da arvore
    if((*x).n == p) ///Verifica se eh o pai
        insereLista(&(*x).filhos,f);
    else if((*x).filhos.tam > 0) ///Verifica se tem filhos
        for(aux = 0; aux<(*x).filhos.tam; aux++) ///Percorre filhos
            insereNo((*x).filhos.vetor[aux],p,f);
}
void imprimeArvore(TNo *x)
{
    int aux;
    printf("(%d",(*x).n);
    if((*x).filhos.tam > 0)
        for(aux = 0; aux<(*x).filhos.tam; aux++) ///Percorre filhos
            imprimeArvore((*x).filhos.vetor[aux]);
    printf(")");
}
void liberaArvore(TNo *x)
{
    int aux;
    if((*x).filhos.tam > 0)
        for(aux = 0; aux<(*x).filhos.tam; aux++) ///Percorre filhos
            liberaArvore((*x).filhos.vetor[aux]);
    free(x);
}
int main(void)
{
    TNo * raiz = iniciaNo(1);///Arvore
    int n,d,i,x,y;
    scanf("%d %d",&n,&d);
    for(i=0; i<d; i++)
    {
        scanf("%d %d",&x,&y);
        insereNo(raiz,x,iniciaNo(y));
    }
    imprimeArvore(raiz);
    liberaArvore(raiz);
    return 0;
}
