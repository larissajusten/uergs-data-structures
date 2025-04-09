#include <stdio.h>
#include <stdlib.h>

// Declara��o da variavel nodo

typedef struct lista
{
	float h, s, vs, vh; // hectare, saca, valor saca, valor hectare recebido
	int a;				// ano
	struct lista *proximo;
} nodo;

// Declara��o da variavel l usada na fun��o insere_meio

int i, l;

// Declara��o das fun��es:

void insere_inicio(nodo **inicio, int ano, float hectares, float sacas, float valor_s, float valor_h);

void insere_meio(nodo **inicio, int ano, float hectares, float sacas, float valor_s, float valor_h);

void insere_fim(nodo **fim, int ano, float hectares, float sacas, float valor_s, float valor_h);

void excluir_inicio(nodo **inicio, nodo **fim);

void excluir_meio(nodo **inicio, int ano);

void excluir_fim(nodo **inicio, nodo **fim);

main()
{
	int ano, opcao, j = 0, k = 0;
	float hectares, sacas, valor_s, valor_h;
	char imprimir;
	i = 0;
	nodo *inicio = NULL;
	nodo *auxiliar = NULL;
	nodo *fim = NULL;
	inicio = (nodo *)malloc(sizeof(nodo)); // crio o inicio da struct sem nenhum dado
	if (inicio)
	{
		inicio->h = 0;
		inicio->s = 0;
		inicio->vs = 0;
		inicio->vh = 0;
		inicio->a = NULL;
		inicio->proximo = NULL;
		fim = inicio;
	}
	do
	{
		printf("\t-----------MENU-----------\n");
		printf("\t1 - Inserir;\n");
		printf("\t2 - Excluir;\n");
		printf("\t3 - Sair;");
		printf("\t\n\nSelecione uma opcao: ");
		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:
			printf("\n\nDigite a quantidade de hectares plantados: ");
			scanf("%f", &hectares);
			printf("\nDigite a quantidade de sacas colhidas: ");
			scanf("%f", &sacas);
			printf("\nDigite o valor da saca: R$ ");
			scanf("%f", &valor_s);
			printf("\nDigite o ano da colheita: ");
			scanf("%d", &ano);
			valor_h = (valor_s * sacas) / hectares;
			if (hectares == 0)
				;
			{
				valor_h = 0;
			}
			if (i == 0) // se for a primeira struct a ser criada, vai ser o inicio, nao preciso entrar em fun�ao nenhuma;
			{
				inicio->h = hectares;
				inicio->s = sacas;
				inicio->vs = valor_s;
				inicio->vh = valor_h;
				inicio->a = ano;
				inicio->proximo = NULL;
				i = 1;
			}
			else // 3 possibilidades: Menor ano digitado - Inserir inicio, Maior ano digitado - Inserir fim
			{
				auxiliar = inicio;
				if (ano < auxiliar->a) // verifico se � o menor ano digitado
				{
					insere_inicio(&inicio, ano, hectares, sacas, valor_s, valor_h);
				}
				else
				{
					auxiliar = fim;
					if (ano > auxiliar->a) // verifico se � o maior ano digitado
					{
						insere_fim(&fim, ano, hectares, sacas, valor_s, valor_h);
					}
					else // verifico se o ano ja existe, senao eu insiro no meio
					{
						j == 0;
						auxiliar = inicio;
						while (auxiliar != NULL)
						{
							if (auxiliar->a == ano)
							{
								j = 1;
							}
							auxiliar = auxiliar->proximo;
						}
						if (j == 1)
						{
							printf("O ano digitado ja existe!");
						}
						else
						{
							insere_meio(&inicio, ano, hectares, sacas, valor_s, valor_h);
						}
					}
				}
			}
			break;
		case 2:
			printf("\n\nDigite o ano da colheita que deseja excluir: ");
			scanf("%d", &ano);
			auxiliar = inicio;
			if (ano == auxiliar->a)
			{
				excluir_inicio(&inicio, &fim);
			}
			else
			{
				auxiliar = fim;
				if (ano == auxiliar->a)
				{
					excluir_fim(&inicio, &fim);
				}
				else
				{
					auxiliar = inicio;
					while (auxiliar != NULL)
					{
						if (ano == auxiliar->a)
						{
							k = 1;
						}
						auxiliar = auxiliar->proximo;
					}
					if (k == 1)
					{
						excluir_meio(&inicio, ano);
					}
					else
					{
						printf("\n\nAno de colheita nao encontrado. Tente novamente.");
					}
				}
			}
			break;
		case 3:
			break;
		default:
			printf("Opcao invalida. Tente novamente.");
			break;
		}
		printf("\n\n\n------------------------------------------------------------------\n\n\n");
		system("pause");
		system("cls");
	} while (opcao != 3);
	fflush(stdin);
	printf("\n\nImprimir lista?(s ou n): ");
	scanf("%c", &imprimir);
	switch (imprimir)
	{
	case 's':
		auxiliar = inicio;
		while (auxiliar != NULL)
		{
			printf("\n\n--------------------------------\n\n");
			printf("\tColheita de %d", auxiliar->a);
			printf("\n-Quantidade de hectares plantados: %f", auxiliar->h);
			printf("\n-Quantidade de sacas colhidas: %f", auxiliar->s);
			printf("\n-Valor da saca: R$ %.2f", auxiliar->vs);
			printf("\n-Valor recebido por hectare: R$ %.2f", auxiliar->vh);
			auxiliar = auxiliar->proximo;
		}
		break;
	case 'n':
		break;
	default:
		printf("Opcao invalida. Terminando programa.");
		break;
	}
}

