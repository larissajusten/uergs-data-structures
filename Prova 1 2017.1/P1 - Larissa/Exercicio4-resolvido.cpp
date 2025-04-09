#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int op;

typedef struct filmes{
    char nome[50];
    int yfilme;
    int yassistido;
    int nota;
    struct filmes *prox;
}no;

void InserirFinal(**inicio, **fim);
void RetirarFinal(**inicio, **fim);
void RetirarInicio(**inicio, **fim);
void Exibir(**inicio, **fim);

int main(){
	no *inicio = NULL;
	no *final = NULL;
    do{
        printf("[1]Inserir no final da LISTA.\n");
        printf("[2]Excluir do final da LISTA.\n");
        printf("[3]Excluir do inicio da LISTA.\n");
        printf("[4]Imprimir LISTA.\n");
        printf("[0]Sair.\n");
        printf("A: ");
        scanf("%d",&op);

        switch(op){
            case 0:
            esvaziar(&inicio, &fim);
            printf("A Lista foi esvaziada com sucesso! \n");
            break;
            case 1:
            InserirFinal(&inicio, &fim);
            break;
            case 2:
            RetirarFinal(&inicio, &fim);
            break;
            case 3:
            RetirarInicio(&inicio, &fim);
            break;
            case 4:
            Exibir(&inicio, &fim);
            break;
            default:
            printf("Op invalida!");
        }
    }while(op>=1 && op<=4);
}

//funcoes
void InserirFinal(*inicio, *fim){
    no *Aux = NULL;
    novo = (no*)malloc(sizeof(no));
    novo->prox = NULL;
	if(!novo){
		printf("Memoria indisponivel. \n");
	}else{
	    fflush(stdin);
		printf("Digite o nome do filme: ");
		gets(novo->nome);
		printf("Digite o ano do filme: ");
		scanf("%d", &novo->yfilme);
		printf("Digite o ano que o filme foi assistido: ");
		scanf("%d", &novo->yassistido);
		printf("Digite a nota do filme: ");
		scanf("%d",&novo->nota);
		novo->prox=NULL;
		printf("\n");
	}
	if(inicio == NULL){
		inicio = novo;
	}else{
		 if(fim->prox !=NULL){
	       	Aux = inicio->prox;
	        while(Aux->prox !=NULL ){
	            Aux=Aux->prox;
	    	}
	        Aux->prox=novo;
   		}else{
        	fim->prox = novo;
		}	
	}
	novo = NULL;
	Aux = NULL;
}
void RetirarFinal(*inicio, *fim){
    no *Atual = NULL;
    no *Anterior = NULL;

	if (LISTA->prox==NULL){
		printf("Lista encontra-se vazia. \n");
	}else{
		Atual=LISTA->prox;
		Anterior=LISTA;
		while(Atual->prox!=NULL){
			Anterior=Atual;
			Atual=Atual->prox;
		}
		Anterior->prox=NULL;
		free(Atual);
	}
}
void RetirarInicio(**inicio){
    no *Aux;
	if (*inicio->prox==NULL){
		printf("Lista encontra-se vazia. \n");
	}else{
		Aux=*inicio->prox;
		*inicio->prox=Aux->prox;
		free(Aux);
	}
}
void Exibir(**inicio, **fim){
    no *Aux;
  	if (LISTA->prox == NULL){
		printf("A lista encontra-se vazia. \n");
	}else{
		Aux=LISTA->prox;
		printf("Lista: \n");
			while(Aux!=NULL){
				printf("Nome:%s \nAno do filme:%d \nAno Assistido:%d \nNota:%d \n", Aux->nome, Aux->yfilme, Aux->yassistido, Aux, &Aux);
				Aux=Aux->prox;
			}
	}
}
int esvaziar(**inicio, **fim){
	int opt;
	no *Aux, *Atual;
	if(*inicio->prox!=NULL){
		Atual=*inicio->prox;
		while(Atual!=NULL){
			Aux=Atual->prox;
			free(Atual);
			Atual=Aux;
		}
		free(Aux);
	}
	opt=main();
	return opt;
}
