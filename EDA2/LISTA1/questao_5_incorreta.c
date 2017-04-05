#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_VETOR 7

int ini = 0, fim = 0;
void imprimir(int *fila);
int incluir(int *fila,int valor);
void retirar();
void busca_binaria(int *fila, int busca);
int main(){

    int fila[TAMANHO_VETOR],valor, busca, i=0;
    char op;


    do{
      printf("--------------------------------------------\n");
      printf("A -> Incluir um vetor ordenado na fila\n");
      printf("B -> Busca Binaria\n");
      printf("I -> Incluir um elemento (int) na fila\n");
      printf("R -> Remover um elemento da fila\n");
      printf("P -> Imprimir a fila\n");
      printf("F -> Sair do programa\n");
      printf("--------------------------------------------\n");
        scanf(" %c",&op);
        if(op == 'I'){
            scanf(" %d",&valor);
        }

    switch (op){
        case 'A':
            while(incluir(fila, i)){
              i++;
            }
        break;

        case 'B':
            printf("Digite o numero que deseja encontrar\n");
            printf("Ini = %d Fim = %d\n", ini, fim);
            scanf(" %d", &busca);
            busca_binaria(fila, busca);
        break;

        case 'I':
            incluir(fila,valor);
        break;

        case 'R':
            retirar();
        break;

        case 'P':
            imprimir(fila);
            break;

        case 'F':
            return 0;
        break;
        }
    }while(1);

    return 0;
}


int incluir(int *fila,int valor){

    if(fim == ini){
        fila[fim++] = valor;
    }else{
        if(fim > ini && fim < TAMANHO_VETOR-1){
            fila[fim++] = valor;
        }
        else if(fim == (TAMANHO_VETOR-1) && ini > 0){
            fila[fim] = valor;
            fim = 0;
        }
        else if(ini>fim && ini-fim >= 2){
            fila[fim++] = valor;
        }
        else if(ini-fim == 1 || (fim == (TAMANHO_VETOR-1) && ini ==0)){
            printf("Lista cheia\n");
            return 0;
        }
    }
    return 1;
}

void busca_binaria(int *fila, int busca){
  int meio=0, aux_fim, aux_ini, repeticao=1;
  aux_fim = fim;
  aux_ini = ini;
  if(aux_ini == aux_fim){
    printf("Lista vazia\n");
  }
  else{
    while(repeticao != meio){
      repeticao = meio;
    if(aux_ini <= aux_fim){
        meio = aux_ini + (aux_fim-aux_ini)/2;
        printf("1º\n");
    }
    else if(aux_ini > aux_fim){
        meio = aux_ini + ((TAMANHO_VETOR-aux_ini) + aux_fim)/2; /*((TAMANHO_VETOR-1) - aux_ini +1)*/
        printf("2º\n");
    }
        printf("Meio = %d --- Max = %d --- Min = %d\n", meio, aux_fim, aux_ini);
        if(meio > TAMANHO_VETOR-1){
          meio = TAMANHO_VETOR - meio;
        }
        if(fila[meio] == busca){
          printf("O valor foi encontrado na posicao %d\n", meio);
          break;
        }
        if(fila[meio] < busca){
          if(meio + 1 > TAMANHO_VETOR-1){
            aux_ini = 0;
          }
          else{
            aux_ini = meio+1;
          }
        }
        if(fila[meio] > busca){
          if(meio < 0){
            aux_fim = TAMANHO_VETOR-meio;
          }
          else{
            aux_fim = meio-1;
          }
        }
    }
//       0  1  2 3 4 5 6
//      [40|50|4|5|6|9|20]

//      0  1  2  3  4  5 6
//     [40|50|60|70|80|9|20]
  }
}

void retirar(){

    if(ini == fim){
        printf("Lista vazia\n");
    }
    else if(ini == (TAMANHO_VETOR-1)){
        ini = 0;
    }
    else if(ini != fim){
        ini++;
    }
}

void imprimir(int *fila){
    int i = ini;
    if(ini == fim){
      printf("Lista esta vazia\n");
    }
    else{
      printf("Posicao do vetor[Valor do elemento]\n\n");
      while(i != fim){
        printf("%d[%d] ",i,fila[i]);

        if(i == (TAMANHO_VETOR-1)){
          i = 0;
        }else{
          i++;
        }
      }
      printf("\n");
    }
}
