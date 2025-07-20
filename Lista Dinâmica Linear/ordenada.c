#include<stdio.h>
#include<stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
}CELULA;

CELULA* get_node()
{
    return (CELULA*)malloc(sizeof(CELULA));
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
    return lista == NULL;
}

void inserir_lista_ordem(CELULA **lista, int val)
{
    CELULA *atual=*lista;
    CELULA *anterior=NULL;
    CELULA *q;

    q = get_node();
    if(q != NULL)
    {
        q->info = val;

        while(atual != NULL && atual->info < val)
        {
            anterior = atual;
            atual = atual->next;
        }
        if(atual == *lista)
        {
            q->next = *lista;
            *lista = q;
        }
        else
        {
            anterior->next = q;
            q->next = atual;
        }
    }
    else
        printf("\nErro ao alocar o no!\n");
}

void show(CELULA *lista)
{
    CELULA *aux;

    if(!empty(lista))
    {
        aux = lista;
        printf("\nLista - [\t");
        while(aux != NULL)
        {
            printf("%d\t", aux->info);
            aux = aux->next;
        }
        printf("]\n");
    }
    else
        printf("\nErro! Lista esta vazia.\n");
}

void main()
{
    CELULA *lista;

    init(&lista);

    inserir_lista_ordem(&lista, 7);
    show(lista);
    inserir_lista_ordem(&lista, 1);
    show(lista);
    inserir_lista_ordem(&lista, 8);
    show(lista);
}
