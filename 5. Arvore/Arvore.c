#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------------------
-------------------------------ARVORES----modelo ----------------------------------------
---------------------------------Larissa Espelocin J---------------------------------------
-------------------------------Estrutura de Dados 2017/1-----------------------------------
-------------------------------------------------------------------------------------------*/

typedef struct Arvore{
    int num;
    struct Nodo *esq;
    struct Nodo *dir;
}Nodo;
int Nivel;


main(){
    Nodo *Raiz = NULL;
    int op;

    do{
        printf("Escolha:\n");
        printf("\t{1}Adicionar folha\n"); //Inserir no
        printf("\t{2}Ver Arvore\n"); //Imprimir
        printf("\t{0}Sair\n");
        printf("Op: ");
        scanf("%d", &op);

        switch(op){
        case 0:
            return 0;
            break;
        case 1:
            Inserir(&Raiz);
            break:
        case 2:
            Imprimir(&Raiz);
            break;
        default:
            printf("Op indisponivel! Tente novamente.\n");
            break;
        }
    }while(op!=0);
}

void Inserir(Nodo **Raiz){
    Nodo *Aux;
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));

    if(novo){
        printf("Digite o numero a ser inserido: ");
        scanf("%d", &novo->num);
        novo->esq = NULL;
        novo->dir = NULL;

        if(Raiz==NULL){
            Raiz = novo;
        }else{
            Aux = Raiz;
            if(Aux->esq != NULL && grau != 2){
                Aux->esq = novo;
            }
        }
    }else{
        printf("Memoria indisponivel!");
    }
}

void Imprimir(Nodo **Raiz){


}


