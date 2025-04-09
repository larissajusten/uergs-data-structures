#include <stdio.h>
#include <stdlib.h>

//Struct
typedef struct contas{
	int cod;
	int dia, mes, ano;
	float valor;
	struct contas *prox;
}nox;
typedef struct pagas{
	int cod;
	int dia, mes, ano;
	int diap, mesp, anop;
	float valor;
	struct pagas *prox;
}noy;
//Chamando as funções
int menu();
void opcoes(nox *FContas, noy *PPagas, int op);
void insere(nox *FContas);
void remove(nox *FContas);
void cadastra(noy *PPagas);
void vtpagas(noy *PPagas);
void listar(nox *FContas);
void maiorconta(nox *FContas);
//Main
int main(){
	int op;
	nox *FContas=(nox*)malloc(sizeof(nox));
	noy *PPagas=(noy*)malloc(sizeof(noy));
	if(!FContas){
		printf("Memoria indisponivel");
		exit(1);
	}
	if(!PPagas){
		printf("Memoria indisponivel");
		exit(1);
	}
	do{
		op=menu();
		opcoes(FContas,PPagas,op);
	}while(op>0 && op<=6);
	free(FContas);
	free(PPagas);
	return 0;
}
//Funções
int menu(){
	int op;
	printf("[0]Sair. \n");
	printf("[1]Inserir conta. \n");
	printf("[2]Mover conta paga. \n");
	printf("[3]Valor total de contas pagas. \n");
	printf("[4]Listar contas a pagar. \n");
	printf("[5]Listar informações das contas ainda a pagar. \n");
	printf("[6]Conta com maior valor a ser paga. \n");
	scanf("%d", &op);
	return op;
}
void opcoes(nox *FContas, noy *PPagas, int op){
	
	switch(op){
		case 1:
			insere(FContas);
			break;
		case 2:
			remove(FContas);
			break;
		case 3:
			vtpagas(PPagas);
			break;
		case 4:
			cadastra(PPagas);
			break;
		case 5:
			listar(FContas);
			break;
		case 6:
			maiorconta(FContas);
			break;
		default:
			printf("Comando invalido \n");
	}
}
//Cadastra conta(s) a ser(em) paga(s)
void insere(nox *FContas){
	nox *novo=(nox *)malloc(sizeof(nox));
	nox *Aux;

	if(FContas->prox==NULL){
		printf("Digite o codigo da conta: \n");
		scanf("%d",&novo->cod);
		printf("Digite a data de vencimento da conta [dd mm aa]: \n");
		scanf("%d %d %d", &novo->dia, &novo->mes, &novo->ano);
		printf("Digite o valor da conta: \n");
		scanf("%f", &novo->valor);
		FContas->prox=novo;
	}
	else{
		Aux=FContas->prox;
		while(Aux->prox!=NULL){
			Aux=Aux->prox;
		}
		printf("Digite o codigo da conta: \n");
		scanf("%d",&novo->cod);
		printf("Digite a data de vencimento da conta [dd mm aa]: \n");
		scanf("%d %d %d", &novo->dia, &novo->mes, &novo->ano);
		printf("Digite o valor da conta: \n");
		scanf("%f", &novo->valor);
		Aux->prox=novo;
	}
}
//Remove conta(s) a ser(em) paga(s)
void remove(nox *FContas){
	int dia, mes, ano, g=1;
	nox *Aux=FContas->prox;

	while(g==1){
		printf("Digite a data da conta que deseja remover: \n");
		scanf("%d %d %d", &dia, &mes, &ano);
		while(Aux->prox!=NULL){
			if(Aux->ano==ano){
				if(Aux->mes==mes){
					if(Aux->dia==dia){
						free(Aux);
						printf("Conta removida com sucesso. \n");
					}else{
						Aux=Aux->prox;
					}
				}else{
					Aux=Aux->prox;
				}
			}else{
				Aux=Aux->prox;
			}
		}
		printf("Nao ha conta a ser removida no dia digitado. \n");
		printf("Digite [1] para remover outra conta e [0] para sair. ");
		scanf("%d", &g);
	}
} 
//Cadastra conta(s) paga(s)
void cadastra(noy *PPagas){
	noy *Aux;
	noy *novo=(noy *)malloc(sizeof(noy));

	if(PPagas->prox==NULL){
		printf("Digite o codigo da conta: \n");
		scanf("%d",&novo->cod);
		printf("Digite a data de vencimento da conta [dd mm aa]: \n");
		scanf("%d %d %d", &novo->dia, &novo->mes, &novo->ano);
		printf("Digite a data de pagamento da conta [dd mm aa]: \n");
		scanf("%d %d %d", &novo->diap, &novo->mesp, &novo->anop);
		printf("Digite o valor da conta: \n");
		scanf("%f", &novo->valor);
		PPagas->prox=novo;
	}else{
		Aux=FContas->prox;
		while(Aux->prox!=NULL){
			Aux=Aux->prox;
		}
		printf("Digite o codigo da conta: \n");
		scanf("%d",&novo->cod);
		printf("Digite a data de vencimento da conta [dd mm aa]: \n");
		scanf("%d %d %d", &novo->dia, &novo->mes, &novo->ano);
		printf("Digite a data de pagamento da conta [dd mm aa]: \n");
		scanf("%d %d %d", &novo->diap, &novo->mesp, &novo->anop);
		printf("Digite o valor da conta: \n");
		scanf("%f", &novo->valor);
		Aux->prox=novo;
	}
}
//Valor total de contas pagas
void vtpagas(noy *PPagas){
	float vtotal=0;
	noy *Aux;

	if(PPagas->prox==NULL){
		printf("Nao ha nenhuma conta paga. \n");
	}
	else{
		Aux=PPagas->prox;
		while(Aux->prox!=NULL){
			vtotal = vtotal + Aux->valor;
			Aux=Aux->prox;
		}
		vtotal = vtotal + Aux->valor;
		printf("Valor total de contas pagas: %2.f \n", vtotal);
	}
}
//Listar informações das contas ainda a pagar
void listar(nox *FContas){
	int a=1;
	nox *Aux;

	if(FContas->prox==NULL){
		printf("Nao ha contas a pagar. \n");
	}
	else{
		Aux=FContas->prox;
		while(Aux->prox!=NULL){
			printf("Conta [%d]:\n",a);
			printf("O codigo da conta [%d]: %d.\n", a, Aux->cod);
			printf("A data de pagamento da conta [%d]: %d/%d/%d",a, Aux->dia, Aux->mes, Aux->ano);
			printf("O Valor da conta [%d] a ser pago: %2.f", a, Aux->valor);
			a++;
			Aux=Aux->prox;
		}
		printf("Conta [%d]:\n",a);
		printf("O codigo da conta [%d]: %d.\n", a, Aux->cod);
		printf("A data de pagamento da conta [%d]: %d/%d/%d",a, Aux->dia, Aux->mes, Aux->ano);
		printf("O Valor da conta [%d] a ser pago: %2.f", a, Aux->valor);
	}
}
//Conta com o maior valor a ser paga
void maiorconta(nox *FContas){
	float tmp;
	nox *Aux;
	nox *Aux2;

	if(FContas->prox==NULL){
		printf("Nao ha contas a serem pagas.");
	}
	else{
		Aux=FContas->prox;
		while(Aux->prox!=NULL){
			Aux2=Aux->prox;
			if(Aux->valor >= Aux2->valor){
				tmp=Aux->valor;
				Aux=Aux2;
			}
			else{
				tmp=Aux->valor;
				Aux=Aux2;
			}
		}
	}
	printf("O maior valor de conta ainda nao pago e: %2.f", tmp);
}