//Andrew Bilotti, Lab 02 Converting back to binary 

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  //Number to be converted
  int i;

  cout << "Enter a number between 0 and 15: ";
  cin >> i;

  bool a,b,c,d;
  
  //14 = 2^3 + 2^2 + 2^1 + 0*2^0

  //8 only if greater than num - 8 gt 0
  d = i % 2;
  c = (i / 2) % 2;
  b = (i / 4) % 2;
  a = (i / 8) % 2;

  cout << i << " in binary is " << a << b << c << d << endl;
}
