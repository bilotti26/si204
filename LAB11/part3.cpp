#include <iostream>
#include <cmath>

using namespace std;

void repeat(string s, int count);
void cantor_row(int length);
void cantor_row(int width, int levels);

int main() {
  cout << "size: ";
  int l;
  cin >> l;
  cout << "Width-" << l << " Cantor set:" << endl;
  for(int i = 0; i < log(l) / log(3) + 1; i++) {
    cantor_row(l, i);
    cout << endl;
  }
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

void cantor_row(int width, int levels) {
  if (levels <= 0) {
    repeat("X", width);
  } else if (width <= 1) {
    repeat("X", width / 3 - levels);
  } else {
    //Width (length / 3) cantor region
    cantor_row(width / 3, levels - 1);
    //Width (length / 3) empty region
    repeat("_", width / 3);
    //Width (length / 3) cantor set
    cantor_row(width / 3, levels - 1);
  }
}

