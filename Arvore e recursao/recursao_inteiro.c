#include<stdio.h>

int soma_digito(int n)
{
    return n < 10 ? n : n%10 + soma_digito(n/10);
}

void main()
{
    char confirma;
    int num;

    do
    {
        printf("\nInforme um numero para somar os digitos: ");
        scanf("%d", &num);

        printf("\nResultado[%d] - %d.", num, soma_digito(num));
        printf("\n\nDeseja colocar outro numero? (S/N)\n");
        scanf(" %c", &confirma);
    }while(confirma != 'n' && confirma != 'N');
}
