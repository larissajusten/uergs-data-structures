#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//exercicio1
void CadastroF(int cpf,int nserie,char descricao[50],char profissional[20],float valor);
void CadastroJ(int cnpj,int nserie,char descricao[50],char setor[20],float valor);
void LerInformacoes();

int main(){
    int menu, cpf, cnpj, nserie;
    char descricao[50];
    char profissional[20];
    char setor[20];
    float valor;

    do{
        printf("[1]Cadastrar informaçoes Cliente Pessoa Fisica.\n");
        printf("[2]Cadastrar informaçoes Cliente Pessoa Juridica.\n");
        printf("[3]Ler informaçoes.\n");
        printf("A: ");
        scanf("%d", &menu);
        printf("\n");
        switch(menu){
            case 1:
            printf("Digite o CPF do cliente: ");
            scanf("%d", &cpf);
            printf("Digite o numero de serie do equipamento: ");
            scanf("%d", &nserie);
            printf("Digite a descriacao do problema [50]: ");
            fflush(stdin);
            gets(descricao);
            printf("Digite o nome do profissional responsavel pelo concerto: ");
            scanf("%s",&profissional);
            printf("Digite o valor previsto no orcamento: ");
            scanf("%f",&valor);
            printf("\n");
            CadastroF(cpf, nserie, descricao, profissional, valor);
            break;
            case 2:
            printf("Digite o CNPJ do cliente: ");
            scanf("%d", &cnpj);
            printf("Digite o numero de serie do equipamento: ");
            scanf("%d", &nserie);
            printf("Digite a descriacao do problema [50]: ");
            fflush(stdin);
            gets(descricao);
            printf("Digite o nome do setor solicitante: ");
            scanf("%s",&setor);
            printf("Digite o valor previsto no orcamento: ");
            scanf("%f",&valor);
            printf("\n");
            CadastroJ(cnpj, nserie, descricao, setor, valor);
            break;
            case 3:
            LerInformacoes();
            break;
            default:
            printf("Opcao invalida!");
        }
    }while(menu>=1 && menu<=3);
}
//funcoes
void CadastroF(int cpf,int nserie,char descricao[50],char profissional[20],float valor){
    FILE *fis;
    fis = fopen("pessoafisica.txt","wt");
    fprintf(fis, "%d\t%d\t%s\t%s\t%f\n",cpf, nserie, descricao, profissional, valor);
    fclose(fis);
}
void CadastroJ(int cnpj,int nserie,char descricao[50],char setor[20],float valor){
    FILE *jur = fopen("pessoajuridica.txt","wt");
    fprintf(jur, "%d\t%d\t%s\t%s\t%2.f\n",cnpj, nserie, descricao, setor, valor);
    fclose (jur);
}
void LerInformacoes(){
    int cpf, cnpj, nserie;
    char desc[50], prof[20], setor[20];
    float valor;

    FILE *fis = fopen("pessoafisica.txt","rt");
      while (!feof(fis)){
          if (!feof(fis))
            fscanf(fis,"%d %d %s %s %f",&cpf,&nserie,&desc,&prof,&valor);
            if (!feof(fis))
            printf("Cpf:%d\nNumero de serie:%d\nDescricao:%s\nProfissional:%s\nValor:%2.f\n\n",cpf, nserie, desc, prof, valor);
        }
    fclose(fis);

    FILE *jur = fopen("pessoajuridica.txt","rt");
      while (!feof(jur)){
          if (!feof(jur))
            fscanf(jur,"%d %d %s %s %f",&cnpj,&nserie,&desc,&prof,&valor);
            if (!feof(jur))
            printf("Cnpj:%d\nNumero de serie:%dDescricao:%s\nSetor solitante:%s\nValor:%2.f\n\n",cnpj, nserie, desc, setor,valor);
        }
    fclose(jur);
}
