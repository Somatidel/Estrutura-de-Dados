#include<stdio.h>
#define TAMF 15

typedef struct sPilha
{
    int vetor[TAMF];
    int topo;
}Pilha;

void inicializar_pilha(Pilha *p)
{
    p->topo = -1;
}

int pilha_vazia(Pilha *p)
{
    if(p->topo == -1)
        return 1;
    return 0;
}

void empilhar(Pilha *p, int valor)
{
    p->topo+=1;
    p->vetor[p->topo] = valor;
}

int desempilhar(Pilha *p)
{
    if(pilha_vazia(p))
    {
        printf("Pilha esta vazia!\n\n");
        return -1;
    }
    else
        return p->vetor[p->topo--];
}

void diferenciar(Pilha *p, int valor)
{
    if(valor %2 == 0)
        empilhar(p, valor);
    else
        desempilhar(p);
}

void ler_pilha(Pilha *p)
{
    int i, valor;

    printf("Lendo pilha...\n");
    for(i=0; i<TAMF; i++)
    {
        printf("%do. valor: ", i+1);
        scanf("%d", &valor);
        diferenciar(p, valor);
    }
    printf("\n");
}


void exibir_pilha(Pilha p)
{
    while(!pilha_vazia(&p))
        printf("Elemento: %d\n", desempilhar(&p));
}

void main()
{
    Pilha p;

    inicializar_pilha(&p);

    ler_pilha(&p);
    exibir_pilha(p);
}
