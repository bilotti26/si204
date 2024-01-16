#include <iostream>
#include <cmath>
using namespace std;

int main() {

char m;
cin >> m;

int alpha;
cin >> alpha;

int d, y;
//find 26XXXX
d = alpha / 10000;
y = d + 2000;

cout << "Class of " << y << '\n';

return 0;

}
