#include <iostream>
#include <cmath>

using namespace std;

int main() {

  //Reads in two lengths in the format x feet y inches and returns the difference in length between the two in the same format
  
  int aX, aY, bX, bY;
  char dc;
  cout << "Enter two lengths in feet and inches (larger first!)\n";
  cin >> aX >> dc >> aY >> dc;
  cin >> bX >> dc >> bY;
  cout << bX << bY;

}
