#include <iostream>
#include <cmath>

using namespace std;

int main() {

  //year to check if it is a leap year
  int year;

  //If divisible by 400, then leap year
  //If divisible by 100, then not leap year
  //If divisible by 4, not 100, then leap year
  
  //Input
  cout << "Enter year: ";
  cin >> year;

  //String so I only cout once
  string s;

  //Logic
  if (year % 4 == 0) {
    if (year % 400 == 0) {
      s = "Is Leap Year";
    } else if (year % 100 == 0) {
      s = "Is Not Leap Year";
    } else {
      s = "Is Leap Year";
    }
  } else {
    s = "Is Not Leap Year";
  }

  //Print the output
  cout << s << endl;

  return 0;
}
