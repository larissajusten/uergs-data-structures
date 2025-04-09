#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*2.	Fa�a um programa em C para cadastrar filmes de uma locadora, onde � necess�rio gravar/ler de arquivo:

b)	Ter um menu inicial perguntando se o usu�rio deseja ler ou gravar.
c)	Caso gravar: o usu�rio deve digitar os dados dos filmes at� que a digite �fim� para encerrar a digita��o
a.	cadastrar para cada filme: cod, nome_filme, g�nero
d)	Caso gravar: listar os livros cadastrados
e)	Utilize o modo de grava��o/leitura a partir do fim do arquivo.*/

int main()
{
    int menu, cod;
    char nome_filme[30];
    char genero[16];
    char a[10];
    char codi[10], nome[20], gen[15];
    FILE *fil;
    do
    {
        printf("[1]Ler. \n");
        printf("[2]Gravar. \n");
        printf("[0]Sair\n");
        printf("A: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            do
            {
                fil = fopen("filmes.txt", "at");
                printf("Digite o codigo do filme:");
                scanf("%d", &cod);
                fprintf(fil, "%d\t", cod);
                printf("Digite o nome do filme: ");
                fflush(stdin);
                gets(nome_filme);
                fprintf(fil, "%s\t", nome_filme);
                printf("Digite o genero do filme: ");
                gets(genero);
                fprintf(fil, "%s\n", genero);
                printf("Digite 'fim' para sair ou 's' para continuar: \n");
                gets(a);
            } while (strcmp("s", a) == 0);
            fclose(fil);
            break;
        case 2:
            fil = fopen("filmes.txt", "rt");
            while (!feof(fil))
            {
                fscanf(fil, "%s%s%s", &codi, &nome, &gen);
                if (!feof(fil))
                    printf("Codigo:%s Nome:%s Genero:%s\n", codi, nome, gen);
            }
            break;
        default:
            printf("Op invalida!");
        }
    } while (menu >= 1 && menu <= 2);
    /*a)Qual a finalidade de usar ponteiros?
    Poder mudar o valor da variavel original.
      b)Voc� usou ponteiros para criar este c�digo em C? Por qu�?
    N�o. Por que n�o precisei fazer grandes movimenta��es com as variaveis.
*/
}
