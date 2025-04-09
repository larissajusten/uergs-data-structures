#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*3.
Uma string é considerada palíndromo se ela pode ser lida da esquerda para a direita ou da direita para a esquerda com o mesmo significado.
Neste caso, não podemos considerar as acentuações, as letras maiúsculas ou minúsculas, os espaços e os caracteres especiais.
A seguir, estão alguns exemplos:

    Ex1.: subi no onibus
    Ex2.: radar

Escreva um programa que determine se uma expressão é palíndroma ou não.
*/

typedef struct no
{
    char string;
    struct no *prox;
} Nodo;

void Push(Nodo **Base1, Nodo **Topo1, char plv);
void Palindroma(Nodo **Base1, Nodo **Topo1);
void Zerar(Nodo **Base1);
void Imprimir(Nodo **Base1);
Nodo *pop(Nodo **Base1);

int main()
{
    int j = 0, i = 0, op;
    char palavra[20], plv;
    Nodo *Topo1 = NULL;
    Nodo *Base1 = NULL; //----------------------Pilha

    do
    {
        printf("\n\t\t\tEscolha:\n\t{1}Escrever palavra\n\t{2}Palindroma\n\t{3}Imprimir\n\t{0}Sair\nOp:");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            Zerar(&Base1);
            break;
        case 1:
            printf("Digite uma palavra: ");
            fflush(stdin);
            gets(palavra);
            fflush(stdin);
            j = strlen(palavra);
            printf("Tamanho da palavra = %d", j);
            Zerar(&Base1);
            Base1 = NULL;
            Topo1 = NULL;
            i = 0;
            do
            {
                plv = palavra[i];
                Push(&Base1, &Topo1, plv);
                i++;
            } while (i != j);
            fflush(stdin);
            break;
            break;
        case 2:
            Palindroma(&Base1, &Topo1);
            break;
        case 3:
            printf("\n\t\t\t\tPilha:\n");
            Imprimir(&Base1);
            // printf("\n\n\t\t\t\tPilha[2]:\n");
            // Imprimir(&Base2);
            break;
        default:
            printf("Opcao invalida! Tente novamente.");
        }
    } while (op != 0);
}
void Push(Nodo **Base1, Nodo **Topo1, char palavra)
{
    Nodo *Aux, *Anterior;
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));

    if (novo)
    {
        novo->string = palavra;
        novo->prox = NULL;
    }
    else
    {
        printf("Memoria indisponivel!\n");
    }
    if (*Base1 == NULL)
    {
        *Base1 = novo;
        *Topo1 = *Base1;
    }
    else
    {
        Aux = *Topo1;
        Aux->prox = novo;
        *Topo1 = novo;
    }
}
void Palindroma(Nodo **Base1, Nodo **Topo1)
{
    Nodo *Atual, *Anterior, *Ultimo, *Primeiro;

    if (*Base1 == NULL)
    {
        printf("\n\tPilha VAZIA! Tente adicionar uma palavra primeiro.\n");
    }
    else if ((*Base1)->prox == NULL)
    {
        printf("\n\tA palavra e PALINDROMA.\n");
    }
    else
    {
        Primeiro = *Base1;
        Ultimo = *Topo1;
        Atual = *Base1;
        if (Primeiro->string != Ultimo->string)
        {
            printf("A palavra nao e PALINDROMA!");
        }
        else
        {
            while (Primeiro->string == Ultimo->string)
            {
                if (Primeiro != Ultimo)
                {
                    Primeiro = Primeiro->prox;
                    Atual = *Base1;
                    while (Atual != Ultimo)
                    {
                        Anterior = Atual;
                        Atual = Atual->prox;
                    }
                    Ultimo = Anterior;
                }
                else
                {
                    printf("A palavra e PALINDROMA!");
                    main();
                }
            }
        }
    }
}
void Zerar(Nodo **Base1)
{
    Nodo *Prox, *Atual;
    if (*Base1 != NULL)
    {
        Atual = *Base1;
        while (Atual != NULL)
        {
            Prox = Atual->prox;
            free(Atual);
            Atual = Prox;
        }
    }
}
void Imprimir(Nodo **Base1)
{
    Nodo *Aux;
    int i = 0;

    if (*Base1 == NULL)
    {
        printf("\tA pilha se encontra vazia!\n");
    }
    else
    {
        Aux = *Base1;
        while (Aux != NULL)
        {
            printf("\n\tAux[%d]->caracter = %c\tAux = %d\tAux->prox = %d", i, Aux->string, Aux, Aux->prox);
            Aux = Aux->prox;
            i++;
        }
    }
}
Nodo *pop(Nodo **Base1)
{
    Nodo *Ultimo, *Penultimo, *Tmp = NULL;

    if (*Base1 == NULL)
    {
        printf("A pilha esta vazia!\n\n");
        return NULL;
    }
    else
    {
        Ultimo = *Base1;
        while (Ultimo->prox != Tmp)
        {
            Ultimo = Ultimo->prox;
        }
        return Ultimo;
        Tmp = Ultimo;
    }
}

/*
            Tmp = pop(Base1);
            if(*Base2 == NULL){
                printf("3");
                *Base2 = Tmp;
                *Topo2 = *Base2;
            }else{
                printf("4");
                Aux = *Topo2;
                Aux->prox = Tmp;
                *Topo2 = Tmp;
                (*Topo2)->prox = NULL;
            }
        }
    }

*/
