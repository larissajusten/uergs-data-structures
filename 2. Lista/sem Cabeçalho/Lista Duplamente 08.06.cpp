#include <stdlib.h>
#include <stdio.h>
/*----------------------------Larissa Espelocin---------------------------
-------------------------Estrutura de Dados 2017/1------------------------
--------------------------------------------------------------------------
-------------------------LISTA DUPLAMENTE ENCADEADA-----------------------*/

typedef struct listaD{
	int num;
	struct listaD *prox;
	struct listaD *ant;
}Nodo;
int tam=0;
//CHAMADA DAS FUNCOES
void InserirInicio(Nodo **inicioLD, Nodo **fimLD);
void InserirMeio(Nodo **inicioLD, Nodo **fimLD);
void InserirAnt(Nodo **inicioLD, Nodo **fimLD);
void InserirFim(Nodo **inicioLD, Nodo **fimLD);
void Zerar(Nodo **inicioLD, Nodo **fimLD);
void Imprimir(Nodo **inicioLD, Nodo **fimLD);

main(){
	int op;
	Nodo *inicioLD = NULL;
	Nodo *fimLD = NULL;
	
	do{
	printf("Escolha: \n\tINSERIR:\n\t\t[1]INICIO\n\t\t[2]MEIO\n\t\t[3]ANTERIOR\n\t\t[4]FIM\n\t[8]Imprimir\n\t[9]Zerar\n\t[0]Sair\nOp: ");
	scanf("%d", &op);
		switch(op){
			case 0:
				system("cls");
				printf("\n\t\t\t\t\tVOCE APERTOU SAIR\n");
				Zerar(&inicioLD, &fimLD);
				return 0;
			break;
			case 1:
				system("cls");
				printf("\n\t\t\t\t\tINSERIR NO INICIO\n");
				InserirInicio(&inicioLD, &fimLD);
			break;
			case 2:
				system("cls");
				printf("\n\t\t\t\t\tINSERIR NO MEIO\n");
				InserirMeio(&inicioLD, &fimLD);
			break;
			case 3:
				system("cls");
				printf("\n\t\t\t\t\tINSERIR ANTES DE UM NUMERO\n");
				InserirAnt(&inicioLD, &fimLD);
			break;
			case 4:
				system("cls");
				printf("\n\t\t\t\t\tINSERIR NO FIM\n");
				InserirFim(&inicioLD, &fimLD);
			break;
			case 8:
				system("cls");
				printf("\n\t\t\t\t\tIMPRIMIR\n");
				Imprimir(&inicioLD, &fimLD);
			break;
			case 9:
				system("cls");
				Zerar(&inicioLD, &fimLD);
				inicioLD = NULL;
				fimLD = NULL;
			break;
			default: 
			printf("\nOpcao invalida! Tente novamente.\n");	
		}
	}while(op=!0);	
}
void InserirInicio(Nodo **inicioLD, Nodo **fimLD){
	Nodo *Aux;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	
	if(novo){
		printf("Digite o numero: ");
		scanf("%d", &novo->num);
		printf("\n");
		novo->ant = NULL;
		novo->prox = NULL;
		tam++;
		if(*inicioLD == NULL){
			*inicioLD = novo;
			*fimLD = *inicioLD;
		}else{
			novo->prox = *inicioLD;
			Aux = *inicioLD;
			Aux->ant = novo;
			*inicioLD = novo;
		}
	}else{
		printf("\n\tMemoria indisponivel! Tente novamente.\n");	
	}
}
void InserirMeio(Nodo **inicioLD, Nodo **fimLD){
	Nodo *Aux, *Aux2;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	int x, 
		tmp = 1;
		
	x = tam;			//-------------------------
	if(x == 1){			//
		tmp = x;		//
	}else if(x%2==0){	// 
		x = x/2;		//  Define o meio da lista
	}else{				//
		x = x-1;		//
		x = x/2;		//
	}					//-------------------------
	
	if(novo){
		printf("Digite o numero: ");
		scanf("%d", &novo->num);
		printf("\n");
		novo->ant = NULL;
		novo->prox = NULL;
		
		if(*inicioLD == NULL){
			*inicioLD = novo;
			*fimLD = *inicioLD;
		}else if((*inicioLD)->prox == NULL){
			InserirFim(inicioLD, fimLD);
		}else{
			Aux = *inicioLD;
			while(tmp != x){
				Aux = Aux->prox;
				tmp++;	
			}
			Aux2 = Aux->prox;
			novo->ant = Aux;
			novo->prox = Aux2;
			Aux2->ant = novo;
			Aux->prox = novo;
		}
	}else{
		printf("\n\tMemoria indisponivel! Tente novamente.\n");
	}
}
void InserirAnt(Nodo **inicioLD, Nodo **fimLD){
	Nodo *Aux, *Tmp;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	int num;
	
	printf("Digite o numero ANTERIOR:");
	scanf("%d", &num);
	
	if(novo){
		printf("Digite o numero: ");
		scanf("%d", &novo->num);
		printf("\n");
		novo->ant = NULL;
		novo->prox = NULL;
		tam++;
		
		if(*inicioLD == NULL){
			*inicioLD = novo;
			*fimLD = *inicioLD;
		}else{
			Aux = *inicioLD;
			while(Aux->num != num && Aux->prox != NULL){
				Aux = Aux->prox;
			}
			Tmp = Aux->prox;
			if(Tmp != NULL){
				Aux->prox = novo;
				novo->ant = Aux;
				novo->prox = Tmp;
				Tmp->ant = novo;	
			}else{
				Aux->prox = novo;
				novo->ant = Aux;
				novo->prox = Tmp;
			}
		}
	}else{
		printf("\n\tMemoria indisponivel! Tente novamente.\n");
	}
}
void InserirFim(Nodo **inicioLD, Nodo **fimLD){
	Nodo *Aux;
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	
	if(novo){
		printf("Digite o numero: ");
		scanf("%d", &novo->num);
		printf("\n");
		novo->ant = NULL;
		novo->prox = NULL;
		tam++;
		if(*inicioLD == NULL){
			*inicioLD = novo;
			*fimLD = *inicioLD;
		}else{
			(*fimLD)->prox = novo;
			novo->ant = *fimLD;
			*fimLD = novo;
		}
	}else{
		printf("\n\tMemoria indisponivel! Tente novamente.\n");
	}	
}
void Imprimir(Nodo **inicioLD, Nodo **fimLD){
	Nodo *Aux, *Aux2;
	int i=1;
	
	//------------------------------------------------Comecando do inicio
	
	if(*inicioLD == NULL){
		printf("\n\tA lista esta vazia!\n");
	}else{
		Aux = *inicioLD;
		while(Aux != NULL){
			printf("\tNodo[%d]:\n\t\tAnt: %d\n\t\tEndereco: %d\n\t\tNum: %d\n\t\tProx: %d\n", i, Aux->ant, Aux, Aux->num, Aux->prox);
			i++;
			Aux = Aux->prox;
		}
		printf("\nTamanho total da lista: %d\n", tam);
	}
	
	//------------------------------------------------Comecando do fim
	/*
	if(*inicioLD == NULL){
		printf("\n\tA lista esta vazia!\n");
	}else{
		Aux2 = *fimLD;
		while(Aux != NULL){
			printf("Nodo[%d]:\n\tEndereco: %d\n\tNum: %d\n\tAnt: %d\n\tProx: %d\n", i, Aux, Aux->num, Aux->ant,  Aux->prox);
			i++;
			Aux = Aux->ant;
		}
	}
	*/	
}
void Zerar(Nodo **inicioLD, Nodo **fimLD){
	Nodo *Atual, *Prox;
	Nodo *Ultimo, *Penultimo;
	
	if(*inicioLD == NULL){  
		printf("\n\nA LISTA esta vazia!\n\n");
	}
	else if(*inicioLD == *fimLD){
		free(*inicioLD);
		free(*fimLD);
		printf("\n\nA LISTA esta vazia!\n\n");
	}else{
		Atual = *inicioLD;
		while(Atual != NULL){
			Prox = Atual->prox;
			free(Atual);
			Atual = Prox;
		}
		printf("\n\nA LISTA esta vazia!\n\n");
	}
	
	/*if(*inicioLD == *fimLD){
		free(*inicioLD);
		free(*fimLD);
		printf("\n\nA LISTA esta vazia!\n");
	}else{
		Ultimo = *fimLD;
		while(Ultimo != NULL){
			Penultimo = Ultimo->ant;
			free(Ultimo);
			Ultimo = Penultimo;
		}
		printf("\n\nA LISTA esta vazia!\n");
	}
	*/
}
