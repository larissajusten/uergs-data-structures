#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
	int num;
	struct no *prox;
} Nodo;
// Inserir
void InserirInicio();
void InserirFim();
// Excluir
void ExcluirInicio();
void ExcluirFim();
// Exibir
void Exibir();
// Nodos
Nodo *inicio = NULL;
Nodo *fim = NULL;

int main()
{
	int op;

	do
	{
		printf("\nDigite \n [1]Inserir Inicio\n [2]Inserir Fim\n [3]Excluir Inicio\n [4]Excluir Fim\n [5]Imprimir\n [0]Sair: ");
		scanf("%d", &op);
		switch (op)
		{
		case 0:
			return 0;
			break;
		case 1:
			InserirInicio();
			break;
		case 2:
			InserirFim();
			break;
		case 3:
			ExcluirInicio();
			break;
		case 4:
			ExcluirFim();
			break;
		case 5:
			Exibir();
			break;
		default:
			printf("\nOpcao inavalida!");
		}
	} while (op != 0);
}

void InserirInicio()
{
	Nodo *Aux;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	printf("\nDigite um numero: ");
	scanf("%d", &novo->num);
	novo->prox = NULL;

	if (inicio == NULL)
	{
		inicio = novo;
		fim = inicio;
	}
	else
	{
		if (inicio->prox == NULL)
		{
			Aux = inicio;
			inicio = novo;
			novo->prox = Aux;
		}
		else
		{
			Aux = inicio->prox;
			inicio = novo;
			inicio->prox = Aux;
		}
	}
}
void InserirFim()
{
	Nodo *aux;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	printf("\nDigite um numero: ");
	scanf("%d", &novo->num);
	novo->prox = NULL;

	if (inicio == NULL)
	{
		inicio = novo;
		fim = novo;
	}
	else
	{
		if (inicio->prox != NULL)
		{
			aux = inicio->prox;
			while (aux->prox != NULL)
			{
				aux = aux->prox;
			}
			aux->prox = novo;
			fim = novo;
		}
		else
		{
			inicio->prox = novo;
			fim = novo;
		}
	}
}

void ExcluirInicio()
{
	Nodo *Aux;
	if (inicio == NULL)
	{
		printf("A lista enconrtra-se vazia");
	}
	else
	{
		Aux = inicio->prox;
		printf("O numero a ser retirado e: %d\n", inicio->num);
		printf("O proximo do nodo a ser retirado e: %d\n", inicio->prox);
		printf("O nodo a ser retirado e: %d\n", inicio);
		free(inicio);
		inicio = Aux;
	}
}

void ExcluirFim()
{
	Nodo *Atual, *Anterior;
	if (inicio == NULL)
	{
		printf("Lista encontra-se vazia. \n");
	}
	else
	{
		if (inicio->prox == NULL)
		{
			printf("O numero a ser retirado e: %d\n", inicio->num);
			printf("O proximo do nodo a ser retirado e: %d\n", inicio->prox);
			printf("O nodo a ser retirado e: %d\n", inicio);
			free(inicio);
		}
		else
		{
			Atual = inicio->prox;
			Anterior = inicio;
			while (Atual->prox != NULL)
			{
				Anterior = Atual;
				Atual = Atual->prox;
			}
			Anterior->prox = NULL;
			fim = Anterior;
			printf("O numero a ser retirado e: %d\n", Atual->num);
			printf("O proximo do nodo a ser retirado e: %d\n", Atual->prox);
			printf("O nodo a ser retirado e: %d\n", Atual);
			free(Atual);
		}
	}
}

void Exibir()
{
	Nodo *Aux;
	int i = 0;

	if (inicio == NULL)
	{
		printf("A lista encontra-se vazia. \n");
	}
	else
	{
		if (inicio->prox == NULL)
		{
			printf("Pos:%d num:%d inicio:%d inicio->prox:%d \n", i, inicio->num, inicio, inicio->prox);
		}
		else
		{
			printf("Lista: \n");
			Aux = inicio->prox;
			printf("Pos:%d num:%d Aux:%d Aux->prox:%d \n", i, inicio->num, inicio, inicio->prox);
			while (Aux != NULL)
			{
				i++;
				printf("Pos:%d num:%d Aux:%d Aux->prox:%d \n", i, Aux->num, Aux, Aux->prox);
				system("pause");
				Aux = Aux->prox;
			}
		}
	}
}
