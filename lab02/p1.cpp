//Andrew Bilotti, Lab 02 Reading binary numbers

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int i;

  cout << "Enter a 4-bit binary number: ";
  
  cin >> i;

  bool a,b,c,d;

  a = i / 1000;

  b = (i % 1000) / 100;
  
  c = (i % 100) / 10;

  d = (i % 10);

  //Decimal value
  int ans;

  ans = a * pow(2, 3) + b * pow(2, 2) + c * pow(2, 1) + d;

  cout << "In decimal " << a << b << c << d << " = " << ans << "\n";

}
