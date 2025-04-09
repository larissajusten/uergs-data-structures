#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercício 6.

Considere que um estacionamento da Rua Direita, em Porto alegre, que é composto por uma única alameda que guarda até dez carros.
Existe apenas uma entrada/saída no estacionamento, e esta extremidade da alameda dá acesso justamente à Rua Direita.
Se chegar um cliente para retirar um carro que não seja o mais próximo da saída, todos os carros bloqueando seu caminho sairão do estacionamento.
O carro do cliente será manobrado para fora do estacionamento, e os outros carros voltarão a ocupar a mesma sequência inicial.

Escreva um programa que processe um grupo de linhas de entrada.
Cada linha de entrada contém um ‘E’, de entrada, ou um ‘S’ de saída, e o número da placa do carro.
Presume-se que os carros cheguem e partam na mesma ordem que entraram no estacionamento.
O programa deve imprimir uma mensagem sempre que um carro  chegar ou sair.
Quando um carro chegar, a mensagem deve especificar se existe ou não vaga para o carro no estacionamento.
Se não houver vaga, o carro partirá sem entrar no estacionamento.
Quando um carro sair do estacionamento, a mensagem deverá incluir o número de vezes em que o carro foi manobrado para fora
do estacionamento para permitir que os outros carros saíssem.
*/

