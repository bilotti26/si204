#include <iostream>
#include <cmath>

using namespace std;

void triangle(int h);

int main() {
  int tmp;
  cout << "size: ";
  cin >> tmp;
  cout << "Height-" << size << " Sierpinski triangle:";
  triangle(tmp);
  return 0;
}

void traingle(int h) {
  if (h == 1) {
    cout << "▲";
    return;
  }

  triangle(h - 1);
  
  for(int i = 0; i < h - 1; i++)
    cout << ".";

  triangle(h - 1);

  cout << endl;

  for(int i = 0; i < h; i++)
    cout << ".";
}
