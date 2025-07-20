#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct sNo
{
    int info;
    struct sNo* esq;
    struct sNo* dir;
}NO;

typedef struct sArvore
{
    NO* raiz;
}ARVORE;

void init(NO** raiz)
{
    *raiz = NULL;
}

NO* maior_esquerda(NO* raiz)
{
    if(raiz->esq != NULL)
        return maior_esquerda(raiz->esq);
    return raiz;
}

NO* maior_direita(NO* raiz)
{
    if(raiz->dir != NULL)
        return maior_direita(raiz->dir);
    return raiz;
}

void inserir(NO** raiz, int x)
{
    NO* novo;

    if(*raiz == NULL)
    {
        novo = (NO*)malloc(sizeof(NO));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->info = x;
        *raiz = novo;
    }
    else if((*raiz)->info > x)
        inserir(&(*raiz)->esq, x);
    else
        inserir(&(*raiz)->dir, x);
}

void remover(NO** raiz, int x)
{
    NO* aux;

    if(*raiz == NULL)
        printf("\nValor não existe!\n");
    else if((*raiz)->info > x)
        remover(&(*raiz)->esq, x);
    else if((*raiz)->info < x)
        remover(&(*raiz)->dir, x);
    else
    {
        aux = *raiz;

        if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        {
            free(*raiz);
            *raiz = NULL;
        }
        else if((*raiz)->esq == NULL)
        {
            *raiz = (*raiz)->dir;
            aux->dir = NULL;
            free(aux);
        }
        else if((*raiz)->dir == NULL)
        {
            *raiz = (*raiz)->esq;
            aux->esq = NULL;
            free(aux);
        }
        else
        {
            aux = maior_direita(*raiz);
            aux->esq = (*raiz)->esq;
            aux->dir = (*raiz)->dir;
            free(*raiz);
            *raiz = aux;
        }
    }
}

void em_ordem(NO* raiz){
    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf("|%d|", raiz->info);
        em_ordem(raiz->dir);
    }
}

void pre_ordem(NO* raiz){
    if(raiz != NULL){
        printf("|%d|", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(NO* raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("|%d|", raiz->info);
    }
}

void main()
{
    NO* n;
    int op, num;

    setlocale(LC_ALL, "");

    init(&n);

    do
    {

        printf("\n<Menu>\n");
        printf("\n1 - Inserir um valor.");
        printf("\n2 - Apresentar em Pós-Ordem.");
        printf("\n3 - Apresentar em Ordem.");
        printf("\n4 - Apresentar em Pré-Ordem.");
        printf("\n5 - Remover um valor.");
        printf("\n0 - Encerrar Programa.");
        printf("\n\nSelecione uma das opções: ");
        scanf("%d",&op);

        switch(op)
        {

        case 1:
            printf("\nInsira o número que deseja: ");
            scanf("%d",&num);
            inserir(&n,num);
            break;
        case 2:
            pos_ordem(n);
            break;
        case 3:
            em_ordem(n);
            break;
        case 4:
            pre_ordem(n);
            break;
        case 5:
            printf("\nInsira o número que deseja remover:");
            scanf("%d",&num);
            remover(&n,num);
            em_ordem(n);
            break;
        case 0:
            printf("\nFim do Programa.\n");
            break;
        default:
            printf("\nComando Inválido.\n");
            break;

        }
    }
    while(op!=0);

}
