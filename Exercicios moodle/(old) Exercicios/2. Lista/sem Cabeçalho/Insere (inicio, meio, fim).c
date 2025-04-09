#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int valor;
	struct nodo *prox;
} lista;

void insereinicio(lista **inicio, lista **novo)
{
	(*novo)->prox = *inicio;
	*inicio = (*novo);
}

void inseremeio(lista **primeiro, lista **meio, lista **atual)
{
	lista *auxp = *primeiro;
	int aux = 1;
	while (aux == 1)
	{
		if ((*meio)->valor != (*auxp).valor)
		{
			*auxp = *auxp->prox;
		}
		else
		{
			(*atual)->prox = (*auxp).prox;
			(*auxp).prox = *atual;
			aux = 0;
		}
	}
}

void inserefim(lista **ultimo, lista **p)
{
	(*ultimo)->prox = *p;
	(*p)->prox = NULL;
	*ultimo = *p;
}

main()
{
	lista *P, *meio = NULL, *inicio = NULL, *ultimo = NULL;
	int num, aux = 0;
	int i = 1, e = 1;
	while (i != 0)
	{
		P = (lista *)malloc(sizeof(lista));
		if (P)
		{
			// Primeira vez
			if (inicio == NULL)
			{
				printf("Digite um VALOR para inserir: ");
				scanf("%d", &P->valor);
				ultimo = P;
				inicio = P;
				inicio->prox = NULL;
			}
			else
			{
				// Restante das vezes
				printf(" [1] Para inserir no incio \n [2] Para inserir no meio \n [3] Para inserir no fim \n [0]Sair \n ESCOLHA: ");
				scanf("%d", &i);
				if (i != 0)
				{
					printf("Digite um VALOR para inserir: ");
					scanf("%d", &P->valor);
				}
				switch (i)
				{
				case 1:
					insereinicio(&inicio, &P);
					break;
				case 2:
					printf("Digite depois de qual valor deseja inserir: ");
					meio = (lista *)malloc(sizeof(lista));
					scanf("%d", &meio->valor);
					inseremeio(&inicio, &meio, &P);
					break;
				case 3:
					inserefim(&ultimo, &P);
					break;
				default:
					break;
				}
			}
		}
	}
	printf("\n");

	// Imprimir lista
	if (inicio == NULL)
	{
		printf("lista vazia");
	}
	else
	{
		lista *estruturaaux;
		estruturaaux = inicio;
		while (estruturaaux != NULL)
		{
			printf("valor [%d] \n", estruturaaux->valor);
			estruturaaux = estruturaaux->prox;
		}
	}
}
