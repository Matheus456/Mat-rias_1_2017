#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct fila {
	int capacidade;
	int primeiro;
	int ultimo;
	int nItens;
	int *dados;
}Fila;

void busca_binaria(Fila fila, int busca, int tamanho_vetor);
void criar_fila( Fila *fila, int c );
void inserir(Fila *fila, int v);
int remover_fila( Fila *fila );
int fila_vazia( Fila *fila );
int fila_cheia( Fila *fila );
void imprimir_fila(Fila *fila);
int calcula_meio(int aux_ini, int aux_fim, int meio, int tamanho_vetor, int busca, Fila fila);

void main () {

	int tamanho_vetor;
	int valor, busca, num_elementos, i;
	char opcao;
	Fila fila_1;

	printf("Capacidade da fila? ");
	scanf("%d",&tamanho_vetor);
	criar_fila(&fila_1, tamanho_vetor);

	while(1){
		printf("------------------------");
		printf("\nA - Inserir elemento\nB - remover elemento\nC -");
		printf("Mostrar Fila\nD - Buscar na Fila\nF - Inserir vetor ordenado\n");
		printf("E - Sair\n");
		printf("------------------------\n\nOpcao? ");
		scanf(" %c", &opcao);


		switch(opcao){

			case 'E': exit(0);

			case 'A':
				if (fila_cheia(&fila_1)){
					printf("\nFila Cheia!!!\n\n");
				}
				else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%d", &valor);
					inserir(&fila_1,valor);
				}
				break;

			case 'B':
      if (fila_vazia(&fila_1)){
					printf("\nFila vazia!!!\n\n");
				}
				else {
					valor = remover_fila(&fila_1);
					printf("\n%d removido com sucesso\n\n", valor) ;
				}
				break;

				case 'C': // mostrar fila
					if (fila_vazia(&fila_1)){
						printf("\nFila vazia!!!\n\n");
					}
					else {
						printf("\nConteudo da fila => ");
						imprimir_fila(&fila_1);
					}
					break;

          case 'D':
          if (fila_vazia(&fila_1)){
              printf("\nFila vazia!!!\n\n");
          }
					else{
						scanf(" %d", &busca);
						busca_binaria(fila_1, busca, tamanho_vetor);
					}
					break;

					case 'F':
						printf("Digite o numero de elementos que voce deseja colocar\n");
						scanf(" %d", &num_elementos);
						while(i<num_elementos && !fila_cheia(&fila_1)){
							inserir(&fila_1, i*2);
							i++;
						}
					break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
}
void busca_binaria(Fila fila, int busca, int tamanho_vetor){
	clock_t Ticks[2];
	Ticks[0] = clock();
  int meio=0, aux_fim, aux_ini, flag = 0;
  aux_ini = fila.primeiro;
  aux_fim = fila.ultimo;
	while(aux_fim < aux_ini && flag <= 0){
    meio = calcula_meio(aux_ini, aux_fim, meio, tamanho_vetor, busca, fila);
		if((meio<aux_ini && meio>aux_fim) || meio>tamanho_vetor || meio<0){
			flag = 2;
		}
		if(fila.dados[meio] == busca && flag == 0){
	    printf("O valor foi encontrado na posicao %d\n", meio);
			flag = 1;
	    break;
	  }
	  if(fila.dados[meio] < busca){
	      if(meio + 1 > tamanho_vetor-1){
	        aux_ini = 0;
	      }
	      else{
	         aux_ini = meio+1;
	    }
		}
	  if(fila.dados[meio] > busca){
	      if(meio < 0){
	        aux_fim = tamanho_vetor-meio;
	      }
	      else{
	         aux_fim = meio-1;
	      }
	   }
		 if(fila.dados[aux_ini] == busca && flag == 0 && aux_ini >= fila.primeiro && aux_ini <= tamanho_vetor){
			 printf("O valor foi encontrado na posicao %d\n", aux_ini);
			 flag = 1;
		 }
		 if(fila.dados[aux_ini] == busca && flag == 0 && aux_ini <= fila.ultimo && aux_ini >= 0){
			 printf("O valor foi encontrado na posicao %d\n", aux_ini);
			 flag = 1;
		 }
	}
	while(aux_fim > aux_ini && flag <= 0){
    meio = calcula_meio(aux_ini, aux_fim, meio, tamanho_vetor, busca, fila);
		if(meio < aux_ini || meio > aux_fim){
			flag = 2;
		}
		if(fila.dados[meio] == busca && flag == 0){
      printf("O valor foi encontrado na posicao %d\n", meio);
			flag = 1;
      break;
    }
    if(fila.dados[meio] < busca){
         aux_ini = meio+1;
    }
    if(fila.dados[meio] > busca){
         aux_fim = meio-1;
     }
		 if(fila.dados[aux_ini] == busca && flag == 0 && aux_ini >= fila.primeiro && aux_ini <= fila.ultimo){
			 printf("O valor foi encontrado na posicao %d\n", aux_ini);
			 flag = 1;
		 }
  }

	 if(flag == 0 || flag == 2){
		 printf("Valor nao encontrado!\n");
	 }
	 Ticks[1] = clock();
	 double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	 printf("Tempo gasto: %g ms\n", Tempo);
}

int calcula_meio(int aux_ini, int aux_fim, int meio, int tamanho_vetor, int busca, Fila fila){
	char b;
	printf("ENTREI\n");
	if(aux_ini < aux_fim){
      meio = aux_ini + (aux_fim-aux_ini) *((float)(busca-fila.dados[aux_ini])/(fila.dados[aux_fim] - fila.dados[aux_ini]));
	}
	if(aux_ini > aux_fim){
    meio = aux_ini + ((tamanho_vetor-aux_ini) + aux_fim) *((float)(busca-fila.dados[aux_ini])/(fila.dados[aux_fim] - fila.dados[aux_ini]));
	}
	if(meio > tamanho_vetor-1){
		meio = meio - tamanho_vetor;
	}
	return meio;
}

void criar_fila( Fila *fila, int c ) {
	fila->capacidade = c;
	fila->dados = (int*) malloc (fila->capacidade * sizeof(int));
	fila->primeiro = 0;
	fila->ultimo = -1;
	fila->nItens = 0;
}

void inserir(Fila *fila, int v) {
	if(fila->ultimo == fila->capacidade-1){
		fila->ultimo = -1;
	}
	fila->ultimo++;
	fila->dados[fila->ultimo] = v;
	fila->nItens++;
}


int fila_cheia(Fila *fila ) {
	return (fila->nItens == fila->capacidade);
}

int fila_vazia(Fila *fila ){
	return (fila->nItens==0);
}

int remover_fila(Fila *fila ) {
	int temp = fila->dados[fila->primeiro++];
	if(fila->primeiro == fila->capacidade){
		fila->primeiro = 0;
	}
	fila->nItens--;
	return temp;
}

void imprimir_fila(Fila *fila){
	int cont, i;
  printf("\n");
	for ( cont=0, i= fila->primeiro; cont < fila->nItens; cont++){
		printf("Posicao %d -> %d\n",cont, fila->dados[i++]);
		if (i == fila->capacidade)
			i=0;
	}
	printf("\n\n");
}
