#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *esq;
    struct cell *dir;
}CELULA;

typedef struct sDeque
{
    CELULA *inicio;
    CELULA *fim;
}DEQUE;

CELULA* get_node()
{
    return (CELULA*)malloc(sizeof(CELULA));
}

void free_node(CELULA *q)
{
    free(q);
}

void init(DEQUE *deque)
{
    deque->inicio = NULL;
    deque->fim = NULL;
}

int empty(DEQUE deque)
{
    return (deque.inicio == NULL && deque.fim == NULL);
}

void inserir_inicio(DEQUE *deque, int val)
{
    CELULA *q;

    q = get_node();
    if(q != NULL)
    {
        q->info = val;
        q->esq = NULL;
        q->dir = deque->inicio;
        if(empty(*deque))
            deque->fim = q;
        else
            (deque->inicio)->esq = q;

        deque->inicio = q;
    }
    else
        printf("\nErro ao alocar o no...\n");
}

void inserir_fim(DEQUE *deque, int val)
{
    CELULA *q;

    q = get_node();
    if(q != NULL)
    {
        q->info = val;
        q->esq = deque->fim;
        q->dir = NULL;
        if(empty(*deque))
            deque->inicio = q;
        else
            (deque->fim)->dir = q;
        deque->fim = q;
    }
    else
        printf("\nErro ao alocar o no...\n");
}

int remover_inicio(DEQUE *deque)
{
    int buffer=-1;
    CELULA *aux;

    if(!empty(*deque))
    {
        buffer = (deque->inicio)->info;
        if(deque->inicio == deque->fim)
        {
            free_node(deque->inicio);
            deque->inicio = NULL;
            deque->fim = NULL;
        }
        else
        {
            aux = deque->inicio;
            ((deque->inicio)->dir)->esq = NULL;
            deque->inicio = (deque->inicio)->dir;
            free_node(aux);
        }
        return 1;
    }
    return buffer;
}

int remover_fim(DEQUE *deque)
{
    int buffer=-1;
    CELULA *aux;

    if(!empty(*deque))
    {
        buffer = (deque->fim)->info;
        if(deque->inicio == deque->fim)
        {
            free_node(deque->fim);
            deque->inicio = NULL;
            deque->fim = NULL;
        }
        else
        {
            aux = deque->fim;
            ((deque->fim)->esq)->dir = NULL;
            deque->fim = (deque->fim)->esq;
            free_node(aux);
        }
    }
    return buffer;
}

void show(DEQUE deque)
{
    CELULA *aux;

    if(!empty(deque))
    {
        aux = deque.inicio;
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
    DEQUE deque;
    int opcao, val;

    init(&deque);

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
            inserir_inicio(&deque, val);
            break;
        case 2:
            printf("Informe um valor para inserir no fim: ");
            scanf("%d", &val);
            inserir_fim(&deque, val);
            break;
        case 3:
            printf("\nRemovendo no inicio do deque... ");
            if(remover_inicio(&deque) != -1)
                printf("Removido!\n");
            else
                printf("Erro! Deque vazia.\n");
            break;
        case 4:
            printf("\nRemovendo no fim do deque... ");
            if(remover_fim(&deque) != -1)
                printf("Removido!\n");
            else
                printf("Erro! Deque vazia.\n");
            break;
        case 5:
            printf("\nApresentando...");
            show(deque);
            break;
        default:
            printf("\nSelecione uma opcao valida!\n");
        }
    }
    while(opcao != 0);
}
