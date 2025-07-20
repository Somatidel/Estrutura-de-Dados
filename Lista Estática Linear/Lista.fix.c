#include<stdio.h>
#define TAMF 10

typedef struct sLista
{
    char valor[TAMF];
    int n;
} LISTA;

void inicializarLista(LISTA *L)
{
    L->n = -1; //(*L).n = -1;
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
    if(L-> n+1 == TAMF)
        return 1;
    else
        return 0;
}

int inserirListaFim(LISTA *L, char elemento)
{
    if(listaCheia(L))
    {
        printf("\nLista esta cheia!\n");
        return 1;
    }
    L->valor[L->n+1] = elemento;
    L->n = L->n++;

    return 0;
}

int inserirListaPosicao(LISTA *L, int posicao, char elemento)
{
    if(listaCheia(L))
    {
        printf("\nLista esta cheia!\n");
        return 1;
    }

    if(posicao < 0 || posicao > L->n+1)
    {
        printf("\nValor invalido!\n");
        return 0;
    }

}

void main()
{
    LISTA lista;
    inicializarLista(&lista);
}
