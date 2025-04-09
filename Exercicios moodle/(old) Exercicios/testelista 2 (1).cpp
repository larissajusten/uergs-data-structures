#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int cod;
	float peso;
	struct nodo *prox;
} boi;

main() {
//	struct nodo *inicio=NULL, *novo, *p;
	boi *inicio=NULL, *novo, *p;
	int continua=1;
	int codigo=0;
	while (continua==1) {
//		boi=(struct nodo *) malloc (sizeof(struct nodo));
		novo=(boi *) malloc(sizeof(boi));	//insere bois no final da lista
		if (novo) {
			novo->prox=NULL;
			printf ("\nDigite o codigo do boi: ");
			scanf ("%d",&novo->cod);
			printf ("\nDigite o peso do boi: ");
			scanf ("%f",&novo->peso);
//			novo->cod=codigo++;
			if (inicio==NULL) {
				inicio=novo;
			}
			else {
				p=inicio;
			}
			while (p!=NULL) {
				if (p->prox==NULL) {
					p->prox=novo;
					p=NULL;
				}
				else {
				p=p->prox;
				}
			}
			printf ("\nDeseja continuar? [1] SIM. 	[OUTRO NUMERO] NAO. \n");
			scanf ("%d",&continua);		//fim while insere
		}
	}
	if (inicio==NULL) {
		printf ("Lista vazia. ");
	}
	else {		//lista tudo
		p=inicio;
		while (p!=NULL) {
			printf ("\nCodigo= %d.", p->cod);
			printf ("\nPeso= %.2f.\n", p->peso);
			p=p->prox; 
		}
	}
/*	int cod,i=0;
	printf("\nDigite o codigo do boi: ");
	scanf("%d",&cod);
	while (boi!=NULL){
		if(boi->cod==cod){
			printf("Peso: %.2f",boi->peso);
			boi=NULL;
			i=1;
		}
		else{
			boi=boi->prox;
		}
	}
	if(i=0){
		printf("Se fudeu, doidao.");
	} */
}
