#include <stdio.h>
#include <stdlib.h>

/* 4.	Escreva um programa em C que leia uma seqüência de caracteres (no máximo 20 caracteres) e os armazene em uma pilha P1 e a imprima.
Em seguida crie uma segunda pilha P2 e chame uma função que receba P1 e P2 como parâmetros e copie para P2 os elementos de P1, de modo que P2 seja o inverso de P1.
Ao final desse procedimento a pilha P1 ficará vazia.
Imprima a pilha P2.
*/

typedef struct no{
	char seq;
	struct no *prox;
}Nodo;

void Push(Nodo **Topo, Nodo **Base, char carac);
void Imprimir(Nodo **Base);
void P3(Nodo **Topo, Nodo **Base, Nodo **Topo2, Nodo **Base2);

main(){
	Nodo *Topo = NULL;
	Nodo *Base = NULL;
	Nodo *Topo2 = NULL;
	Nodo *Base2 = NULL;
	Nodo *Aux;
    Nodo *Anterior;

	int j=0, i=0, op;
	char caracteres[20], carac;

	do{
    printf("\nDigite:\n\t[1]Inserir \n\t[2]Imprimir\n\t[3]Mover de P1 para P2\n\t[0]Sair\n\t\tOp:");
    scanf("%d", &op);
    switch(op){
    case 1:
        printf("Digite 20 caracteres: \n");
        fflush(stdin);
        j = 1;
        printf("{%d}:",j);
        while(j!=20){
            scanf("%c", &caracteres[j]);
            j++;
        }
        printf("j = %d\n", j);
        do{
            carac = caracteres[j];
            Push(&Topo, &Base, carac);
            j--;
        }while(j!=0);
        if(j==0){
            fflush(stdin);
            break;
        }
    case 2:
        printf("\nPilha[1]:");
            Imprimir(&Base);
        printf("\nPilha[2]:");
            Imprimir(&Base2);
    break;
    case 3:
        P3(&Topo, &Base, &Topo2, &Base2);
    break;
    default:
        printf("Op invalida!");
        break;
    }
    }while(op!=0);
}

void Push(Nodo **Topo, Nodo **Base, char carac){
	Nodo *Aux;
	Nodo *novo = (Nodo*)malloc(sizeof(Nodo));

	if(novo){
		novo->prox = NULL;
		novo->seq = carac;
	}else{
		printf("Memoria indisponivel \n");
	}

	if(*Base == NULL){
		*Base = novo;
		*Topo = novo;
	}else{
	    Aux = *Topo;
	    Aux->prox = novo;
		*Topo = novo;
	}
}
void Imprimir(Nodo **Base){
	Nodo *Aux;
    int i=0;

	if(*Base == NULL){
		printf("A pilha se encontra vazia!\n");
	}else{
		Aux = *Base;
		while(Aux != NULL){
			printf("\n\tAux[%d]->caracter = %c\tAux = %d\tAux->prox = %d",i, Aux->seq, Aux, Aux->prox);
			Aux = Aux->prox;
			i++;
		}
	}
}
void P3(Nodo **Topo, Nodo **Base, Nodo **Topo2, Nodo **Base2){
    Nodo *AuxP1, *PenultimoP1, *UltimoP1;
    Nodo *AuxP2;

    if(*Base == NULL){
        printf("P1 esta vazia!");
    }else{
        while(UltimoP1 != *Base){
        UltimoP1 = (*Base)->prox;
        PenultimoP1 = *Base;
            while(UltimoP1->prox != NULL){
                PenultimoP1 = UltimoP1;
                UltimoP1 = UltimoP1->prox;
            }
            PenultimoP1->prox = NULL;

            if(*Base2 == NULL){
                *Base2 = UltimoP1;
                *Topo2 = *Base2;
            }else{
                AuxP2 = *Topo2;
                AuxP2->prox = UltimoP1;
                *Topo2 = UltimoP1;
            }
            free(UltimoP1);
            UltimoP1 = PenultimoP1;
        }
        }
    }

