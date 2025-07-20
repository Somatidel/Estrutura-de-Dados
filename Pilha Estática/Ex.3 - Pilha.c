#include<stdio.h>
#define TAMF 10

typedef struct sPilha
{
    int vetor[TAMF];
    int topo;
}Pilha;

void inicializar_pilha(Pilha *p)
{
    p->topo = -1;
}

int pilha_cheia(Pilha *p)
{
    if(p->topo+1 == TAMF)
        return 1;
    return 0;
}

int pilha_vazia(Pilha *p)
{
    if(p->topo == -1)
        return 1;
    return 0;
}

int empilhar(Pilha *p, int valor)
{
    if(pilha_cheia(p))
    {
        printf("Pilha esta cheia!\n\n");
        return 1;
    }

    p->topo++;
    p->vetor[p->topo] = valor;

    return 0;
}

int desempilhar(Pilha *p)
{
    if(pilha_vazia(p))
    {
        printf("Pilha esta vazia!\n\n");
        return -1;
    }

    return p->vetor[p->topo--];
}

void preencher_pilha(Pilha *p, Pilha *s)
{
    int valor, verifica;

    do
    {
        printf("Insira um valor: ");
        scanf("%d", &valor);
        if(valor == -1)
            printf("Coloque pelo menos um valor valido...\n\n");
    }
    while(valor == -1);
    while(!verifica && valor != -1)
    {
        if(valor > 0)
            verifica = empilhar(p, valor);
        else if(valor < 0)
            verifica = empilhar(s, valor);
        else
        {
            desempilhar(p);
            desempilhar(s);
        }

        if(!verifica)
        {
            printf("Insira um valor: ");
            scanf("%d", &valor);
        }
        if(verifica || valor == -1)
            printf("Fim de leitura!\n\n");
    }
}

void exibir_pilha(Pilha p)
{
    while(!pilha_vazia(&p))
        printf("Elemento: %d\n", desempilhar(&p));
}

void main()
{
    Pilha N, P;

    inicializar_pilha(&P);
    inicializar_pilha(&N);

    preencher_pilha(&P, &N);

    printf("Pilha P\n");
    exibir_pilha(P);

    printf("\nPilha N\n");
    exibir_pilha(N);
}
