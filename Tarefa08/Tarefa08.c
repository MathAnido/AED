#include<stdio.h>
#include<stdlib.h>
typedef struct no{
    int id;
    struct no *esquerda,*direita;
} TNo;

TNo * iniciaNo(int id){
    TNo * novo = (TNo *) malloc(sizeof(TNo));
    (*novo).id = id;
    (*novo).esquerda = (*novo).direita = NULL;
    return novo;
}

void constroi(TNo **x, int *i, int *pre, int*em,int e, int raiz, int d){
    int nRaiz;
    *x = iniciaNo(pre[*i]);
    if(e<raiz){
        *i = *i + 1;
        for(nRaiz=0; pre[*i]!=em[nRaiz]; nRaiz++);
        constroi(&(**x).esquerda, i, pre, em, e, nRaiz, raiz-1);
    }
    if(d>raiz){
        *i = *i + 1;
        for(nRaiz=raiz; pre[*i]!=em[nRaiz]; nRaiz++);
        constroi(&(**x).direita, i, pre, em, raiz+1, nRaiz, d);
    }
}

void imprime(TNo *x){
    if((*x).esquerda!=NULL) imprime((*x).esquerda);
    if((*x).direita!=NULL)  imprime((*x).direita);
    printf("%d\n",(*x).id);
    free(x);
}

int main(void){
    TNo *raiz = NULL;
    int *pre=NULL, *em=NULL, n, i, c=0;
    scanf("%d",&n);
    pre = (int *) malloc(sizeof(int)*n);
    em = (int *) malloc(sizeof(int)*n);
    for(i=0; i<n; i++)  scanf("%d",&pre[i]);
    for(i=0; i<n; i++)  scanf("%d",&em[i]);
    for(i=0; pre[c]!=em[i]; i++);
    constroi(&raiz,&c,pre,em,0,i,n-1);
    imprime(raiz);
    free(pre);
    free(em);
    return 0;
}