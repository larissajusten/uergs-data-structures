#include <stdio.h>
#include <stdlib.h>

/*2. Após fazer uma busca por valor, insira ordenado uma lista.
Ao digitar um valor, o seu código deve fazer a inserção ordenada.
a. Sempre apresente, o endereço do dado, o dado e o endereço do próximo.*/

typedef struct no{
	int num;
	struct no *prox;
}Nodo;

//Inserir
void Inserir(Nodo **inicio, Nodo **fim);
//void InserirInicio(Nodo **inicio, Nodo **fim, int num);
//void InserirFim(Nodo **inicio, Nodo **fim, int num);
//Excluir
void ExcluirInicio (Nodo **inicio);
void ExcluirFim(Nodo **inicio, Nodo **fim);
//Exibir
void Exibir(Nodo **inicio);
//Busca
void Busca(Nodo **inicio, Nodo **fim);

int main(){
	int op;
	Nodo *inicio = NULL;
	Nodo *fim = NULL;
	Nodo Aux, Anterior;
	do{
	printf("\nDigite \n [1]Inserir\n [2]Excluir Inicio\n [3]Excluir Fim\n [4]Imprimir\n [5]Busca\n [0]Sair: ");
	scanf("%d", &op);
	switch(op){
		case 0:
		return 0;
		break;
		case 1:
		Inserir(&inicio, &fim);
		break;
		case 2:
		ExcluirInicio(&inicio);
		break;
		case 3:
		ExcluirFim(&inicio, &fim);
		break;
		case 4:
		Exibir(&inicio);
		break;
		case 5:
		system("cls");
		Busca(&inicio, &fim);
		break;
		default:
		printf("\nOpcao inavalida!");
		break;
		}
	}while(op!=0);
}

void Inserir(Nodo **inicio, Nodo **fim){
	Nodo *Aux = NULL;
	Nodo *Anterior = NULL;
	Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
	if(novo){
		printf("\nDigite um numero: ");
		scanf("%d", &novo->num);
		novo->prox = NULL;
	}else{
		printf("Memoria indisponivel!\n");
	}

	if(*inicio == NULL){
		*inicio = novo;
		*fim = *inicio;
	}else{
		Aux = *inicio;
        while(Aux != NULL && novo->num > Aux->num){
            Anterior = Aux;
            Aux = Aux->prox;
        }
		if(Aux == NULL){
			(*fim)->prox = novo;
			(*fim) = novo;
			(*fim)->prox = NULL;
		}
		if(Anterior == NULL ){
            novo->prox = *inicio;
            *inicio = novo;
		}
		else{
			Anterior->prox = novo;
			novo->prox = Aux;
		}
	}
}

/*void InserirInicio(Nodo **inicio, Nodo **fim, int num){
	Nodo *Aux;
	Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
	printf("\nDigite um numero: ");
	scanf("%d", &novo->num);
	novo->prox = NULL;

	if(*inicio==NULL){
		*inicio = novo;
		*fim = *inicio;
	}else{
		if((*inicio)->prox == NULL){
			Aux = *inicio;
			*inicio = novo;
			novo->prox = Aux;
		}else{
			Aux = (*inicio)->prox;
			*inicio = novo;
			(*inicio)->prox = Aux;
		}
	}
}
void InserirFim(Nodo **inicio, Nodo **fim, int num){
    Nodo *aux;
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    printf("\nDigite um numero: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;

    if((*inicio)==NULL){
    	*inicio = novo;
    	*fim = novo;
	}else{
	    if((*inicio)->prox != NULL){
	        aux = (*inicio)->prox;
	        while(aux->prox!=NULL){
	            aux = aux->prox;
	        }
	    	aux->prox = novo;
	    	*fim = novo;
	    }else{
	        (*inicio)->prox = novo;
	        *fim = *inicio;
	    }
	}
}*/

void ExcluirInicio(Nodo **inicio){
	Nodo *Aux;
	if(*inicio==NULL){
		printf("A lista enconrtra-se vazia");
	}else{
		Aux = (*inicio)->prox;
		printf("O numero a ser retirado e: %d\n", (*inicio)->num);
		printf("O proximo do nodo a ser retirado e: %d\n", (*inicio)->prox);
		printf("O nodo a ser retirado e: %d\n", *inicio);
		free(inicio);
		*inicio=Aux;
	}
}

void ExcluirFim(Nodo **inicio, Nodo **fim){
	Nodo *Atual, *Anterior;
	if (inicio==NULL){
		printf("Lista encontra-se vazia. \n");
	}else{
		if((*inicio)->prox == NULL){
			printf("O numero a ser retirado e: %d\n", (*inicio)->num);
			printf("O proximo do nodo a ser retirado e: %d\n", (*inicio)->prox);
			printf("O nodo a ser retirado e: %d\n", *inicio);
			free(inicio);
		}else{
			Atual=(*inicio)->prox;
			Anterior=*inicio;
			while(Atual->prox!=NULL){
				Anterior=Atual;
				Atual=Atual->prox;
			}
			Anterior->prox=NULL;
			*fim = Anterior;
			printf("O numero a ser retirado e: %d\n", Atual->num);
			printf("O proximo do nodo a ser retirado e: %d\n", Atual->prox);
			printf("O nodo a ser retirado e: %d\n", Atual);
			free(Atual);
		}
	}
}

void Exibir(Nodo **inicio){
	Nodo *Aux;
	int i = 0;
    Aux = *inicio;

	if (Aux == NULL){
		printf("A lista encontra-se vazia. \n");
	}else{
			printf("Lista: \n");
			while(Aux!=NULL){
			i++;
			printf("Pos:%d num:%d Aux:%d Aux->prox:%d \n",i, Aux->num, Aux, Aux->prox);
			Aux=Aux->prox;
			}
		}
	}


void Busca(Nodo **inicio, Nodo **fim){
	int num;
	Nodo *Aux;
	printf("Digite o numero que deseja procurar: ");
	scanf("%d", &num);
	Aux = *inicio;
	while(Aux->num!=num && Aux->prox!=NULL){
		Aux = Aux->prox;
	}
	if(Aux->num == num){
		printf("O numero que deseja procurar foi encontrado: \n\n ");
		printf("\n O numero: %d ", Aux->num);
		printf("\n O nodo original: %d", Aux);
		printf("\n O nodo prox: %d", Aux->prox);
	}else{
		printf("Numero nao encontrado.");
	}
}

