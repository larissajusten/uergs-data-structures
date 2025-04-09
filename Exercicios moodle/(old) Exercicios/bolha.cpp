#include <stdlib.h>
#include <stdio.h>

int vetor[5];

void bolha_rec(int n) {
     int j;
     int troca=0;
     
     for (j=0; j<n-1; j++){
         if((vetor[j])>(j+1)){
         int temp = vetor[j]; // troca
         vetor[j] = vetor[j+1];
         vetor [j+1] = temp;
         troca=1;
         }
     if(troca!=0){ //houve troca
         bolha_rec(n-1);
         }
}
}

int main(){ 
      int i;
      printf("Digite 5 numeros aleatorios \n");
      for(i=0; i<5;i++){
      scanf("%d",&vetor[i]);
      } 
      bolha_rec(i);
      
      for(i=0; i<5;i++){
      printf("%d ", vetor[i]);
      }
      system("pause");
}
