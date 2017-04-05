#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
  struct Lista *prox;
  struct Lista *ant;
  int valor;
  int indice;
}lista;

lista *inserir_lista(lista *lista_anel, int i);
void busca_lista(lista *lista_anel, int busca);
void impressao_lista(lista *lista_anel);
lista *ordenar_lista(lista *lista_anel);

int main() {
  char escolha;
  int i=0, busca;
  lista *lista_anel;
  lista_anel = malloc(sizeof(lista));
  lista_anel->prox = NULL;
  lista_anel->ant = NULL;
  while (1) {
    printf("Digite a sua escolha:\n");
    scanf(" %c", &escolha);
    switch (escolha) {
      case 'a':
        printf("Digite o valor\n");
        if(i==0){
          scanf(" %d", &lista_anel->valor);
          lista_anel->indice = i;
        }
        else{
          lista_anel = inserir_lista(lista_anel, i);
        }
        printf("%d\n", i);
        i++;
        break;

      case 'b':
        lista_anel = ordenar_lista(lista_anel);
        printf("Lista ordenada!\n");
        break;

      case 'c':
        printf("Digite a busca\n");
        scanf(" %d", &busca);
        busca_lista(lista_anel, busca);
        break;

      case 'd':
        impressao_lista(lista_anel);
        break;

      case 'e':
        return 0;

      default:
        printf("Digite uma das letras da opcao!\n");
    }
  }
  return 0;
}

lista *inserir_lista(lista *lista_anel, int i){
  lista *novo, *aux;
  aux = lista_anel;
  novo = malloc(sizeof(lista));
  scanf(" %d", &novo->valor);
  novo->indice = i;

  if(lista_anel->prox == NULL){
     lista_anel->prox = novo;
     lista_anel->ant = novo;
     novo->ant = lista_anel;
     novo->prox = lista_anel;
  }
  else{
    while((aux->prox)->indice != 0){
        aux = aux->prox;
    }
    (aux->prox)->ant = novo;
    novo->prox = aux->prox;
    aux->prox = novo;
    novo->ant = aux;
  }
  return lista_anel;
}

void busca_lista(lista *lista_anel, int busca){
  lista *aux;
  int fim=0, meio, ini=0;
  aux = lista_anel;
  while((aux->prox)->indice != 0){
    aux = aux->prox;
    fim++;
  }
  while(fim >= ini){
    aux = lista_anel;
    meio = ini + (fim-ini)/2;
    /*Laço para chegar até o meio*/
    while(aux->indice != meio){
      aux = aux->prox;
    }
    if(aux->valor > busca){
      fim = aux->indice - 1;
    }
    else if(aux->valor < busca){
      ini = aux->indice + 1;
    }
    else if(aux->valor == busca){
      printf("Encontrado! Está localizado na posicao %d da lista\n", aux->indice);
      fim = -3;
    }

  }
}

void impressao_lista(lista *lista_anel) {
  lista *aux;
  aux = lista_anel;
  while(aux->prox->indice != 0){
    printf("%d-", aux->valor);
    aux = aux->prox;
  }
  printf("%d\n", aux->valor);
}

lista *ordenar_lista(lista *lista_anel){
  lista *aux, *aux2;
  int swap;
  aux = lista_anel;
  aux2 = lista_anel;
  while((aux->prox)->indice != 0){
    aux2 = aux->prox;
    while(aux2->indice != 0){
      if(aux->valor > aux2->valor){
        swap = aux->valor;
        aux->valor = aux2->valor;
        aux2->valor = swap;
      }
    aux2 = aux2->prox;
    }
    aux = aux->prox;
  }
  return lista_anel;
}
