#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int main() {
  map<string, double> frutas;
  int n, i, j, qnt;
  string nome;
  double preco, total=0;
  cin >> n;
  while(n>0){
    total = 0;
    cin >> i;
    while(i>0){
      cin >> nome;
      cin >> preco;
      frutas[nome] = preco;
      i--;
    }
    cin >>  j;
    while(j>0){
      cin >> nome;
      cin >> qnt;
      total = total + frutas[nome]*qnt;
      j--;
    }
    printf("R$ %.2lf\n", total);
    cout << "R$ " << fixed << setprecision(2) << total << endl;
    n--;
  }
  return 0;
}
