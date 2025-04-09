#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int dados;
	struct lista*anterior;
}nodo;

void insere_fim(nodo**inicio,nodo**fim,int valor)
{
	nodo*p;
	p=(nodo*)malloc(sizeof(nodo));
	if(p)
	{
		p->dados=valor;
		p->anterior=*fim;
		*fim=p;
	}
}

void insere_inicio(nodo**inicio,nodo**fim,int valor)
{
	nodo*aux2;
	nodo*p;	
	aux2=*fim;	
	while(aux2->anterior!=NULL)
	{
		aux2=aux2->anterior;
	}
	if(aux2->anterior==NULL)
	{
		p=(nodo*)malloc(sizeof(nodo));
		if(p)
		{
			aux2->anterior=p;
			p->dados=valor;
			p->anterior=NULL;
			*inicio=p;
		}
	}
}
/*
void insere_meio()
{
		nodo*aux2;
	nodo*p;
	aux2=(nodo*)malloc(sizeof(nodo));
	if(aux2)
	{
		aux2=fim;
		while(aux2!=NULL&&aux2->dados!=local)
		{
			aux2=aux2->anterior;
		}
		if(aux2->dados==local)
		{
			p=(nodo*)malloc(sizeof(nodo));
			if(p)
			{
				p->dados=valor;
				p->anterior=fim;
				fim=p;
			}
		}
	}
	else
	{
		printf("Local nao encontrado");
	}
}
*/
int main()
{

	int opcao,valor,local;
	char imp;
	nodo*fim=NULL;
	nodo*inicio=NULL;
	nodo*aux=NULL;
	//inserindo primeiros valores na lista
	fim=(nodo*)malloc(sizeof(nodo));
	if(fim)
	{
		fim->dados=1;
		fim->anterior=NULL;
		inicio=fim;
	}
	aux=(nodo*)malloc(sizeof(nodo));
	if(aux)
	{
		aux->dados=2;
		aux->anterior=fim;
		fim=aux;
	}
	aux=(nodo*)malloc(sizeof(nodo));
	if(aux)
	{
		aux->dados=3;
		aux->anterior=fim;
		fim=aux;
	}
	aux=(nodo*)malloc(sizeof(nodo));
	if(aux)
	{
		aux->dados=4;
		aux->anterior=fim;
		fim=aux;
	}
	aux=(nodo*)malloc(sizeof(nodo));
	{
		aux->dados=5;
		aux->anterior=fim;
		fim=aux;
	}
	//a partir de agora, o usuario que insere os valores na lista
	printf("\t----------MENU----------\n");
	printf("\t1 - Inserir no inicio;\n");
	printf("\t2 - Inserir no meio;\n");
	printf("\t3 - Inserir no fim;\n");
	printf("\t\n\nSelecione uma opcao: ");
	scanf("%d",&opcao);
	switch(opcao)
	{
		case 1:
			printf("\n\nDigite o valor a ser inserido: ");
			scanf("%d",&valor);
			insere_inicio(&inicio,&fim,valor);
			aux=inicio;
			printf("\n\nDado do inicio: %d",aux->dados);
			break;
		/*case 2:
			break;*/
		case 3:
			printf("\n\nDigite o valor a ser inserido: ");
			scanf("%d",&valor);
			insere_fim(&inicio,&fim,valor);
			aux=fim;
			printf("\n\nDado do fim: %d",aux->dados);
			break;
		default:
			printf("Opcao invalida.");
			break;
	}
	fflush(stdin);
	printf("\n\nImprimir lista?(s ou n): ");
	scanf("%c",&imp);
	switch(imp)
	{
		case 's':
			printf("\n\n");
			aux=fim;
			while(aux!=NULL)
			{
				printf("Dado: %d \tEndereco: %d \tAnterior: %d \n",aux->dados,aux,aux->anterior);
				aux=aux->anterior;
			}
			break;
		case 'n':
			break;
		default:
			printf("opcao invalida");
			break;			
	}
}