// Fun��es:

void insere_inicio(nodo **inicio, int ano, float hectares, float sacas, float valor_s, float valor_h)
{
	nodo *p = NULL;
	p = (nodo *)malloc(sizeof(nodo));
	if (p)
	{
		p->h = hectares;
		p->s = sacas;
		p->vs = valor_s;
		p->vh = valor_h;
		p->a = ano;
		p->proximo = *inicio;
		*inicio = p;
	}
}

void insere_meio(nodo **inicio, int ano, float hectares, float sacas, float valor_s, float valor_h)
{
	nodo *aux = NULL;
	nodo *aux2 = NULL;
	nodo *p = NULL;
	l = 0;
	p = (nodo *)malloc(sizeof(nodo));
	if (p)
	{
		p->h = hectares;
		p->s = sacas;
		p->vs = valor_s;
		p->vh = valor_h;
		p->a = ano;
	}
	aux = *inicio;
	while (l == 0)
	{
		aux2 = aux->proximo;
		if (aux->a < ano && aux2->a > ano)
		{
			aux->proximo = p;
			p->proximo = aux2;
			l = 1;
		}
		aux = aux2;
	}
}

void insere_fim(nodo **fim, int ano, float hectares, float sacas, float valor_s, float valor_h)
{
	nodo *p = NULL;
	nodo *aux = NULL;
	aux = *fim;
	p = (nodo *)malloc(sizeof(nodo));
	if (p)
	{
		p->h = hectares;
		p->s = sacas;
		p->vs = valor_s;
		p->vh = valor_h;
		p->a = ano;
		p->proximo = NULL;
		aux->proximo = p;
		*fim = p;
	}
}

void excluir_inicio(nodo **inicio, nodo **fim)
{
	nodo *p = NULL;
	nodo *aux = NULL;
	nodo *aux2 = NULL;
	p = *inicio;
	if (*inicio == *fim)
	{
		free(p);
		i = 0;
		aux2 = (nodo *)malloc(sizeof(nodo));
		if (aux2)
		{
			aux2->h = 0;
			aux2->s = 0;
			aux2->vs = 0;
			aux2->vh = 0;
			aux2->a = NULL;
			*inicio = aux2;
		}
	}
	else
	{
		aux = p->proximo;
		free(p);
		*inicio = aux;
	}
}

void excluir_meio(nodo **inicio, int ano)
{
	nodo *p = NULL;
	nodo *aux = NULL;
	p = *inicio;
	l = 0;
	while (l == 0)
	{
		aux = p->proximo;
		if (aux->a == ano)
		{
			l = 1;
		}
		else
		{
			p = aux;
		}
	}
	p->proximo = aux->proximo;
	free(aux);
}

void excluir_fim(nodo **inicio, nodo **fim)
{
	nodo *p = NULL;
	nodo *aux = NULL;
	p = *inicio;
	l = 0;
	while (l == 0)
	{
		aux = p->proximo;
		if (aux->proximo == NULL)
		{
			l = 1;
		}
		else
		{
			p = aux;
		}
	}
	free(aux);
	p->proximo = NULL;
	*fim = p;
}
