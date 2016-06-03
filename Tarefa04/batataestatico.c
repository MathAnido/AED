#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct strcrianca *kid;

typedef struct strcrianca
{
    char* nome;
} crianca;

typedef struct strlista
{
    crianca *lista[1000];
    int primeiro, ultimo, tamanho;
} lista;

lista* cria_lista(void)
{
    lista *rodinha = (lista*) malloc(sizeof (lista));
    rodinha->primeiro=0;
    rodinha->ultimo=0;
    rodinha->tamanho=0;

    return rodinha;
}

int lista_vazia(lista *rodinha)
{
    if(rodinha->tamanho==0)
        return 1;
    else
        return 0;
}

int tamanho_lista(lista *rodinha)
{
    return rodinha->tamanho;
}

void insere_lista(lista *rodinha, crianca *kid, int posicao)
{
   // printf("test\n");
    int i;

    if(posicao<1000){


    /*if(lista_vazia(rodinha)){
        rodinha->lista[0]=kid;
        rodinha->ultimo = 0;
        rodinha->primeiro=0;
    }*/
       // printf("Test\n");
        rodinha->lista[posicao]=kid;
        rodinha->tamanho++;
    }

}

char* retira_lista(lista *rodinha,int posicao)
{
    char* retorno;
    int i;
    retorno = rodinha->lista[posicao]->nome;
    for(i=posicao;i<tamanho_lista(rodinha)-1;i++){
        rodinha->lista[i]=rodinha->lista[i+1];
    }
    rodinha->tamanho--;

    return retorno;
}


int main(void)
{
    int n,k;
    scanf("%d %d",&n,&k);
    lista *rodinha = cria_lista();
    int i;
    for(i = 0; i < n; i++){
        crianca *kid = (crianca*) malloc(sizeof(crianca));
        char * nome = (char*) malloc(sizeof(char)* 20);
        scanf("%s", nome);
        kid->nome = nome;
        insere_lista(rodinha, kid, i);
    }
    int batataquente = 0;
    while(tamanho_lista(rodinha) > 0){

        batataquente = (batataquente + k) % tamanho_lista(rodinha);

        printf("%s\n", retira_lista(rodinha, batataquente));
    }


    /*while(tamanho_lista(rodinha)>1){
        int aux;
        aux=k;
        while(aux>n){
            aux=aux-n+1;
        }
        printf("%s\n",retira_lista(rodinha,aux));

        n--;
        k++;
    }
    */
    return 0;
}



