#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arq;
	char string[30];
	char num[10];
	int a = 1, b;

	printf("Digite 1 para escrever e 0 para ler: ");
	scanf("%d", &b);
	if (b == 1)
	{
		arq = fopen("arq.txt", "wb"); // Open in write mode to overwrite the file
		if (arq == NULL)
		{
			perror("Erro ao abrir o arquivo");
			return 1;
		}
		while (a != 0)
		{
			printf("Digite o nome: ");
			scanf(" %[^\n]", string); // Use safer input method
			printf("Digite o numero: ");
			scanf(" %[^\n]", num); // Use safer input method
			fwrite(string, sizeof(char), 30, arq);
			fwrite(num, sizeof(char), 10, arq);
			printf("Digite [0] para sair e [1] para continuar: ");
			scanf("%d", &a);
		}
		fclose(arq);
	}
	else
	{
		arq = fopen("arq.txt", "rb"); // Open in read mode
		if (arq == NULL)
		{
			perror("Erro ao abrir o arquivo");
			return 1;
		}
		while (fread(string, sizeof(char), 30, arq) == 30 && fread(num, sizeof(char), 10, arq) == 10)
		{
			printf("Nome: %s\n", string);
			printf("Numero: %s\n", num);
		}
		fclose(arq);
	}
	return 0;
}
