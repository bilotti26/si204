#include <iostream>
using namespace std;

int calspace(int num);

int main()
{
  int n;
  cout << "Integer? ";
  cin >> n;

  cout << "#spaces= " << calspace(n) << endl;
  return 0;
}

int calspace(int num)
{
 if (num == 0) {
   return 1;
 } else if (num < 0) {
   return 1 + calspace(-num);
 } else if (num >= 10) {
   return 1 + calspace(num / 10);
 } else {
   return 1;
 }
}
