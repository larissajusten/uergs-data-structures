#include <stdio.h>
#include <stdlib.h>

//struct - PILHA; FIMPAR; FPAR.
typedef struct Nodo {
    int num;
    struct no *prox;
}no;
//Chamando as funções
int menu(void);
int opcao(no *PILHA, int opt);
int inicia(no *auxnodo);
void push(no *PILHA);
void pop(no *PILHA);
no *ultnode(no *PILHA);
void fila(int var);
no *aloca();
//Main
main(){
    int opt;
    no *PILHA = (no *)malloc(sizeof(no));

    if(!PILHA){
        printf("Memoria indisponivel! Tente novamente mais tarde.");
        exit(1);
    }
    else {
        inicia(PILHA);
        do{
            opt=menu();
            opcao(PILHA, opt);
        }while(opt>=0);
    }
    free(PILHA);
    return 0;
}
//Funções
int menu(void){
    int opt;
    printf("Escolha uma das seguintes opcoes: \n");
    printf("[0]Sair");
    printf("[1]Inserir");
    printf("[2]Retirar");
    scanf("%d", &opt);
    return opt;
}
int opcao(no *PILHA, int opt){
    if(opt=0){
        return 5;
    }
    else{
       switch(opt){
            case 1:
                push(PILHA);
                break;
            case 2:
                pop(PILHA);
                break;
            default:
                printf("Comando invalido!");
       }
    }
}
int inicia(no *auxnodo){
    if(auxnodo->prox==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//Inserir
void push(no *PILHA){
    int num;
    no *Aux2;
    no *Tmp;

    while(num!=0){
    printf("Digite um numero: [0]Para parar de digitar");
    scanf("%d",&num);
        if(PILHA->prox==NULL){
            PILHA->num = num;
            PILHA->prox = Tmp;
            push(PILHA);
            }
        else{
        	Tmp=ultnode(PILHA);
        	Tmp->num = num;
        	Tmp->prox = Tmp;
            }
    }
}
//Retirar
void pop(no *PILHA){
    int var;
    no *Aux3;

    if(PILHA->prox==NULL){
        printf("Pilha vazia!");
    }
    else{
        Aux3=ultnode(PILHA);
        var=Aux3->num;
        free(Aux3);
        fila(var);
    }
}
//Retorna ultimo no da PILHA
no *ultnode(no *PILHA){
    no *Aux;

    if(PILHA->prox!=NULL){
        Aux=PILHA->prox;
        while(Aux->prox!=NULL){
            Aux=Aux->prox;
        }
        return Aux;
    }
}
//Colocar na FILA
void fila(int var){
    no *FPAR = (no *)malloc(sizeof(no));
    no *FIMPAR = (no *)malloc(sizeof(no));
    //LISTA PAR
    if(!FPAR){
        printf("Memoria indisponivel!");
        exit(1);
    }
    else {
        inicia(FPAR); }
    //LISTA IMPAR
    if(!FIMPAR){
        printf("Memoria indisponivel");
        exit(1);
    }
    else {
        inicia(FIMPAR); }
    //Verificação do número
    no *novo=aloca();
    no *Aux4;
    no *Aux5;

    if(var%2==0){
    	if(FPAR->prox==NULL){
    		FPAR->prox=novo;
    		novo->num=var;
    		novo->prox=NULL;
    	}
    	else{
    		Aux4=FPAR->prox;
    		while(Aux4->prox!=NULL){
    			Aux4=Aux4->prox;
    		}
    		Aux4->prox=novo;
    		novo->num=var;
    		novo->prox=NULL;
    	}
    }
    else{
    	if(FIMPAR->prox==NULL){
    		FIMPAR->prox=novo;
    		novo->num=var;
    		novo->prox=NULL;
    	}
    	else{
    		Aux5=FIMPAR->prox;
    		while(Aux5->prox!=NULL){
    			Aux5=Aux5->prox;
    		}
    		Aux5->prox=novo;
    		novo->num=var;
    		novo->prox=NULL;
    	}

    }
}
//Alocar memória
no *aloca(){
    no *novo=(no *)malloc(sizeof(no));
    if(!novo){
        printf("Nao foi possivel localizar um espaco de memoria");
        exit(1);
    }
    else{
        return novo;
    }
}