#include <stdio.h>
#include <stdlib.h>

struct Node{
	int nota;
	char nome[60];
	int anoF;
	int anoA;
	struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);



int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
	}
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	tam=0;
}

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar filme no inicio da lista\n");
	printf("3. Adicionar filme no final da lista\n");
	printf("4. Retirar filme do inicio da lista\n");
	printf("5. Retirar filme do fim da lista\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *LISTA, int op)
{
	node *tmp;
	switch(op){
		case 0:
			printf("Programa finalizado");
			return 1;
			break;



		case 1:
			exibe(LISTA);
			break;

		case 2:
			insereInicio(LISTA);
			break;

		case 3:
			insereFim(LISTA);
			break;

		case 4:
			tmp= retiraInicio(LISTA);
			printf("Retirado: %3d\n\n", tmp->nome);
			break;

		case 5:
			tmp= retiraFim(LISTA);
			printf("Retirado: %3d\n\n", tmp->nome);
			break;


		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	printf("Digite o ano que o filme foi feito :  \n");
		scanf("%d", &novo->anoF);
		fflush(stdin);
		printf("Digite o nome do filme a ser inserido ( sem espacos por favor): \n");
		fflush(stdin);
		scanf("%s", &novo->nome);
		printf("Digite o ano em que voce assistiu o filme:  \n");
		fflush(stdin);
		scanf("%d", &novo->anoA);
        printf("Digite a nota que voce da ao filme \n");
		fflush(stdin);
		scanf("%d", &novo->nota);
		return novo;
	}
}


void insereFim(node *LISTA)
{
	node *novo=aloca();
	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
	tam++;
}

void insereInicio(node *LISTA)
{
	node *novo=aloca();
	node *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;

	tam++;
}

void exibe(node *LISTA)
{
	system("clear");
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("\n Ano que o filme foi feito:%d, Nome do filme:%s, Ano que o filme foi assistido:%d,Nota:%d \n", tmp->anoF, tmp->nome, tmp->anoA, tmp->nota);
		tmp = tmp->prox;
	}


}


node *retiraInicio(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja esta vazia\n");
		return NULL;
	}else{
		node *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		tam--;
		return tmp;
	}

}

node *retiraFim(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja vazia\n\n");
		return NULL;
	}else{
		node *ultimo = LISTA->prox,
			 *penultimo = LISTA;

		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}

		penultimo->prox = NULL;
		tam--;
		return ultimo;
	}
}


