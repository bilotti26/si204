#include <iostream>
using namespace std;

int main() {
  int zero = 0, pos = 0, neg = 0, k;
  while(cin >> k)
  {
    if (k == 0)
      zero++;
    else if (k > 0)
      pos++;
    else
      neg++;
  }
  cout << " neg = " << neg << endl;
  cout << "zero = " << zero << endl;
  cout << " pos = " << pos << endl;

  return 0;
}
