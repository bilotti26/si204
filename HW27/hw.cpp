#include <iostream>
using namespace std;

double pow(double, int);

int main()
{
  double x;
  int n;
  cout << "Enter x and n: ";
  cin >> x >> n;
  cout << "x^n is " << pow(x,n) << endl;
  return 0;
}

// Define pow: it must be recursive!
double pow(double x, int n) {
  if (n == 0)
    return 1.0;
  else if (n <= 0)
    return (1 / x) * pow(x, n + 1);
  else
    return x * pow(x, n - 1);
}
