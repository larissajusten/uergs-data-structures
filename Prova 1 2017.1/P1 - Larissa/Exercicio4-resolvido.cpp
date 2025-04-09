#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int op;

typedef struct filmes
{
	char nome[50];
	int yfilme;
	int yassistido;
	int nota;
	struct filmes *prox;
} no;

void InserirFinal(no **inicio, no **fim);
void RetirarFinal(no **inicio, no **fim);
void RetirarInicio(no **inicio);
void Exibir(no **inicio);

int main()
{
	no *inicio = NULL;
	no *final = NULL;
	do
	{
		printf("[1]Inserir no final da LISTA.\n");
		printf("[2]Excluir do final da LISTA.\n");
		printf("[3]Excluir do inicio da LISTA.\n");
		printf("[4]Imprimir LISTA.\n");
		printf("[0]Sair.\n");
		printf("A: ");
		scanf("%d", &op);

		switch (op)
		{
		case 0:
			esvaziar(&inicio);
			printf("A Lista foi esvaziada com sucesso! \n");
			break;
		case 1:
			InserirFinal(&inicio, &final);
			break;
		case 2:
			RetirarFinal(&inicio, &final);
			break;
		case 3:
			RetirarInicio(&inicio);
			break;
		case 4:
			Exibir(&inicio);
			break;
		default:
			printf("Op invalida!");
		}
	} while (op >= 1 && op <= 4);
}

// funcoes
void InserirFinal(no **inicio, no **fim)
{
	no *Aux = NULL;
	no *novo = (no *)malloc(sizeof(no));
	novo->prox = NULL;
	if (!novo)
	{
		printf("Memoria indisponivel. \n");
	}
	else
	{
		fflush(stdin);
		printf("Digite o nome do filme: ");
		gets(novo->nome);
		printf("Digite o ano do filme: ");
		scanf("%d", &novo->yfilme);
		printf("Digite o ano que o filme foi assistido: ");
		scanf("%d", &novo->yassistido);
		printf("Digite a nota do filme: ");
		scanf("%d", &novo->nota);
		novo->prox = NULL;
		printf("\n");
	}
	if (*inicio == NULL)
	{
		*inicio = novo;
		*fim = novo;
	}
	else
	{
		if ((*fim)->prox == novo)
		{
			*fim = novo;
			while (Aux->prox != NULL)
			{
				Aux = Aux->prox;
			}
			Aux->prox = novo;
		}
		else
		{
			(*fim)->prox = novo;
		}
	}
	novo = NULL;
	Aux = NULL;
}
void RetirarFinal(no **inicio, no **fim)
{
	no *Atual = NULL;
	no *Anterior = NULL;

	if (*inicio == NULL)
	{
		printf("Lista encontra-se vazia. \n");
	}
	else
	{
		Atual = (*inicio)->prox;
		Anterior = *inicio;
		while (Atual->prox != NULL)
		{
			Anterior = Atual;
			Atual = Atual->prox;
		}
		Anterior->prox = NULL;
		free(Atual);
	}
}
void RetirarInicio(no **inicio)
{
	no *Aux;
	if (*inicio == NULL)
	{
		printf("Lista encontra-se vazia. \n");
	}
	else
	{
		Aux = *inicio;
		*inicio = Aux->prox;
		free(Aux);
	}
}
void Exibir(no **inicio)
{
	no *Aux;
	if (*inicio == NULL)
	{
		printf("A lista encontra-se vazia. \n");
	}
	else
	{
		Aux = *inicio;
		printf("Lista: \n");
		while (Aux != NULL)
		{
			printf("Nome:%s \nAno do filme:%d \nAno Assistido:%d \nNota:%d \n", Aux->nome, Aux->yfilme, Aux->yassistido, Aux->nota);
			Aux = Aux->prox;
		}
	}
}
int esvaziar(no **inicio)
{
	int opt;
	no *Aux, *Atual;
	if (*inicio != NULL)
	{
		Atual = *inicio;
		while (Atual != NULL)
		{
			Aux = Atual->prox;
			free(Atual);
			Atual = Aux;
		}
		free(Aux);
	}
	opt = main();
	return opt;
}
