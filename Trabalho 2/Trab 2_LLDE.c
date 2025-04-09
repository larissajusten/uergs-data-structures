#include <stdio.h>
#include <stdlib.h>

char arqt[10];

//Struct Arquivo
typedef struct arquivo {
	int codigo;
	float salario;
	char nome[10];
}arq;
//Struct Lista Duplamente Encadeada
typedef struct nodo{
	int codigo;
	float salario;
	char nome[10];
	struct nodo *ant;
	struct nodo *prox;
}listaD;

//Chamando as funções
void CadastrarArq(FILE *fid, listaD *pListaD, listaD *inicioListaD, listaD *fimListaD);
void InserirInicio(listaD *inicioListaD, listaD *pListaD, listaD *fimListaD, FILE *fid);
void InserirMeio(listaD *inicioListaD, listaD *pListaD, listaD *fimListaD, FILE *fid);
void InserirFim(listaD *inicioListaD, listaD *pListaD, listaD *fimListaD, FILE *fid);
void ImprimirLista(listaD *inicioListaD, listaD *pListaD);
void ImprimirMaiorValor(listaD *inicioListaD);

//Inicio main
main(){
	FILE *fid;
    listaD *pListaD = NULL, *inicioListaD = NULL, *fimListaD = NULL;
    pListaD = (listaD*)malloc(sizeof(listaD));

	int op = 1;

	//Menu
	while (op != 0){
        printf("\nMENU PRINCIPAL");
        printf("[1]Cadastrar.\n");
        printf("[2]Imprimir a lista.\n");
        printf("[3]Imprimir maior valor.\n");
        printf("[4]Imprimir em ordem crescente.\n");
        printf("[0]Sair.\n");
        printf("\n\t");
        scanf("%d", &op);

        switch(op){
        	case 1:
        	CadastrarArq(fid, **pListaD, **inicioListaD, **fimListaD);
            break;
            case 2:
            ImprimirLista(**inicioListaD, **pListaD);
            break;
            case 3:
            ImprimirMaiorValor(**inicioListaD, **pListaD);
            break;
            case 4:
            //Ordenar de ordem crescente de código
            //Imprimir novamente
            break;
        }
	}
}
//Funções
void CadastrarArq(FILE *fid, listaD *pListaD, listaD *inicioListaD, listaD *fimListaD){
	int auxcod;
	float salario;
	int cont=0;

    printf("Digite o nome do arquivo (10):");
    scanf("%s",&arqt);

    if(cont=0){

    	fid=fopen(arqt,"w+t");
        printf("\nDigite o codigo: ");
        scanf("%d",&listaD.codigo);
        fprintf(fid,"%d",listaD.codigo);
        printf("\n Digite o salario: ");
        scanf("%f",&listaD.salario);
        fprintf(fid,"%f",listaD.salario);
        printf("\n Digite o nome: ");
        scanf("%s",&listaD.nome[10]);
        fprintf(fid,"%s",listaD.nome[10]);
        fclose(fid);
        cont++;
            InserirInicio(**inicioListaD, **pListaD, **fimListaD, fid);
        }
    else
        salario=listaD.salario;
    	printf("Digite o codigo: ");
    	scanf("%d",&auxcod);
    	if(auxcod<=10){//------------------------/*função InserirInicio*/
    		fid=fopen(arqt,"a+t");
			(arq).codigo=auxcod;
			fprintf(fid,"%d",listaD.codigo);
            printf("\nDigite o salario: ");
            scanf("%f",&listaD.salario);
            fprintf(fid,"%f",salario);
            printf("\nDigite o nome: ");
            scanf("%s",&listaD.nome);
            fprintf(fid,"%s",listaD.nome);
            fclose(fid);
    		InserirInicio(**inicioListaD, **pListaD, **fimListaD, fid);
    	}
    	else if(auxcod>=11 && auxcod<=25){/*função InserirMeio -e em ordem crescente-*/
    		fid=fopen(arqt,"a+t");
			listaD.codigo=auxcod;
			fprintf(fid,"%d",listaD.codigo);
            printf("\nDigite o salario: ");
            scanf("%f",&listaD.salario);
            fprintf(fid,"%f",listaD.salario);
            printf("\nDigite o nome: ");
            scanf("%s",&listaD.nome);
            fprintf(fid,"%s",listaD.nome);
            fclose(fid);
            InserirMeio(**inicioListaD, **pListaD, **fimListaD, fid);

    	}
    	else{ /*(auxcod>23)*///-------------------/*função InserirFim*/
    		fid=fopen(arqt,"a+t");
			listaD.codigo=auxcod;
			fprintf(fid,"%d",listaD.codigo);
            printf("\nDigite o salario: ");
            scanf("%f",&listaD.salario);
            fprintf(fid,"%f",listaD.salario);
            printf("\nDigite o nome: ");
            scanf("%s",&listaD.nome);
            fprintf(fid,"%s",listaD.nome);
            fclose(fid);
            InserirFim(**inicioListaD, **pListaD, **fimListaD, fid);
        }
    }

