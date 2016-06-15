#include <stdio.h>
#include <stdlib.h>
typedef struct lista
{
    int tam;
    struct no * primeiro,*ultimo;
} TLista;
typedef struct no
{
    int n;
    struct no *prox;
    TLista filhos;
} TNo;
void iniciaLista(TLista *x)
{
    (*x).tam = 0;
    (*x).primeiro = (*x).ultimo = NULL;
}
TNo * iniciaNo(int n)
{
    TNo * novo = (TNo *) malloc(sizeof(TNo));
    (*novo).n = n;
    (*novo).prox = NULL;
    iniciaLista(&(*novo).filhos);
    return novo;
}
int insereLista(TLista *x, TNo * y)
{
    if((*x).tam == 0)///lista esta vazia
        (*x).primeiro = (*x).ultimo = y;
    else
    {
        (*(*x).ultimo).prox = y;
        (*x).ultimo = y;
    }
    (*x).tam++;
}
void insereNo(TNo *x, int p,TNo * f)/// (x) No atual | (p) N do Pai | (f) Nó filho
{
    TNo *aux;///Primeiro No da arvore
    if((*x).n == p) ///Verifica se eh o pai
        insereLista(&(*x).filhos,f);
    else if((*x).filhos.tam > 0) ///Verifica se tem filhos
        for(aux = (*x).filhos.primeiro; aux!=NULL; aux= (*aux).prox) ///Percorre filhos
            insereNo(aux,p,f);
}
void imprimeArvore(TNo *x)
{
    TNo * aux;
    printf("(%d",(*x).n);
    if((*x).filhos.tam > 0)
        for(aux = (*x).filhos.primeiro; aux != NULL; aux = (*aux).prox) ///Percorre filhos
            imprimeArvore(aux);
    printf(")");
}
void liberaArvore(TNo *x)
{
    TNo * aux;
    if((*x).filhos.tam > 0)
        for(aux = (*x).filhos.primeiro; aux != NULL; aux = (*aux).prox) ///Percorre filhos
            liberaArvore(aux);
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
