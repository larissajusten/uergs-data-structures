#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *prox;
} no;

void InserirLista(no *LISTA);

int main()
{
    int op;
    no *Aux = NULL;
    no *Aux1 = NULL;
    no *Aux2 = NULL;
    no *Aux3 = NULL;
    no *LISTA = (no *)malloc(sizeof(no));
    if (!LISTA)
    {
        printf("Nao ha espaco de memoria disponivel!");
        exit(1);
    }
    else
    {
        LISTA->num = NULL;
        do
        {
            printf("[1]Inserir no fim da lista.\n");
            printf("[2]Imprimir lista.\n");
            printf("[0]Sair.\n");
            printf("A: ");
            scanf("%d", &op);
            fflush(stdin);
            switch (op)
            {
            case 0:
                Aux = LISTA->prox;
                free(LISTA);
                while (Aux != NULL)
                {
                    Aux1 = Aux->prox;
                    free(Aux);
                    Aux = Aux1;
                    free(Aux1);
                }
                free(Aux);
                printf("A lista esta vazia!");
                break;
            case 1:
                if (LISTA->num == NULL)
                {
                    printf("Digite o numero: ");
                    scanf("%d", &LISTA->num);
                    LISTA->prox = NULL;
                }
                else
                {
                    InserirLista(LISTA);
                }
                break;
            case 2:
                if (LISTA->num == NULL)
                {
                    printf("A lista esta vazia!");
                }
                else
                {
                    if (LISTA->prox == NULL)
                    {
                        printf("Num: %d Endereco: %d End proximo: %d\n", LISTA->num, LISTA, LISTA->prox);
                    }
                    else
                    {
                        printf("Num: %d End proximo:: %d End: %d\n", LISTA->num, LISTA->prox, LISTA);
                        Aux3 = LISTA->prox;
                        while (Aux3->prox != NULL)
                        {
                            printf("Num: %d End proximo: %d End: %d\n", Aux3->num, Aux3->prox, Aux3);
                            Aux3 = Aux3->prox;
                        }
                        printf("Num: %d End proximo: %d End: %d\n", Aux3->num, Aux3->prox, Aux3);
                    }
                }
                break;
            default:
                printf("Op invalida!");
            }
        } while (op >= 1 && op <= 2);
    }
}

void InserirLista(no *LISTA)
{
    no *aux;
    no *novo = (no *)malloc(sizeof(no));
    printf("Digite o numero: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    if (LISTA->prox != NULL)
    {
        aux = LISTA->prox;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    else
    {
        LISTA->prox = novo;
    }
}
