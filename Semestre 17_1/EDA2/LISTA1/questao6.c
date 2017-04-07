#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

int busca_binaria(int *vetor, int num);

int main(){
  int vetor[MAX];
  double time_inicio, time_fim;
  int i;
  time_inicio = clock();
  for(i=0; i<MAX; i++){
    vetor[i] = i;
  }
  int num, resposta, max = sizeof(vetor)/sizeof(vetor[0]);

  /* A função sizeof já é resolvida pelo compilador, pois ele simplesmente já sabe
o que foi feito na definição da variável, logo a única opção de passar para a função
é já passar o tamanho junto. Pois dentro da função ele irá calcular o tamanho do
ponteiro. */

  scanf(" %d", &num);
  resposta = busca_binaria(vetor, num);
  if(resposta == 1) printf("Existe!\n");
  else printf("Não existe!\n");
  time_fim = clock();
  printf("Tempo de execução: %lf\n", time_fim-time_inicio);
  return 0;
}

int busca_binaria(int *vetor, int num){
  int meio, max = 0, min=0;
  max = MAX;
  while(min < max){
    meio = min + (max-min) * ((num - vetor[min])/(vetor[max]-vetor[min]));
    if(num == vetor[meio]){
      return 1;
    }
    else if(num > vetor[meio]){
      min = meio+1;
    }
    else if(num < vetor[meio]){
      max = meio-1;
    }
  }
  return -1;
}
