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
    if((f->fim+1) % TAMF == f->inicio)
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

        printf("Informe um valor: ");
        scanf("%d", &valor);
    }
}

int maior_elemento(Fila f)
{
    int maior, auxiliar;

    maior = dequeue(&f);
    while(!vazia(&f))
    {
        auxiliar = dequeue(&f);
        if(auxiliar > maior)
            maior = auxiliar;
    }

    return maior;
}

int menor_elemento(Fila f)
{
    int menor, auxiliar;

    menor = dequeue(&f);
    while(!vazia(&f))
    {
        auxiliar = dequeue(&f);
        if(auxiliar < menor)
            menor = auxiliar;
    }

    return menor;
}

int comprimento(Fila *f)
{
    return (f->fim - f->inicio+TF)%TAMF;
}

int somador(Fila f)
{
    int soma=0;

    while(!vazia(&f))
        soma += dequeue(&f);

    return soma;
}

float media_aritmetica(Fila *f)
{
    return ((float)somador(*f))/comprimento(f);
}

void main()
{
    Fila f;

    inicializar_fila(&f);

    preencher_fila(&f);

    printf("\nMaior elemento: %d\n", maior_elemento(f));
    printf("Menor elemento: %d\n", menor_elemento(f));
    printf("Media aritmetica: %.2f\n", media_aritmetica(&f));
}
