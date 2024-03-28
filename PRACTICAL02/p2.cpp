#include <iostream>

using namespace std;

string isSpecial(string str);

int main() {
  string* words = new string[100];

  string dc;
  int count = 0;
  cin >> dc;
  int i = 0;
  while (true) {
    string str;
    cin >> str;
    if (str == ".")
      break;
    if(isSpecial(str) != "null"){
      words[count] = isSpecial(str);
      count++;
    }
  }
  for(int j = 0; j < count; j++)
    cout << words[j] << ((j == count - 1) ? "" : " ");
  cout << endl;
  
  delete [] words;

  return 0;
}











string isSpecial(string str) {
  string tmp = str;
  int n = tmp.length();
  char c = tmp[0];
  bool special = false;
  for(int i = 1; i < n; i++) {
    if (tmp[i] == c) {
      special = true;
      tmp[i] = tmp[i] - 32;
    }
  }
  if (special) {
    tmp[0] -= 32;
    return tmp;
  } else
    return "null";
}

