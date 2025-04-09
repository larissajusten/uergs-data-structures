#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	FILE *arq;
	char string[30];
	char num[10];
	int a=1,b;
	
	printf("Digite 1 para escrever e 0 para ler: ");
	scanf("%d",&b);
	if(b==1){
		arq=fopen("arq.txt","r+b");
		while(a!=0){
			printf("Digite o nome: ");
			gets(string);
			printf("Digite o numero: ");
			gets(num);
			fflush(stdin);
			fwrite(string,sizeof(char),30,arq);
			fwrite(num,sizeof(char),10,arq);
			printf("Digite [0] para sair e [1] para continuar: ");
			scanf("%d", &a);
			fflush(stdin);
		}
		fclose(arq);
	}else{
		arq=fopen("arq.txt","r+b");
		while(!feof(arq)){
			fread(string, sizeof(char), 10 ,arq);
			fread(num, sizeof(char), 10 ,arq);
			printf("%s",string);
			printf("%d",num);
		}
		fclose(arq);
		}
	}


