#include<stdio.h>
#define TAMF 10

typedef struct sFila
{
    int vetor[TAMF];
    int inicio, fim;
} Fila;

void inicializar_fila(Fila *f)
{
    f->inicio = TAMF - 1;
    f->fim = TAMF - 1;
}

int vazia(Fila *f)
{
    if(f->inicio == f->fim)
        return 1;
    return 0;
}

int cheia(Fila *f)
{
    if((f->fim + 1)%TAMF == f->inicio)
        return 1;
    return 0;
}

void queue(Fila *f, int valor)
{
    if(cheia(f))
        printf("Fila cheia!\n\n");
    else
    {
        f->fim = (f->fim+1) % TAMF;
        f->vetor[f->fim] = valor;
    }
}

int dequeue(Fila *f)
{
    if(!vazia(f))
    {
        f->inicio = (f->inicio+1) % TAMF;
        return f->vetor[f->inicio];
    }

    printf("Fila vazia!\n\n");
    return -1;
}

void preencher_fila(Fila *f)
{
    int valor;

    printf("Inserindo valores... (-1 para sair)\n");
    do
    {
        printf("Informe um valor: ");
        scanf("%d", &valor);
        if(valor == -1)
            printf("Insira pelo menos um valor valido!\n\n");
    }
    while(valor == -1);
    while(!cheia(f) && valor != -1)
    {
        queue(f, valor);

        if(!cheia(f))
        {
            printf("Informe um valor: ");
            scanf("%d", &valor);
        }

        if(cheia(f))
            printf("Fila cheia!\n");
    }
}

int comprimento(Fila f)
{
    int contador=0;

    while(!vazia(&f))
    {
        dequeue(&f);
        contador++;
    }

    return contador;
}

void main()
{
    Fila f;

    inicializar_fila(&f);

    preencher_fila(&f);
    printf("\nExistem %d elemento(s).\n", comprimento(f));
}
