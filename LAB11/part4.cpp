#include <iostream>
#include <cmath>

using namespace std;

void repeat(string s, int count);
void carpet_row(int row, int col, int size);
  int main() {
  cout << "size: ";
  int l;
  cin >> l;
  cout << "Width-" << l << " Sierpinski carpet:" << endl;
  carpet_row(0,0,l);
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


//reworked carpet row function
//Since size makes it square, we can do a lot of weird things
void carpet_row(int row, int col, int size) {
  //We will start always @ (0, 0), work out way left and right
  //String definiton for diamond
  string DIAMOND = "\u2bc1";
  //Two base cases: check if it is a space (part of the hole)
  //♦♦♦->will go to base case 3 times, all diamonds
  //♦ ♦->diamond hole diamond
  //♦♦♦->again goes to base case 3 times
  
  //Space base case: basically if the row and the column is small enough
  if ((row / size) % 3 <= 1 && 
      (col / size) % 3 <= 1) {
    cout << " ";
    return;
  }

  //Diamond base case - size reduced every iteration till we get diamonds 
  if (size == 1) {
    cout << DIAMOND;
    return;
  }

  //Print the subsquares for each subsquare
  //in relation to top right 
  //TOP LEFT
  carpet_row(row, col, size / 3);
  //TOP CENTER
  carpet_row(row, col + size / 3, size / 3);
  //TOP RIGHT
  carpet_row(row, col + 2 * size / 3, size / 3);
  //MIDDLE LEFT
  carpet_row(row + size / 3, col, size / 3);
  //NO CARPET ROW FOR THE CENTER--BLANK SPACE!!!

  //MIDDLE RIGHT
  carpet_row(row + size / 3, col + 2 * size / 3, size / 3);
  //BOTTOM LEFT
  carpet_row(row + 2 * size / 3, col, size / 3);
  //BOTTOM CENTER
  carpet_row(row + 2 * size / 3, col + size / 3, size / 3);
  //BOTTOM RIGHT
  carpet_row(row + 2 * size / 3, col + 2 * size / 3, size / 3);
}
