#include<stdio.h>
#include<string.h>
#define TAMF 20

typedef struct sPilha
{
    char vetor[TAMF];
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

int empilhar(Pilha *p, char valor)
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
        printf("Pilha vazia!\n\n");
        return -1;
    }

    return p->vetor[p->topo--];
}

void preencher_pilha(Pilha *p, char compara[])
{
    char valor;
    int i=0;

    printf("Insira uma palavra: ");
    do
    {
        scanf("%c", &valor);
        fflush(stdin);
        if(valor < 0)
            printf("Erro! Uso de numero na palavra!\n\n");
    }
    while(valor < 0);
    while(!pilha_cheia(p) && valor != 10)
    {
        empilhar(p, valor);
        compara[i++] = valor;

        scanf("%c", &valor);
        fflush(stdin);
    }
}

int comparar_letra(char a, char b)
{
    if(a >= 'A' && a <= 'Z')
        a+=32;
    if(b >= 'A' && b <= 'Z')
        b+=32;

    if(a==b)
        return 1;
    return 0;
}

int verificador(Pilha p, char compara[])
{
    int i=0, verifica;

    verifica = comparar_letra(desempilhar(&p), compara[i]);
    while(!pilha_vazia(&p) && verifica)
    {
        i++;
        verifica = comparar_letra(desempilhar(&p), compara[i]);
    }

    return verifica;
}

void main()
{
    Pilha p;
    char compara[TAMF];

    inicializar_pilha(&p);

    preencher_pilha(&p, compara);
    if(verificador(p, compara))
        printf("Eh um palindromo\n\n");
    else
        printf("Nao eh um palindromo\n\n");
}
