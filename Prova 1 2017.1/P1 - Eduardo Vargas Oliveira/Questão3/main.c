#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x,*px;
  x=3;
  px=&x;
  printf("\nx =%d",x);
  printf("\n &x = %d",&x);
  printf("\n px = %d",px);
  printf("\n*px= %d",*px);
  x++;
  printf("\n a) x++ = %d ",x);
  printf("\n aumenta o valor da variavel\n");

  printf("\n b) %d",(*px)++);
  printf("\n aumenta o valor do conteudo de  x\n");


  printf("\n c)= %d\n",*(px++));
  printf("\n aumenta o valor do conteudo de x\n");

  printf("\n d) %d\n",*px+1);
  printf("\n aumenta o numero que corresponde ao endereco de x\n");

  printf("\n e) %d",*(px++));
  printf("\n aumenta o valor do endereco de x \n");

  printf("\n f) %d\n",*(px+10));
  printf("\n aumenta o valor do endereco de x em 10\n");



}
