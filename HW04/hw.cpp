#include <iostream>

using namespace std;

int main() {

  //3 characters for input
  //C  A  T
  //a  b  c
  char a,b,c;

  //Take input
  cout << "Input a 3-letter word in uppercase letters: ";
  cin >> a >> b >> c;

  //'A' = 65 in ASCII table, 'a' = 97, so just add 32 to each character
  a += 32;
  b += 32;
  c += 32;

  //Give output
 cout << "Output: " << a << b << c << endl;

  return 0;
}
