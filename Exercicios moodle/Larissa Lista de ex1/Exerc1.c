#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1.	Fa�a um c�digo em c que receba dois valores inteiros e calcule a soma.
Por�m, passe os valore para a vari�vel X e Y, realize a soma desses valores e apresente o resultado para o usu�rio.
Utilize ponteiro para manipular a vari�vel X e vari�vel Y e SOMA. Ao t�rmino, imprima:

a.	Vari�vel X
b.	Endere�o do ponteiro X
c.	Conte�do do ponteiro X
d.	Ponteiro X
e.	Vari�vel Y
f.	Endere�o do ponteiro Y
g.	Conte�do do ponteiro Y
h.	Ponteiro Y
i.	Vari�vel SOMA
j.	Endere�o do ponteiro SOMA
k.	Conte�do do ponteiro SOMA
l.	Ponteiro SOMA*/

int main()
{
    int x, y, soma;
    int *px, *py, *psoma;

    printf("Digite o valor da variavel x: ");
    scanf("%d", &x);
    px = &x;
    printf("X: %d\n", x);
    printf("&X: %d\n", &x);
    printf("Endereco Px: %d\n", &px);
    printf("Conteudo Px: %d\n", px);
    printf("Px: %d\n", px);

    printf("Digite o valor da variavel y: ");
    scanf("%d", &y);
    py = &y;
    printf("Y: %d\n", y);
    printf("&Y: %d\n", &y);
    printf("Endereco Py: %d\n", &py);
    printf("Conteudo Py: %d\n", py);

    psoma = &soma;
    *psoma = *px + *py;
    printf("Soma: %d\n", soma);
    printf("&Soma: %d\n", &soma);
    printf("Endereco Psoma: %d\n", &psoma);
    printf("Conteudo Psoma: %d\n", psoma);
}
