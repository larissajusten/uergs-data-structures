#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int valor;
	struct nodo *prox;
}lista;

void insereinicio (int val, lista **ini, lista *novo){
	novo->prox=(*ini);
	(*ini)=novo;
	novo->valor=val;
}

void inseremeio (){
	
} 

void inserefim(int val, lista **novo, lista *ultimo){
	(*novo)->prox=NULL;
	ultimo=novo;
	(*novo)->valor=val;
	(*novo)->prox=NULL;
}

main() {
	lista *P, *inicio=NULL;
	lista *ultimo=NULL;
	int num, aux=0;
	int i,e=1;
		while(e!=0){
		printf("Digite um valor para inserir");
		scanf("%d",&num);
		P=(lista*)malloc(sizeof(lista));
		printf("[1] Para inserir no incio \n [2] Para inserir no meio \n [3] Para inserir no fim \n [0]Sair");
		scanf("%d",&e);
		switch(e){
			case 1: 
				insereinicio(num, &inicio, P);
				break;
			case 2:
				break;
			case 3:
				if(P!=NULL){
					P=P->prox;	
				}
				else {
					inserefim(num, ultimo, P);
				}
					break;
			}
	
		}
		
	if(inicio==NULL){
        printf("lista vazia");
    } 
	else {
		aux=inicio;
        while(aux!=NULL){
            printf("valor=%d",inicio->valor);
            aux=inicio->prox;
        }
	}
}


