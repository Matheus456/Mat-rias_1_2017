#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
  int valor;
  struct Arvore *sad;
  struct Arvore *sae;
}arvore;

arvore *inserir_arvore(arvore *raiz, int numero);
void printa(arvore *raiz);

int main() {
  arvore *raiz;
  int i, numero;
  raiz = malloc(sizeof(arvore));
  raiz->sae = NULL;
  raiz->sad = NULL;
  printf("numero de elementos da arvore?\n");
  scanf(" %d", &i);
  printf("digite o valor\n");
  scanf(" %d", &numero);
  raiz->valor = numero;
  i--;

  while (i>0) {
    printf("digite o valor\n");
    scanf(" %d", &numero);
    raiz = inserir_arvore(raiz, numero);
    i--;
  }
  printf("Os valores são:\n");
  printa(raiz);

  return 0;
}

arvore *inserir_arvore(arvore *raiz, int numero){
  if(raiz == NULL){
    raiz = malloc(sizeof(arvore));
    raiz->sae = NULL;
    raiz->sad = NULL;
    raiz->valor = numero;
  }
  else if(raiz->valor < numero){
    raiz->sad = inserir_arvore(raiz->sad, numero);
  }
  else{
    raiz->sae = inserir_arvore(raiz->sae, numero);
  }
  return raiz;
}

void printa(arvore *raiz){
  if(raiz != NULL){
    printa(raiz->sae);
    printf("%d\n", raiz->valor);
    printa(raiz->sad);
  }
}
