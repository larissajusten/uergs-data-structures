#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exerc�cio 6.

Considere que um estacionamento da Rua Direita, em Porto alegre, que � composto por uma �nica alameda que guarda at� dez carros.
Existe apenas uma entrada/sa�da no estacionamento, e esta extremidade da alameda d� acesso justamente � Rua Direita.
Se chegar um cliente para retirar um carro que n�o seja o mais pr�ximo da sa�da, todos os carros bloqueando seu caminho sair�o do estacionamento.
O carro do cliente ser� manobrado para fora do estacionamento, e os outros carros voltar�o a ocupar a mesma sequ�ncia inicial.

Escreva um programa que processe um grupo de linhas de entrada.
Cada linha de entrada cont�m um �E�, de entrada, ou um �S� de sa�da, e o n�mero da placa do carro.
Presume-se que os carros cheguem e partam na mesma ordem que entraram no estacionamento.
O programa deve imprimir uma mensagem sempre que um carro  chegar ou sair.
Quando um carro chegar, a mensagem deve especificar se existe ou n�o vaga para o carro no estacionamento.
Se n�o houver vaga, o carro partir� sem entrar no estacionamento.
Quando um carro sair do estacionamento, a mensagem dever� incluir o n�mero de vezes em que o carro foi manobrado para fora
do estacionamento para permitir que os outros carros sa�ssem.
*/
