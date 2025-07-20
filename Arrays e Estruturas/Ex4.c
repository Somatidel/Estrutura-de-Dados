#include<stdio.h>
#define TF 10

/**
4. Leia um vetor de 10 posições e em seguida um valor X qualquer. Seu programa deverá
fazer uma busca do valor de X no vetor lido. Caso encontre o valor deverá ser removido
do vetor
**/

void lerVetor(int vet[])
{
    int i;

    printf("Fazendo a leitura do vetor...\n");

    for(i=0; i<TF; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vet[i]);
    }
}

int lerValor(int x)
{
    printf("\nDigite um valor para excluir: ");
    scanf("%d", &x);

    return x;
}

int pesquisarValor(int a, int vetor[])
{
    int i=0;

    while((i < TF) && (vetor[i]!= a))
        i++;

    if(i == TF)
        return -1;
    else
        return i;
}

int removerValor(int vetor[], int pos, int tl)
{
    int i;

    printf("\nRemovendo valor do vetor...\n");

    if(pos != -1)
    {
        for(i=pos; i<tl; i++)
            vetor[i] = vetor[i+1];
        tl--;
    }
    else
        printf("\nValor nao encontrado :(\n");

    return tl;
}

void apresentarVetor(int vetor[], int tl)
{
    int i;

    printf("\nApresentando vetor final...");
    for(i=0; i<tl; i++)
        printf("\nVetor[%d]: %d.", i, vetor[i]);
}

void main()
{
    int valor, vetor[TF], posicao, tl=TF;

    lerVetor(vetor);

    //antes de remover
    apresentarVetor(vetor, tl);

    valor = lerValor(valor);
    posicao = pesquisarValor(valor, vetor);
    tl = removerValor(vetor, posicao, tl);

    //depois de remover
    apresentarVetor(vetor, tl);
}
