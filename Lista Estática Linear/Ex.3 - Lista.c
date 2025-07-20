#include<stdio.h>
#define TAMF 10

/**
Desenvolva um programa em Linguagem C que permita fazer as seguintes operações
sobre uma lista linear estática de números reais: inserir um elemento mantendo a
ordem crescente entre os elementos no vetor; remover um valor indicado pelo usuário,
eliminando eventuais “lacunas abertas” com a remoção.
**/

typedef struct sLista
{
    float vetor[TAMF];
    int n;
} LISTA;

void inicializarLista(LISTA *L)
{
    L->n = -1;
}

int listaCheia(LISTA *L)
{
    return (L->n+1 == TAMF);
}

int listaVazia(LISTA *L)
{
    return (L->n == -1);
}

int incluirOrdemCrescente(LISTA *L, float valor)
{
    int i=0, j;

    if(listaCheia(L))
    {
        printf("Lista esta cheia!\n\n");
        return 1;
    }

    while(i<L->n+1 && valor > L->vetor[i])
        i++;

    for(j=(L->n+1); j>i; j--)
        L->vetor[j] = L->vetor[j-1];
    L->vetor[i] = valor;
    L->n+=1;

    return 0;
}

int excluirElemento(LISTA *L, float valor)
{
    int i, novoTam=0;

    if(listaVazia(L))
    {
        printf("Lista esta vazia...\n\n");
        return 1;
    }

    for(i=0; i<(L->n+1); i++)
        if(L->vetor[i] != valor)
        {
            L->vetor[novoTam] = L->vetor[i];
            novoTam++;
        }

    if(novoTam == i)
    {
        printf("Valor nao encontrado...\n\n");
        return 1;
    }

    L->n = novoTam-1;

    return 0;
}

void exibirVetor(LISTA *L)
{
    int i;

    if(!listaVazia(L))
    {
        for(i=0; i<(L->n+1); i++)
            printf("[%d] - %.2f\n", i, L->vetor[i]);
        printf("\n");
    }
    else
        printf("Lista esta vazia, nada para apresentar.\n\n");
}

int menu()
{
    int opcao;

    do
    {
        printf("1. Incluir um elemento (ordem crescente);\n");
        printf("2. Excluir um elemento;\n");
        printf("3. Exibir lista;\n");
        printf("0. Sair.\n");
        printf("Selecione: ");
        scanf("%d", &opcao);
        printf("\n");
    }
    while(opcao < 0 || opcao > 3);

    return opcao;
}

void main()
{
    LISTA lista;
    int opcao;
    float valor;

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
            printf("Insira um valor para incluir na lista: ");
            scanf("%f", &valor);
            if(!incluirOrdemCrescente(&lista, valor))
                printf("Inclusao feita com sucesso!\n\n");
            break;
        case 2:
            printf("Informe um valor para excluir da lista: ");
            scanf("%f", &valor);
            if(!excluirElemento(&lista, valor))
                printf("Sucesso!\n\n");
            break;
        case 3:
            exibirVetor(&lista);
            break;
        }
    }
    while(opcao != 0);
}
