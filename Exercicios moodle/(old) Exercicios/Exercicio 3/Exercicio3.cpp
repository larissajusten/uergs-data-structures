#include <stdio.h>
#include <stdlib.h>

// Exercicio - Larissa Espelocin

int main()
{
	int time, moradia;
	float salario;

	printf("Qual seu time de cora��o?\n1-Goias\n2-Vila nova\n3-Internacional\n4-Gremio\n5-Outros");
	scanf("%d", &time);
	printf("Onde voc� mora?\n1-Rio Grande do Sul\n2-Goias\n3-Outros");
	scanf("%d", &moradia);
	printf("Qual o seu salario?");
	scanf("%f", &salario);
}
