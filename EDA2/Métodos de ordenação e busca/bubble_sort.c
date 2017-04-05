#include <stdio.h>
#include <stdlib.h>
/*
  O método bubble sort ordena o vetor em todo o seu processo, isto é, ele não fi
xa um valor e procura o seu lugar. Esse método tem o objetivo de a cada ciclo co
locar o maior número na última posição, logo, a cada laço ele vai da posição um
até a posição que não foi preenchida com o último termo, se no meio do caminho
ele achar algum termo maior do o que ele leva, ele faz a troca e carrega o ele
mento maior.
*/

int main(){
int i=0, j, aux;
int num_elementos;
int vetor_elementos[10];
num_elementos = sizeof(vetor_elementos)/sizeof(vetor_elementos[0]);
printf("Número de elementos: %d\nDigite os números desejados:\n", num_elementos);

while(i<num_elementos){
  scanf(" %d", &vetor_elementos[i]);
  i++;
  printf("%d\n", i);
}

for(i=num_elementos-1; i>0; i--){
  j = 0;
  while(j<i){
    if(vetor_elementos[j] > vetor_elementos[j+1]){
      aux = vetor_elementos[j];
      vetor_elementos[j] = vetor_elementos[j+1];
      vetor_elementos[j+1] = aux;
    }
    j++;
  }
}

i=0;
printf("\n\n");
while(i<num_elementos){
  printf("%d\n", vetor_elementos[i]);
  i++;
}
  return 0;
}
