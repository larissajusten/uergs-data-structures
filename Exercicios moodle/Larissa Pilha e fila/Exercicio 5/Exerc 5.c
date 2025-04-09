#include <stdio.h>
#include <stdlib.h>

/*5.	Crie uma pilha (pilha1) e peça ao usuário para dizer qual elemento da pilha deve ser removido.
Caso seja o último que foi inserido, apresente a pilha impressa.
Caso o elemento que se deseja excluir não seja o último, crie uma nova pilha(pilha2), desempilhe os elementos pilha 1 para a pilha 2,
até que chegue ao elemento que se desejou desempilhar.
Neste momento imprima as duas pilhas.
Posteriormente, volte a pilha 1, sendo que os elementos da pilha 2, devam ser novamente empilhados para a pilha 1.
*/

typedef struct pilha{
    char elemento;
    struct pilha *prox;
}Nodo;
int tam;

Nodo *Pop(Nodo **Base, Nodo **Topo);
void Zerar(Nodo **Base1);
void Imprimir(Nodo **Base);
void Push(Nodo **Topo, Nodo **Base, char elem);
void P3(Nodo **Topo, Nodo **Base, Nodo **Topo1, Nodo **Base1, char retirado);

main(){
    Nodo *Topo = NULL;
    Nodo *Base = NULL;
    Nodo *Topo1 = NULL;
    Nodo *Base1 = NULL;
    int op;
    char elem, retirado;

    do{
        printf("Escolha: \n\t{1}Inserir na pilha\n\t{2}Retirar por elemento\n\t{3}Imprimir\n\t{9}Zerar\n\t{0}Sair\nOp:");
        scanf("%d", &op);
        switch(op){
        case 0:
            Zerar(&Base);
            Zerar(&Base1);
        break;
        case 1:
            printf("Digite o elemento a ser inserido: ");
            fflush(stdin);
            scanf("%c", &elem);
            Push(&Topo, &Base, elem);
        break;
        case 2:
            printf("Digite o elemento a ser retirado: ");
            fflush(stdin);
            scanf("%c", &retirado);
            if(Topo->elemento == retirado){
                Imprimir(&Base);
            }else{
                P3(&Topo, &Base, &Topo1, &Base1, retirado);
            }
        break;
        case 3:
            printf("\nPilha[1]: \n");
            printf("\n\tBase->elemento = %c \tBase = %d \tBase->prox = %d", Base->elemento, Base, Base->prox);
            Imprimir(&Base);
            printf("\nPilha[2]: \n");
            Imprimir(&Base1);
        break;
        case 9:
            Zerar(&Base);
            Zerar(&Base1);
        break;
        default:
            printf("Op invalida!");
        }
    }while(op != 0);
}
void Push(Nodo **Topo, Nodo **Base, char elem){
    Nodo *Aux;
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));

    if(novo){
        novo->elemento = elem;
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
	Nodo *Aux = NULL;
	int i = 1;

	if(*Base == NULL){
		printf("A pilha se encontra vazia!");
	}else{
		Aux = *Base;
		while(Aux != NULL){
			printf("\n\tAux->elemento = %s \tAux[%d] = %d \tAux->prox = %d", Aux->elemento, i, Aux, Aux->prox);
			Aux = Aux->prox;
			i++;
		}
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

void P3(Nodo **Topo, Nodo **Base, Nodo **Topo1, Nodo **Base1, char retirado){
    Nodo *Tmp;
    char caract;

    if(*Base == NULL){
        printf("P1 esta vazia!");
    }else{
            while(Tmp->elemento != retirado && (*Base)->prox !=  NULL){
                Tmp = Pop(Base, Topo);
                caract = Tmp->elemento;
                Push(Topo1, Base1, caract);
            }
        if((*Base)->prox == NULL){
            if((*Base)->elemento != retirado){
                Tmp = Pop(Base, Topo);
                caract = Tmp->elemento;
                Push(Topo1, Base1, caract);
            }else{
                printf("\nPilha[1]: \n");
                Imprimir(Base);
                printf("\nPilha[2]: \n");
                Imprimir(Base1);
            }
        }
        printf("\nPilha[1]: \n");
        Imprimir(Base);
        printf("\nPilha[2]: \n");
        Imprimir(Base1);
    }
}
