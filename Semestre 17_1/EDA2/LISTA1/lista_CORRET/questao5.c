#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
	int primeiro;
	int ultimo;
	int *dados;
	int capacidade;
	int nItens;
}Fila;

void menu();
void busca_binaria(Fila fila, int busca, int tamanho_vetor);
void criarFila( Fila *fila, int c );
void inserir(Fila *fila, int v);
int remover( Fila *fila );
int estaVazia( Fila *fila );
int estaCheia( Fila *fila );
void mostrarFila(Fila *fila);
int calcula_meio(int aux_ini, int aux_fim, int meio, int tamanho_vetor);

void main () {

	int tamanho_vetor;
	char opcao;
	int valor, busca;
	Fila fila_1;

	printf("Capacidade da fila? ");
	scanf("%d",&tamanho_vetor);
	criarFila(&fila_1, tamanho_vetor);

	while(1){
		menu();
		scanf(" %c", &opcao);

		switch(opcao){

			case 'E': exit(0);

			case 'A':
				if (estaCheia(&fila_1)){
					printf("\nFila Cheia!!!\n\n");
				}

				else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%d", &valor);
					inserir(&fila_1,valor);
				}
				break;

			case 'B':
      	if (estaVazia(&fila_1)){
					printf("\nFila vazia!!!\n\n");
				}

				else {
					valor = remover(&fila_1);
					printf("\n%d removido com sucesso\n\n", valor) ;
				}
				break;

			case 'C': // mostrar fila
				if (estaVazia(&fila_1)){
					printf("\nFila vazia!!!\n\n");
				}

				else {
					printf("\nConteudo da fila => ");
					mostrarFila(&fila_1);
				}
				break;

        case 'D':
        if (estaVazia(&fila_1)){
            printf("\nFila vazia!!!\n\n");
        }

				else{
          scanf(" %d", &busca);
          busca_binaria(fila_1, busca, tamanho_vetor);
        }
        break;

			default:
				printf("\nOpcao Invalida\n\n");

		}
	}
}
void busca_binaria(Fila fila, int busca, int tamanho_vetor){
	/*A flag é para notificar se o número foi encontrado ou não*/
  int meio=0, aux_fim, aux_ini, flag = 0;
  aux_ini = fila.primeiro;
  aux_fim = fila.ultimo;

	/*Se fim estiver antes do inicio*/
	while(aux_fim < aux_ini){
		meio = calcula_meio(aux_ini, aux_fim, meio, tamanho_vetor);
		if(fila.dados[meio] == busca){
	    printf("O valor foi encontrado na posicao %d\n", meio);
			flag = 1;
	    break;
	  }
		/*Incrementando inicio*/
	  if(fila.dados[meio] < busca){
	      if(meio + 1 > tamanho_vetor-1){
	        aux_ini = 0;
	      }
	      else{
	         aux_ini = meio+1;
	    }
		}

		/*Incrementando fim*/
	  if(fila.dados[meio] > busca){
	      if(meio < 0){
	        aux_fim = tamanho_vetor-meio;
	      }
	      else{
	         aux_fim = meio-1;
	      }
	   }
	}

	/*Se fim estiver depois do inicio*/
	while(aux_fim > aux_ini && flag == 0){
		meio = calcula_meio(aux_ini, aux_fim, meio, tamanho_vetor);
    if(fila.dados[meio] == busca){
      printf("O valor foi encontrado na posicao %d\n", meio);
			flag = 1;
      break;
    }
		/*Incrementando inicio*/
		if(fila.dados[meio] < busca){
         aux_ini = meio+1;
    }

		/*Incrementando fim*/
    if(fila.dados[meio] > busca){
         aux_fim = meio-1;
     }
  }
	/*Se inicio igual a fim*/
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


void criarFila( Fila *fila, int c ) {
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

int remover(Fila *fila ) {
	int temp = fila->dados[fila->primeiro++];
	if(fila->primeiro == fila->capacidade){
		fila->primeiro = 0;
	}

	fila->nItens--;
	return temp;
}

int estaVazia(Fila *fila ) {
	return (fila->nItens==0);
}

int estaCheia(Fila *fila ) {
	return (fila->nItens == fila->capacidade);
}

void mostrarFila(Fila *fila){
	int cont, i;
  printf("\n");
	for ( cont=0, i= fila->primeiro; cont < fila->nItens; cont++){
		printf("Posicao %d -> %d\n",cont, fila->dados[i++]);
		if (i == fila->capacidade)
			i=0;
	}
	printf("\n\n");
}

void menu(){
	printf("------------------------");
	printf("\nA - Inserir elemento\nB - Remover elemento\nC -");
	printf("Mostrar Fila\nD - Buscar na Fila\nE - Sair\n");
	printf("------------------------\n\nOpcao? ");
}
