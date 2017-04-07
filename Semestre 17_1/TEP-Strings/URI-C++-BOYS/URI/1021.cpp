#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int  real, centavo;
  int n100, n50, n20, n10, n5, n2, n1, n050, n025, n010, n005, n001;
  scanf(" %d.%d", &real, &centavo);
  n100 = real/100;
  n50 = (real - n100*100)/50;
  n20 = (real - n100*100 - n50*50)/20;
  n10 = (real - n100*100 - n50*50 - n20*20)/10;
  n5 = (real - n100*100 - n50*50 - n20*20 - n10*10)/5;
  n2 = (real - n100*100 - n50*50 - n20*20 - n10*10 - n5*5)/2;
  n1 = (real - n100*100 - n50*50 - n20*20 - n10*10 - n5*5 - n2*2);

  n050 = centavo/50;
  n025 = (centavo - n050*50)/25;
  n010 = (centavo - n050*50 - n025*25)/10;
  n005 = (centavo - n050*50 - n025*25 - n010*10)/5;
  n001 = (centavo - n050*50 - n025*25 - n010*10 - n005*5);

  cout<< "NOTAS:\n";
  cout << n100 << " nota(s) de R$ 100.00\n";
  cout << n50 << " nota(s) de R$ 50.00\n";
  cout << n20 << " nota(s) de R$ 20.00\n";
  cout << n10 << " nota(s) de R$ 10.00\n";
  cout << n5 << " nota(s) de R$ 5.00\n";
  cout << n2 << " nota(s) de R$ 2.00\n";

  cout<< "MOEDAS:\n";
  cout << n1 << " moeda(s) de R$ 1.00\n";
  cout << n050 << " moeda(s) de R$ 0.50\n";
  cout << n025 << " moeda(s) de R$ 0.25\n";
  cout << n010 << " moeda(s) de R$ 0.10\n";
  cout << n005 << " moeda(s) de R$ 0.05\n";
  cout << n001 << " moeda(s) de R$ 0.01\n";

  return 0;
}
