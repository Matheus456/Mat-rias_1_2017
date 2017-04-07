#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens;
}Fila;
void busca_binaria(Fila fila, int busca, int tamanho_vetor);
void criarFila( Fila *f, int c );
void inserir(Fila *f, int v);
int remover( Fila *f );
int estaVazia( Fila *f );
int estaCheia( Fila *f );
void mostrarFila(Fila *f);
int calcula_meio(int aux_ini, int aux_fim, int meio, int tamanho_vetor);

void main () {

	int tamanho_vetor;
	char opcao;
	int valor, busca;
	Fila umaFila;

	printf("Capacidade da fila? ");
	scanf("%d",&tamanho_vetor);
	criarFila(&umaFila, tamanho_vetor);

	while(1){
		printf("------------------------");
		printf("\nA - Inserir elemento\nB - Remover elemento\nC -");
		printf("Mostrar Fila\nD - Buscar na Fila\nE - Sair\n");
		printf("------------------------\n\nOpcao? ");
		scanf(" %c", &opcao);


		switch(opcao){

			case 'E': exit(0);

			case 'A':
				if (estaCheia(&umaFila)){
					printf("\nFila Cheia!!!\n\n");
				}
				else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%d", &valor);
					inserir(&umaFila,valor);
				}
				break;

			case 'B':
      if (estaVazia(&umaFila)){
					printf("\nFila vazia!!!\n\n");
				}
				else {
					valor = remover(&umaFila);
					printf("\n%d removido com sucesso\n\n", valor) ;
				}
				break;

				case 'C': // mostrar fila
					if (estaVazia(&umaFila)){
						printf("\nFila vazia!!!\n\n");
					}
					else {
						printf("\nConteudo da fila => ");
						mostrarFila(&umaFila);
					}
					break;

          case 'D':
          if (estaVazia(&umaFila)){
              printf("\nFila vazia!!!\n\n");
          }
          else{
            scanf(" %d", &busca);
            busca_binaria(umaFila, busca, tamanho_vetor);
          }
          break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
}
void busca_binaria(Fila fila, int busca, int tamanho_vetor){
  int meio=0, aux_fim, aux_ini, flag = 0;
  aux_ini = fila.primeiro;
  aux_fim = fila.ultimo;
	while(aux_fim < aux_ini){
		meio = calcula_meio(aux_ini, aux_fim, meio, tamanho_vetor);
		if(fila.dados[meio] == busca){
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
	}
	while(aux_fim > aux_ini && flag == 0){
		meio = calcula_meio(aux_ini, aux_fim, meio, tamanho_vetor);
    if(fila.dados[meio] == busca){
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
  }
	/*Caso o aux_fim == aux_ini*/

	 if(fila.dados[aux_ini] == busca && flag == 0){
 			printf("O valor foi encontrado na posicao %d\n", aux_ini);
			flag = 1;
	 }
	 if(flag == 0){
		 printf("Valor nao encontrado!\n");
	 }
}

int calcula_meio(int aux_ini, int aux_fim, int meio, int tamanho_vetor){
	if(aux_ini < aux_fim){
		  meio = aux_ini + (aux_fim-aux_ini)/2;
	}
	if(aux_ini > aux_fim){
		meio = aux_ini + ((tamanho_vetor-aux_ini) + aux_fim)/2; /*(((tamanho_vetor-1) - aux_ini) +1)*/
	}
	if(meio > tamanho_vetor-1){
		meio = tamanho_vetor - meio;
	}
	return meio;
}


void criarFila( Fila *f, int c ) {
	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;
}

void inserir(Fila *f, int v) {
	if(f->ultimo == f->capacidade-1){
		f->ultimo = -1;
	}
	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++;
}

int remover(Fila *f ) {
	int temp = f->dados[f->primeiro++];
	if(f->primeiro == f->capacidade){
		f->primeiro = 0;
	}
	f->nItens--;
	return temp;
}

int estaVazia(Fila *f ) {
	return (f->nItens==0);
}

int estaCheia(Fila *f ) {
	return (f->nItens == f->capacidade);
}

void mostrarFila(Fila *f){
	int cont, i;
  printf("\n");
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){
		printf("Posicao %d -> %d\n",cont, f->dados[i++]);
		if (i == f->capacidade)
			i=0;
	}
	printf("\n\n");
}
