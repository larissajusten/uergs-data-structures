#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int num;
	char word;
	struct nodo *prox; 
}no;
int tam;
//funções
int menu();
void opcoes(no *LISTA, int opt);
void Inserir(no *LISTA);
void inserirNum(no *LISTA);
void inserirWord(no *LISTA);
void inserirPos(no *LISTA);
void InserirInicio(no *LISTA);
void InserirFim(no *LISTA);
no *retirar(no *LISTA);
no *retirarInicio(no *LISTA);
no *retirarFim(no *LISTA);
void exibir(no *LISTA);
no *aloca();
int vazia(no *LISTA);
void inicia(no *LISTA);
int esvaziar(no *LISTA);
//main
int main(){
	int opt;
	no *LISTA = (no*)malloc(sizeof(no));
	if(!LISTA){
		printf("Memoria indisponivel");
		return 0;
	}else{
		inicia(LISTA);
		do{
			opt=menu();
			opcoes(LISTA,opt);
		}while(opt>0 && opt<=8);
	}
	free(LISTA);
}
//funções principais
int menu(){
	int opt;
	printf("\n\tEscolha uma das seguintes opcoes: \n");
	printf("[0]Sair. \n");
	printf("[1]Inserir. \n");
	printf("[2]Inserir no inicio. \n");
	printf("[3]Inserir no fim. \n");
	printf("[4]Retirar. \n");
	printf("[5]Retirar do inicio. \n");
	printf("[6]Retirar do fim. \n");
	printf("[7]Exibir. \n");
	printf("[8]Zerar. \n");
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
		system("clear");
		printf("A Lista foi esvaziada com sucesso! \n");
		break;
	case 1:
		system("clear");
		Inserir(LISTA);
		system("clear");
		break;
	case 2: 
		system("clear");
		InserirInicio(LISTA);
		system("clear");
		break;
	case 3:
		system("clear");
		InserirFim(LISTA);
		system("clear");
		break;
	case 4:
		system("clear");
		tmp=retirar(LISTA);
		if(tmp!=NULL){
			printf("O numero retirado e: %d\n", tmp->num);
			printf("A letra retirada e: %c\n", tmp->word);
			free(tmp);
		}
		break;
	case 5:
		system("clear");
		tmp=retirarInicio(LISTA);
		if(tmp!=NULL){
			printf("O numero retirado e: %d\n", tmp->num);
			printf("A letra retirada e: %c\n", tmp->word);
			free(tmp);
		}
		break;
	case 6:
		system("clear");
		tmp=retirarFim(LISTA);
		if(tmp!=NULL){
			printf("O numero retirado e: %d\n", tmp->num);
			printf("A letra retirada e: %c\n", tmp->word);
			free(tmp);
		}
		break;
	case 7:
		system("clear");
		exibir(LISTA);
		break;
	case 8:
		op=esvaziar(LISTA);
		system("clear");
		printf("A Lista foi esvaziada com sucesso! \n");
		inicia(LISTA);
		opcoes(LISTA,op);
		break;
	default:
		system("clear");
		printf("Opcao invalida. Tente novamente.\n");
		break;
	}
}
void Inserir(no *LISTA){
	int op;
	printf("\nEscolha: \n");
	printf("[0]Sair. \n");
	printf("[1]Inserir por numero. \n"); 
	printf("[2]Inserir por letra. \n");
	printf("[3]Inserir por posicao. \n");
	scanf("%d",&op);
	fflush(stdin);
	switch(op){
		case 0:
		esvaziar(LISTA);
		break;
		case 1:
		inserirNum(LISTA);
		break;
		case 2:
		inserirWord(LISTA);
		break;
		case 3:
		inserirPos(LISTA);
		break;
		default:
		printf("Opcao invalida.\n");
		break;
	}
}
//funções da 'Função Inserir'----------------------------------------------------------------------------------
void inserirNum(no *LISTA){
	no *Aux, *Aux2;
	int tmp;
	no *novo=aloca();
	printf("Digite o numero o qual apos deve-se inserir o no: \n");
	scanf("%d", &tmp);
	fflush(stdin);
	Aux=LISTA->prox;
	if (LISTA->prox==NULL){
		LISTA->prox=novo;
		tam++;
	}else{
		while(Aux->num!=tmp){
			Aux=Aux->prox;
		}
		if(Aux->num==tmp){
			Aux2=Aux->prox;
			Aux->prox=novo;
			novo->prox=Aux2;
			tam++;
		}else{
			printf("Numero nao encontrado. \n");
		}
	}
}
void inserirWord(no *LISTA){
	no *Aux, *Aux2;
	char tmp;
	printf("Digite a letra a qual apos deve-se inserir o no: \n");
	scanf(" %c", &tmp);
	no *novo=aloca();
	fflush(stdin);
	Aux=LISTA->prox;
	if(LISTA->prox==NULL){
		LISTA->prox=novo;
		tam++;
	}else{
		while(Aux->word!=tmp){
			Aux=Aux->prox;
		}
		Aux2=Aux->prox;
		Aux->prox=novo;
		novo->prox=Aux2;
		tam++;
	}
}
void inserirPos(no *LISTA){
	no *Atual, *Anterior;
	int tmp, count;
	printf("Digite a posicao que deseja inserir o no: \n");
	scanf("%d",&tmp);
	fflush(stdin);
	if(tmp>0 && tmp<=tam){
		if(tmp==1){
			InserirInicio(LISTA);
		}else{
			Atual=LISTA->prox;
			Anterior=LISTA;
			no *novo=aloca();
			for(count=1; count<tmp; count++){
				Anterior=Atual;
				Atual=Atual->prox;
			}
			Anterior->prox=novo;
			novo->prox=Atual;
			tam++;
		}
	}else{
		printf("Posicao de entrada invalida. \n");
	}
}
//-------------------------------------------------------------------------------------------------------------
void InserirInicio(no *LISTA){
	no *Aux;
	no *novo=aloca();
	if(LISTA->prox==NULL){
		LISTA->prox=novo;
		tam++;	
	}else{
		Aux=LISTA->prox;
		LISTA->prox=novo;
		novo->prox=Aux;
		tam++;
	}
}
void InserirFim(no *LISTA){
	no *Aux;
	no *novo=aloca();
	if (LISTA->prox==NULL){
		LISTA->prox=novo;
		tam++;
	}else{
		Aux=LISTA->prox;
		while(Aux->prox!=NULL){
			Aux=Aux->prox;
		}
		Aux->prox=novo;
		tam++;
	}
}
no *retirar(no *LISTA){
	no *Atual, *Anterior;
	int tmp;
	printf("Qual a oposicao que deseja retirar: \n");
	scanf("%d",&tmp);
	fflush(stdin);
	if (LISTA->prox==NULL){
		printf("A lista encontra-se vazia. \n");
		return NULL;
	}else{
		if (tmp>0 && tmp<=tam){
			if(tmp==1){
				retirarInicio(LISTA);
			}else{
				int count;
				Atual=LISTA->prox;
				Anterior=LISTA;
				for (count = 1; count < tmp; count++){
					Anterior=Atual;
					Atual=Atual->prox;
				}
				Anterior->prox=NULL;
				tam--;
				return Atual;
			}
		}else{
			printf("Elemento invalido. \n");
			return NULL;
		}
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
		tam--;
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
		tam--;
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
			printf("Pos:%d num:%d letra:%c \n",i, Aux->num, Aux->word);
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
		printf("Digite o novo numero a ser inserido: \n");
		scanf("%d", &novo->num);
		fflush(stdin);
		printf("Digite a letra a ser inserida: \n");
		fflush(stdin);
		scanf(" %c", &novo->word);
		return novo;
	}
}
int vazia(no *LISTA){
	if(LISTA->prox==NULL){
		return 1;
	}else{
		return 0;
	}
}
void inicia(no *LISTA){
	LISTA->prox=NULL;
	tam=0;
}
int esvaziar(no *LISTA){
	int opt;
	no *Aux, *Atual;
	if(vazia(LISTA) == 0){
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