#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	FILE *fid;
	char nome[20];
	char s[]="fim";
	int f=0;
	
	fid=fopen("nomewrite.txt","w+t");
	printf("Digite o nome da pessoa: ");
	gets(nome);
	f=strcmp(nome,s);
	//f=strcmp(nome,"fim");
	while(f!=0){
		fprintf(fid,"Nome: %s ",nome);
		fflush(stdin);
		printf("Digite o nome da pessoa: ");
		gets(nome);
		f=strcmp(nome,s);
	}
	fclose(fid);	
}
//13 = Enter em ASCII
//if(getch()==13){
//		if(getch()==)
//}
