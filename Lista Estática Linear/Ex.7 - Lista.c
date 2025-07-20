#include<stdio.h>
#define TAMF 50

typedef struct sLocatario
{
    char nome[50], cpf[15];
} Locador;

typedef struct sBarraca
{
    int idBarraca;
    Locador locatario;
    int situacaoAluguel, idProduto, ocupado;
} Barraca;
//se idProduto = 1, então vende bebida;
//se idProduto = 2, então vende lanche;
//se idProduto = 3, então vende artigos em geral;

typedef struct sLista
{
    Barraca barracas[TAMF];
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

int inicializarBarraca(LISTA* L)
{
    int i;

    for(i=0; i<TAMF; i++)
    {
        L->barracas[i].idBarraca = i+1;
        L->barracas[i].ocupado = 0;
        L->n+=1;
    }

    return 0;
}

int solicitarBarraca(LISTA *L)
{
    if(listaCheia(L))
    {
        printf("Todas as barracas estao ocupadas...\n\n");
        return 1;
    }

    int i=0;

    while(i < (L->n+1) && L->barracas[i].ocupado == 0)
        i++;

    printf("\nAlugando barraca %d\n", L->barracas[i].idBarraca);
    printf("Nome do locatário: ");
    fgets(L->barracas[i].locatario.nome, 49, stdin);
    printf("CPF: ");
    fgets(L->barracas[i].locatario.cpf, 14, stdin);
    printf("Situação do aluguel (1 - Pago, 0 - Não pago): ");
    scanf("%d", &L->barracas[i].situacaoAluguel);
    printf("Produto (1 - Bebida, 2 - Lanches, 3 - Artigos em geral): ");
    scanf("%d", &L->barracas[i].idProduto);
    L->barracas[i].ocupado = 1;

    return 0;
}

int menu()
{
    int opcao;

    do
    {
        printf("Menu:\n");
        printf("1. Alugar barraca\n");
        printf("2. Relatório de inadimplentes\n");
        printf("3. Relatório de barracas livres e ocupadas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao < 0 || opcao > 3)
            printf("Escolha uma opcao valida...\n\n");
    }
    while(opcao < 0 || opcao > 3);

    return opcao;
}

void main()
{
    LISTA barracas;
}


