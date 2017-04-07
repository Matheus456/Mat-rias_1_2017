#include <iostream>
#include <stack>

using namespace std;
int main() {
  stack<char> pilha;
  string diamantes;
  int n_repeticoes, n_diamante=0;
  cin >> n_repeticoes;
  while(n_repeticoes>0){
    while(!pilha.empty()){
      pilha.pop();
    }
    cin >> diamantes;
    for(int i=0; diamantes[i]!=0; i++){
      if(diamantes[i] == '<'){
        pilha.push('<');
      }
      if(diamantes[i] == '>'){
        if(!pilha.empty()){
          n_diamante++;
          pilha.pop();
        }
      }
    }
    cout << n_diamante << endl;
    n_diamante =0;
    n_repeticoes--;
  }
  return 0;
}
