#include<stdio.h>
#define TAMF 10

typedef struct sFila
{
    int vetor[TAMF];
    int inicio, fim;
} Fila;

void inicializar_fila(Fila *f)
{
    f->inicio = TAMF - 1;
    f->fim = TAMF - 1;
}

int vazia(Fila *f)
{
    if(f->inicio == f->fim)
        return 1;
    return 0;
}

int cheia(Fila *f)
{
    if((f->fim + 1)%TAMF == f->inicio)
        return 1;
    return 0;
}

void queue(Fila *f, int valor)
{
    if(cheia(f))
        printf("Fila cheia!\n\n");
    else
    {
        f->fim = (f->fim+1) % TAMF;
        f->vetor[f->fim] = valor;
    }
}

int dequeue(Fila *f)
{
    if(!vazia(f))
    {
        f->inicio = (f->inicio+1) % TAMF;
        return f->vetor[f->inicio];
    }

    printf("Fila vazia!\n\n");
    return -1;
}

void preencher_fila(Fila *f)
{
    int valor;

    printf("\nInserindo valores... (-1 para sair)\n");
    do
    {
        printf("Informe um valor: ");
        scanf("%d", &valor);
        if(valor == -1)
            printf("Insira pelo menos um valor valido!\n\n");
    }
    while(valor == -1);
    while(!cheia(f) && valor != -1)
    {
        queue(f, valor);

        printf("Informe um valor: ");
        scanf("%d", &valor);
    }
}

int comprimento(Fila f)
{
    return (f->fim - f->inicio+TAMF)%TAMF;
}

void comparar_fila(Fila *F1, Fila *F2)
{
    int contador_fila_1, contador_fila_2;

    if(!vazia(F1) && !vazia(F2))
    {
        contador_fila_1 = comprimento(*F1);
        contador_fila_2 = comprimento(*F2);

        if(contador_fila_1 == contador_fila_2)
            printf("As filas tem o mesmo tamanho.\n\n");
        else if(contador_fila_1 < contador_fila_2)
            printf("A fila 2 tem mais elementos.\n\n");
        else
            printf("A fila 1 tem mais elementos.\n\n");

    }
    else if(!vazia(F1) && vazia(F2))
        printf("Fila 2 esta vazia!\n\n");
    else if(vazia(F1) && !vazia(F2))
        printf("Fila 1 esta vazia!\n\n");
    else
        printf("Ambas as filas estao vazias!\n\n");
}

int menu()
{
    int opcao;

    printf("1. Preencher fila 1;\n");
    printf("2. Preencher fila 2;\n");
    printf("3. Comparar filas;\n");
    printf("0. Sair do programa.\n");
    printf("Selecione: ");
    scanf("%d", &opcao);

    return opcao;
}

void main()
{
    Fila F1, F2;
    int opcao;

    inicializar_fila(&F1);
    inicializar_fila(&F2);

    do
    {
        opcao = menu();

        switch(opcao)
        {
        case 0:
            printf("\nFim de programa.\n");
            break;
        case 1:
            inicializar_fila(&F1);
            preencher_fila(&F1);
            break;
        case 2:
            inicializar_fila(&F2);
            preencher_fila(&F2);
            break;
        case 3:
            comparar_fila(&F1, &F2);
            break;
        default:
            printf("Selecione uma opcao valida.\n\n");
        }
    }
    while(opcao != 0);
}
