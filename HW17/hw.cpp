#include <iostream>
#include <string>

using namespace std;

int main() {
  int n; //number of words

  //take in number of words
  cout << "Number of words: ";
  cin >> n;

  string *sentence = new string[n];
  
  //take in sentence
  cout << "Sentence: ";
  for(int i=0; i<n; i++) {
    string word;
    cin >> word;
    sentence[i] = word;
  }

  //output reg sentence
  for(int i = 0; i < n; i++){
    cout << sentence[i] << ((i == n - 1) ? "" : " ");
  }
  cout << "? ";
  
  //output rev sentence
  for(int i = n - 1; i >= 0; i--) {
    cout << sentence[i] << ((i == 0) ? "" : " ");
  }
  cout << "!" << endl;

  return 0;
}
