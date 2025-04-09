#include <stdio.h>
#include <stdlib.h>
#define clear system ("clear")
void listaP( int par );
void listaI( int impar);
void LerP();
void LerI();
int main()
{
    int op=0,num=0,par=0,impar=0;
    do{
            printf("\n Digite 1 para gravar um numero\n");
            printf("\n Digite 2 para ler os numeros pares\n");
            printf("\n Digite 3 para ler os numeros impares\n");
            printf("\n Digite 0 para sair \n");
            printf("\n Opcao desejada: \n");
            scanf("%d",&op);


        switch (op){

    case 0:
        exit (1);
        break;

    case 1:
        printf("\n Digite o numero que deseja gravar:  ");
        scanf("%d",&num);
        if (num%2==0){
            par=num;
            num=0;
            listaP(par);
            printf("\n Numero gravado !");
        }
        else{

            impar=num;
            num=0;
            listaI(impar);
            printf("\n Numero gravado !");

        }

        break;

    case 2:

        LerP();
        break;




    case 3:
        LerI();
        break;

    default:
        printf("\n Opcao invalida ! \n");

        }
    }while(op!=0);
    return 0;
}



void listaP (int par){

  FILE *nump;
  nump = fopen ("ListaP.txt", "at");
  fprintf(nump, "%d\n",par);
  fclose (nump);
}


void listaI (int impar){

  FILE *numi;
  numi = fopen ("ListaI.txt", "at");
  fprintf(numi, "%d\n",impar);
  fclose (numi);
}


void LerP(){
  char par[40];
  FILE *nump;
  nump = fopen ("ListaP.txt", "rt");
  while (!feof(nump))
    {
       fscanf(nump,"%s",&par);
       if (!feof(nump))
       printf("\n Numero : %s",par);
    }
}

void LerI(){
  char impar[40];
  FILE *numi;
  numi = fopen ("ListaI.txt", "rt");
  while (!feof(numi))
    {
       fscanf(numi,"%s",&impar);
       if (!feof(numi))
       printf("\n Numero : %s",impar);
    }
}
