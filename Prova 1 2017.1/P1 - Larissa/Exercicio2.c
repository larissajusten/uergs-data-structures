#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int vetor[10];
int a;

int menu();
void opcoes(int op);
FILE *impar;
FILE *par;

int main()
{
    int op;

    do
    {
        op = menu();
        opcoes(op);
    } while (op > 0 && op <= 3);
}

int menu()
{
    int menu;
    printf("[1]Gravar numeros.\n");
    printf("[2]Ler os numeros pares.\n");
    printf("[3]Ler os numeros impares.\n");
    printf("[0]Sair.\n");
    printf("A: ");
    scanf("%d", &menu);
    return menu;
}

void opcoes(int op)
{
    int pars, impars, vetori;
    int pares, impares;
    switch (op)
    {
    case 0:
        exit(1);
        break;
    case 1:
        for (a = 0; a < 10; a++)
        {
            printf("Digite um numero: ");
            scanf("%d", &vetor[a]);
        }
        for (a = 0; a < 10; a++)
        {
            vetori = vetor[a];
            if (vetori % 2 == 0)
            {
                pars = vetor[a];
                FILE *par = fopen("pares.txt", "at");
                fprintf(par, "%d", pars);
                fclose(par);
            }
            else
            {
                impars = vetor[a];
                FILE *impar = fopen("impares.txt", "at");
                fprintf(impar, "%d", impars);
                fclose(impar);
            }
        }
        printf("\n");
        break;
    case 2:
        par = fopen("pares.txt", "rt");
        while (!feof(par))
        {
            if (!feof(par))
                fscanf(par, "%d", &pares);
            if (!feof(par))
                printf("Par:%d\n", pares);
        }
        fclose(par);
        printf("\n");
        break;
    case 3:
        impar = fopen("impares.txt", "rt");
        while (!feof(impar))
        {
            if (!feof(impar))
                fscanf(impar, "%d", &impares);
            if (!feof(impar))
                printf("Impar:%d\n", impares);
        }
        fclose(impar);
        printf("\n");
        break;
    default:
        printf("Op invalida!");
    }
}
