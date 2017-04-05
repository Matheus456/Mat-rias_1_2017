#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_VETOR 6

void swap(int *vetor, int i, int j);

int main() {
  int i, j, gap, tam_vetor, vetor[TAMANHO_VETOR];

  for(int z = 0; z<TAMANHO_VETOR; z++){
    scanf(" %d", &vetor[z]);
    printf("aq\n");
  }

  tam_vetor = sizeof(vetor)/sizeof(vetor[0]);
  gap = tam_vetor/2;
  while (gap > 1) {
    j = gap;
    for(i=0; i<gap; i++){
      if(vetor[i] > vetor[j]){
        swap(vetor, i, j);
      }
      j++;
      }
    gap = gap/2;
    printf("preso\n");
  }

  for(int z = 0; z<TAMANHO_VETOR; z++){
    printf("%d\n", vetor[z]);
  }

  return 0;
}

void swap(int *vetor, int i, int j){
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}
