#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 4.	Escreva um programa em C que leia uma seqüência de caracteres (no máximo 20 caracteres) e os armazene em uma pilha P1 e a imprima.
Em seguida crie uma segunda pilha P2 e chame uma função que receba P1 e P2 como parâmetros e copie para P2 os elementos de P1, de modo que P2 seja o inverso de P1.
Ao final desse procedimento a pilha P1 ficará vazia.
Imprima a pilha P2.
*/

typedef struct no{
	char seq;
	struct no *prox;
}Nodo;
int tam=0;

void Push(Nodo **Topo, Nodo **Base, char carac);
void P3(Nodo **Topo, Nodo **Base, Nodo **Topo2, Nodo **Base2);
void Imprimir(Nodo **Base);
void Zerar(Nodo **Base1);
Nodo *Pop(Nodo **Base, Nodo **Topo);

main(){
	Nodo *Topo = NULL,
         *Base = NULL,
         *Topo2 = NULL,
         *Base2 = NULL;
	int j=0, i=0, op;
	char caracteres[20], carac;

    do{
    printf("\nEcolha: \n\t[1]Inserir \n\t[2]Imprimir\n\t[3]Mover de P1 para P2\n\t[0]Sair\n\t\tOp:");
    scanf("%d", &op);
    switch(op){
    case 0:
        Zerar(&Base);
    break;
    case 1:
        printf("Digite os caracteres: ");
        fflush(stdin);
        gets(caracteres);
        fflush(stdin);
        j = strlen(caracteres);
        Zerar(&Base);
        Base = NULL;
        Topo = NULL;
        i = 0;
        do{
            carac = caracteres[i];
            Push(&Topo, &Base, carac);
            i++;
        }while(i!=j);
    break;
    case 2:
        printf("\nPilha[1]:");
            Imprimir(&Base);
        printf("\n\nPilha[2]:");
            Imprimir(&Base2);
    break;
    case 3:
        P3(&Topo, &Base, &Topo2, &Base2);
        Base = NULL;
        Topo = NULL;
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
        novo->seq = carac;
        novo->prox = NULL;
        if(*Base == NULL){
            *Base = novo;
            *Topo = *Base;
            tam++;
        }else{
            Aux = *Topo;
            Aux->prox = novo;
            *Topo = novo;
            tam++;
        }
    }else{
        printf("Memoria indisponivel!\n");
    }
}
void Imprimir(Nodo **Base){
	Nodo *Aux;
	int i = 1;

	if(*Base == NULL){
		printf("A pilha se encontra vazia!");
	}else{
		Aux = *Base;
		while(Aux != NULL){
			printf("\n\tAux->seq = %c \tAux[%d] = %d \tAux->prox = %d", Aux->seq, i, Aux, Aux->prox);
			Aux = Aux->prox;
			i++;
		}
	}
}
void P3(Nodo **Topo, Nodo **Base, Nodo **Topo2, Nodo **Base2){
    Nodo *AuxP1,
         *AuxP2,
         *Tmp;
    char caract;
    *Base2 = NULL;
    *Topo2 = NULL;
    if(*Base == NULL){
        printf("P1 esta vazia!");
    }else{
        while((*Base)->prox != NULL){
            Tmp = Pop(Base, Topo);
            caract = Tmp->seq;
            Push(Topo2, Base2, caract);
        }
        Tmp = Pop(Base, Topo);
        caract = Tmp->seq;
        Push(Topo2, Base2, caract);
    }
}
void Zerar(Nodo **Base1){
    Nodo *Prox, *Atual;
    if(*Base1 != NULL){
        Atual = *Base1;
        while(Atual != NULL){
        Prox = Atual->prox;
        free(Atual);
        Atual = Prox;
        }
    }
}
Nodo *Pop(Nodo **Base, Nodo **Topo){
	Nodo *Atual, *Anterior;
	if (*Base == NULL){
		printf("Lista encontra-se vazia. \n");
	}else if((*Base)->prox == NULL){
			return *Base;
    }else{
        Atual=(*Base)->prox;
        Anterior=*Base;
        while(Atual->prox!=NULL){
            Anterior=Atual;
            Atual=Atual->prox;
        }
        Anterior->prox=NULL;
        *Topo = Anterior;
        return Atual;
		}
	}

 /*     -----------------------------------------------------------------------------------------------------------
        while(UltimoP1 != *Base){
        UltimoP1 = (*Base)->prox;
        PenultimoP1 = *Base;
            while(UltimoP1->prox != NULL){
                PenultimoP1 = UltimoP1;
                UltimoP1 = UltimoP1->prox;
            }
            PenultimoP1->prox = NULL;

            if(*Base2 == NULL){------------------------------CODIGO
                *Base2 = UltimoP1;------------------------ALTERNATIVO
                *Topo2 = *Base2;-----------------------------PARA
            }else{------------------------------------------FUNCAO
                AuxP2 = *Topo2;-------------------------------P3
                AuxP2->prox = UltimoP1;
                *Topo2 = UltimoP1;
            }
            free(UltimoP1);
            UltimoP1 = PenultimoP1;
        }-----------------------------------------------------------------------------------------------------------
*/
