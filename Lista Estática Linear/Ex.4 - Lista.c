#include<stdio.h>
#define TAMF 10

typedef struct sLista
{
    int vetor[TAMF];
    int n;
} LISTA;

void inicializarLista(LISTA *L)
{
    L->n = -1;
}

int listaCheia(LISTA *L)
{
    if(L->n+1 == TAMF)
        return 1;
    else
        return 0;
}

int incluirLista(LISTA *L, int valor)
{
    if(listaCheia(L))
    {
        printf("Lista 1 esta cheia!\n\n");
        return 1;
    }

    L->vetor[L->n+1] = valor;
    L->n+=1;

    return 0;
}

int concatenarLista(LISTA *L1, LISTA *L2)
{
    if(listaCheia(L1))
    {
        printf("Lista 1 esta cheia!\n\n");
        return 1;
    }

    int i;

    for(i=0; L1->n+1 < TAMF && i < (L2->n+1); i++)
    {
        L1->vetor[L1->n+1] = L2->vetor[i];
        L1->n+=1;
    }

    return 0;
}

void exibirVetor(LISTA *L)
{
    int i;

    for(i=0; i<(L->n+1); i++)
        printf("[%d] - %d\n", i, L->vetor[i]);
    printf("\n");
}

void main()
{
    LISTA lista_1, lista_2;

    inicializarLista(&lista_1);
    inicializarLista(&lista_2);

    incluirLista(&lista_1, 1);
    incluirLista(&lista_1, 2);
    incluirLista(&lista_1, 3);
    incluirLista(&lista_1, 4);
    incluirLista(&lista_1, 5);
    incluirLista(&lista_1, 6);

    incluirLista(&lista_2, 1);
    incluirLista(&lista_2, 2);
    incluirLista(&lista_2, 3);
    incluirLista(&lista_2, 4);
    incluirLista(&lista_2, 5);

    exibirVetor(&lista_1);
    exibirVetor(&lista_2);

    concatenarLista(&lista_1, &lista_2);

    exibirVetor(&lista_1);
}
