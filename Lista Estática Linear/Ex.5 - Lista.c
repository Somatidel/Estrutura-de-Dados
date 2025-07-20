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

int intercalarLista(LISTA *L1, LISTA *L2, LISTA *L3)
{
    int i=0;

    while(L3->n+1 != TAMF && (i < L1->n+1 || i < L2->n+1))
    {
        if(i < L1->n+1)
            incluirLista(L3, L1->vetor[i]);
        if(i < L2->n+1)
            incluirLista(L3, L2->vetor[i]);
        i++;
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
    LISTA lista_1, lista_2, lista_3;

    inicializarLista(&lista_1);
    inicializarLista(&lista_2);
    inicializarLista(&lista_3);

    incluirLista(&lista_1, 1);
    incluirLista(&lista_1, 3);
    incluirLista(&lista_1, 5);
    incluirLista(&lista_1, 6);
    incluirLista(&lista_1, 7);
    incluirLista(&lista_1, 8);

    incluirLista(&lista_2, 2);
    incluirLista(&lista_2, 4);

    exibirVetor(&lista_1);
    exibirVetor(&lista_2);
    exibirVetor(&lista_3);

    intercalarLista(&lista_1, &lista_2, &lista_3);

    exibirVetor(&lista_3);
}
