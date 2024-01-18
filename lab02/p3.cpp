//Andrew Bilotti, Lab 02 Unix Permissions

#include <iostream>
#include <cmath>

using namespace std;


int main() {
  //3-digit number
  //Each digit is 3-bit number
  //e.g. 7 -> 111 -> rwx, etc;
  
  cout << "Permissions: ";

  int i;
  cin >> i;

  //split into 3 seperate numbers
  int a,b,c;
  a = i / 100;
  b = (i % 100) / 10;
  c = i % 10;

  //cout << a << b << c;
  
  //First group : user
  int R, W, X;
  X = a % 2;
  W = (a / 2) % 2;
  R = (a / 4) % 2;

  cout << "User: \n";
  cout << "read    " << R << "\n";
  cout << "write   " << W << "\n";
  cout << "execute " << X << "\n\n";

  //Second group : Group
  X = b % 2;
  W = (b / 2) % 2;
  R = (b / 4) % 2;

  cout << "Group: \n";
  cout << "read    " << R << "\n";
  cout << "write   " << W << "\n";
  cout << "execute " << X << "\n\n";

  //Third group: Other
  X = c % 2;
  W = (c / 2) % 2;
  R = (c / 4) % 2;

  cout << "Other: \n";
  cout << "read    " << R << "\n";
  cout << "write   " << W << "\n";
  cout << "execute " << X << "\n\n";

}
