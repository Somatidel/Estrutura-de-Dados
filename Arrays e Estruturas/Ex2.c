#include<stdio.h>
#define TF 16
/**
2. Leia um vetor de 16 posições e troque os 8 primeiros valores pelos 8 últimos e vice-versa. Escreva ao final o vetor obtido.
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

void trocarVetores(int a[])
{
    int i, buffer, meio = TF/2;

    for(i=0; i<meio; i++)
    {
        buffer = a[i];
        a[i] = a[i+meio];
        a[i+meio] = buffer;
    }
}

void apresentarVetor(int vetor[])
{
    int i;

    printf("\nApresentando vetor final...");
    for(i=0; i<TF; i++)
        printf("\nVetor[%d]: %d.", i, vetor[i]);
}

void main()
{
    int vetor[TF];

    lerVetor(vetor);
    trocarVetores(vetor);
    apresentarVetor(vetor);

}
