#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Definicao das estruturas */

/* Contem o no da arvore */
typedef struct StructArvore {
  int info, altura;
  struct StructArvore *esq, *dir;
} noArvore;

/* Os prototipos */
noArvore *cria_arvore(int );
noArvore *cria_no(void );
void insere_esquerda (noArvore *, int );
void insere_direita (noArvore *, int );
void visita (noArvore *);
void visitaOrdem (noArvore *);
void posOrdem(noArvore *);
void ordem (noArvore *);
noArvore *remover (noArvore *, int);


/* Aqui comeca tudo */
void main(void ) {
  noArvore *raiz;       /* raiz da arvore binaria */
  noArvore *p;
  noArvore *q;        /* ponteiros auxiliares */
  char linha[80];  /* linha com os numeros para a arvore */
  char *numero;       /* ponteiro para os numeros lidos */
  int num;         /* numero em formato int */

  puts("Entre com os numeros inteiros, separados por brancos.");
  puts("Use uma unica linha para fornecer os numeros.");
  gets(linha);

  numero = strtok(linha, " "); /* pega o primeiro numero da lista */
  num = atoi(numero);          /* converte para inteiro */
  raiz = cria_arvore(num);     /* insere na raiz */
  numero = strtok(NULL, " ");  /* pega o segundo numero */

  while (numero) {
    q = raiz; p = raiz;
    printf("Li numero %d\n", num); /* le novo numero */
    num = atoi(numero);

    while (num != p->info && q) { /* procura na arvore */
      p = q;
      if (num < p->info)
      q = p->esq;               /* passa para arvore esquerda */
      else
       q = p->dir;               /* passa para direita */
    }

    if (num == p->info)
      printf("O numero %d ja existe na arvore.\n", num);
    else {  /* nao achei, vou inserir o numero na arvore */
      if (num < p->info)
        insere_esquerda(p, num);   /* insere na arvore esquerda */
      else
        insere_direita(p, num);   /* insere na arvore direita */
    }
    numero = strtok(NULL, " "); /* continuemos */
  } /* fim do while (numero) */


/* Aqui imprimimos a arvore e calculamos a altura de cada no */
  puts("Imprime a arvore em pos ordem");
  posOrdem(raiz);

/* Como ficam os numeros ordenados? */
  puts ("Imprime a arvore em ordem");
  ordem(raiz);


/* Tenho de recalcular as alturas da arvore,
   portanto, vamos pos ordem */
  puts("Imprime a arvore em pos ordem");
  posOrdem(raiz);

/* Finalmente, imprimimos em ordem para ver se funcionou */
  puts ("Imprime a arvore em ordem");
  ordem(raiz);
}

/* A dificil rotina recursiva de percorrem uma arvore em pos ordem */
void posOrdem(noArvore *p) {
  if (p->esq) posOrdem(p->esq);
  if (p->dir) posOrdem(p->dir);
  visita(p); /* aqui calcula a altura */
}

/* A tambem dificil rotina de percurso em ordem */
void ordem (noArvore *p) {
     if (p->esq) ordem(p->esq);
     visitaOrdem(p); /* Nesta visita nao calculamos a altura */
     if (p->dir) ordem(p->dir);
}

/* A visita em pos ordem e usada para calcular a altura da arvore */
void visita (noArvore *p) {
     int alt1, alt2;
     if (p->esq) alt1 = p->esq->altura;
     else alt1 = 0;
     if (p->dir) alt2 = p->dir->altura;
     else alt2 = 0;
     if (alt1>alt2) p->altura = alt1 + 1;
     else p->altura = alt2 + 1;
     printf("info = %d ", p->info);
     printf("altura = %d\n", p->altura);
}

/* So imprime o conteudo do no */
void visitaOrdem (noArvore *p) {
     printf("info = %d ", p->info);
     printf("altura = %d\n", p->altura);
}

/* Cria um no completo para arvore */
noArvore *cria_arvore (int x) {
  noArvore *p;

  p = cria_no ();
  if (p) {
    p->info = x;
    p->altura = 0;
    return p;
  }
  else {
    puts("Faltou espaco para alocar no.");
    return NULL;
  }

}

/* Cria um no basico para arvore, usada em cria_arvore */
noArvore *cria_no(void ) {
  noArvore *p;

  if ((p = (noArvore *) malloc(sizeof(noArvore))) == NULL)
    return NULL;
  else {
    p->esq = NULL; p->dir = NULL;
    return p;
  }
 }


/* Insere um no a esquera de um no */
void insere_esquerda(noArvore *p, int x) {
  noArvore *q;

  if (p->esq)
    puts("Operacao de insercao a esquerda ilegal.");
  else {
    q = cria_arvore(x);
    p->esq = q;
  }
}

/* insere um no a direita de um no */
void insere_direita(noArvore *p, int x) {
  noArvore *q;

  if (p->dir)
    puts("Operacao de insercao a direita ilegal.");
  else {
    q = cria_arvore(x);
    p->dir = q;
  }
}

