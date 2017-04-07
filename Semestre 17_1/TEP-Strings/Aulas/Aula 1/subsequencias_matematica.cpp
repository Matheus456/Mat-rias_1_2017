/*Programa para calcular subsequências por matemática*/
#include <iostream>


using namespace std;
int main() {
  string s;
  int n;
  cin >> s;
  n = s.size();

  /*1<<n é o valor de 1 em binário, que é 00000001, deslocado n bits, caso n = 1,
  o valor seria 00000010. Se fosse 2 00000100. E assim por diante. Basicamente
  que dizer 2^n*/
  for(int i=0; i<(1<<n/*2^n*/); ++i){
    for(int j=0; j<n; j++){
      /*& é uma and binária e && é uma porta lógica and, logo 1&2 = 0 e 3&1 = 1
      e 1&&2 = 1 pois comparando de bit a bit, eles não são iguais, porém se
      comparar com && ele verifica se os valores são ambos verdadeiros,
      que é o caso*/
      if(i&/*AND binária*/(1<<j)){
        cout << s[j];
      }
    }
    cout << endl;
  }

//  cout << (2&1) << endl <<
//  cout << (3&1) << endl;
  return 0;
}
