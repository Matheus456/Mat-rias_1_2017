#include <stdio.h>
#include <stdlib.h>
/*
  O método insert sort coloca os números em ordem de acordo com o que já existe
no vetor, isto é, se o primeiro elemento que estiver no vetor for maior do que o
elemento que está sendo analisado, esse elemento será colocado na primeira posi
ção.
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
}

for(i=1; i<num_elementos; i++){
  j = 0;
  while(j<i){
    if(vetor_elementos[j] > vetor_elementos[i]){
      aux = vetor_elementos[i];
      vetor_elementos[i] = vetor_elementos[j];
      vetor_elementos[j] = aux;
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
