//Andrew Bilotti 260516
//Practicum 1
//part 3
//15 feb 2023
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  int middleRow = n - (n/2);

  for (int i = 0; i < middleRow - 1; i++) {
    //first middle and last columns
    for(int j = 0; j < i; j++)
      cout << '.';
    cout << '@';
    for(int j = i + 2; j < n - i; j++)
      cout << '.';
    cout << '@';
    for(int j = n - i; j < n; j++)
      cout << '.';

    cout << endl;
  }
  
  if (n % 2 == 0) {
    for (int i = 1; i < n / 2; i++)
      cout << '.';
    cout << "@@";
    for (int i = n / 2; i < n - 1; i++)
      cout << '.';
    cout << endl;
    for (int i = 1; i < n / 2; i++)
      cout << '.';
    cout << "@@";
    for (int i = n / 2; i < n - 1; i++)
      cout << '.';

  } else {
    for (int i = 0; i < n / 2; i++)
      cout << '.';
    cout << '@';
    for (int i = n / 2; i < n - 1; i++)
      cout << '.';
  }
  cout << endl;
  //other for but in reverse
  for (int i = middleRow - 2; i >= 0; i--) {
    for(int j = 0; j < i; j++)
      cout << '.';
    cout << '@';
    for(int j = i + 2; j < n - i; j++)
      cout << '.';
    cout << '@';
    for(int j = n - i; j < n; j++)
      cout << '.';

    cout << endl;

  }
  return 0;
}
