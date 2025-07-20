#include<stdio.h>
#define TAMF 10

typedef struct sPilha
{
    int vetor[TAMF];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p)
{
    p->topo = -1;
}

int cheia(Pilha *p)
{
    if(p->topo+1 == TAMF)
        return 1;
    return 0;
}

int vazia(Pilha *p)
{
    if(p->topo == -1)
        return 1;
    return 0;
}

void empilhar(Pilha *p, int valor)
{
    if(cheia(p))
    {
        printf("Pilha cheia!\n\n");
        return;
    }

    p->topo++;
    p->vetor[p->topo] = valor;
}

int desempilhar(Pilha *p)
{
    if(vazia(p))
    {
        printf("Pilha vazia!\n\n");
        return -1;
    }

    return p->vetor[p->topo--];
}

void preencher_pilha(Pilha *p)
{
    int valor, i;

    printf("\nPreenchendo pilha...\n");
    for(i=0; i<TAMF; i++)
    {
        printf("%d: ", i);
        scanf("%d", &valor);
        empilhar(p, valor);
    }
}

void inverter_ordem(Pilha *p)
{
    int auxiliar[TAMF], i;

    if(!vazia(p))
    {
        for(i=0; i<TAMF; i++)
            auxiliar[i] = desempilhar(p);

        for(i=0; i<TAMF; i++)
            empilhar(p, auxiliar[i]);

        printf("Sucesso!\n\n");
    }
    else
        printf("Pilha vazia!\n\n");
}

void exibir(Pilha p)
{
    int i;

    printf("\n");
    if(!vazia(&p))
        for(i=0; i<TAMF; i++)
            printf("Elemento %d: %d\n", i, desempilhar(&p));
    else
        printf("Pilha vazia!\n\n");
}

int menu()
{
    int opcao;

    do
    {
        printf("1. Preencher pilha;\n");
        printf("2. Inverter ordem;\n");
        printf("3. Exibir pilha;\n");
        printf("0. Sair do programa.\n");
        printf("Selecione: ");
        scanf("%d", &opcao);
        if(opcao < 0 || opcao > 3)
            printf("Selecione uma opcao valida.\n\n");
    }
    while(opcao < 0 || opcao > 3);

    return opcao;
}

void main()
{
    Pilha P;
    int opcao;

    inicializar_pilha(&P);

    do
    {
        opcao = menu();

        switch(opcao)
        {
        case 0:
            printf("Fim do programa!\n");
            break;
        case 1:
            preencher_pilha(&P);
            break;
        case 2:
            inverter_ordem(&P);
            break;
        case 3:
            exibir(P);
            break;
        }
    }
    while(opcao != 0);
}
