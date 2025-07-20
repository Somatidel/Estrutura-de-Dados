#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *esq;
    struct cell *dir;
}CELULA;

void get_node(CELULA **q)
{
    *q = (CELULA*)malloc(sizeof(CELULA));
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

void inserir_inicio(CELULA **inicio, CELULA **fim, int val)
{
    CELULA *q;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;
        q->esq = NULL;
        q->dir = *inicio;
        if(empty(*inicio, *fim))
            *fim = q;
        else
            (*inicio)->esq = q;
        *inicio = q;
    }
    else
        printf("\nErro ao alocar o no...\n");
}

void inserir_fim(CELULA **inicio, CELULA **fim, int val)
{
    CELULA *q;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;
        q->esq = *fim;
        q->dir = NULL;
        if(empty(*inicio, *fim))
            *inicio = q;
        else
            (*fim)->dir = q;
        *fim = q;
    }
    else
        printf("\nErro ao alocar o no...\n");
}

int remover_inicio(CELULA **inicio, CELULA **fim)
{
    CELULA *aux;

    if(!empty(*inicio, *fim))
    {
        if(*inicio == *fim)
        {
            free_node(*inicio);
            *inicio = NULL;
            *fim = NULL;
        }
        else
        {
            aux = *inicio;
            ((*inicio)->dir)->esq = NULL;
            *inicio = (*inicio)->dir;
            free_node(aux);
        }
        return 1;
    }
    return 0;
}

int remover_fim(CELULA **inicio, CELULA **fim)
{
    CELULA *aux;

    if(!empty(*inicio, *fim))
    {
        if(*inicio == *fim)
        {
            free_node(*fim);
            *inicio = NULL;
            *fim = NULL;
        }
        else
        {
            aux = *fim;
            ((*fim)->esq)->dir = NULL;
            *fim = (*fim)->esq;
            free_node(aux);
        }
        return 1;
    }
    return 0;
}

void show(CELULA *inicio, CELULA *fim)
{
    CELULA *aux;

    if(!empty(inicio, fim))
    {
        aux = inicio;
        printf("\nDeque - [\t");
        while(aux != NULL)
        {
            printf("%d\t", aux->info);
            aux = aux->dir;
        }
        printf("]\n");
    }
    else
        printf("\nDeque vazia: nada para apresentar!\n");
}

int menu()
{
    int opcao;

    printf("----------MENU----------\n");
    printf("1. Inserir no inicio;\n");
    printf("2. Inserir no fim;\n");
    printf("3. Remover no inicio;\n");
    printf("4. Remover no fim;\n");
    printf("5. Exibir elementos;\n");
    printf("0. Sair do programa.\n");
    printf("Selecione: ");
    scanf("%d", &opcao);
    printf("\n");

    return opcao;
}

void main()
{
    CELULA *inicio;
    CELULA *fim;
    int opcao, val;

    init(&inicio, &fim);

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 0:
            printf("\nFim de programa.");
            break;
        case 1:
            printf("Informe um valor para inserir no inicio: ");
            scanf("%d", &val);
            inserir_inicio(&inicio, &fim, val);
            break;
        case 2:
            printf("Informe um valor para inserir no fim: ");
            scanf("%d", &val);
            inserir_fim(&inicio, &fim, val);
            break;
        case 3:
            printf("\nRemovendo no inicio do deque... ");
            if(remover_inicio(&inicio, &fim))
                printf("Removido!\n");
            else
                printf("Erro! Deque vazia.\n");
            break;
        case 4:
            printf("\nRemovendo no fim do deque... ");
            if(remover_fim(&inicio, &fim))
                printf("Removido!\n");
            else
                printf("Erro! Deque vazia.\n");
            break;
        case 5:
            printf("\nApresentando...");
            show(inicio, fim);
            break;
        default:
            printf("\nSelecione uma opcao valida!\n");
        }
    }
    while(opcao != 0);
}
