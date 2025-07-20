#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct sNo
{
    int info;
    struct sNo *esq;
    struct sNo *dir;
} NO;

void init(NO** raiz)
{
    *raiz = NULL;
}

NO* maior_direita(NO* raiz)
{
    if(raiz->dir != NULL)
        return maior_direita(raiz->dir);
    return raiz;
}

void inserir(NO** raiz, int val)
{
    NO* novo;

    if(*raiz == NULL)
    {
        novo = (NO*)malloc(sizeof(NO));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->info = val;
        *raiz = novo;
    }
    else if((*raiz)->info < val)
        inserir(&((*raiz)->dir), val);
    else
        inserir(&((*raiz)->esq), val);
}

NO* pesquisar(NO* raiz, int val)
{
    NO* aux;
    aux = raiz;
    if(raiz == NULL)
        return NULL;
    else if(raiz->info < val)
        return pesquisar(raiz->dir, val);
    else if(raiz->info > val)
        return pesquisar(raiz->esq, val);
    else
        return aux;
}

void remover(NO** raiz, int val)
{
    if(*raiz == NULL)
        printf("\nValor, não existe!\n");
    else if((*raiz)->info < val)
        remover(&((*raiz)->dir), val);
    else if((*raiz)->info > val)
        remover(&((*raiz)->esq), val);
    else
    {
        NO* aux;

        aux = *raiz;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        {
            free(*raiz);
            *raiz = NULL;
        }
        else if((*raiz)->esq == NULL)
        {
            *raiz = (*raiz)->dir;
            free(aux);
        }
        else if((*raiz)->dir == NULL)
        {
            *raiz = (*raiz)->esq;
            free(aux);
        }
        else
        {
            aux = maior_direita((*raiz)->esq);
            (*raiz)->info = aux->info;
            remover(&((*raiz)->esq), aux->info);
        }
    }
}

int calcular_nos(NO* raiz)
{
    return (raiz != NULL) ? 1 + calcular_nos(raiz->esq) + calcular_nos(raiz->dir): 0;
}

int calcular_folhas(NO* raiz)
{
    if(raiz != NULL)
    {
        if(raiz->esq == NULL && raiz->dir == NULL)
            return 1;
        return calcular_folhas(raiz->esq) + calcular_folhas(raiz->dir);
    }

    return 0;
}

int calcular_altura(NO* raiz)
{
    int esquerda, direita;

    if(raiz != NULL)
    {
        esquerda = calcular_altura(raiz->esq);
        direita = calcular_altura(raiz->dir);
        return esquerda > direita ? esquerda + 1 : direita + 1;
    }
    return 0;
}

void pre_ordem(NO* raiz)
{
    if(raiz != NULL)
    {
        printf("|%d| ", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void em_ordem(NO* raiz)
{
    if(raiz != NULL)
    {
        em_ordem(raiz->esq);
        printf("|%d| ", raiz->info);
        em_ordem(raiz->dir);
    }
}

void percurso_em_ordem_morris(NO* raiz)
{
    NO* atual = raiz;
    while (atual != NULL)
    {
        if (atual->esq == NULL)
        {
            printf("|%d| ", atual->info);
            atual = atual->dir;
        }
        else
        {
            NO* pre = atual->esq;
            while (pre->dir != NULL && pre->dir != atual)
                pre = pre->dir;

            if (pre->dir == NULL)
            {
                pre->dir = atual;
                atual = atual->esq;
            }
            else
            {
                pre->dir = NULL;
                printf("|%d| ", atual->info);
                atual = atual->dir;
            }
        }
    }
}

void pos_ordem(NO* raiz)
{
    if(raiz != NULL)
    {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("|%d| ", raiz->info);
    }
}

void main()
{
    NO* raiz;

    setlocale(LC_ALL, "");

    init(&raiz);

    inserir(&raiz, 1);
    inserir(&raiz, 18);
    inserir(&raiz, 3);
    inserir(&raiz, 9);
    inserir(&raiz, 0);
    inserir(&raiz, 5);
    inserir(&raiz, 19);

    remover(&raiz, 18);

    printf("\nQuantidade de nós: %d\n", calcular_nos(raiz));
    printf("\nQuantidade de folhas: %d\n", calcular_folhas(raiz));
    printf("\nAltura da árvore: %d\n", calcular_altura(raiz));

    printf("\nPré-ordem: ");
    pre_ordem(raiz);
    printf("\nEm-ordem: ");
    em_ordem(raiz);
    printf("\nEm-ordem (Morris): ");
    percurso_em_ordem_morris(raiz);
    printf("\nPós-ordem: ");
    pos_ordem(raiz);
}
