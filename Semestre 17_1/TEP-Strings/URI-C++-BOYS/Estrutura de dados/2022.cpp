#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iomanip>

using namespace std;

typedef struct Aparelho{
  string nome;
  double preco;
  int prio;
}aparelho;

bool compara(const aparelho &a, const aparelho &b);

int main() {
  vector<aparelho> lista;
  string nome;
  double preco;
  int i;
  while(cin >> nome){
    cin >> i;
    getchar();
    for(int j=0; j<i; j++){
      lista.push_back(aparelho());
      getline(cin, lista[j].nome);
      //cin >> lista[j].nome;
      cin >> lista[j].preco;
      getchar();
      cin >> lista[j].prio;
      getchar();
      //std::cout << "passeiprio" << '\n';
    }
    sort(lista.begin(), lista.end(), compara);
    cout << "Lista de " << nome << endl;
    for(int j=0; j<i; j++){
      cout << lista[j].nome <<  " - R$";
      preco = lista[j].preco;
      cout << fixed << setprecision(2) << preco << endl;
    }
    cout << '\n';
    }
  return 0;
}

bool compara(const aparelho &b, const aparelho &a)
{
  if(a.prio == b.prio){
    if(a.preco != b.preco){
      return a.preco > b.preco;
    }
    else{
      return a.nome > b.nome;
    }
  }
    return a.prio < b.prio;
}
