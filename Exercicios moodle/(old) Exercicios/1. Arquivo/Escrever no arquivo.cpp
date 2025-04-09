#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fid;
	char nome[20];
	char s[] = "fim";
	int f = 0;

	fid = fopen("nomewrite.txt", "w+t");
	if (fid == NULL)
	{
		perror("Erro ao abrir o arquivo");
		return 1;
	}

	printf("Digite o nome da pessoa: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0'; // Remove newline character
	f = strcmp(nome, s);

	while (f != 0)
	{
		fprintf(fid, "Nome: %s\n", nome);
		printf("Digite o nome da pessoa: ");
		fgets(nome, sizeof(nome), stdin);
		nome[strcspn(nome, "\n")] = '\0'; // Remove newline character
		f = strcmp(nome, s);
	}
	fclose(fid);
	return 0;
}
