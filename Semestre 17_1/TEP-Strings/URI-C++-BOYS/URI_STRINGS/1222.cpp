#include <iostream>
#include <string>

using namespace std;

int main() {
  int N_palavra, linhas_pag, caracteres_linha;
  int i=0, tamanho;
  string palavra;

  cin >> N_palavra >> linhas_pag >> caracteres_linha;
  getline(cin, palavra);
  tamanho = palavra.size();

  while(palavra[i] != ' '){
    i++;
  }



  return 0;
}
