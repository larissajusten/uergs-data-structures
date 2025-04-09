#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#define MAX 16

typedef struct Fila
{
	int maxLugares = 4;
	int lugaresOcupados;
} Fila;

void insereinicio (Fila **inicio, Fila **novo){
	(*novo)->prox=*inicio;
	*inicio=(*novo);
}
void inserefim(Fila **ultimo, Fila **p){
	(*ultimo)->prox = *p;
	(*p)->prox = NULL;
	*ultimo = *p;
}
void removeinicio(){
	Fila *aux = *inicio;
	inicio=inicio->prox;
	free(aux);
}
void removefim(){
	Fila *auxp = *inicio;
	int aux = 1;
	while(aux == 1){
		if((*fim)->valor != (*auxp).valor){
		}else{
			(*atual)->prox = (*auxp).prox;
			(*auxp).prox = *atual;
			aux = 0;
		}
		
	}  //NAO TERMINADA// FAZER
}

void inserePrimeiraVez(Fila **inicioDaFila, Fila **fimDaFila, Fila **mesaAux){
	fimDaFilaNormal = mesaAux;
    inicioDaFila = mesaAux;
    inicioDaFila->prox = NULL;
    fimDaFila->prox = NULL;
}

void alocarMesa(Fila **inicioMesasOcupadas,
				Fila **mesasDisponiveis,
				Fila **inicioDasMesasDisponiveis,
				Fila **fimDasMesasDisponiveis,
				Fila **inicioDaFilaPrioritaria,
				Fila **inicioDaFilaNormal
				){
	if(mesasDisponiveis != NULL){
		removefim(&mesasDisponiveis);
		inserefim(, &fimDaFilaNormal);

		fimDaFilaNormal = mesaAux;
    	inicioDaFilaNormal = mesaAux;
        inicioDaFilaNormal->prox = NULL;
        fimDaFilaNormal->prox = NULL;

	}
}

main(){
	Fila *filaPrioritaria, *inicioDaFilaPrioritaria=NULL, *fimDaFilaPrioritaria=NULL,
		 *filaNormal, *inicioDaFilaNormal=NULL, *fimDaFilaNormal=NULL,
		 *mesasDisponiveis, *inicioDasMesasDisponiveis=NULL, *fimDasMesasDisponiveis=NULL,
		 *mesasOcupadas; *inicioDasMesasDisponiveis=NULL, *fimDasMesasDisponiveis=NULL;
	Fila *mesaAux = NULL;

	filaPrioritaria  = (Fila*)malloc(sizeof(Fila));
	filaNormal       = (Fila*)malloc(sizeof(Fila));
	mesasDisponiveis = (Fila*)malloc(sizeof(Fila));
	mesasOcupadas    = (Fila*)malloc(sizeof(Fila));

	printf("Restaurante Bem Servido.\nSeja Bem vindo.\n \n");

	int opcao = -1;
	while(opcao =! 0){
		
		printf("Escolha uma das opcoes a seguir: \n");
		printf("1 - Nova entrada\n");
		printf("2 - Vizualizar mesas\n");
		printf("3 - Vizualizar lista de espera\n");
		printf("4 - Desocupar mesa\n");
		printf("0 - Digite para sair \n");
		printf(":\n");

		scanf("%d",opcao);

		switch(opcao){
			case 1:
				printf("Digite qual a fila: \n");
				printf("1 - Normal \n");
				printf("2 - Prioritaria \n");
				printf(": \n");
				scanf("%d",opcao);
				switch(opcao);
					case 1:
						if(inicioDaFilaNormal == NULL) {
							int cond = 1;
							do{
								printf("Digite o número de pessoas esperando uma mesa: ");
								scanf("%d", &mesaAux->lugaresOcupados);
								if(mesaAux->lugaresOcupados => mesaAux->maxLugares){
									printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
								} else {
									cond = 0;
								}
							}while(cond);
				            fimDaFilaNormal = mesaAux;
				            inicioDaFilaNormal = mesaAux;
				            inicioDaFilaNormal->prox = NULL;
				            fimDaFilaNormal->prox = NULL;
				        } else {
				        	int cond = 1;
				        	do{
								printf("Digite o número de pessoas esperando uma mesa: ");
								scanf("%d", &mesaAux->lugaresOcupados);
								if(mesaAux->lugaresOcupados => mesaAux->maxLugares){
									printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
								} else {
									cond = 0;
								}
							}while(cond);
							inserefim(&fimDaFilaNormal, &mesaAux);
				        }
						break;
					case 2:
						if(inicioDaFilaPrioritaria == NULL) {
							int cond = 1;
							do{
								printf("Digite o número de pessoas esperando uma mesa: ");
								scanf("%d", &mesaAux->lugaresOcupados);
								if(mesaAux->lugaresOcupados => mesaAux->maxLugares){
									printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
								} else {
									cond = 0;
								}
							}while(cond);
				            fimDaFilaPrioritaria = mesaAux;
				            inicioDaFilaPrioritaria = mesaAux;
				            inicioDaFilaPrioritaria->prox = NULL;
				            fimDaFilaPrioritaria->prox = NULL;
				        } else {
				        	int cond = 1;
				        	do{
								printf("Digite o número de pessoas esperando uma mesa: ");
								scanf("%d", &mesaAux->lugaresOcupados);
								if(mesaAux->lugaresOcupados => mesaAux->maxLugares){
									printf("O maximo de lugares na mesa é: %d", mesaAux->maxLugares);
								} else {
									cond = 0;
								}
							}while(cond);
							inserefim(&fimDaFilaPrioritaria, &mesaAux);
				        }
						break;
				}
				opcao = -1;
				break;
			case 2:
				inserefim(&fimDaFilaNormal, &mesaAux);	
				break;
			case 3:
				
				break;
			case 4:

				break;
			default:
		}


	}




	scanf("%d", &pessoas);
	if (pessoas<listamesa->lugares){
		listamesa->lugares=pessoas;
	}else{
		F=(lfila*)malloc(sizeof(lfila));
		if(F){
			//Primeira vez
			if(inicio == NULL) {
				printf("Digite o número de pessoas esperando uma mesa: ");
				scanf("%d", &F->pessoas);
	            ultimofila = F;
	            iniciofila = F;
	            iniciofila->prox = NULL;
	        } else {    	
	        	//Restante das vezes
				printf(" Para inserir: \n[1]Se a houver pessoas com preferencia. \n [2]Se não houver. \n[0]Sair \n ESCOLHA: ");
				scanf("%d",&i);
				if(i!=0){
					printf("Digite o numero de pessoas esperando por uma mesa: ");
						
					switch(i){
						case 1:
						
						break;
						case 2:
							
						break;
					}		
				}
			}
		}
	}

		//M=(lmesa*)malloc(sizeof(lmesa))
}