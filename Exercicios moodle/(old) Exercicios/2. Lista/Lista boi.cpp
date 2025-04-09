#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int cod;
    float peso;
    struct nodo *prox;
};
int main()
{
    struct nodo *fim = NULL;
    struct nodo *inicio = NULL;
    struct nodo *boi;
    int continua = 1;
    boi = NULL;
    while (continua == 1)
    {
        boi = (struct nodo *)malloc(sizeof(struct nodo));
        if (boi)
        {
            printf("Digite o codigo do boi: ");
            scanf("%d", &boi->cod);
            printf("Digite o peso do boi: ");
            scanf("%f", &boi->peso);
            boi->prox = NULL;
            if (inicio == NULL)
            {
                nodo *fim = boi;
                nodo *incio = boi;
            }
            else
            {
                fim->prox = boi;
                fim = boi;
            }
            printf("Deseja continuar(1): ");
            scanf("%d", &continua);
        }
    }
    printf("%d", fim->cod);
    // imprimir a lista.
    if (inicio == NULL)
    {
        printf("lista vazia");
    }
    else
    {
        boi = inicio;
        while (boi != NULL)
        {
            printf("codigo=%d", boi->cod);
            printf("peso=%f", boi->peso);
            boi = boi->prox;
        }
    }
}
