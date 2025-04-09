#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*----------------------------Larissa Espelocin---------------------------
-------------------------Estrutura de Dados 2017/1------------------------
-----------------------------------N3-------------------------------------
------------------------------Arvore Binaria------------------------------

1.	Implemente uma �rvore bin�ria que verifique as seguintes situa��es:
a.      Pe�a ao usu�rio para inserir dados para uma �rvore
b.	    Fa�a uma fun��o que receba uma �rvore bin�ria e retorne o n�mero de folhas dessa �rvore
            (o total de n�s que n�o tem nenhum filho).
c.	    Fa�a uma fun��o que receba uma �rvore bin�ria e retorne a quantidade de n�s que n�o s�o folhas
            (o total de n�s que tem pelo menos um filho)
d.	    Fa�a uma fun��o que deve verificar de a altura da �rvore bin�ria e apresente o resultado para o usu�rio.
e.	    Implemente fun��es que apresentem o resultado da busca:
            Percurso em pr�-ordem ou Profundidade
            Percurso em Ordem ou Ordem Sim�trica
            Percurso em P�s-Ordem
*/
typedef struct Arvore
{
    struct Arvore *esq;
    int valor;
    struct Arvore *dir;
} Folha;
int Altura;

void Inserir(Folha **Raiz, int num);
int NumerodeFolhas(Folha **Raiz);
int Nos(Folha **Raiz);
int maior(int a, int b);
int AlturaA(Folha **Raiz);
//----------------IMPRIMIR
void Imprimir0(Folha **Raiz);
void Imprimir1(Folha **Raiz);
void Imprimir2(Folha **Raiz);

main()
{
    Folha *Raiz = NULL;
    int op, opt, valor;
    int numFolhas;
    int nos;
    int altura;
    do
    {
        printf("Escolha: \n");
        printf("\t{0} Sair. \n");
        printf("\t{1} Inserir... \n");
        printf("\t{2} Numero de FOLHAS. \n");
        printf("\t{3} Numero de NOS. \n");
        printf("\t{4} Altura da arvore. \n");
        printf("\t{5} Imprimir...\n");
        printf("Op: ");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            exit(1);
            break;
        case 1:
            printf("Digite o numero que deseja inerir: ");
            scanf("%d", &valor);
            Inserir(&Raiz, valor);
            break;
        case 2:
            numFolhas = NumerodeFolhas(&Raiz);
            printf("\n\tO numero de folhas e: %d\n", numFolhas);
            break;
        case 3:
            nos = Nos(&Raiz);
            nos = nos - numFolhas;
            printf("\n\tO numero de nos e: %d", nos);
            break;
        case 4:
            altura = AlturaA(&Raiz);
            printf("\n\tA altura e: %d\n", altura);
            break;
        case 5:
            system("cls");
            printf("Voce escolheu a opcao IMPRIMIR: \n");
            printf("\t{1}Pre-ordem ou Profundidade.\n");
            printf("\t{2}Ordem ou Ordem Simetrica.\n");
            printf("\t{3}Pos-Ordem.\n");
            printf("Op:");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                Imprimir0(&Raiz);
                break;
            case 2:
                Imprimir1(&Raiz);
                break;
            case 3:
                Imprimir2(&Raiz);
                break;
            default:
                printf("Opcao de IMPRIMIR invalida.\n");
                break;
            }
            break;
        default:
            printf("Op invalida!");
            break;
        }
    } while (op != 0);
}
void Inserir(Folha **Raiz, int num)
{
    if (*Raiz == NULL)
    {
        *Raiz = (Folha *)malloc(sizeof(Folha));
        (*Raiz)->valor = num;
        (*Raiz)->esq = NULL;
        (*Raiz)->dir = NULL;
    }
    else
    {
        if (num < (*Raiz)->valor)
            Inserir(&(*Raiz)->esq, num);
        if (num > (*Raiz)->valor)
            Inserir(&(*Raiz)->dir, num);
    }
}
int NumerodeFolhas(Folha **Raiz)
{
    Folha *Aux;
    Aux = *Raiz;
    if (Aux == NULL)
    {
        return 0;
    }
    if (Aux->esq == NULL && Aux->dir == NULL)
    {
        return 1;
    }
    return NumerodeFolhas(&Aux->esq) + NumerodeFolhas(&Aux->dir);
}

int Nos(Folha **Raiz)
{ // Nos sem ser folhas
    Folha *Aux;
    Aux = *Raiz;
    if (Aux == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + Nos(&(Aux->esq)) + Nos(&(Aux->dir));
    }
}
int maior(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int AlturaA(Folha **Raiz)
{ // A altura da Arvore
    Folha *Aux;
    Aux = *Raiz;
    if ((Aux == NULL) || (Aux->esq == NULL && Aux->dir == NULL))
    {
        return 1;
    }
    else
    {
        return 1 + maior(AlturaA(&(Aux->esq)), AlturaA(&(Aux->dir)));
    }
}
void Imprimir0(Folha **Raiz)
{ // Percurso em pr�-ordem ou Profundidade
    Folha *Aux;
    Aux = *Raiz;
    if (Aux != NULL)
    {
        printf("\n\tEsquerda: %d\n\tFolha: %d\n\tValor: %d\n\tDireita: %d\n", Aux->esq, Aux, Aux->valor, Aux->dir);
        Imprimir0(&(Aux->esq));
        Imprimir0(&(Aux->dir));
    }
}
void Imprimir1(Folha **Raiz)
{ // Percurso em Ordem ou Ordem Sim�trica
    Folha *Aux;
    Aux = *Raiz;
    if (Aux != NULL)
    {
        Imprimir1(&(Aux->esq));
        printf("\n\tEsquerda: %d\n\tFolha: %d\n\tValor: %d\n\tDireita: %d\n", Aux->esq, Aux, Aux->valor, Aux->dir);
        Imprimir1(&(Aux->dir));
    }
}
void Imprimir2(Folha **Raiz)
{ // Percurso em P�s-Ordem
    Folha *Aux;
    Aux = *Raiz;
    if (Aux != NULL)
    {
        Imprimir2(&(Aux->esq));
        Imprimir2(&(Aux->dir));
        printf("\n\tEsquerda: %d\n\tFolha: %d\n\tValor: %d\n\tDireita: %d\n", Aux->esq, Aux, Aux->valor, Aux->dir);
    }
}
