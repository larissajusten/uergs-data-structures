#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*Elabore um programa que receba as informações do rebanho de bovinos em uma fazenda. O fazendeiro recebe lotes de bois e cadastra em um arquivo o código (int) do boi,
o peso (float) e a data de nascimento.
As inclusões terminam quando no menu for finalizado o programa:
menu: [1]Insere boi; [2]Lista todos os bois; [3]Calcula total de peso dos bois; [4]Mostra boi mais velho; [5]Fim. */

//FUNÇÕES PARA ABRIR E FECHAR ARQUIVO

/* FILE* AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo) {
        case 'g':
            arquivo = fopen(caminho,"wt");
            break;
        case 'l':
            arquivo = fopen(caminho, "rt");
            break;
        case 'a':
            arquivo = fopen(caminho, "a");
            break;
    }
    if(arq_lote==NULL){
        printf("Impossivel abrir o arquivo para escrita");
        exit(0);
    }
    return arquivo;
}

void FechaArquivo(FILE *arquivo){
    fclose(arquivo);
} */

struct boilote {
    int codigo;
    float peso;
    int dnascimento;
};
int main()
{   char arq_lote[20];
    int menu=0;
    int i=0,k,dta_nasc=0;
    float totalpeso;

    printf ("Digite o nome do arquivo: ");
    scanf("%s",&arq_lote);
    FILE *fid;


    if(arq_lote==NULL){
        printf("Impossivel abrir o arquivo para escrita");
    }

    struct boilote b;
    do{
        printf("Escolha uma opcao:\n [1]Inserir boi. \n [2]Lista de todos os bois. \n [3]Calcular o total de peso dos bois. \n [4]Mostra o boi mais velho. \n [5]Fim. \n\nESCOLHA: ");
        scanf("%d",&menu);

    switch(menu){
        case 1:

            fid=fopen(arq_lote,"a+t");
            printf("\nDigite o codigo do boi: ");
            scanf("\n%d",&b.codigo);
            fprintf(fid,"\n%d",b.codigo);
            printf ("Digite o peso do boi: ");
            scanf("\n%f", &b.peso);
            fprintf(fid,"\n%f",b.peso);
            printf ("Digite a data de nascimento do boi: ");
            scanf("\n%d", &b.dnascimento);
            fprintf(fid,"\n%d",b.dnascimento);
            fclose(fid);
        break;
        case 2:
            char temp;
            fid=fopen(arq_lote,"rt");
            while(!(feof(fid))){
                fscanf(fid,"%c",&temp);
                printf("Codigo do boi: %d\n\n", b.codigo);
            }
            while(temp!='\n'){
                b.codigo=temp;
                fscanf(fid,"%c",&temp);
            }
            fclose(fid);
        break;
        case 3:
            fid=fopen(arq_lote,"rt");
            for(k=0;k>i;k++){
                totalpeso=+b.peso;
            }
            fclose(fid);
        break;
        case 4:
            for(i=0;dta_nasc<=b.dnascimento;i++){
                b.dnascimento=dta_nasc;
            };
        break;
        default:
        goto exit;
    }
    }while(menu!=5);

    exit:
    system("PAUSE");

}
