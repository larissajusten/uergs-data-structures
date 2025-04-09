#include <stdlib.h>
#include <stdio.h>

struct cachorro{
	char nome[50];
	int idade;
	char sexo[1];
};
void imprime(struct cachorro *k){
		printf("O nome do cachorro e: %s\n E seu endereço e: %d\nA idade do cachorro e: %d \n E seu endereço e: %dO sexo do cachorro e: %s\n E seu endereço e: %d", 
		k->nome, &k->nome, 
		k->idade, &k->idade, 
		k->sexo, &k->sexo);
	printf("\nO endereco da struct: %d\nO conteudo da struct: %d\nO conteudo do ponteiro struct: %d", &k, k, *k);
}
int main(){
	int i;
	struct cachorro dog;
		printf("\nDigite a idade do cachorro:");
		scanf("%d",&dog.idade);
		printf("Digite o nome do cachorro:");
		scanf("%s",&dog.nome);
		printf("Digite o sexo do cachorro[F/M]:");
		scanf("%s",&dog.sexo);
	imprime(&dog);
}
