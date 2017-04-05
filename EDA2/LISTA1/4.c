#include <stdio.h>
#include <stdlib.h>

void ordena_vetor(int **vetor_elementos, int tam_vetor);
void imprimir_vetor(int *vetor_elementos, int tam_vetor);
void inserir_vetor(int **vetor_elementos);

int main() {
  int *vetor_elementos, *vetor_index;
  int tam_vetor, tam_indice, pesquisa, ponto_final, ponto_inicial;
  int i;
  inserir_vetor(&vetor_elementos);
  tam_vetor = sizeof(vetor_elementos)/sizeof(vetor_elementos[0]);
  imprimir_vetor(vetor_elementos, 10);

  printf("Digite o número de índices que deseja, menor que o tamanho do vetor(%d).\n", tam_vetor);
  scanf(" %d", &tam_indice);
  vetor_index = malloc(sizeof(int)*tam_indice);

  for(i=0; i<tam_indice; i++){
    vetor_index[i] = (i*tam_vetor)/tam_indice;
  }

  printf("Digite o número a ser pesquisado\n");
  scanf(" %d", &pesquisa);
  if(pesquisa > vetor_elementos[vetor_index[tam_indice-1]]){
    ponto_final = tam_vetor;
  }
  else{
    for(i=0; i<tam_indice; i++){
      if(pesquisa < vetor_elementos[vetor_index[i]]){
        ponto_final = vetor_index[i];
        break;
      }
    }
  }
  ponto_inicial = ponto_final - (tam_vetor/tam_indice);
  for(i=ponto_inicial; i<=ponto_final; i++){
    if(pesquisa == vetor_elementos[i]){
      printf("O numero foi encontrado! Posicao = %d\n", i);
      i = -40;
      break;
    }
  }
  if(i != -40){
    printf("O numero nao foi encontrado!\n");
  }
  return 0;
}

void ordena_vetor(int **vetor_elementos, int tam_vetor){
  int i, j, aux;
  for(i=0; i<tam_vetor; i++){
      j = i+1;
      while(j<tam_vetor){
        if(vetor_elementos[i] > vetor_elementos[j]){
          aux = *vetor_elementos[i];
          *vetor_elementos[i] = *vetor_elementos[j];
          *vetor_elementos[j] = aux;
        }
        j++;
      }
  }

}

void imprimir_vetor(int *vetor_elementos, int tam_vetor){
  int i = 0;
  while(i<tam_vetor){
    printf("%d\n", vetor_elementos[i]);
    i++;
  }
}

void inserir_vetor(int **vetor_elementos){
  int i, tam_vetor;
  printf("Digite o tamanho do seu vetor\n");
  vetor_elementos = malloc(sizeof(int*));
  scanf(" %d", &tam_vetor);
  *vetor_elementos = malloc(tam_vetor * sizeof(int));
  printf("Digite os valores do seu vetor\n");

  for(i=0; i<tam_vetor; i++){
    printf("%d\nTamanhoVetor = %d\n", i, tam_vetor);
    scanf(" %d", &vetor_elementos[i]);
  }
  //ordena_vetor(vetor_elementos, tam_vetor);
}