void InserirInicio(listaD *inicioListaD, listaD *pListaD, listaD *fimListaD, FILE *fid){
	listaD *pAux;
	//Alocar a memória

	if(pListaD){
		if(*inicioListaD == NULL){
			inicioListaD = pListaD;
			fid=fopen(arqt,"r");
			(pListaD)->codigo=listaD.codigo;
			(pListaD)->salario=listaD.salario;
			(pListaD)->nome=listaD.nome;
			fclose(fid);
			pListaD->ant = NULL;
			pListaD->prox = NULL;
				if(pListaD->prox == NULL){
					*fimListaD = *pListaD;
				}
		}else{
			pAux = inicioListaD;
			pAux->ant = pListaD;
			inicioListaD = pListaD;
			fid=fopen(arqt,"r");
			pListaD->codigo=listaD.codigo;
			pListaD->salario=listaD.salario;
			pListaD->nome=listaD.nome;
			fclose(fid);
			pListaD->prox = pAux;
				if(pListaD->prox == NULL){
					*fimListaD = pListaD;}
		}

	}else {
		printf("Erro ao alocar memoria para  a lista (malloc)\n");
		}
}
void InserirMeio(listaD *inicioListaD, listaD *pListaD, listaD *fimListaD, FILE *fid){
	int aux = 1;
	int auxcod=11;
	listaD *pAux = *inicioListaD;
	listaD *pAux2;

	//Ler do arquivo para colocar na lista
	fid=fopen(arqt,"r");
	pListaD->codigo=listaD.codigo;
	pListaD->salario=listaD.salario;
	pListaD->nome=listaD.nome;
	fclose(fid);
	//
	/*while(aux == 1){
		pAux2=pAux->prox;
		if((*pAux2).codigo>=auxcod+1 && (*pAux2).codigo<25){
			if(*pAux2.codigo==pListaD.(codigo-1){

			}
		}

		else {
			(*atual)->prox = (*auxp).prox;
			(*auxp).prox = *atual;
			aux = 0;
			*auxp = *auxp->prox;
		}
	}*/
	/*nodo*aux=NULL;
	nodo*aux2=NULL;
	nodo*p=NULL;
	l=0;
	p=(nodo*)malloc(sizeof(nodo));
	aux=*inicio;
	while(l==0)
	{
		aux2=aux->proximo;
		if(aux->a<ano&&aux2->a>ano)
		{
			aux->proximo=p;
			p->proximo=aux2;
			l=1;
		}
		aux=aux2;
	}
} */


void InserirFim(listaD *inicioListaD, listaD *pListaD, listaD *fimListaD, FILE *fid){
	listaD *pAux;

	if(pListaD){
		if(*inicioListaD == NULL){
			*inicioListaD = pListaD;
			fid=fopen(arqt,"r");
			pListaD->codigo=listaD.codigo;
			pListaD->salario=listaD.salario;
			pListaD->nome=listaD.nome;
			fclose(fid);
			pListaD->ant = NULL;
			pListaD->prox = NULL;
				if(pListaD->prox == NULL){
					*fimListaD = pListaD;
				}
		}else{
			pAux = *inicioListaD;

			while(pAux->prox != NULL){
			pAux = pAux->prox;
			pListaD->ant = pAux;
			pListaD->prox = NULL;
			fid=fopen(arqt,"r");
			pListaD->codigo=listaD.codigo;
			pListaD->salario=listaD.salario;
			pListaD->nome=listaD.nome;
			fclose(fid);
			pAux->prox= *pListaD;
				if(pListaD->prox == NULL){
					fimListaD = pListaD;
			}
		}
	}
	}else {
		printf("Erro ao alocar memoria para a lista (malloc)\n");
		}
}
void ImprimirLista(listaD *inicioListaD, listaD *pListaD){

	if(inicioListaD==NULL){
        printf("A lista esta vazia!");
    } else {
        pListaD=inicioListaD;
        while(pListaD!=NULL){
            printf("Codigo  =%d",pListaD->codigo);
            printf("Salario =%2.f",pListaD->salario);
            printf("Nome    =%s",pListaD->nome);
            pListaD=pListaD->prox;
        }

    }
}
void ImprimirMaiorValor(listaD *inicioListaD, listaD *pListaD){
	int aux;

	if (inicioListaD!=NULL){
		aux=inicioListaD->salario;
		pListaD=inicioListaD->prox;
		while(pListaD!=NULL){
		if(aux<pListaD->salario){
			aux=pListaD->salario;
			pListaD=pListaD->prox;
		}
		else{
			pListaD=pListaD->prox;
		}
	}
	}
	printf("Maior salario: %d",aux);
}

void Ordenar(FILE *fid, lista *inicioListaD){
	fid=fopen(arq_lote.bin,"r+t");
}
