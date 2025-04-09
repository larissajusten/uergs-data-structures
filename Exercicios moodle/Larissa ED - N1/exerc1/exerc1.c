#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct
typedef struct senha{
    int senha;
    struct senha *prox;
}Node;
typedef struct paciente{
	
    int senha;
    char nome[18];
    char plano[18];
    int exame;
    struct paciente *prox;
}Nodo;

//chamamento das funções
int menu();
void opcoes(Nodo *ATENDIDOS, Node *FILA, int op);
void InserirFila(Node *FILA);
void CadastroPaciente(Nodo *ATENDIDOS, Node *FILA);

//main
main(){
    int a=1, op;
    Nodo *Unimed, *Aux, *Aux2;
    Node *FILA = (Node*)malloc(sizeof(Node));
    Nodo *ATENDIDOS = (Nodo*)malloc(sizeof(Nodo));
    FILA->prox=NULL;
    ATENDIDOS->prox=NULL;
    if(!ATENDIDOS){
        printf("Espaço de memoria indisponivel!");
    }else{
        while(a==1){
            InserirFila(FILA);
            printf("Para inserir a senha de atendimento [1], para atender o paciente [0]: ");
            scanf("%d", &a);
            if(a == 1){
	            InserirFila(FILA);
    		}else{
    			op=menu();
	    		opcoes(ATENDIDOS, FILA, op);
			}
        }
    }

    printf("\nLista dos pacientes atendidos.");
        if(ATENDIDOS->prox == NULL){
            printf("Nao ha nenhum paciente atendido!");
        }else{
            Aux2=ATENDIDOS->prox;
            while(Aux2 != NULL){
            	printf("\nO endereco do no e: %d",Aux2);
                printf("\n\nA senha do Paciente e: %d", Aux2->senha);
                printf("\nO nome do Paciente e: %s", Aux2->nome);
                printf("\nO plano do Paciente e: %s", Aux2->plano);
				if(Aux2->exame==1){
                    printf("\no exame que o Paciente realizou foi de sangue.");
                }else{
                    printf("\no exame que o Paciente realizou foi de imagem.");
                }
                Aux2 = Aux2->prox;
            }
        }

    printf("\n\nPacientes atendidos que possuem Unimed");
    
    	if(ATENDIDOS->prox == NULL){
            printf("\nNao ha nenhum paciente atendido!");
        }else{
	        Unimed = ATENDIDOS->prox;
	        while(Unimed != NULL){
	        	if(strcmp("Unimed",Unimed->plano)==0){
	        		printf("\nO enreco do no e: %d",Unimed);
		            printf("\nA senha do paciente e: %d",Unimed->senha);
		            printf("\nO nome do paciente e: %s",Unimed->nome);
		            if(Unimed->exame==1){
		                printf("\nO exame realizado pelo paciente foi de sangue.");
		            }else{
		                printf("\nO exame realizado pelo paciente foi de imagem.");
		            }
	           	}
	            Unimed = Unimed->prox;
	        }
	}


    printf("\n\nPacientes que fizeram exame de sangue");
    	if(ATENDIDOS->prox == NULL){
            printf("\nNao ha nenhum paciente atendido!");
        }else{
        	Aux = ATENDIDOS->prox;
            while(Aux != NULL){
	           	if(Aux->exame==1){
				    printf("\nO endereco do no e: %d",Aux);
	            	printf("\nA senha do paciente e: %d",Aux->senha);
	            	printf("\nO nome do paciente e: %s",Aux->nome);
	            	printf("\nO plano do  paciente e: %s",Aux->plano);
				}
            	Aux=Aux->prox;
            }
         }  
            
}

//funções
int menu(){
    int op;
    printf("\n[1]Cadastrar um novo paciente.\n");
    printf("[0]Sair\n");
    printf("A: ");
    scanf("%d",&op);
    fflush(stdin);
    return op;
}
void opcoes(Nodo *ATENDIDOS, Node *FILA, int op){
    switch(op){
    case 0:
       	break;
    case 1:
        CadastroPaciente(ATENDIDOS, FILA);
    	break;
    default:
        printf("A opcao escolhida nao existe! Tente novamente!");
    }
}
void InserirFila(Node *FILA){
    Node *aux;
    Node *novo = (Node*)malloc(sizeof(Node));
    printf("\nDigite sua senha (APENAS numeros): ");
    scanf("%d",&novo->senha);
    novo->prox = NULL;
    if(FILA->prox !=NULL){
        aux = FILA->prox;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
    	aux->prox = novo;
    }else{
        FILA->prox = novo;
    }
}
void CadastroPaciente(Nodo *ATENDIDOS, Node *FILA){
        Node *aux; //auxiliar para FILA
        Nodo *aux1; //auxiliar para LISTA

        Nodo *novo = (Nodo*)malloc(sizeof(Nodo));

        if(!novo){
            printf("Memoria indisponivel!");
            exit(1);
        }else{
            novo->prox=NULL;
            //passando senha da FILA para a LISTA
            aux = FILA->prox;
            novo->senha = aux->senha;
            FILA->prox = aux->prox;
            free(aux);
            //inserindo as informações

            printf("Digite o nome do Paciente:");
            gets(novo->nome);
            printf("\nDigite o plano de saude do paciente: [Unimed/Ipe] ");
            gets(novo->plano);
            printf("\nDigite o tipo de exame\n [1]Exame de sangue \n [2]Exame de imagem \nA: ");
            scanf("%d",&novo->exame);

                if(ATENDIDOS->prox !=NULL){
                   	aux1 = ATENDIDOS->prox;
                    while(aux1->prox!=NULL){
                        aux1=aux1->prox;
                    }
                    aux1->prox=novo;
                }else{
                    ATENDIDOS->prox = novo;
                }
        }
}
