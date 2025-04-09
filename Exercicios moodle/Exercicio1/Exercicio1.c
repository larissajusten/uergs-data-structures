#include <stdio.h>
#include <stdlib.h>

// EXERCICIO 1       -  Larissa Espelocin

int main () {
	int s,op,m,t;
	float a,b,c,d,f;
do {	
	printf("Escolha uma opcao:\n 1.Novo salario \n 2.Ferias \n 3.Decimo terceiro \n 4.Sair");
	scanf ("%d",&op);

switch (op) {
case 1:
printf("Digite seu salario atual:\n ");
scanf("%d",&s);
	
	if (s>350) {
	a=s*0,15;
	printf("Seu salario e %f",a);}
	
	if (s<350 && s>600) {
	b=s*0,10;
	printf ("Seu salario e %f",b);}
	
	if (s<600) {
	c=s*0,05;
	printf ("Seu salario e %f",c);}
break;

case 2:
printf("Digite seu salario atual:\n ");
scanf("%d",&s);
f=s+(1/3*s);
printf ("O valor de suas ferias sao %f",f);
break;

case 3:
printf ("Digite o seu salario atual: \n");
scanf ("%d",&s);
printf ("Digite o numero de meses de trabalho (max.12): \n");
scanf ("%d",&m);
t=(s*m)/12;
printf ("O seu decimo terceiro e %t\n",t);
break;

case 4:
printf ("Voce escolheu a opcao Sair.");
break;
}
return 0;
	
	while (op=0 && op<4);
	printf ("Opcao invalida.");}

}
