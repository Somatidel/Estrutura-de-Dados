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

int inserirLista(LISTA *L, int pos, int numero)
{
    int i;

    if(listaCheia(L))
    {
        printf("\nLista esta cheia!\n");
        return 1;
    }

    if(pos < 0 || pos > L->n+1)
    {
        printf("\nPosicao invalida!\n");
        return 1;
    }

    for(i=L->n+1; i>pos; i--)
        L->vetor[i] = L->vetor[i-1];

    L->vetor[pos] = numero;
    L->n = L->n+=1;

    return 0;
}

int removerLista(LISTA *L, int pos)
{
    int i;

    if(pos < 0 || pos > L->n+1)
    {
        printf("\nPosicao invalida!\n");
        return 1;
    }

    for(i=pos; i<L->n+1; i++)
        L->vetor[i] = L->vetor[i+1];

    L->n = L->n-=1;

    return 0;
}

int acessarValorLista(LISTA *L, int pos)
{
    if(pos < 0 || pos > L->n)
        printf("\nPosicao invalida!\n");
    else
        return L->vetor[pos];
}

int procurarValorLista(LISTA *L, int numero)
{
    int i=0, elemento = -1;

    while(i<L->n+1 && elemento == -1)
    {
        if(L->vetor[i] == numero)
            elemento = i;
        i++;
    }

    return elemento;
}

void exibirVetor(LISTA *L)
{
    int i;

    for(i=0; i<(L->n+1); i++)
        printf("[%d] - %d\n", i, L->vetor[i]);
    printf("\n");
}

int menu()
{
    int opcao;

    do
    {
        printf("1. Inserir um elemento em uma posicao especifica;\n");
        printf("2. Remover um elemento de uma posicao especifica;\n");
        printf("3. Acessar um elemento de uma posicao especifica;\n");
        printf("4. Procurar um determinado elemento;\n");
        printf("5. Exibir os elementos do vetor.\n");
        printf("0. Sair;\n");
        printf("Selecione: ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao < 0 || opcao > 5)
            printf("\nSelecione uma opcao valida!\n");
    }
    while(opcao < 0 || opcao > 5);

    return opcao;
}


void main()
{
    LISTA lista;
    int opcao, pos, valor;

    inicializarLista(&lista);

    do
    {
        opcao = menu();

        switch(opcao)
        {
        case 0:
            printf("\nFim do programa.\n");
            break;
        case 1:
            printf("Insira um valor e uma posicao para inserir: ");
            scanf("%d %d", &valor, &pos);
            if(!inserirLista(&lista, pos, valor))
                printf("\nInclusao bem sucedida!\n");
            break;
        case 2:
            printf("Insira uma posicao para excluir: ");
            scanf("%d", &pos);
            if(!removerLista(&lista, pos))
                printf("Exclusao bem sucedida!\n");
            break;
        case 3:
            printf("Informe uma posicao para acessar: ");
            scanf("%d", &pos);
            printf("[%d] - %d\n", pos, acessarValorLista(&lista, pos));
            break;
        case 4:
            printf("Digite um valor para pesquisar: ");
            scanf("%d", &valor);
            pos = procurarValorLista(&lista, valor);
            if(pos == -1)
                printf("\nValor nao encontrado...\n");
            else
                printf("\n[%d] - %d\n\n", pos, valor);
            break;
        case 5:
            exibirVetor(&lista);
            break;
        }
    }
    while(opcao != 0);
}
