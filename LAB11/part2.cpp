#include <iostream>

using namespace std;

void repeat(string s, int count);
void cantor_row(int length);

int main() {
  cout << "size: ";
  int l;
  cin >> l;
  cout << "Width-" << l << " Cantor set:" << endl;
  cantor_row(l);
  cout << endl;
  return 0;
}

void repeat(string s, int count) {
  if (count <= 0) {
    return;
  } else {
    cout << s;
    repeat(s, count - 1);
  }
}

void cantor_row(int length) {
  if (length <= 1) {
    cout << "X";
  } else {
    //Width (length / 3) cantor region
    cantor_row(length / 3);
    //Width (length / 3) empty region
    repeat("_", length / 3);
    //Width (length / 3) cantor set
    cantor_row(length / 3);
  }
}

