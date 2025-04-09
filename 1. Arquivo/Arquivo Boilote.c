#include <stdio.h>
#include <stdlib.h>
struct boilote{
int codigo;
char nome[10];
float peso;
int nascimento;
};
int main()
{
    FILE *fid;
    int op;
    struct boilote i;
    do{
    printf("\n 1- Inserir boi ");
    printf("\n 2- Listar bois ");
    printf("\n 3- Calcular peso total dos bois ");
    printf("\n 4- Boi mais velho  ");
    printf("\n 5- Sair do programa ");
    printf("\n escolha uma opcao: ");
    scanf("%d",&op);

    switch(op){

        case 1:
           fid=fopen(arq_lote.bin,"a+t");
           printf("\nDigite o codigo do boi:  ");
           scanf("%d",&i.codigo);
           fprintf(fid,"\n%d",i.codigo);
           printf("\n Digite o peso do boi: ");
           scanf("%f",&peso);
           fprintf(fid,"\n%f",i.peso);
           printf("\n Digite o nome do boi:  ");
           scanf("%s",&nome);
           fprintf(fid,"\n%s",i.nome);
           printf("\n Digite a data de nascimento: ");
           scanf("%d",&nascimento);
           fprintf(fid,"%s",nascimento);
           fclose(fid);
           break;

        case 2:
            char temp;
            fid=fopen(arq_lote,"rt");
            while(!(feof(fid))){
                fscanf(fid,"%c",&temp);
                printf("\n Codigo do boi :%d\n\n",i.codigo);
            }

            }



















    while(op!=5);
    }
}
}

