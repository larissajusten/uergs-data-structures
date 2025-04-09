#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 8;
    int *p, *q;
    q = a;
    p = a;

    printf("P++: %d", p);
    p++;
    printf("(*p)++: %d", p); // erro
    (*p)++;
    printf("*(p++): %d", p);
    *(p++);
    printf("*p+1: %d", p);
    *p + 1;
    printf("*(p+1): %d", p);
    *(p + 1);
    printf("*(p+10): %d", p);
    *(p + 10);
}
