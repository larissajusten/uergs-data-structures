#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
}; 
typedef struct Node node;

int tamanhoListaDeEspera;
int tamanhoMesasOcupadas;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFimListaDeEspera(node *LISTA, int val);
void insereInicioListaDeEspera(node *LISTA, int val);
void insereFimMesasOcupadas(node *LISTA, int val);
void insereInicioMesasOcupadas(node *LISTA, int val);
void exibeListaDeEspera(node *LISTA);
void exibeMesasOcupadas(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA, int val);
node *retiraInicioListaDeEspera(node *LISTA);
node *retiraInicioMesasOcupadas(node *LISTA);
node *retiraFimListaDeEspera(node *LISTA);
node *retiraFimMesasOcupadas(node *LISTA);
node *retiraListaDeEspera(node *LISTA);
node *retiraMesasOcupadas(node *LISTA);

int main(void)
{
	tamanhoListaDeEspera = 0;
	tamanhoMesasOcupadas = 0;
	node *mesasOcupadas = (node *) malloc(sizeof(node));
	node *listaDeEspera = (node *) malloc(sizeof(node));
	if(!listaDeEspera || !mesasOcupadas){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(mesasOcupadas);
	inicia(listaDeEspera);
	
	
	
	int maxMesas = 4;
	int qtdMesasDisponiveis = maxMesas;
	int codigoListaDeEspera = 1;
	int opt = 1;
	
	while(opt) {
		int opt, pss;
		printf("\n\nEscolha a opcao\n");
		printf("0. Sair\n");
		printf("1. Nova entrada\n");
		printf("2. Exibir mesas ocupadas\n");
		printf("3. Exibir lista de espera\n");
		printf("4. Desocupar mesa\n");
		printf("Opcao: "); scanf("%d", &opt);
		switch(opt){
			case 0:
				printf("\n\nAté logo!\n\n");
				system("pause");
				system("exit");
			case 1:
					if(qtdMesasDisponiveis < 1){
						printf("Existe alguem com necessidades especiais? 1 para sim ou 2 para nao\n");
						scanf("%d", &opt);
						switch(opt){
							case 1:
								printf("> Quantas pessoas?");scanf("> %d", &pss);
								insereInicioListaDeEspera(listaDeEspera, pss);
								break;
							case 2:
								printf("> Quantas pessoas?");scanf("> %d", &pss);
								insereFimListaDeEspera(listaDeEspera,  pss);
								break;
							default:
								break;
						}
					}else{
						printf("> Quantas pessoas? "); scanf("> %d", &pss);
						insereFimMesasOcupadas(mesasOcupadas, pss);
						qtdMesasDisponiveis--;
						printf("> Mesa movida para mesas ocupadas!");
					}
				break;
			case 2:
				exibeMesasOcupadas(mesasOcupadas);
				break;
			case 3:
				exibeListaDeEspera(listaDeEspera);
				break;
			case 4:
				retiraMesasOcupadas(mesasOcupadas);
				if(tamanhoListaDeEspera > 1){
					insereFimMesasOcupadas(mesasOcupadas, retiraInicioListaDeEspera(listaDeEspera)->num);
					printf("> Primeira mesa da lista de espera movida para mesas ocupadas!");
				}else{
					printf("> Uma mesa a mais está vaga porem não há ninguem na lista de espera!");
				}
				
				break;
			default:
				printf("\n\nEste comando não é valido!\n\n");
		}
	}

	free(mesasOcupadas);
	free(listaDeEspera);
	return 0;
	}
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

node *aloca(int value)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		novo->num = value;
		return novo;
	}
}


void insereFimMesasOcupadas(node *LISTA, int value)
{
	node *novo=aloca(value);
	novo->prox = NULL;
	
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
	tamanhoMesasOcupadas++;
}
void insereFimListaDeEspera(node *LISTA, int value)
{
	node *novo=aloca(value);
	novo->prox = NULL;
	
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
	tamanhoListaDeEspera++;
}

void insereInicioListaDeEspera(node *LISTA, int value)
{
	node *novo=aloca(value);	
	node *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->prox = oldHead;
	
	tamanhoListaDeEspera++;
}
void insereInicioMesasOcupadas(node *LISTA, int value)
{
	node *novo=aloca(value);	
	node *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->prox = oldHead;
	
	tamanhoMesasOcupadas++;
}

void exibeListaDeEspera(node *LISTA)
{
	system("cls");
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tamanhoListaDeEspera ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tamanhoListaDeEspera ; count++)
		printf("%5d", count+1);
	
		
	printf("\n\n");
}
void exibeMesasOcupadas(node *LISTA)
{
	system("cls");
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tamanhoMesasOcupadas ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tamanhoMesasOcupadas ; count++)
		printf("%5d", count+1);
	
		
	printf("\n\n");
}
void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

node *retiraInicioListaDeEspera(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja esta vazia\n");
		return NULL;
	}else{
		node *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		tamanhoListaDeEspera--;
		return tmp;
	}
				
}
node *retiraInicioMesasOcupadas(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja esta vazia\n");
		return NULL;
	}else{
		node *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		tamanhoMesasOcupadas--;
		return tmp;
	}
				
}

node *retiraFimListaDeEspera(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja vazia\n\n");
		return NULL;
	}else{
		node *ultimo = LISTA->prox,
			 *penultimo = LISTA;
			 
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
			 
		penultimo->prox = NULL;
		tamanhoListaDeEspera--;
		return ultimo;		
	}
}
node *retiraFimMesasOcupadas(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja vazia\n\n");
		return NULL;
	}else{
		node *ultimo = LISTA->prox,
			 *penultimo = LISTA;
			 
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
			 
		penultimo->prox = NULL;
		tamanhoMesasOcupadas--;
		return ultimo;		
	}
}
node *retiraListaDeEspera(node *LISTA)
{
	int opt,
		count;
	
	printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tamanhoListaDeEspera);
	scanf("%d", &opt);
	
	if(opt>0 && opt <= tamanhoListaDeEspera){
		if(opt==1)
			return retiraInicioListaDeEspera(LISTA);
		else{
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
				 
			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}
			
		anterior->prox=atual->prox;
		tamanhoListaDeEspera--;
		return atual;
		}
			
	}else{
		printf("Elemento invalido\n\n");
		return NULL;
	}
}
node *retiraMesasOcupadas(node *LISTA)
{
	int opt,
		count;
	exibeMesasOcupadas(LISTA);
	printf("Qual das mesas acima você deseja retirar, [de 1 ate %d] voce deseja retirar: ", tamanhoMesasOcupadas);
	scanf("%d", &opt);
	
	if(opt>0 && opt <= tamanhoMesasOcupadas){
		if(opt==1)
			return retiraInicioMesasOcupadas(LISTA);
		else{
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
				 
			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}
			
		anterior->prox=atual->prox;
		tamanhoMesasOcupadas--;
		return atual;
		}
			
	}else{
		printf("Elemento invalido\n\n");
		return NULL;
	}
}
