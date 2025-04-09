#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int num;
	struct nodo *prox;
} Nodo;

// Inserir
void InserirInicio(Nodo **inicio, Nodo **fim);
void InserirFim(Nodo **inicio, Nodo **fim);
void InserirNum(Nodo **inicio, Nodo **fim);
// Excluir
void ExcluirInicio(Nodo **inicio, Nodo **fim);
void ExcluirFim(Nodo **inicio, Nodo **fim);
// Exibir
void Exibir(Nodo **inicio, Nodo **fim);

int main()
{
	Nodo *inicio = NULL;
	Nodo *fim = NULL;
	int op;

	do
	{
		printf("\nDigite \n [1]Inserir Inicio\n [2]Inserir Fim\n [3]Inserir Num\n [4]Excluir Inicio\n [5]Excluir Fim\n [6]Imprimir\n [0]Sair: ");
		scanf("%d", &op);
		switch (op)
		{
		case 0:
			return 0;
			break;
		case 1:
			InserirInicio(&inicio, &fim);
			break;
		case 2:
			InserirFim(&inicio, &fim);
			break;
		case 3:
			InserirNum(&inicio, &fim);
			break;
		case 4:
			ExcluirInicio(&inicio, &fim);
			break;
		case 5:
			ExcluirFim(&inicio, &fim);
			break;
		case 6:
			Exibir(&inicio, &fim);
			break;
		default:
			printf("\nOpcao inavalida!");
		}
	} while (op != 0);
}

void InserirInicio(Nodo **inicio, Nodo **fim)
{
	Nodo *Aux;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	printf("\nDigite um numero: ");
	scanf("%d", &novo->num);
	novo->prox = NULL;

	if (*inicio == NULL)
	{
		*inicio = novo;
		*fim = *inicio;
	}
	else
	{
		if ((*inicio)->prox == NULL)
		{
			Aux = *inicio;
			*inicio = novo;
			novo->prox = Aux;
		}
		else
		{
			Aux = (*inicio)->prox;
			*inicio = novo;
			(*inicio)->prox = Aux;
		}
	}
}
void InserirFim(Nodo **inicio, Nodo **fim)
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
		if ((*inicio)->prox != NULL)
		{
			aux = (*inicio)->prox;
			while (aux->prox != NULL)
			{
				aux = aux->prox;
			}
			aux->prox = novo;
			fim = novo;
		}
		else
		{
			(*inicio)->prox = novo;
			fim = novo;
		}
	}
}
void InserirNum(Nodo **inicio, Nodo **fim)
{
	Nodo *Aux, *Aux2;
	int tmp;
	printf("Digite o numero o qual apos deve-se inserir o no: \n");
	scanf("%d", &tmp);
	fflush(stdin);
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	if (novo)
	{
		printf("\nDigite um numero: ");
		scanf("%d", &novo->num);
		novo->prox = NULL;
		Aux = (*inicio)->prox;
		if ((*inicio)->prox == NULL)
		{
			(*inicio)->prox = novo;
		}
		else
		{
			while (Aux->num != tmp)
			{
				Aux = Aux->prox;
			}
			if (Aux->num == tmp)
			{
				Aux2 = Aux->prox;
				Aux->prox = novo;
				novo->prox = Aux2;
			}
			else
			{
				printf("Numero nao encontrado. \n");
			}
		}
	}
}
void ExcluirInicio(Nodo **inicio, Nodo **fim)
{
	Nodo *Aux;
	if (inicio == NULL)
	{
		printf("A lista enconrtra-se vazia");
	}
	else
	{
		Aux = (*inicio)->prox;
		printf("O numero a ser retirado e: %d\n", (*inicio)->num);
		printf("O proximo do nodo a ser retirado e: %d\n", (*inicio)->prox);
		printf("O nodo a ser retirado e: %d\n", inicio);
		free(inicio);
		inicio = Aux;
	}
}

void ExcluirFim(Nodo **inicio, Nodo **fim)
{
	Nodo *Atual, *Anterior;
	if (inicio == NULL)
	{
		printf("Lista encontra-se vazia. \n");
	}
	else
	{
		if ((*inicio)->prox == NULL)
		{
			printf("O numero a ser retirado e: %d\n", (*inicio)->num);
			printf("O proximo do nodo a ser retirado e: %d\n", (*inicio)->prox);
			printf("O nodo a ser retirado e: %d\n", inicio);
			free(inicio);
		}
		else
		{
			Atual = (*inicio)->prox;
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

void Exibir(Nodo **inicio, Nodo **fim)
{
	Nodo *Aux;
	int i = 0;

	if (inicio == NULL)
	{
		printf("A lista encontra-se vazia. \n");
	}
	else
	{
		if ((*inicio)->prox == NULL)
		{
			printf("Pos:%d num:%d inicio:%d inicio->prox:%d \n", i, (*inicio)->num, inicio, (*inicio)->prox);
		}
		else
		{
			printf("Lista: \n");
			Aux = (*inicio)->prox;
			printf("Pos:%d num:%d Aux:%d Aux->prox:%d \n", i, (*inicio)->num, inicio, (*inicio)->prox);
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
