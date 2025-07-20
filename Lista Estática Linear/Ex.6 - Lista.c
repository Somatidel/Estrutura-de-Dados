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

int listaVazia(LISTA *L)
{
    if(L->n == -1)
        return 1;
    else
        return 0;
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

int inverterLista(LISTA *L1, LISTA *L2)
{
    int i;

    if(listaVazia(L1))
    {
        printf("Lista esta vazia, nao eh possivel realizar a operacao.\n\n");
        return 1;
    }

    for(i=0; i<(L1->n+1); i++)
        incluirLista(L2, L1->vetor[(L1->n)-i]);

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

    printf("Lista 1:\n");
    exibirVetor(&lista_1);

    printf("Lista 2:\n");
    exibirVetor(&lista_2);

    inverterLista(&lista_1, &lista_2);

    printf("Lista 2:\n");
    exibirVetor(&lista_2);
}
