#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct
typedef struct senha
{
    int senha;
    struct senha *prox;
} Node;

typedef struct paciente
{
    int senha;
    char nome;
    char plano;
    int exame;
    struct paciente *prox;
} Nodo;

// chamamento das fun��es
int menu();
void opcoes(Nodo *ATENDIDOS, Node *FILA, int op);
void InserirFila(Node *FILA);
void CadastroPaciente(Nodo *ATENDIDOS, Node *FILA);

// main
main()
{
    int a = 1, op;
    Nodo *Unimed, *Aux, *Aux2;
    Node *FILA = (Node *)malloc(sizeof(Node));
    Nodo *ATENDIDOS = (Nodo *)malloc(sizeof(Nodo));

    if (!ATENDIDOS)
    {
        printf("Espa�o de memoria indisponivel!");
    }
    else
    {
        while (a = !0)
        {
            InserirFila(FILA);
            printf("Para inserir a senha de atendimento digite [1], para sair [0]");
        }
        op = menu();
        opcoes(ATENDIDOS, FILA, op);
    }

    printf("Lista dos pacientes atendidos.");
    if (ATENDIDOS->prox == NULL)
    {
        printf("Nao ha nenhum paciente atendido!");
    }
    else
    {
        Aux2 = ATENDIDOS->prox;
        while (Aux2->prox = !NULL)
        {
            printf("A senha do Paciente e: %d", Aux2->senha);
            printf("O nome do Paciente e: %s", Aux2->nome);
            printf("O plano do Paciente e: %s", Aux2->plano);
            if (Aux2->exame == 1)
            {
                printf("o exame que o Paciente realizou foi de sangue.");
            }
            else
            {
                printf("o exame que o Paciente realizou foi de imagem.");
            }
        }
    }

    printf("Pacientes atendidos que possuem Unimed");
    Unimed = ATENDIDOS->prox;
    while (strcmp('Unimed', Unimed->plano) == 1)
    {
        printf("A senha do paciente e: %d", Unimed->senha);
        printf("\nO nome do paciente e: %s", Unimed->nome);
        if (Unimed->exame == 1)
        {
            printf("\nO exame realizado pelo paciente foi de sangue.");
        }
        else
        {
            printf("\nO exame realizado pelo paciente foi de imagem.");
        }
        Unimed = Unimed->prox;
    }

    printf("Pacientes que fizeram exame de sangue");
    Aux = ATENDIDOS->prox;
    while (Aux->exame == 1)
    {
        printf("A senha do paciente e: %d", Aux->senha);
        printf("\nO nome do paciente e: %s", Aux->nome);
        printf("\nO plano do  paciente e: %s", Aux->plano);
        Aux = Aux->prox;
    }
}

// fun��es
int menu()
{
    int op;
    printf("[1]Cadastrar um novo paciente.");
    printf("[0]Sair");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

void opcoes(Nodo *ATENDIDOS, Node *FILA, int op)
{
    switch (op)
    {
    case 0:
        exit(1);
    case 1:
        CadastroPaciente(ATENDIDOS, FILA);
        break;
    default:
        printf("A opcao escolhida nao existe! Tente novamente!");
    }
}

void InserirFila(Node *FILA)
{
    Node *aux;
    Node *novo = (Node *)malloc(sizeof(Node));
    if (!novo)
    {
        printf("Nao ha memoria disponivel para seu no.");
    }
    else
    {
        printf("Digite sua senha (APENAS numeros): ");
        scanf("%d", &novo->senha);
        novo->prox = NULL;

        if (FILA->prox == NULL)
        {
            FILA->prox = novo;
        }
        else
        {
            aux = FILA->prox;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
}
void CadastroPaciente(Nodo *ATENDIDOS, Node *FILA)
{
    Node *aux;  // auxiliar para FILA
    Nodo *aux1; // auxiliar para LISTA

    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));

    if (!novo)
    {
        printf("Memoria indisponivel!");
        exit(1);
    }
    else
    {
        novo->prox = NULL;
        // passando senha da FILA para a LISTA
        aux = FILA->prox;
        novo->senha = aux->senha;
        FILA->prox = aux->prox;
        free(aux);
        // inserindo as informa��es

        printf("Digite o nome do Paciente:");
        gets(novo->nome);
        printf("\nDigite o plano de saude do paciente: [Unimed/Ipe] ");
        gets(novo->plano);
        printf("\nDigite o tipo de exame\n [1]Exame de sangue \n [2]Exame de imagem \nA: ");
        scanf("%d", &novo->exame);

        if (ATENDIDOS->prox == NULL)
        {
            ATENDIDOS->prox = novo;
        }
        else
        {
            aux1 = ATENDIDOS->prox;
            while (aux1->prox != NULL)
            {
                aux1 = aux1->prox;
            }
            aux1->prox = novo;
        }
    }
}
