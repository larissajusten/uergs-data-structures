#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct boilote
{
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
  struct boilote oldest_boi;
  float total_peso;
  int first_boi = 1;

  do
  {
    printf("\n 1- Inserir boi ");
    printf("\n 2- Listar bois ");
    printf("\n 3- Calcular peso total dos bois ");
    printf("\n 4- Boi mais velho  ");
    printf("\n 5- Sair do programa ");
    printf("\n escolha uma opcao: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      fid = fopen("arq_lote.bin", "ab");
      if (fid == NULL)
      {
        printf("\nErro ao abrir o arquivo para escrita.\n");
        break;
      }
      printf("\nDigite o codigo do boi:  ");
      scanf("%d", &i.codigo);
      printf("\nDigite o peso do boi: ");
      scanf("%f", &i.peso);
      printf("\nDigite o nome do boi:  ");
      scanf("%s", i.nome);
      printf("\nDigite a data de nascimento (YYYYMMDD): ");
      scanf("%d", &i.nascimento);
      fwrite(&i, sizeof(struct boilote), 1, fid);
      fclose(fid);
      break;

    case 2:
      fid = fopen("arq_lote.bin", "rb");
      if (fid == NULL)
      {
        printf("\nErro ao abrir o arquivo para leitura.\n");
        break;
      }
      printf("\nLista de bois:\n");
      while (fread(&i, sizeof(struct boilote), 1, fid))
      {
        printf("\nCodigo do boi: %d", i.codigo);
        printf("\nPeso do boi: %.2f", i.peso);
        printf("\nNome do boi: %s", i.nome);
        printf("\nData de nascimento: %d\n", i.nascimento);
      }
      fclose(fid);
      break;

    case 3:
      fid = fopen("arq_lote.bin", "rb");
      if (fid == NULL)
      {
        printf("\nErro ao abrir o arquivo para leitura.\n");
        break;
      }
      total_peso = 0;
      while (fread(&i, sizeof(struct boilote), 1, fid))
      {
        total_peso += i.peso;
      }
      printf("\nPeso total dos bois: %.2f\n", total_peso);
      fclose(fid);
      break;

    case 4:
      fid = fopen("arq_lote.bin", "rb");
      if (fid == NULL)
      {
        printf("\nErro ao abrir o arquivo para leitura.\n");
        break;
      }
      first_boi = 1;
      while (fread(&i, sizeof(struct boilote), 1, fid))
      {
        if (first_boi || i.nascimento < oldest_boi.nascimento)
        {
          oldest_boi = i;
          first_boi = 0;
        }
      }
      if (!first_boi)
      {
        printf("\nBoi mais velho:");
        printf("\nCodigo do boi: %d", oldest_boi.codigo);
        printf("\nPeso do boi: %.2f", oldest_boi.peso);
        printf("\nNome do boi: %s", oldest_boi.nome);
        printf("\nData de nascimento: %d\n", oldest_boi.nascimento);
      }
      else
      {
        printf("\nNenhum boi encontrado.\n");
      }
      fclose(fid);
      break;

    case 5:
      printf("\nSaindo do programa.\n");
      break;

    default:
      printf("\nOpcao invalida. Tente novamente.\n");
      break;
    }
  } while (op != 5);

  return 0;
}