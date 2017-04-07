#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n_carros, vagas, entrada, saida, tempo = 0, flag = 0;
  stack<int> pilha;
  cin >> n_carros >> vagas;
  while(n_carros > 0){
      cin >> entrada >> saida;
    if(flag == 0){

      if(pilha.size() <=2){
        pilha.push(saida);
        entrada = saida+1;
        cout << entrada << pilha.top();
      }

      if(pilha.size() == vagas){
        if(entrada<pilha.top()){
          cout << "\nENTREI1\n";
          flag = 1;
        }
        while(pilha.top()>tempo){
          tempo++;
        }
        pilha.pop();
      }
      if(pilha.top()<tempo){
        cout << "\nENTREI2\n";
        flag = 1;
      }
      if(pilha.top() == tempo){
        pilha.pop();
      }
      if(pilha.size() <=2){
        pilha.push(saida);
        entrada = saida+1;
      }
    }
    n_carros--;
  }
  if(!pilha.empty() && flag != 1){
    while(pilha.top()>tempo){
      tempo++;
    }
    pilha.pop();
    if(pilha.top()<tempo){
      cout << "\nENTREI2\n";
      flag = 1;
    }
  }

  if(flag == 1){
    cout << "nao\n";
  }
  else{
    cout << "sim\n";
  }
  return 0;
}
