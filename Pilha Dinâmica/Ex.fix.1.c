#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
}CELULA;

void get_node(CELULA **q)
{
    *q = (CELULA*)malloc(sizeof(CELULA));
}

void free_node(CELULA *q)
{
    free(q);
}

void init(CELULA **pilha)
{
    *pilha = NULL;
}

int empty(CELULA *pilha)
{
    return (pilha == NULL);
}

void push(CELULA **pilha, int val)
{
    CELULA *q;

    get_node(&q);
    if(q != NULL)
    {
        q->info = val;
        q->next = *pilha;
        *pilha = q;
    }
    else
        printf("\nErro ao alocar o no...\n");
}

int pop(CELULA **pilha)
{
    CELULA *aux;
    int num;

    if(!empty(*pilha))
    {
        aux = *pilha;
        num = aux->info;
        *pilha = aux->next;
        free_node(aux);

        printf("\nRemovido!\n");
    }
    else
    {
        printf("\nErro! Pilha vazia.\n");
        num = -1;
    }

    return num;
}

int stacktop(CELULA *pilha)
{
    if(!empty(pilha))
        return pilha->info;
    return -1;
}

void show(CELULA *pilha)
{
    CELULA *aux;

    if(!empty(pilha))
    {
        aux = pilha;
        printf("\nPilha - [");
        while(aux != NULL)
        {
            printf("\t%d", aux->info);
            aux = aux->next;
        }
        printf("\t]\n");
    }
    else
        printf("\nPilha vazia, nada para exibir!\n");
}

int menu()
{
    int opcao;

    printf("----------MENU----------\n");
    printf("1. Inserir no pilha;\n");
    printf("2. Remover da pilha;\n");
    printf("3. Mostrar topo da pilha;\n");
    printf("4. Exibir elementos;\n");
    printf("0. Sair do programa.\n");
    printf("Selecione: ");
    scanf("%d", &opcao);

    return opcao;
}

void main()
{
    CELULA *pilha;
    int opcao, val;

    init(&pilha);

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
            push(&pilha, val);
            break;
        case 2:
            printf("\nRemovendo...");
            pop(&pilha);
            break;
        case 3:
            val = stacktop(pilha);
            if(val == -1)
                printf("\nErro! Pilha vazia.\n");
            else
                printf("\nTopo da pilha: %d\n", val);
            break;
        case 4:
            printf("\nApresentando...\n");
            show(pilha);
            break;
        default:
            printf("\nSelecione uma opcao valida!\n");
        }
    }
    while(opcao != 0);
}

