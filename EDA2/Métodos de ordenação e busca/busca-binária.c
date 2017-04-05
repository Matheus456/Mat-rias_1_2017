#include <stdio.h>
#include <stdlib.h>
/*
  Busca binária é uma busca que procura um número sempre quebrando o vetor ao me
io, para que ela seja realizada é necessário que o vetor esteja ordenado, pois
a cada repetição ela compara se o número está maior ou menor que o meio.
*/

int busca_binaria(int *vetor, int num);

int main(){
  int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
  // int vetor[9];
  // vetor[0] = 1;
  // vetor[1] = 2;
  // vetor[2] = 3;
  // vetor[3] = 4;
  // vetor[4] = 5;
  // vetor[5] = 6;
  // vetor[6] = 7;
  // vetor[7] = 8;
  // vetor[8] = 9;
  int num, resposta, max = sizeof(vetor)/sizeof(vetor[0]);

  /* A função sizeof já é resolvida pelo compilador, pois ele simplesmente já sabe
o que foi feito na definição da variável, logo a única opção de passar para a função
é já passar o tamanho junto. Pois dentro da função ele irá calcular o tamanho do
ponteiro. */

  printf("Duvida pq q aqui o max dá certo e dentro da função não... \n%d\n", max);
  scanf(" %d", &num);
  resposta = busca_binaria(vetor, num);
  if(resposta == 1) printf("Existe!\n");
  else printf("Não existe!\n");
  return 0;
}

int busca_binaria(int *vetor, int num){
  int meio, max = 0, min=0;
  max = 10;
  printf("%d\n", max);
  meio = (max-min)/2 + min;
  while(min < max){
    if(num == vetor[meio]){
      return 1;
    }
    meio = (max-min)/2 + min;
    else if(num > vetor[meio]){
      min = meio+1;
    }
    else if(num < vetor[meio]){
      max = meio-1;
    }
  }
  return -1;
}
