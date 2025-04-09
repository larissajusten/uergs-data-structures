#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#if defined (_WIN32) || defined(WIN32)
#define clear system("cls")
#else
#define clear system ("clear")
#endif

void clienteF (int cpf, char responsavel[40],int orcamento,int numeroS,char descricao[40]);
void clienteJ(int cnpj, char descricao[100], char setor[40], int numeroS, int orcamento);
void lclienteF ();
void lclienteJ();


int main(int argc, char const *argv[]){
	int menu,cpf,orcamento,numeroS,cnpj;
	char responsavel[40],descricao[40],setor[40];

	do{
	    printf("1 - Gravar dados de pessoa fisica\n");
	    printf("2 - Gravar dados de pessoa juridica\n");
	    printf("3 - Ler dados de pessoas fisicas\n");
	    printf("4 - Ler dados de pessoas juridicas\n");
	    printf("0 - Sair\n");
	    printf("Escolha uma opcoes: ");
	    scanf("%d",&menu);

	    switch (menu){
	      case 1:
		      clear;
		      printf("Digite o cpf do cliente:");
		      scanf("%d",&cpf);
		      printf("\nDigite o nome do responsavel: ");
		      scanf("%s",&responsavel);
		      printf("\nDigite o orcamento: ");
		      scanf("%d",&orcamento);
		      printf("\nDigite o numero de serie: ");
		      scanf("%d",&numeroS);
		      printf("\nDigite a descricao do problema: ");
		      scanf("%s",&descricao);
		      clienteF(cpf, responsavel, orcamento,numeroS,descricao);
		      break;
	      case 2:
		      clear;
		      printf("Digite o cnpj da empresa:");
		      scanf("%d",&cnpj);
		      printf("\nDigite a descricao do problema: ");
		      scanf("%s",&descricao);
		      printf("\nDigite setor: ");
		      scanf("%s",&setor);
		      printf("\n Digite o numero de serie :");
		      scanf("%d",&numeroS);
		      printf("\n Digite o orcamento: ");
		      scanf("%d",&orcamento);
		      clienteJ(cnpj, descricao, setor, numeroS, orcamento);
	     	  break;
	      case 3:
		      clear;
		     lclienteF();
		      break;
	      case 4:
	     	  lclienteJ();
	      	  break;
	      case 0:
		      exit(1);
		      break;
	      default:
		      printf("Opcao invalida!\n");
	    }
	  }while(menu!=0);
	return 0;
}


void clienteF (int cpf, char responsavel[40],int orcamento,int numeroS,char descricao[40]){
  FILE *clienteF;
  clienteF = fopen ("clienteF.txt", "at");
  fprintf(clienteF, "%d\t%s\t%d\t%d\t%s\n",cpf,responsavel,orcamento,numeroS,descricao);
  fclose (clienteF);
}

void clienteJ (int cnpj, char descricao[100], char setor[40], int numeroS, int orcamento){
  FILE *clienteJ;
  clienteJ = fopen ("clienteJ.txt", "at");
  fprintf(clienteJ, "%d\t%s\t%s\t%d\t%d\n",cnpj,descricao,setor,numeroS,orcamento);
  fclose (clienteJ);
}



void lclienteJ (){
  char cnpj [40], descricao[100], setor[40],numerosS[40],orcamento[40];
  FILE *clienteJ;
  clienteJ = fopen ("clienteJ.txt", "rt");
  while (!feof(clienteJ)){
      if (!feof(clienteJ))
        fscanf(clienteJ,"%s %s %s %s %s",&cnpj,&descricao,&setor,&orcamento);
        if (!feof(clienteJ))
        printf("CNPJ:%s Descricao:%s Setor:%s Numero de serie: %s Orcamento: %s\n",cnpj,descricao,setor,orcamento);

    }
}
void lclienteF (){
  char cpf[40], responsavel[40], orcamento[40], numeroS[40],descricao[100];
  FILE *clienteF;
  clienteF = fopen ("clienteF.txt", "rt");
  while (!feof(clienteF)){
      if (!feof(clienteF))
        fscanf(clienteF,"%s %s %s %s %s",&cpf,&responsavel,&orcamento,&numeroS,&descricao);
        if (!feof(clienteF))
        printf("CPF:%s Responsavel:%s Orcamento:%s Numero de serie: %s Descricao: %s\n",cpf,responsavel,orcamento,numeroS,descricao);

    }
}
