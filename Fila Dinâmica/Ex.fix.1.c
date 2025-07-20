#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
}CELULA;

typedef struct sFila
{
    CELULA *inicio;
    CELULA *fim;
}FILA;

void get_node(CELULA **q)
{
    *q = (CELULA*)malloc(sizeof(CELULA));
}

void free_node(CELULA *q)
{
    free(q);
}

void init(FILA *fila)
{
    fila->fim = NULL;
    fila->inicio = NULL;
}

int empty(FILA fila)
{
    return (fila.inicio == NULL && fila.fim == NULL);
}

void enqueue(FILA *fila, int val)
{
    CELULA *q;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;
        q->next = NULL;
        if(empty(*fila))
            fila->inicio = q;
        else
            (fila->fim)->next = q;
        fila->fim = q;
    }
    else
        printf("\nErro ao alocar o no!\n");
}

int dequeue(FILA *fila)
{
    int buffer=-1;
    CELULA *aux;

    if(!empty(*fila))
    {
        aux = fila->inicio;
        buffer = aux->info;
        fila->inicio = aux->next;
        if(fila->inicio == NULL)
            fila->fim = NULL;
        free_node(aux);
    }

    return buffer;
}

void show(FILA fila)
{
    CELULA *aux;

    if(!empty(fila))
    {
        aux = fila.inicio;
        printf("Fila - [\t");
        while(aux != NULL)
        {
            printf("%d\t", aux->info);
            aux = aux->next;
        }
        printf("]\n");
    }
    else
        printf("Nada para exibir, fila vazia!\n");
}

int menu()
{
    int opcao;

    printf("------------MENU------------\n");
    printf("1. Inserir na fila;\n");
    printf("2. Remover da fila;\n");
    printf("3. Exibir elementos;\n");
    printf("0. Sair do programa;\n");
    printf("Selecione: ");
    scanf("%d", &opcao);
    printf("\n");

    return opcao;
}

void main()
{
    FILA fila;
    int val, opcao;

    init(&fila);

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 0:
            printf("Fim do programa.\n");
            break;
        case 1:
            printf("Informe um valor para inserir na fila: ");
            scanf("%d", &val);
            enqueue(&fila, val);
            break;
        case 2:
            printf("Removendo... ");
            if(dequeue(&fila) != -1)
                printf("Sucesso!\n");
            else
                printf("Erro, fila esta vazia!\n");
            break;
        case 3:
            printf("Exibindo fila...\n");
            show(fila);
            break;
        default:
            printf("Selecione um valor valido!\n\n");
        }
    }
    while(opcao != 0);
}
