#include <iostream>

using namespace std;

int main() {
  float inteiro;
  int dia, mes, ano;
  cin >> inteiro;
  ano = (int)inteiro/365;
  mes = (int)(((inteiro/365)-ano)*365/30);
  dia= (int)inteiro-((ano*365)+(mes*30));
  cout << ano << " ano(s)\n";
  cout << mes << " mes(es)\n";
  cout << dia << " dia(s)\n";
  return 0;
}
