#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  int i, k = 0;
  queue<int> fila, descartados;
  cin >> i;
  while(i != 0){
    for(int j=1; j<=i; j++){
      fila.push(j);
    }
    for(int j=i; j>1; j--){
      descartados.push(fila.front());
      fila.pop();
      fila.push(fila.front());
      fila.pop();
    }
    cout << "Discarded cards: ";
    while(k < (descartados.size()-1)){
      cout <<descartados.front() << ", ";
      descartados.pop();
    }
    cout <<descartados.front() << endl;
    cout << "Remaining card: " << fila.front() << endl;
    cin >> i;
    while(!descartados.empty()) descartados.pop();
    while (!fila.empty()) fila.pop();
  }
  return 0;
}
