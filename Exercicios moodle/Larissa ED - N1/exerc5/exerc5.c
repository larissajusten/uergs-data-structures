#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#if defined(_WIN32) || defined(WIN32)
#define clear system("cls")
#else
#define clear system("clear")
#endif

void cliente(int cod, char nome[40], char ende[100]);
void pizza(int cod, char nome[40], float valor);
void venda(int codc, int codp, int total, float vtotal);
void lpizza();
void lcliente();
void lvenda();
void renda();

int main(int argc, char const *argv[])
{
	int codp, codc, total, menu;
	float vp, vc;
	char nome[40], ende[100];

	do
	{
		printf("1 - Gravar dados das pizzas\n");
		printf("2 - Gravar dados dos clientes\n");
		printf("3 - Gravar dados da venda\n");
		printf("4 - Ler dados das pizzas\n");
		printf("5 - Ler dados dos clientes\n");
		printf("6 - Ler dados das vendas\n");
		printf("0 - Sair\n");
		printf("Escolha uma opcoes: ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			clear;
			printf("Digite o codigo da pizza[4]:");
			scanf("%d", &codp);
			printf("\nDigite o nome da pizza: ");
			scanf("%s", &nome);
			printf("\nDigite o valor: ");
			scanf("%f", &vp);
			pizza(codp, nome, vp);
			break;
		case 2:
			clear;
			printf("Digite o codigo do cliente[4]:");
			scanf("%d", &codc);
			printf("\nDigite o nome do cliente: ");
			scanf("%s", &nome);
			printf("\nDigite o endereco: ");
			scanf("%s", &ende);
			cliente(codc, nome, ende);
			break;
		case 3:
			clear;
			printf("Digite o codigo do cliente:");
			scanf("%d", &codc);
			printf("Digite o codigo do pizza:");
			scanf("%d", &codp);
			printf("Digite a Quantidade de pizza:");
			scanf("%d", &total);
			printf("Digite o valor pago: ");
			scanf("%f", &vc);
			venda(codc, codp, total, vc);
			break;
		case 4:
			lpizza();
			break;
		case 5:
			lcliente();
			break;
		case 6:
			lvenda();
			break;
		case 0:
			renda();
			break;
		default:
			printf("Op errada!\n");
		}
	} while (menu != 0);
	return 0;
}

void cliente(int cod, char nome[40], char ende[100])
{
	FILE *cli;
	cli = fopen("cliente.txt", "at");
	fprintf(cli, "%d\t%s\t%s\n", cod, nome, ende);
	fclose(cli);
}

void pizza(int cod, char nome[40], float valor)
{
	FILE *piz;
	piz = fopen("pizza.txt", "at");
	fprintf(piz, "%d\t%s\t%.2f\n", cod, nome, valor);
	fclose(piz);
}

void venda(int codc, int codp, int total, float vtotal)
{
	FILE *venda;
	venda = fopen("vendas.txt", "at");
	fprintf(venda, "%d\t%d\t%d\t%.2f\n", codc, codp, total, vtotal);
	fclose(venda);
}

void lpizza()
{
	char nome[40], cod[4], valor[15];
	FILE *piz;
	piz = fopen("pizza.txt", "rt");
	while (!feof(piz))
	{
		if (!feof(piz))
			fscanf(piz, "%s %s %s", &cod, &nome, &valor);
		if (!feof(piz))
			printf("Codigo:%s Nome:%s Valor:%s\n", cod, nome, valor);
	}
}

void lcliente()
{
	char nome[40], cod[4], ende[100];
	FILE *cli;
	cli = fopen("cliente.txt", "rt");
	while (!feof(cli))
	{
		fscanf(cli, "%s %s %s", &cod, &nome, &ende);
		if (!feof(cli))
			printf("Codigo:%s Nome:%s Valor:%s\n", cod, nome, ende);
	}
}

void lvenda()
{
	char codp[20], codc[20], total[20], totalp[20];
	FILE *venda;
	venda = fopen("vendas.txt", "rt");
	while (!feof(venda))
	{
		fscanf(venda, "%s %s %s %s", &codc, &codp, &totalp, &total);
		if (!feof(venda))
			printf("Codigo:%s Nome:%s Valor:%s\n", codc, codp, totalp, total);
	}
}

void renda()
{
	char codp[20], codc[20], total[20], totalp[20];
	int totalpi = 0;
	float totalv = 0;
	FILE *venda;
	venda = fopen("vendas.txt", "rt");
	while (!feof(venda))
	{
		fscanf(venda, "%s %s %s %s", &codc, &codp, &totalp, &total);
		if (!feof(venda))
		{
			totalpi = totalpi + (int)atoll(totalp);
			totalv = totalv + (float)atoll(total);
		}
	}
	printf("Total pizzas:%d Total de valor:%.2f\n", totalpi, totalv);
}
