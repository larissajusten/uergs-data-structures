#include <stdlib.h>
#include <stdio.h> //-----------------------------------FILA-----(First In First Out)-------------------------------------------------------------------------------

/*1.
Escreva um algoritmo que implemente as seguintes informações: suponha que você tem uma fila de impressão de documentos composto por : nome do documento – usuário.
Esta fila de impressão precisa ser implementada de acordo com o critério FIFO.
Faça inserção de documentos na fila de inserção e posteriormente, imprima-os.
Quando o documento for impresso, o mesmo será retirado da fila.
Sempre imprima dos dados juntamente com os endereços atuais e dos próximos.
*/

typedef struct no {
	 int usuario;
	 char nome_doc[50];
	 struct  no *prox;
}Nodo;

void InserirFim(Nodo **inicio, Nodo **fim);
void Imprimir(Nodo **inicio);

main(){
	int op;
	Nodo *inicio = NULL;
	Nodo *fim = NULL;
	do{
		printf("\n\tFILA DE IMPRESSAO DE DOCUMENTOS\n");
		printf(" [1] Inserir Fim\n");
		printf(" [2] Imprimir\n");
		printf(" [0] Sair\n");
		printf("Escolha: ");
		scanf("%d", &op);

		switch(op){
			case 1:
            system("cls");
			InserirFim(&inicio, &fim);
			break;
			case 2:
			Imprimir(&inicio);
			break;
			case 0:
			return 0;
			break;
			default:
			printf("Op invalida!");
			break;
		}
	}while(op!=0);
}

void InserirFim(Nodo **inicio, Nodo **fim){
	Nodo *Aux;
	Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
	if(novo){
		printf("\t INSERIR ");
		printf("\nDigite o usuario (apenas numeros): ");
		scanf("%d", &novo->usuario);
		fflush(stdin);
		printf("Digite o nome do documento: ");
		scanf("%s", &novo->nome_doc);
		novo->prox = NULL;
	}else{
		printf("Espaco de memoria indisponivel!");
	}

	if(*inicio == NULL){
		*inicio = novo;
		*fim = *inicio;
	}else{
		if((*inicio)->prox == 	NULL){
			(*inicio)->prox = novo;
			*fim = novo;
		}else{
			Aux = *inicio;
			while(Aux->prox != NULL){
				Aux = Aux->prox;
			}
			Aux->prox = novo;
			*fim = Aux->prox;
		}
	}

}

void Imprimir(Nodo **inicio){
	Nodo *Aux;
	if(*inicio != NULL){
		Aux = *inicio;
		while(Aux != NULL){
            printf("\nUsuario: %d \nNome do Documento: %s \nNodo: %d \nNodo->prox: %d\n\n", Aux->usuario, Aux->nome_doc, Aux, Aux->prox);
			Aux = Aux->prox;
		}
	}else{
		printf("Lista vazia!");
	}
}
