#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
void insere(int *vetor, int tamanho_vetor);
int *couting_sort(int *vetor, int tamanho_vetor, int divisor);
void imprime(int *vetor, int tamanho_vetor);
int *radix_sort(int *vetor, int tamanho_vetor);

void main(){
	int tamanho_vetor, *vetor;
  char opcao;
	printf("Capacidade do seu vetor?");
	scanf("%d",&tamanho_vetor);
  vetor = malloc(sizeof(int)*tamanho_vetor);
	while(1){
		menu();
		scanf(" %c", &opcao);
		switch(opcao){

			case 'E': exit(0);

			case 'A':
        insere(vetor, tamanho_vetor);
			break;

			case 'B':
        vetor = radix_sort(vetor, tamanho_vetor);
        //vetor = couting_sort(vetor, tamanho_vetor, 10);
      break;

			case 'C': // mostrar fila
        imprime(vetor, tamanho_vetor);
      break;

		  default:
			   printf("\nOpcao Invalida\n\n");

		}
	}
}

void menu(){
	printf("------------------------");
	printf("\nA - Inserir elemento\nB - remover elemento\nC -");
	printf("Mostrar Fila\nD - Buscar na Fila\nF - Inserir vetor ordenado\n");
	printf("E - Sair\n");
	printf("------------------------\n\nOpcao? ");
}

void insere(int *vetor, int tamanho_vetor){
  int valor;
  for(int i=0; i<tamanho_vetor; i++){
    printf("V[%d] = \n", i);
    scanf(" %d", &valor);
    vetor[i] = valor;
  }
}

int *couting_sort(int *vetor, int tamanho_vetor, int divisor){
  int *vetor_repeticoes, *vetor_ordenado;
  int tam_vetor_repeticoes = 10, indice;
  vetor_repeticoes = malloc(sizeof(int)*10);
  vetor_ordenado = malloc(sizeof(int)*tamanho_vetor);
  /*Zerando todos os valores do vetor de repeticoes*/
  for(int i=0; i<tamanho_vetor; i++){
    vetor_repeticoes[i] = 0;
  }
  for(int i=0; i<tamanho_vetor; i++){
    vetor_repeticoes[(vetor[i]/divisor)%10] = vetor_repeticoes[(vetor[i]/divisor)%10] + 1;
  }
  for(int i=1; i<tam_vetor_repeticoes; i++){
    vetor_repeticoes[i] = vetor_repeticoes[i] + vetor_repeticoes[i-1];
  }
  for(int i=tamanho_vetor-1; i>=0; i--){
    indice = vetor_repeticoes[(vetor[i]/divisor)%10]-1;
    vetor_repeticoes[(vetor[i]/divisor)%10] = vetor_repeticoes[(vetor[i]/divisor)%10] - 1;
    vetor_ordenado[indice] = vetor[i];
  }
  return vetor_ordenado;
}

int *radix_sort(int *vetor, int tamanho_vetor){
  int maior;
  int divisor;
  maior = vetor[0];
  for(int i=1; i<tamanho_vetor; i++){
    if(vetor[i]>maior){
      maior = vetor[i];
    }
  }
  for(divisor=1; maior/divisor!=0; divisor=divisor*10);

  for(int i=1; i<divisor; i=i*10){
    vetor = couting_sort(vetor, tamanho_vetor, i);
  }
	return vetor;
}

void imprime(int *vetor, int tamanho_vetor){
  for(int i=0; i<tamanho_vetor; i++){
    printf("V[%d] = %d\n", i, vetor[i]);
  }
}
