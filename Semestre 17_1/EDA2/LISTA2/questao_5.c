#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
  struct Lista *prox;
  struct Lista *ant;
  int valor;
  int indice;
}lista;

typedef struct Cabecalho{
  lista *ini;
  lista *fim;
  int tamanho;
}cabecalho;

cabecalho* insere(cabecalho *principal, int num);
void printa(cabecalho *principal);
void ordena_quick_sort(cabecalho *principal, int ini, int fim);
int particiona(cabecalho *principal, int ini, int fim);
void troca(cabecalho *principal, lista *fim, lista *ini);

int main() {
  int escolha, num;
  cabecalho *principal;
  principal->ini = NULL;
  principal->fim = NULL;
  while(1){
    printf("Insira a opcao\n");
    scanf(" %d", &escolha);
    switch (escolha) {
      case 1:
        printf("Insira o valor\n");
        scanf(" %d", &num);
        principal = insere(principal, num);
      break;

      case 2:
        ordena_quick_sort(principal, 0, principal->tamanho-1);
      break;

      case 3:
        printa(principal);
      break;

      case 4:
        return 0;
      break;
    }
  }
  return 0;
}

cabecalho* insere(cabecalho *principal, int num){
  lista *aux, *novo;
  novo = malloc(sizeof(lista));
  novo->prox = NULL;
  novo->ant = NULL;
  novo->valor = num;
  aux = principal->ini;
  principal->tamanho++;
  novo->indice = 0;
  if(principal->ini == NULL){
    principal->ini = novo;
    principal->fim = novo;
  }
  else{
    while(aux->prox != NULL){
      aux = aux->prox;
      novo->indice++;
    }
    novo->indice++;
    aux->prox = novo;
    novo->ant = aux;
    principal->fim = novo;
  }
  return principal;
}

void printa(cabecalho *principal){
  lista *aux;
  aux = principal->ini;
  while(aux != NULL){
    printf("%d -- %d\n", aux->valor, aux->indice);
    aux = aux->prox;
  }
}

void ordena_quick_sort(cabecalho *principal, int ini, int fim){
  int pivo;
  printf("ini = %d e fim = %d\n", ini, fim);
  if(fim>ini){
    pivo = particiona(principal, ini, fim);
    ordena_quick_sort(principal, (pivo+1), fim);
    ordena_quick_sort(principal, ini, (pivo-1));
  }
}

int particiona(cabecalho *principal, int ini, int fim){
  lista *aux_ini, *aux_fim, *pivo;
  aux_ini = principal->ini;
  aux_fim = principal->fim;
  while(aux_ini->indice != ini && aux_ini->prox != NULL){
    aux_ini = aux_ini->prox;
  }
  pivo = aux_ini;
  while(aux_fim->indice != fim && aux_fim->ant != NULL){
    aux_fim = aux_fim->ant;
  }
  printf("aux_ini%d -- ini%d\naux_fim%d -- fim%d\n",aux_ini->indice, ini, aux_fim->indice, fim);
  while(aux_fim->indice > aux_ini->indice){
    while(pivo->valor >= aux_ini->valor && aux_ini->prox!=NULL){
      aux_ini = aux_ini->prox;
    }
    while(pivo->valor < aux_fim->valor && aux_fim->ant != NULL){
      aux_fim = aux_fim->ant;
    }
    if(aux_fim->indice > aux_ini->indice){
      troca(principal, aux_fim, aux_ini);
    }
  }
  troca(principal, aux_fim, pivo);
  printf("principal->ini%d\n", principal->ini->indice);
  return pivo->indice;
}

void troca(cabecalho *principal, lista *fim, lista *ini){
  lista *aux;
  int indice;
  if(principal->ini == ini){
    principal->ini = fim;
  }
  if(principal->fim == fim){
    principal->fim = ini;
  }
  indice = fim->indice;
  fim->indice = ini->indice;
  ini->indice = indice;

  if(fim->ant != NULL){
    fim->ant->prox = ini;
  }
  if(ini->ant != NULL){
    ini->ant->prox = fim;
  }
  aux = fim->ant;
  fim->ant = ini->ant;
  ini->ant = aux;
  if(fim->prox != NULL){
    fim->prox->ant = ini;
  }
  if(ini->prox != NULL){
    ini->prox->ant = fim;
  }
  aux = fim->prox;
  fim->prox = ini->prox;
  ini->prox = aux;
  aux = fim;
  fim = ini;
  ini = aux;
}
