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

void init(CELULA **lista)
{
    *lista = NULL;
    //get_node(lista);
    //(*lista)->next = *lista;
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

        if(empty(*lista))
        {
            q->next = q;
            *lista = q;
        }
        else
        {
            q->next = (*lista)->next;
            (*lista)->next = q;
        }
    }
    else
        printf("\nErro ao alocar o nó...\n");
}

void inserir_fim(CELULA **lista, int val)
{
    CELULA *q;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;

        if(empty(*lista))
            q->next = q;
        else
        {
            q->next = (*lista)->next;
            (*lista)->next = q;
        }
        *lista = q;
    }
    else
        printf("\nErro ao alocar o nó...\n");
}

void remover_inicio(CELULA **lista)
{
    CELULA *aux;

    if(!empty(*lista))
    {
        if((*lista) == (*lista)->next)
        {
            free_node(*lista);
            *lista = NULL;
        }
        else
        {
            aux = (*lista)->next;
            (*lista)->next = aux->next;
            free_node(aux);
        }
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
        if((*lista) == (*lista)->next)
        {
            free_node(*lista);
            *lista = NULL;
        }
        else
        {
            aux = (*lista)->next;
            while(aux->next != *lista)
                aux = aux->next;

            aux->next = (*lista)->next;
            free_node(*lista);
            *lista = aux;
        }
        printf("\nRemovido!\n");
    }
    else
        printf("\nErro! Lista vazia.\n");
}

CELULA* pesquisar(CELULA *lista, int val)
{
    CELULA *aux;

    if(!empty(lista))
    {
        aux = lista->next;
        do
        {
            if(aux->info == val)
                return aux;
            aux = aux->next;
        }
        while(aux != lista->next);
    }

    return NULL;
}

void remover_valor(CELULA **lista, int val)
{
    CELULA *q;
    CELULA *aux;

    if((q = pesquisar(*lista, val)) != NULL)
    {
        aux = (*lista)->next;
        if(aux == q)
            remover_inicio(lista);
        else if(q == *lista)
            remover_fim(lista);
        else
        {
            while(aux->next != q)
                aux = aux->next;
            aux->next = q->next;
            free_node(q);
            printf("\nRemovido!\n");
        }
    }
    else
        printf("\nValor nao encontrado!\n");
}

void exibir_lista(CELULA *lista)
{
    CELULA *aux;

    if(!empty(lista))
    {
        aux = lista->next;
        printf("\nLista - [");
        do
        {
            printf("\t%d", aux->info);
            aux = aux->next;
        }
        while(aux != lista->next);
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
