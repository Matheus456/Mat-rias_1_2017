#include <iostream>
#include <stack>


using namespace std;

int main() {
  stack<char> pilha;
  int flag =0;
  char a;
  string texto;
  while(getline(cin, texto)){
    flag = 0;
    while(!pilha.empty()){
      pilha.pop();
    }
    for(int i=0; texto[i]!=0 && flag == 0; i++){
      if(texto[i] == '('){
        pilha.push(texto[i]);
      }
      else if(texto[i] == ')'){
        if(pilha.empty()){
          cout << "incorrect\n";
          flag=1;
          break;
        }
        pilha.pop();
      }
    }
    if(pilha.empty() && flag == 0){
      cout << "correct\n";
    }
    else if(flag == 0){
      cout << "incorrect\n";
    }
  }
  return 0;
}
