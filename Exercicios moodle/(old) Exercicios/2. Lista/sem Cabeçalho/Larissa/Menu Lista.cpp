#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int valor;
	struct nodo *prox;
}lista;

void insereinicio (int val, int *lista, lista *novo){
	novo->prox=ini;
	ini=novo;
	novo->valor=val;
}

main() {
	lista *P, *inicio=NULL;
	int num;
	int i;
	for(i=0;i<10;i++){
		printf("Digite um valor para inserir");
		scanf("%d",&num);
		P=(listar) malloc(sizeof(lista));
		insereinicio(num, inicio, P);
	}
}


