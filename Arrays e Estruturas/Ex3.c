#include<stdio.h>
#define TF 10
/**
3. Leia um vetor de 10 posições e em seguida um valor X qualquer. Seu programa deverá
fazer uma busca do valor de X no vetor lido e informar a posição em que foi encontrado
ou se não foi encontrado.
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
    printf("\nDigite um valor para pesquisar: ");
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

void exibirPesquisa(int posicao)
{
    if(posicao == -1)
        printf("\nValor nao foi encontrado...\n");
    else
        printf("\nValor foi encontrado na posicao %d do vetor!\n", posicao);
}

void main()
{
    int vetor_num[TF],
        valor,
        pos;

    lerVetor(vetor_num);
    valor = lerValor(valor);
    pos = pesquisarValor(valor, vetor_num);
    exibirPesquisa(pos);
}


