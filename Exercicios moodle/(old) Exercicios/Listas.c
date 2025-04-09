#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
}no;

int main(){
    int op;
    no *Aux = NULL;
    no *Aux1 = NULL;
    no *Aux2 = NULL;
    no *novo = (no*)malloc(sizeof(no));
    no *LISTA = (no*)malloc(sizeof(no));
    if(!LISTA){
        printf("Nao ha espaco de memoria disponivel!");
        exit(1);
    }else{
    LISTA->num=NULL;
    do{
        printf("[1]Inserir no fim da lista.\n");
        printf("[2]Imprimir lista.\n");
        printf("[0]Sair.\n");
        printf("A: ");
        scanf("%d",&op);
        fflush(stdin);
        switch(op){
            case 0:
            Aux = LISTA->prox;
            free(LISTA);
            while(Aux!=NULL){
                Aux1=Aux->prox;
                free(Aux);
                Aux=Aux1;
                free(Aux1);
            }
            free(Aux);
            break;
            case 1:
            if(LISTA->num==NULL){
                printf("Digite o numero: ");
                scanf("%d",&LISTA->num);
                LISTA->prox=NULL;
            }else{
                if(LISTA->prox==NULL){
                    printf("Digite o numero: ");
                    scanf("%d",&novo->num);
                    novo->prox=NULL;
                    LISTA->prox=novo;
                    printf("Num: %d End proximo: %d End: %d\n",LISTA->prox->num, LISTA->prox->prox, LISTA);
                }else{
                    Aux=LISTA->prox;
                    while(Aux->prox!=NULL){
                        Aux=Aux->prox;
                    }
                    printf("Digite o numero: ");
                    scanf("%d",&novo->num);
                    Aux->prox=novo;
                }
                printf("Num: %d End proximo: %d End: %d\n",Aux->num, Aux->prox, Aux);
                novo->num = NULL;
                novo->prox = NULL;
                Aux = NULL;
            }
            break;
            case 2:
            if(LISTA->num==NULL){
                printf("A lista esta vazia!");
            }else{
                if(LISTA->prox==NULL){
                    printf("Num: %d Endereco: %d End proximo: %d\n",LISTA->num, LISTA, LISTA->prox);
                    printf("Aqui1");
                }else{
                    printf("Aqui2\n");
                    Aux2=LISTA->prox;
                    while(Aux2->prox!=NULL){
                        printf("Aqui3");
                        printf("Num: %d End proximo: %d End: %d\n",Aux2->num, Aux2->prox, Aux2);
                        Aux2=Aux2->prox;
                    }
                    printf("Num: %d End proximo:: %d End: %d\n",LISTA->num, LISTA->prox, LISTA);

                }
            }
            break;
            default:
            printf("Op invalida!");
        }
    }while(op>=1 && op<=2);
    }
}
