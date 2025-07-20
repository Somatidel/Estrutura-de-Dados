#include<stdio.h>
#define TF 12
/**
1. Fa�a um programa para ler um vetor de 12 posi��es e em seguida ler tamb�m dois
valores X e Y quaisquer correspondentes a duas posi��es no vetor. Ao final seu programa
dever� escrever a soma dos valores encontrados nas respectivas posi��es X e Y.
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

int somarValores(int a, int b)
{
    int soma=0;

    soma = a + b;

    return soma;
}

int pegarPosicao(int x, int *y)
{
    do
    {
        printf("\nInforme a posicao X e posicao Y, respectivamente: ");
        scanf("%d %d", &x, y);
        if(x < 0 || x > 11 || *y < 0 || *y > 11)
            printf("\nSelecione uma posicao valida!\n");

    }while(x < 0 || x > 11 || *y < 0 || *y > 11);

    return x;
}

void apresentarSoma(int soma)
{
    printf("\nO valor da soma das posicoes eh: %d\n", soma);
}

void main()
{
    int x, y,
        vetor[TF],
        somatorio;

    lerVetor(vetor);
    x = pegarPosicao(x, &y);
    somatorio = somarValores(vetor[x], vetor[y]);
    apresentarSoma(somatorio);
}
