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
        q->next = *lista;
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
        q->next = NULL;

        if(empty(*lista))
            *lista = q;
        else
        {
            aux = *lista;
            while(aux->next != NULL)
                aux = aux->next;

            aux->next = q;
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
        *lista = aux->next;
        free_node(aux);

        printf("\nRemovido!\n");
    }
    else
        printf("\nErro! Lista vazia.\n");
}

void remover_fim(CELULA **lista)
{
    CELULA *aux1;
    CELULA *aux2;

    if(!empty(*lista))
    {
        aux1 = *lista;
        if(aux1->next == NULL)
            *lista = NULL;
        else
        {
            while(aux1->next != NULL)
                aux1 = aux1->next;

            aux2 = *lista;
            while(aux2->next != aux1 && aux2->next != NULL)
                aux2 = aux2->next;

            aux2->next = NULL;
        }

        free_node(aux1);
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
        aux = lista;
        while(aux != NULL)
        {
            if(aux->info == val)
                return aux;
            aux = aux->next;
        }
    }

    return NULL;
}

void remover_valor(CELULA **lista, int val)
{
    CELULA *q;
    CELULA *aux;

    if((q = pesquisar(*lista, val)) != NULL)
    {
        aux = *lista;
        if(aux == q)
            remover_inicio(lista);
        else
        {
            while(aux->next != q)
                aux = aux->next;
            aux->next = q->next;
            free_node(q);
        }
        printf("Removido!\n");
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
            aux = aux->next;
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
