#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
     int num;
     struct no *prox;
} Nodo;

int menu();
void opcao(Nodo *LISTAi, Nodo *LISTAf, int op);
void insereInicio(Nodo **LISTAi, int num);
void retiraFim(Nodo **LISTAi, Nodo **LISTAf);

int main()
{
     int op;
     Nodo *LISTAi = (Nodo *)malloc(sizeof(Nodo));
     Nodo *LISTAf = (Nodo *)malloc(sizeof(Nodo));

     if (!LISTAi)
     {
          printf("Espaco de memoria indisponivel.");
          if (!LISTAf)
          {
               printf("Espaco de memoria indisponivel. Tchau!");
          }
          else
          {
               op = 1; // Initialize op
               while (op != 0)
               {
                    op = menu();
                    opcao(&(*LISTAi), &(*LISTAf), op);
               }
          }
          return 0;
     }
}

int menu()
{
     printf("Menu: \n");
     printf(" [1]Inserir no fim. \n");
     printf(" [2]Retirar do fim \n");
     int op; // Declare op
     scanf("%d", &op);
     scanf("%d", &op);
     return op;
}

void opcao(Nodo *LISTAi, Nodo *LISTAf, int op)
{
     switch (op)
     {
     case 0:
          break;
     case 1:
          int num;
          printf("Digite o numero a ser inserido: ");
          scanf("%d", &num);
          insereFim(&LISTAi, &LISTAf, num);
          break;
     case 2:
          retiraFim(&LISTAi, &LISTAf);
          break;
     default:
          printf("Opcao invalida! Tente novamente.");
     }
     system("pause");
}

void insereFim(Nodo **LISTAi, Nodo **LISTAf, int num)
{
     Nodo *atual;
     Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
     if ((*LISTAi)->prox == NULL)
     {
          atual = (*LISTAi)->prox;
     }
     else
     {
          atual = (*LISTAi)->prox;
          while (atual->prox != NULL)
          {
               atual = atual->prox;
          }
          novo->num = num;
          atual->prox = novo;
          novo->prox = NULL;
          *LISTAf = novo;
     }
}
void retiraFim(Nodo **LISTAi, Nodo **LISTAf)
{
     if (*LISTAi == NULL || (*LISTAi)->prox == NULL)
     {
          printf("A sua Lista esta vazia!\n");
     }
     else
     {
          Nodo *atual = *LISTAi;
          Nodo *anterior = NULL;
          while (atual->prox != NULL)
          {
               anterior = atual;
               atual = atual->prox;
          }
          if (anterior != NULL)
          {
               anterior->prox = NULL;
          }
          else
          {
               *LISTAi = NULL;
          }
          *LISTAf = anterior;
          free(atual);
          printf("Elemento removido do fim.\n");
     }
}
