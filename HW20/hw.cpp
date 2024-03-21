// Andrew Bilotti 260516 HW20
#include <iostream>

using namespace std;

int main() {
  int legs;
  cout << "How many legs? ";
  cin >> legs;

  string* trip = new string[legs + 1];

  string deltaC;
  for(int i = 0; i < legs; i++) {
    char dc,c1,c2,c3,c4,c5,c6;
    cin >> c1 >> c2 >> c3 >> dc >> dc >> c4 >> c5 >> c6;

    trip[i] = "___";
    trip[i][0] = c1;
    trip[i][1] = c2;
    trip[i][2] = c3;
    string tmp = "___";
    tmp[0] = c4;
    tmp[1] = c5;
    tmp[2] = c6;

    if (i != 0 && trip[i] != deltaC){
      cout << "city mismatch" << endl;
      return 0;
    } else {
      deltaC = tmp;
    }
  }
  trip[legs] = deltaC;

  cout << "Reverse trip: ";
  for(int i = legs; i >= 0; i--)
    cout << trip[i] << ((i == 0) ? "" : "->");
  cout << endl;
  return 0;
}
