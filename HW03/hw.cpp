#include <iostream>
#include <cmath>

using namespace std;

int main() {

  //Reads in two lengths in the format x feet y inches and returns the difference in length between the two in the same format
  //named as x and y because x feet y inches

  int aX, aY, bX, bY;
  
  //Create character dc (don't care) to trick the 
  char dc;
  cout << "Enter two lengths in feet and inches (larger first!)\n";
  
  //so SPACE and ENTER don't count as symbols, so just do DC for the (') symbol
  //32          '        6         ''
  //INT        CHAR      INT      CHARCHAR

  cin >> aX >> dc >> aY >> dc >> dc;
  cin >> bX >> dc >> bY >> dc >> dc;

  //Compute the difference
  //first turn them into inches
  
  int difference, aInches, bInches;
  aInches = aX * 12 + aY;
  bInches = bX * 12 + bY;

  difference = aInches - bInches;

  //Turn the difference back into feet and inches
  
  int dFeet, dInches;

  dFeet = difference / 12;
  dInches = difference % 12;

  //Output (let's add a newline too so it looks pretty)

  cout << "Difference is " << dFeet << "' " << dInches << "''" << endl;
}
