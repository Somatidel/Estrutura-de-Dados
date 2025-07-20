#include<stdio.h>
#include<string.h>
#define TAMF 50

typedef struct sMusica
{
    char nome[TAMF], genero[TAMF];
} Musica;

typedef struct sFila
{
    Musica vetor[TAMF];
    int inicio, fim;
} Fila;

void inicializar_fila(Fila *f)
{
    f->inicio = TAMF - 1;
    f->fim = TAMF - 1;
}

int vazia(Fila *f)
{
    if(f->inicio == f->fim)
        return 1;
    return 0;
}

int cheia(Fila *f)
{
    if((f->fim+1) % TAMF == f->inicio)
        return 1;
    return 0;
}

void queue(Fila *f, Musica a)
{
    if(cheia(f))
        printf("Fila cheia!\n\n");
    else
    {
        f->fim = (f->fim+1) % TAMF;
        strcpy(f->vetor[f->fim].nome, a.nome);
        strcpy(f->vetor[f->fim].genero, a.genero);
    }
}

void dequeue(Fila *f)
{
    if(!vazia(f))
        f->inicio = (f->inicio+1) % TAMF;
    else
        printf("Fila vazia!\n\n");
}

void remover_linha(char texto[])
{
    if(texto[strlen(texto)-1] == '\n')
        texto[strlen(texto)-1] = '\0';
}

void preencher_fila(Fila *f)
{
    char nome[TAMF], genero[TAMF],
         opcao;

    Musica a;

    printf("\nPreenchendo... (-1 para sair)\n");
    do
    {
        fflush(stdin);
        printf("\nInforme o nome da musica: ");
        fgets(a.nome, 49, stdin);
        fflush(stdin);

        printf("Informe o genero musical: ");
        fgets(a.genero, 49, stdin);
        fflush(stdin);

        remover_linha(a.nome);
        remover_linha(a.genero);

        queue(f, a);

        if(!cheia(f))
        {
            printf("\nDeseja incluir novamente?\n");
            scanf("%c", &opcao);
            fflush(stdin);
        }
    }
    while(!cheia(f) && (opcao == 's' || opcao == 'S'));
}

void exibir_catalogo(Fila f)
{
    int i=0;

    if(!vazia(&f))
    {
        while(!vazia(&f))
        {
            printf("\n[%d] - Nome: %s; Genero: %s", i+1, f.vetor[(f.inicio+1)%TAMF].nome,
                    f.vetor[(f.inicio+1)%TAMF].genero);
            dequeue(&f);
            i++;
        }
        printf("\n");
    }
    else
        printf("Catalogo vazio!\n\n");
}

int menu()
{
    int opcao;

    printf("1. Preencher pasta;\n");
    printf("2. Retirar letra;\n");
    printf("3. Exibir catalogo;\n");
    printf("0. Sair do programa.\n");
    printf("Selecione: ");
    scanf("%d", &opcao);

    return opcao;
}

void main()
{
    Fila f;
    int opcao;

    inicializar_fila(&f);

    do
    {
        opcao = menu();

        switch(opcao)
        {
        case 0:
            printf("\nFim de programa.\n");
            break;
        case 1:
            preencher_fila(&f);
            break;
        case 2:
            dequeue(&f);
            break;
        case 3:
            exibir_catalogo(f);
            break;
        default:
            printf("Selecione uma opcao valida.\n\n");
        }
    }
    while(opcao != 0);
}
