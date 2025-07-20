#include<stdio.h>
#define TAMF 10

typedef struct sFila
{
    int vetor[TAMF];
    int inicio, fim;
} Fila;

typedef struct sPilha
{
    int vetor[TAMF];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p)
{
    p->topo = -1;
}

void inicializar_fila(Fila *f)
{
    f->inicio = TAMF - 1;
    f->fim = TAMF - 1;
}

int pilha_cheia(Pilha *p)
{
    if(p->topo+1 == TAMF)
        return 1;
    return 0;
}

int pilha_vazia(Pilha *p)
{
    if(p->topo == -1)
        return 1;
    return 0;
}

int fila_vazia(Fila *f)
{
    if(f->inicio == f->fim)
        return 1;
    return 0;
}

int fila_cheia(Fila *f)
{
    if((f->fim+1) % TAMF == f->inicio)
        return 1;
    return 0;
}

void empilhar(Pilha *p, int valor)
{
    if(pilha_cheia(p))
        printf("Pilha cheia!\n\n");
    else
    {
        p->topo++;
        p->vetor[p->topo] = valor;
    }
}

int desempilhar(Pilha *p)
{
    if(pilha_vazia(p))
    {
        printf("Pilha vazia!\n\n");
        return -1;
    }

    return p->vetor[p->topo--];
}

void enfileirar(Fila *f, int valor)
{
    f->fim = (f->fim + 1) % TAMF;

    if(fila_vazia(f))
    {
        printf("Fila cheia!\n\n");
        f->fim--;
        if(f->fim == -1)
            f->fim = TAMF - 1;
    }
    else
        f->vetor[f->fim] = valor;
}

int desenfileirar(Fila *f)
{
    if(!fila_vazia(f))
    {
        f->inicio = (f->inicio + 1) % TAMF;
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
    while(valor != -1)
    {
        enfileirar(f, valor);

        printf("Informe um valor: ");
        scanf("%d", &valor);
    }
}

void inverter_fila(Fila *f)
{
    Pilha auxiliar;

    inicializar_pilha(&auxiliar);

    if(!fila_vazia(f))
    {
        while(!fila_vazia(f))
            empilhar(&auxiliar, desenfileirar(f));

        while(!pilha_vazia(&auxiliar))
            enfileirar(f, desempilhar(&auxiliar));
    }
    else
        printf("Nao ha nada para inverter.\n\n");
}

void exibir_fila(Fila f)
{
    if(!fila_vazia(&f))
        while(!fila_vazia(&f))
            printf("Elemento: %d\n", desenfileirar(&f));
    else
        printf("Nada a exibir.\n\n");
}

int menu()
{
    int opcao;

    printf("1. Preencher fila;\n");
    printf("2. Inverter ordem da fila;\n");
    printf("3. Exibir fila;\n");
    printf("0. Sair do programa.\n");
    printf("Selecione: ");
    scanf("%d", &opcao);

    return opcao;
}

void main()
{
    Fila fila;
    int opcao;

    inicializar_fila(&fila);

    do
    {
        opcao = menu();

        switch(opcao)
        {
        case 0:
            printf("\nFim de programa!\n");
            break;
        case 1:
            preencher_fila(&fila);
            break;
        case 2:
            inverter_fila(&fila);
            break;
        case 3:
            exibir_fila(fila);
            break;
        default:
            printf("Selecione uma opcao valida!\n\n");
        }
    }
    while(opcao != 0);
}
