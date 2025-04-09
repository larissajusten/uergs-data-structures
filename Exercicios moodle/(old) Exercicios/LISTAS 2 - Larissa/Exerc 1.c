#include <stdlib.h>
#include <stdio.h>

/* Faça um código em c que permita ao usuário buscar um valor em uma lista. 
O usuário digita um valor, você deve percorrer a lista e verificar se encontra o valor solicitado.
a. Caso encontre, imprima o endereço do valor, o valor e o endereço do próximo.
b. Caso não encontre, informe ao usuário.
c. Caso a lista esteja vazia, informe ao usuário. */

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
	int num;
	struct no *prox;
}Nodo;

//Inserir
void InserirInicio(Nodo **inicio, Nodo **fim);
void InserirFim(Nodo **inicio, Nodo **fim);
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
	do{
	printf("\nDigite \n [1]Inserir Inicio\n [2]Inserir Fim\n [3]Excluir Inicio\n [4]Excluir Fim\n [5]Imprimir\n [6]Busca\n [0]Sair: ");
	scanf("%d", &op);
	switch(op){
		case 0:
		return 0;
		break;
		case 1:
		InserirInicio(&inicio, &fim);
		break;
		case 2:
		InserirFim(&inicio, &fim);
		break;
		case 3:
		ExcluirInicio(&inicio);
		break;
		case 4:
		ExcluirFim(&inicio, &fim);
		break;
		case 5:
		Exibir(&inicio);
		break;
		case 6:
		system("cls");
		Busca(&inicio, &fim);
		break;
		default:
		printf("\nOpcao inavalida!");
		break;
		}
	}while(op!=0);
}

void InserirInicio(Nodo **inicio, Nodo **fim){
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
void InserirFim(Nodo **inicio, Nodo **fim){
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
}

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


