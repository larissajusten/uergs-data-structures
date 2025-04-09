#include <stdio.h>
#include <stdlib.h>

int delta(int *x, int *y, int *z){
    int r,u,h,j;
    u=&x;
    h=&y;
    j=&z;
    r = h*h-(4*u*j);
    return(r);
}


int main(){
    int a,b,c;
    int resultado;
    int *pA,*pB,*pC;

    printf("Digite os valores de A, B, C, respectivamente: \n");
    scanf("%d %d %d", &a, &b, &c);

    *pA=&a;
    *pB=&b;
    *pC=&c;

    printf("*pA = %d",*pA);

    resultado=delta(&a,&b,&c);

    printf("o resultado e: %d",resultado);
}


