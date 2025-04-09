#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1.	Faça um código em c que receba dois valores inteiros e calcule a soma.
Porém, passe os valore para a variável X e Y, realize a soma desses valores e apresente o resultado para o usuário.
Utilize ponteiro para manipular a variável X e variável Y e SOMA. Ao término, imprima:

a.	Variável X
b.	Endereço do ponteiro X
c.	Conteúdo do ponteiro X
d.	Ponteiro X
e.	Variável Y
f.	Endereço do ponteiro Y
g.	Conteúdo do ponteiro Y
h.	Ponteiro Y
i.	Variável SOMA
j.	Endereço do ponteiro SOMA
k.	Conteúdo do ponteiro SOMA
l.	Ponteiro SOMA*/

int main(){
    int x, y, soma;
    int *px, *py, *psoma;

    printf("Digite o valor da variavel x: ");
    scanf("%d",&x);
    px=&x;
    printf("X: %d\n",x);
    printf("&X: %d\n",&x);
    printf("Endereco Px: %d\n",&px);
    printf("Conteudo Px: %d\n",px);
    printf("Px: %d\n",px);

    printf("Digite o valor da variavel y: ");
    scanf("%d",&y);
    py=&y;
    printf("Y: %d\n",y);
    printf("&Y: %d\n",&y);
    printf("Endereco Py: %d\n",&py);
    printf("Conteudo Py: %d\n",py);

    psoma=&soma;
    *psoma=*px+*py;
    printf("Soma: %d\n",soma);
    printf("&Soma: %d\n",&soma);
    printf("Endereco Psoma: %d\n",&psoma);
    printf("Conteudo Psoma: %d\n",psoma);
}
