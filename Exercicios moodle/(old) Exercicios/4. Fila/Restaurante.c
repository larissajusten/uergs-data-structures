#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 16

typedef struct Fila
{
	int maxLugares;
	int lugaresOcupados;
	struct Fila *prox; // Added missing member 'prox'
} Fila;

void insereinicio(Fila **inicio, Fila **novo)
{
	(*novo)->prox = *inicio;
	*inicio = (*novo);
}

void inserefim(Fila **ultimo, Fila **p)
{
	(*ultimo)->prox = *p;
	(*p)->prox = NULL;
	*ultimo = *p;
}

void removeinicio(Fila **inicio)
{
	Fila *aux = *inicio;
	*inicio = (*inicio)->prox;
	free(aux);
}

void removefim(Fila **inicio, Fila **fim)
{
	Fila *auxp = *inicio;
	if (*inicio == *fim)
	{
		free(*fim);
		*inicio = *fim = NULL;
		return;
	}
	while (auxp->prox != *fim)
	{
		auxp = auxp->prox;
	}
	free(*fim);
	*fim = auxp;
	(*fim)->prox = NULL;
}

void inserePrimeiraVez(Fila **inicioDaFila, Fila **fimDaFila, Fila *mesaAux)
{
	*fimDaFila = mesaAux;
	*inicioDaFila = mesaAux;
	(*inicioDaFila)->prox = NULL;
	(*fimDaFila)->prox = NULL;
}

void alocarMesa(Fila **inicioMesasOcupadas,
				Fila **mesasDisponiveis,
				Fila **inicioDasMesasDisponiveis,
				Fila **fimDasMesasDisponiveis,
				Fila **inicioDaFilaPrioritaria,
				Fila **inicioDaFilaNormal,
				Fila **fimDaFilaNormal)
{
	if (mesasDisponiveis != NULL)
	{
		removefim(inicioDasMesasDisponiveis, fimDasMesasDisponiveis);
		inserefim(fimDaFilaNormal, mesasDisponiveis);
	}
}

main()
{
	Fila *filaPrioritaria, *inicioDaFilaPrioritaria = NULL, *fimDaFilaPrioritaria = NULL,
						   *filaNormal, *inicioDaFilaNormal = NULL, *fimDaFilaNormal = NULL,
						   *mesasDisponiveis, *inicioDasMesasDisponiveis = NULL, *fimDasMesasDisponiveis = NULL,
						   *mesasOcupadas;
	inicioDasMesasDisponiveis = NULL;
	fimDasMesasDisponiveis = NULL;
	Fila *mesaAux = NULL;

	filaPrioritaria = (Fila *)malloc(sizeof(Fila));
	filaNormal = (Fila *)malloc(sizeof(Fila));
	inicioDasMesasDisponiveis = NULL;
	fimDasMesasDisponiveis = NULL;
	mesasOcupadas = (Fila *)malloc(sizeof(Fila));

	printf("Restaurante Bem Servido.\nSeja Bem vindo.\n \n");

	int opcao = -1;
	while (opcao != 0)
	{

		printf("Escolha uma das opcoes a seguir: \n");
		printf("1 - Nova entrada\n");
		printf("2 - Vizualizar mesas\n");
		printf("3 - Vizualizar lista de espera\n");
		printf("4 - Desocupar mesa\n");
		printf("0 - Digite para sair \n");
		printf(":\n");
		scanf("%d", &opcao);
		scanf("%d", opcao);

		switch (opcao)
		{
			scanf("%d", &opcao);
			printf("Digite qual a fila: \n");
			printf("1 - Normal \n");
			printf("2 - Prioritaria \n");
			printf(": \n");
			scanf("%d", opcao);
			switch (opcao)
				;
		case 1:
			if (inicioDaFilaNormal == NULL)
			{
				int cond = 1;
				do
				{
					printf("Digite o número de pessoas esperando uma mesa: ");
					if (mesaAux->lugaresOcupados >= mesaAux->maxLugares)
					{
						printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
					}
					if (mesaAux->lugaresOcupados > mesaAux->maxLugares)
					{
						cond = 0;
					}
				} while (cond);
				fimDaFilaNormal = mesaAux;
				inicioDaFilaNormal = mesaAux;
				inicioDaFilaNormal->prox = NULL;
				fimDaFilaNormal->prox = NULL;
			}
			else
			{
				int cond = 1;
				do
				{
					printf("Digite o número de pessoas esperando uma mesa: ");
					scanf("%d", &mesaAux->lugaresOcupados);
					if (mesaAux->lugaresOcupados >= mesaAux->maxLugares)
					{
						printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
					}
					else
					{
						cond = 0;
					}
				} while (cond);
				inserefim(&fimDaFilaNormal, &mesaAux);
			}
			break;
		case 2:
			if (inicioDaFilaPrioritaria == NULL)
			{
				int cond = 1;
				do
				{
					printf("Digite o número de pessoas esperando uma mesa: ");
					scanf("%d", &mesaAux->lugaresOcupados);
					if (mesaAux->lugaresOcupados >= mesaAux->maxLugares)
					{
						printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
					}
					else
					{
						cond = 0;
					}
				} while (cond);
				fimDaFilaPrioritaria = mesaAux;
				inicioDaFilaPrioritaria = mesaAux;
				inicioDaFilaPrioritaria->prox = NULL;
				fimDaFilaPrioritaria->prox = NULL;
			}
			else
			{
				int cond = 1;
				do
				{
					printf("Digite o número de pessoas esperando uma mesa: ");
					scanf("%d", &mesaAux->lugaresOcupados);
					if (mesaAux->lugaresOcupados >= mesaAux->maxLugares)
					{
						printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
					}
					else
					{
						cond = 0;
					}
				} while (cond);
				inserefim(&fimDaFilaPrioritaria, &mesaAux);
			}
			break;
		}
	}
}