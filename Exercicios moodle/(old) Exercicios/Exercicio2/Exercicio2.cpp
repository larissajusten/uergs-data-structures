#include <stdio.h>
#include <stdlib.h>

// EXERCICIO 2 - Larissa Espelocin

int main()
{
	int codigo, conta;
	float valor, rendimento, totalj, totalv, juros;
	do
	{
		printf("Digite o seu codigo: \n");
		scanf("%d", &codigo);
		printf("Escolha seu tipo de conta: [1]Poupanca\n [2]Poupanca Plus\n [3]Fundos de Renda Fixa\n [0]Sair\n");
		scanf("%d", &conta);
		printf("Digite o valor investido: \n");
		scanf("%f", &valor);

		switch (conta)
		{
		case 1:
			juros = valor * (1.5 / 100);
			printf("Seu investimento na conta Poupanca teve o rendimento foi de %f", juros);
			totalv = valor + totalv;
			totalj = juros + totalj;
			break;

		case 2:
			juros = valor * (2 / 100);
			printf("Seu investimento na conta Poupanca Plus teve o rendimento de %f", juros);
			totalv = valor + totalv;
			totalj = juros + totalj;
			break;

		case 3:
			juros = valor * (4 / 100);
			printf("Seu investimento na conta Fundos de Renda Fixa teve o rendimento de %f", juros);
			totalv = valor + totalv;
			totalj = juros + totalj;
			break;
		}

	} while (conta = 0 && conta > 3);
	printf("O total investido foi de %.2f", totalv);
	printf("O total de juros pago foi de %.2f ", totalj);
}
