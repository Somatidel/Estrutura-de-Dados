#include<stdio.h>
#define TAMF 10

typedef struct sDeque
{
    int vetor[TAMF];
    int inicio, fim;
} Deque;

void inicializar_deque(Deque *d)
{
    d->inicio = TAMF - 1;
    d->fim = TAMF - 1;
}

int vazia(Deque *d)
{
    if(d->inicio == d->fim)
        return 1;
    return 0;
}

int cheia(Deque *d)
{
    if((d->fim+1)%TAMF == d->inicio)
        return 1;
    return 0;
}

void inserir_inicio(Deque *d, int valor)
{
    if(d->inicio == 0)
        d->inicio = TAMF - 1;
    else
        d->inicio--;
    if(vazia(d))
    {
        printf("Deque cheio!\n\n");
        d->inicio = (d->inicio+1)%TAMF;
    }
    else
        d->vetor[(d->inicio+1)%TAMF] = valor;
}

void inserir_fim(Deque *d, int valor)
{
    d->fim = (d->fim+1)%TAMF;

    if(vazia(d))
    {
	printf("Deque cheio!\n\n");
	d->fim--;
	if(d->fim == -1)
	   d->fim = TAMF - 1;
    }
    else
	d->vetor[d->fim] = valor;
}

int remover_inicio(Deque *d)
{
    if(!vazia(d))
    {
        d->inicio = (d->inicio+1)%TAMF;
        return d->vetor[d->inicio];
    }

    printf("Deque vazio!\n\n");
    return -1;
}

int remover_fim(Deque *d)
{
    if(!vazia(d))
    {
        d->fim--
	if(d->fim == -1)
	   d->fim = TAMF - 1;
        return d->vetor[(d->fim+1)%TAMF];
    }

    printf("Deque vazio!\n\n");
    return -1;
}

void impressao_nao_classica(Deque *d)
{
    int i;

    if(!vazia(d))
    {
        i=(d->inicio+1)%TAMF;
        while(i!=(d->fim+1)%TAMF)
        {
            printf("Elemento: %d\n", d->vetor[i]);
            i = (i+1)%TAMF;
        }
    }
    else
        printf("Nada para imprimir!\n\n");
}

void impressao_classica(Deque d)
{
    if(!vazia(&d))
        while(!vazia(&d))
            printf("Elemento: %d\n", remover_inicio(&d));
    else
        printf("Nada para imprimir!\n\n");
}


char menu()
{
    char opcao;

    printf("A. Inserir um elemento no inicio do deque;\n");
    printf("B. Inserir um elemento no fim do deque;\n");
    printf("C. Remover um elemento no inicio do deque;\n");
    printf("D. Remover um elemento no fim do deque;\n");
    printf("E. Impressao nao classica;\n");
    printf("F. Impressao classica;\n");
    printf("X. Sair do programa.\n");
    printf("Selecione: ");
    scanf(" %c", &opcao);
    printf("\n");

    return opcao;
}

char upper(char a)
{
    if(a >= 'A' && a <= 'Z')
        return a;
    return a-=32;
}

void main()
{
    Deque d;
    char opcao;
    int valor;

    inicializar_deque(&d);

    do
    {
        opcao = menu();
        opcao = upper(opcao);

        switch(opcao)
        {
        case 'X':
            printf("\nFim de programa.\n");
            break;
        case 'A':
            printf("\nInsira um valor para incluir: ");
            scanf("%d", &valor);
            inserir_inicio(&d, valor);
            break;
        case 'B':
            printf("\nInsira um valor para incluir: ");
            scanf("%d", &valor);
            inserir_fim(&d, valor);
            break;
        case 'C':
            remover_inicio(&d);
            break;
        case 'D':
            remover_fim(&d);
            break;
        case 'E':
            impressao_nao_classica(&d);
            break;
        case 'F':
            impressao_classica(d);
            break;
        default:
            printf("Selecione uma opcao valida.\n\n");
        }
    }
    while(opcao != 'X');
}
