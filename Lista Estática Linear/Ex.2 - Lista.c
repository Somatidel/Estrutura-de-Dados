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

int listaVazia(LISTA *L)
{
    if(L->n == -1)
        return 1;
    else
        return 0;
}

int menu()
{
    int opcao;

    do
    {
        printf("1. Incluir no inicio;\n");
        printf("2. Incluir no final;\n");
        printf("3. Excluir no inicio;\n");
        printf("4. Excluir no final;\n");
        printf("5. Exibir vetor;\n");
        printf("0. Sair.\n");
        printf("Selecione: ");
        scanf("%d", &opcao);
        printf("\n");
    }
    while(opcao < 0 || opcao > 5);

    return opcao;
}

int incluirInicio(LISTA *L, int valor)
{
    int i;

    if(listaCheia(L))
    {
        printf("\nLista esta cheia!\n");
        return 1;
    }

    for(i=(L->n+1); i>0; i--)
        L->vetor[i] = L->vetor[i-1];
    L->vetor[0] = valor;
    L->n+=1;

    return 0;
}

int incluirFinal(LISTA *L, int valor)
{
    if(listaCheia(L))
    {
        printf("\nLista esta cheia!\n");
        return 1;
    }

    L->vetor[L->n+1] = valor;
    L->n+=1;

    return 0;
}

int excluirInicio(LISTA *L)
{
    int i;

    if(listaVazia(L))
    {
        printf("Lista esta vazia...\n\n");
        return 1;
    }

    for(i=0; i<(L->n+1); i++)
        L->vetor[i] = L->vetor[i+1];
    L->n-=1;

    return 0;
}

int excluirFinal(LISTA *L)
{
    if(listaVazia(L))
    {
        printf("Lista esta vazia...\n");
        return 1;
    }

    L->n-=1;

    return 0;
}

void exibirVetor(LISTA *L)
{
    int i;

    if(!listaVazia(L))
    {
        for(i=0; i<(L->n+1); i++)
            printf("[%d] - %d\n", i, L->vetor[i]);
        printf("\n");
    }
    else
        printf("Lista esta vazia, nada para apresentar.\n\n");

}

void main()
{
    LISTA lista;
    int valor, opcao;

    inicializarLista(&lista);

    do
    {
        opcao = menu();

        switch(opcao)
        {
        case 0:
            printf("Fim do programa.\n");
            break;
        case 1:
            printf("Insira um valor para incluir no inicio: ");
            scanf("%d", &valor);
            if(!incluirInicio(&lista, valor))
                printf("\nInclusao feita com sucesso!\n\n");
            break;
        case 2:
            printf("Insira um valor para incluir no final: ");
            scanf("%d", &valor);
            if(!incluirFinal(&lista, valor))
                printf("\nInclusao feita com sucesso!\n\n");
            break;
        case 3:
            printf("Removendo o valor inicial... ");
            if(!excluirInicio(&lista))
                printf("Sucesso!\n\n");
            break;
        case 4:
            printf("Removendo o valor final... ");
            if(!excluirFinal(&lista))
                printf("Sucessor!\n\n");
            break;
        case 5:
            exibirVetor(&lista);
            break;
        }
    }
    while(opcao != 0);
}
