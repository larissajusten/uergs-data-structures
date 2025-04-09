#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int cpf;
	char curso;
	int ano;
	struct nodo *prox;
}no;
//funções
int menu();
void opcoes(no *LISTA, int opt);
void InserirFim(no *LISTA);
no *retirarInicio(no *LISTA);
no *retirarFim(no *LISTA);
void exibir(no *LISTA);
no *aloca();
int esvaziar(no *LISTA);
//main
int main(){
	int opt;
	no *LISTA = (no*)malloc(sizeof(no));
	if(!LISTA){
		printf("Memoria indisponivel");
		return 0;
	}else{
	    LISTA->prox=NULL;
		do{
			opt=menu();
			opcoes(LISTA,opt);
		}while(opt>0 && opt<=4);
	}
	free(LISTA);
}
//funções principais
int menu(){
	int opt;
	printf("\n\tEscolha uma das seguintes opcoes: \n");
	printf("[0]Sair. \n");
	printf("[1]Inserir no fim. \n");
	printf("[2]Retirar do inicio. \n");
	printf("[3]Retirar do fim. \n");
	printf("[4]Exibir. \n");
	scanf("%d", &opt);
	fflush(stdin);
	return opt;
}
void opcoes(no *LISTA, int opt){
	int op;
	no *tmp;
	switch(opt){
	case 0:
		esvaziar(LISTA);
		printf("A Lista foi esvaziada com sucesso! \n");
		break;
	case 1:
		InserirFim(LISTA);
		break;
	case 2:
		tmp=retirarInicio(LISTA);
		if(tmp!=NULL){
			printf("O cpf retirado e: %d\n", tmp->cpf);
			printf("O curso retirado e: %s\n", tmp->curso);
			printf("O ano de inicio retirado e: %d\n", tmp->ano);
			free(tmp);
		}
		break;
	case 3:
		tmp=retirarFim(LISTA);
		if(tmp!=NULL){
			printf("O cpf retirado e: %d\n", tmp->cpf);
			printf("O curso retirado e: %c\n", tmp->curso);
			printf("O ano de inicio retirado e: %d\n", tmp->ano);
			free(tmp);
		}
		break;
	case 4:
		exibir(LISTA);
		break;
	default:
		printf("Opcao invalida. Tente novamente.\n");
		break;
	}
}
void InserirFim(no *LISTA){
	no *Aux;
	no *novo=aloca();
	if (LISTA->prox==NULL){
		LISTA->prox=novo;
	}else{
		Aux=LISTA->prox;
		while(Aux->prox!=NULL){
			Aux=Aux->prox;
		}
		Aux->prox=novo;
	}
}
no *retirarInicio(no *LISTA){
	no *Aux;
	if (LISTA->prox==NULL){
		printf("Lista encontra-se vazia. \n");
		return NULL;
	}else{
		Aux=LISTA->prox;
		LISTA->prox=Aux->prox;
		return Aux;
	}
}
no *retirarFim(no *LISTA){
	no *Atual, *Anterior;
	if (LISTA->prox==NULL){
		printf("Lista encontra-se vazia. \n");
		return NULL;
	}else{
		Atual=LISTA->prox;
		Anterior=LISTA;
		while(Atual->prox!=NULL){
			Anterior=Atual;
			Atual=Atual->prox;
		}
		Anterior->prox=NULL;
		return Atual;
	}
}
void exibir(no *LISTA){
	no *Aux;
	if (LISTA->prox == NULL){
		printf("A lista encontra-se vazia. \n");
	}else{
		int i = 0;
		Aux=LISTA->prox;
		printf("Lista: \n");
		while(Aux!=NULL){
			i++;
			printf("Pos:%d cpf:%d curso:%c ano:%d endereco:%d \n",i, Aux->cpf, Aux->curso, Aux->ano, &Aux);
			Aux=Aux->prox;
		}
	}
}
//funções auxiliares
no *aloca(){
	no *novo;
	novo=(no *)malloc(sizeof(novo));
	if(!novo){
		printf("Memoria indisponivel. \n");
		return NULL;
	}else{
		printf("Digite o cpf a ser inserido: \n");
		scanf("%d", &novo->cpf);
		fflush(stdin);
		printf("Digite o curso a ser inserido: \n");
		fflush(stdin);
		scanf("%s", &novo->curso);
		printf("Digite o ano a ser inserido: \n");
		fflush(stdin);
		scanf("%d", &novo->ano);
		return novo;
	}
}
int esvaziar(no *LISTA){
	int opt;
	no *Aux, *Atual;
	if(LISTA->prox!=NULL){
		Atual=LISTA->prox;
		while(Atual!=NULL){
			Aux=Atual->prox;
			free(Atual);
			Atual=Aux;
		}
	}
	opt=menu();
	return opt;
}
