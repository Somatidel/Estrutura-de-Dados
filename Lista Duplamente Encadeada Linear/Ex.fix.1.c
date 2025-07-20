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
    *q = (CELULA *)malloc(sizeof(CELULA));
}

void free_node(CELULA *q)
{
    free(q);
}

void init(CELULA **lista)
{
    *lista = NULL;
}

int empty(CELULA *lista)
{
    if(lista == NULL)
        return 1;
    return 0;
}

void inserir_inicio(CELULA **lista, int val)
{
    CELULA *q;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;
        q->dir = *lista;
        q->esq = NULL;
        if(!empty(*lista))
            (*lista)->esq = q;
        *lista = q;
    }
    else
        printf("\nErro ao alocar o nó...\n");
}

void inserir_fim(CELULA **lista, int val)
{
    CELULA *q;
    CELULA *aux;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;
        q->dir = NULL;

        if(empty(*lista))
        {
            q->esq = NULL;
            *lista = q;
        }
        else
        {
            aux = *lista;
            while(aux->dir != NULL)
                aux = aux->dir;

            q->esq = aux;
            aux->dir = q;
        }
    }
    else
        printf("\nErro ao alocar o nó...\n");
}

void remover_inicio(CELULA **lista)
{
    CELULA *aux;

    if(!empty(*lista))
    {
        aux = *lista;
        *lista = aux->dir;
        if(!empty(*lista))
            (*lista)->esq = NULL;
        free_node(aux);
        printf("\nRemovido!\n");
    }
    else
        printf("\nErro! Lista vazia.\n");
}

void remover_fim(CELULA **lista)
{
    CELULA *aux;

    if(!empty(*lista))
    {
        aux = *lista;
        if(aux->dir == NULL)
            *lista = NULL;
        else
        {
            while(aux->dir != NULL)
                aux = aux->dir;

            (aux->esq)->dir = NULL;
        }

        printf("\nRemovido!\n");
        free_node(aux);
    }
    else
        printf("\nErro! Lista vazia.\n");
}

CELULA* pesquisar(CELULA *lista, int val)
{
    CELULA *aux;

    if(!empty(lista))
    {
        aux = lista;
        while(aux->dir != NULL)
        {
            if(aux->info == val)
                return aux;
            aux = aux->dir;
        }
    }

    return NULL;
}

void remover_valor(CELULA **lista, int val)
{
    CELULA *q;

    if((q = pesquisar(*lista, val)) != NULL)
    {
        if(q == *lista)
            remover_inicio(lista);
        else
        {
            (q->esq)->dir = q->dir;
            if(q->dir != NULL)
                (q->dir)->esq = q->esq;
            free_node(q);
        }
        printf("\nRemovido!\n");
    }
    else
        printf("\nValor nao encontrado!\n");
}

void exibir_lista(CELULA *lista)
{
    CELULA *aux;

    if(!empty(lista))
    {
        aux = lista;
        printf("\nLista - [");
        while(aux != NULL)
        {
            printf("\t%d", aux->info);
            aux = aux->dir;
        }
        printf("\t]\n");
    }
    else
        printf("\nLista vazia, nada para exibir!\n");
}

int menu()
{
    int opcao;

    printf("----------MENU----------\n");
    printf("1. Inserir no inicio;\n");
    printf("2. Inserir no fim;\n");
    printf("3. Remover no inicio;\n");
    printf("4. Remover um elemento;\n");
    printf("5. Remover no fim;\n");
    printf("6. Exibir lista;\n");
    printf("0. Sair do programa.\n");
    printf("Selecione: ");
    scanf("%d", &opcao);

    return opcao;
}

void main()
{
    CELULA *lista;
    int opcao, val;

    init(&lista);

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 0:
            printf("\nFim de programa!");
            break;
        case 1:
            printf("\nInforme um valor para inserir: ");
            scanf("%d", &val);
            inserir_inicio(&lista, val);
            break;
        case 2:
            printf("\nInforme um valor para inserir: ");
            scanf("%d", &val);
            inserir_fim(&lista, val);
            break;
        case 3:
            printf("\nRemovendo no inicio...");
            remover_inicio(&lista);
            break;
        case 4:
            printf("\nInforme um valor para buscar e remover: ");
            scanf("%d", &val);
            remover_valor(&lista, val);
            break;
        case 5:
            printf("\nRemovendo no fim...");
            remover_fim(&lista);
            break;
        case 6:
            printf("\nApresentando...\n");
            exibir_lista(lista);
            break;
        default:
            printf("\nSelecione uma opcao valida!\n");
        }
    }
    while(opcao != 0);
}
