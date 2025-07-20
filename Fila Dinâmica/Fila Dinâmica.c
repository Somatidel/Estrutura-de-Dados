#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
}CELULA;

void get_node(CELULA **q)
{
    *q = (CELULA *)malloc(sizeof(CELULA));
}

void free_node(CELULA *q)
{
    free(q);
}

void init(CELULA **inicio, CELULA **fim)
{
    *inicio = NULL;
    *fim = NULL;
}

int empty(CELULA *inicio, CELULA *fim)
{
    return (inicio == NULL && fim == NULL);
}

void enqueue(CELULA **inicio, CELULA **fim, int val)
{
    CELULA *q;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;
        q->next = NULL;
        if(empty(*inicio, *fim))
            *inicio = q;
        else
            (*fim)->next = q;
        *fim = q;
    }
    else
        printf("\nFalha ao criar o nó...\n");
}

int dequeue(CELULA **inicio, CELULA **fim)
{
    int buffer=-1;
    CELULA *aux;

    if(!empty(*inicio, *fim))
    {
        aux = *inicio;
        buffer = aux->info;
        *inicio = aux->next;
        if(*inicio == NULL)
            *fim = NULL;
        free_node(aux);
    }

    return buffer;
}

void show(CELULA *inicio, CELULA *fim)
{
    CELULA *aux;

    if(!empty(inicio, fim))
    {
        aux = inicio;
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
    CELULA *inicio;
    CELULA *fim;
    int val, opcao;

    init(&inicio, &fim);

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 0:
            printf("Fim do programa.\n");
            break;
        case 1:
            printf("Informe um valor para inserir na pilha: ");
            scanf("%d", &val);
            enqueue(&inicio, &fim, val);
            break;
        case 2:
            printf("Removendo... ");
            if(dequeue(&inicio, &fim) != -1)
                printf("Sucesso!\n");
            else
                printf("Erro, fila esta vazia!\n");
            break;
        case 3:
            printf("Exibindo pilha...\n");
            show(inicio, fim);
            break;
        default:
            printf("Selecione um valor valido!\n\n");
        }
    }
    while(opcao != 0);
}
