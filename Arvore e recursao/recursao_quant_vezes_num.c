#include<stdio.h>
#include<stdlib.h>

int quant_digito(int n, int k)
{
    n = abs(n);
    return n == 0 ? 0 : (n%10 == k) + quant_digito(n/10, k);
}

void main()
{
    printf("\nQuantidade de ocorrencias do digito: %d.", quant_digito(-1242442, 2));
}
