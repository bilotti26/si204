#include <iostream>
#include <cmath>

int gcd(int n1, int n2);

using namespace std;

int main() {
  int n1,n2;
  char dc;
  while(dc != ';') {
    cin >> n1 >> dc >> n2 >> dc;

    if (gcd(n1,n2) == 1) {
      cout << n1 << "/" << n2 << " is in lowest terms!" << endl;
    }
  }

  return 0;
}

int gcd(int n1, int n2) {
  //Find their greatest common denominator

  //First clue- the GCD will be no more than the smaller of the 2 numebrs
  //condition ? result_if_true : result_if_fale

  for(int i = (n1 > n2) ? n2 : n1; i > 0; i--) {
  //Go down until result is 0
    if (n1 % i == 0 && n2 % i == 0)
      return i;
  }
  return 1;
}
