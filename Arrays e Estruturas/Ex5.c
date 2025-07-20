#include <stdio.h>
#include <string.h>

#define MAXIMOPRODUTOS 2

typedef struct
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} produto;

void removerEspaco(char nome[])
{
    if(nome[strlen(nome)-1] == '\n')
        nome[strlen(nome)-1] = '\0';
}

void cadastrarProdutos(produto produtos[], int tamanho)
{
    int i;

    for (i=0; i<tamanho; i++)
    {
        printf("\nCadastro do produto %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        fflush(stdin);
        printf("Nome: ");
        fgets(produtos[i].nome, 50, stdin);
        removerEspaco(produtos[i].nome);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
    }
}


int encontrarMaiorPreco(produto produtos[], int tamanho)
{
    int indiceMaior=0,
        preco,
        i=1;

    while(i < tamanho)
    {
        if(produtos[i].preco > produtos[indiceMaior].preco)
            indiceMaior = i;
        i++;
    }

    return indiceMaior;
}

int encontrarMaiorQuantidade(produto produtos[], int tamanho)
{
    int indiceMaior=0, i=1;

    while(i < tamanho)
    {
        if(produtos[i].quantidade > produtos[indiceMaior].quantidade)
            indiceMaior = i;
        i++;
    }

    return indiceMaior;
}

void apresentarProduto(produto produtos[], int indice)
{
    printf("\n%d\n%s\n%d\nR$%.2f\n",
           produtos[indice].codigo, produtos[indice].nome,
           produtos[indice].quantidade, produtos[indice].preco);
}

int menu()
{
    int opcao;

    do
    {
        printf("Menu:\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Encontrar produto com maior preco\n");
        printf("3 - Encontrar produto com maior quantidade\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 3)
            printf("\nSelecione uma opcao valida...\n\n");
    }
    while (opcao < 0 || opcao > 3);

    return opcao;
}

void main()
{
    produto produtos[MAXIMOPRODUTOS];
    int opcao, cadastrados=0;

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            cadastrarProdutos(produtos, MAXIMOPRODUTOS);
            cadastrados = 1;
            break;
        case 2:
            if (cadastrados)
                apresentarProduto(produtos, encontrarMaiorPreco(produtos, MAXIMOPRODUTOS));
            else
                printf("\nCadastre os produtos primeiro!\n");
            break;
        case 3:
            if (cadastrados)
                apresentarProduto(produtos, encontrarMaiorQuantidade(produtos, MAXIMOPRODUTOS));
            else
                printf("\nCadastre os produtos primeiro!\n");
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
        }
    }
    while (opcao != 0);
}
