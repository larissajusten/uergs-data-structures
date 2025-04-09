#include <stdlib.h>
#include <stdio.h>

/*2.	Para o mesmo algoritmo anterior, al�m de considerar o nome do documento � usu�rio, acrescente o numero de privil�gio.
Caso o privil�gio for:
-> 1, o documento dever� ser o primeiro a ir para a fila de impress�o.
-> 2, a fila poder� ter seu fluxo normalmente.
*/

typedef struct no
{
	int usuario;
	char nome_doc[50];
	int num_previlegio;
	struct no *prox;
} Nodo;

void InserirInicio(Nodo **inicio, int prev);
void InserirFim(Nodo **inicio, Nodo **fim, int prev);
void Imprimir(Nodo **inicio);

main()
{
	int op, prev;
	Nodo *inicio = NULL;
	Nodo *fim = NULL;
	do
	{
		printf("\n\tFILA DE IMPRESSAO DE DOCUMENTOS\n");
		printf(" [1] Inserir\n");
		printf(" [2] Imprimir\n");
		printf(" [0] Sair\n");
		printf("Escolha: ");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			system("cls");
			printf("\n[1] COM Previlegio \n[2] SEM Previlegio\n Escolha: ");
			scanf("%d", &prev);
			if (prev == 1)
			{
				InserirInicio(&inicio, prev);
			}
			else if (prev == 2)
			{
				InserirFim(&inicio, &fim, prev);
			}
			break;
		case 2:
			Imprimir(&inicio);
			break;
		case 0:
			return 0;
			break;
		default:
			printf("Op invalida!");
			break;
		}
	} while (op != 0);
}
void InserirInicio(Nodo **inicio, int prev)
{
	Nodo *Aux, *Aux2;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	if (novo)
	{
		printf("\t INSERIR COM PREVILEGIO");
		printf("\nDigite o usuario (apenas numeros): ");
		scanf("%d", &novo->usuario);
		fflush(stdin);
		printf("Digite o nome do documento: ");
		scanf("%s", &novo->nome_doc);
		novo->prox = NULL;
		novo->num_previlegio = prev;

		Aux = *inicio;
		novo->prox = Aux;
		*inicio = novo;
	}
	else
	{
		printf("Memoria indisponivel!");
	}
}

void InserirFim(Nodo **inicio, Nodo **fim, int prev)
{
	Nodo *Aux;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	if (novo)
	{
		printf("\t INSERIR SEM PREVILEGIO");
		printf("\nDigite o usuario (apenas numeros): ");
		scanf("%d", &novo->usuario);
		fflush(stdin);
		printf("Digite o nome do documento: ");
		scanf("%s", &novo->nome_doc);
		novo->prox = NULL;
	}
	else
	{
		printf("Espaco de memoria indisponivel!");
	}

	if (*inicio == NULL)
	{
		*inicio = novo;
		*fim = *inicio;
	}
	else
	{
		if ((*inicio)->prox == NULL)
		{
			(*inicio)->prox = novo;
			*fim = novo;
		}
		else
		{
			Aux = *inicio;
			while (Aux->prox != NULL)
			{
				Aux = Aux->prox;
			}
			Aux->prox = novo;
			*fim = Aux->prox;
		}
	}
}

void Imprimir(Nodo **inicio)
{
	Nodo *Aux;
	if (*inicio != NULL)
	{
		Aux = *inicio;
		while (Aux != NULL)
		{
			printf("\nUsuario: %d \nNome do Documento: %s \nNodo: %d \nNodo->prox: %d\n\n", Aux->usuario, Aux->nome_doc, Aux, Aux->prox);
			Aux = Aux->prox;
		}
	}
	else
	{
		printf("Lista vazia!");
	}
}
