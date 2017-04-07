#include <stdio.h>
#include <stdlib.h>
/*
  O método selection sort procura o menor termo e coloca no começo e faz isso até que todos os elementos
fiquem ordenados corretamente.
*/

int main() {
  int i=0, j, aux;
  int num_elementos;
  int vetor_elementos[10];
  num_elementos = sizeof(vetor_elementos)/sizeof(vetor_elementos[0]);
  printf("Número de elementos: %d\nDigite os números desejados:\n", num_elementos);
  while(i<num_elementos){
    scanf(" %d", &vetor_elementos[i]);
    i++;
  }

  for(i=0; i<num_elementos; i++){
      j = i+1;
      while(j<num_elementos){
        if(vetor_elementos[i] > vetor_elementos[j]){
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
