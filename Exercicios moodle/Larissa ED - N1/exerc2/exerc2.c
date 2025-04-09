#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
	int cpf;
	char curso[50];
	int ano;
	struct nodo *prox;
}no;

//funcoes
int menu();
void opcoes(int opt);
void InserirFim();
no *retirarInicio();
no *retirarFim();
void exibir();
int esvaziar();

no *LISTA = NULL;
no *Aux = NULL;
no *novo = NULL;

//main
int main(){
	int opt;
	LISTA = (no*)malloc(sizeof(no));
	if(!LISTA){
		printf("Memoria indisponivel");
		return 0;
	}else{
	    LISTA->prox=NULL;
		do{
			opt=menu();
			opcoes(opt);
		}while(opt>0 && opt<=4);
	}
	free(LISTA);
}

//funcoes principais
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
void opcoes(int opt){
	int op;
	no *tmp;
	switch(opt){
	case 0:
		esvaziar();
		printf("A Lista foi esvaziada com sucesso! \n");
		break;
	case 1:
		InserirFim();
		break;
	case 2:
		tmp=retirarInicio();
		if(tmp!=NULL){
			printf("O cpf retirado e: %d\n", tmp->cpf);
			printf("O curso retirado e: %s\n", tmp->curso);
			printf("O ano de inicio retirado e: %d\n", tmp->ano);
			free(tmp);
		}
		break;
	case 3:
		tmp=retirarFim();
		if(tmp!=NULL){
			printf("O cpf retirado e: %d\n", tmp->cpf);
			printf("O curso retirado e: %s %s\n", tmp->curso);
			printf("O ano de inicio retirado e: %d\n", tmp->ano);
			free(tmp);
		}
		break;
	case 4:
		exibir();
		break;
	default:
		printf("Opcao invalida. Tente novamente.\n");
		break;
	}
}
void InserirFim(){
	novo = (no *)malloc(sizeof(no));
	if(!novo){
		printf("Memoria indisponivel. \n");
		novo = NULL;
	}else{
		printf("Digite o cpf a ser inserido: \n");
		scanf("%d", &novo->cpf);
		fflush(stdin);
		printf("Digite o curso a ser inserido: \n");
		gets(novo->curso);
		fflush(stdin);
		printf("Digite o ano a ser inserido: \n");
		scanf("%d", &novo->ano);
		fflush(stdin);
		novo->prox=NULL;
	}

	 if(LISTA->prox !=NULL){
       	Aux = LISTA->prox;
        while(Aux->prox !=NULL ){
            Aux=Aux->prox;
        }
        Aux->prox=novo;
    }else{
        LISTA->prox = novo;
    }
	novo = NULL;
	Aux = NULL;
}
no *retirarInicio(){
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
no *retirarFim(){
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
void exibir(){
	no *Aux;
	if (LISTA->prox == NULL){
		printf("A lista encontra-se vazia. \n");
	}else{
		Aux=LISTA->prox;
		printf("Lista: \n");
			while(Aux!=NULL){
				printf("Cpf:%d ano:%d curso:%s endereco:%d \n", Aux->cpf, Aux->ano, Aux->curso, Aux, &Aux);
				Aux=Aux->prox;
			}
	}
}

//funcoes auxiliares
int esvaziar(){
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
