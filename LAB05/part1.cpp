//NAME: Andrew Bilotti
//ALPHA: 260516
//DATE: 8FEB2024
//PROJECT: Lab 5 Part 1
//Comments: I am using a lot of returns to make it a lot more efficient,
//if a requirement isn't met or the player dies then might as well
//close the program then :)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
 //Read the board, choose a column to march down, and if there is an X,
 //then you die.
 //
 //Example board:
 //width = 10
 //@X.........@
 //@......X...@
 //@....X....X@
 //@..X.......@
 //@........X.@
 //@.....X....@

  //Boolean for debugging, if turend on it outputs what it reads
  bool debugEnable = false;

  //Read in the file
  string filename;
  cin >> filename;

  //Create the fin & check if it can open
  ifstream fin(filename);
  if (!fin){
    cout << "File not found!" << endl;
    return 1;
  }

  //Get the width from the file and get the position from user
  int width,position;
  string dc1;
  char dc2;

  //width =     10
  //dc1   dc2   width
  fin >> dc1 >> dc2 >> width;

  //Read in the position to go down the board
  cout << "Enter position between 1 and " << width << ": ";
  cin >> position;

  //If the position is more than the width output an error
  if (position > width) {
    cout << "Invalid position!" << endl;
    return 0;
  }
  
  //Integer to store the death step
  int deathStep = 1;

  //Read line by line the board
  while (fin) {
    //for loop for each line, which will be width + 2 for the @ chars
    for(int i = 1; i <= width + 2; i++) {
      //Read in the tile of the board
      char tile;
      fin >> tile;
      if (debugEnable)
        cout << tile;
      //Check if its the row the user selected and if its a period
      //Position is added 1 because of the @ character at the beginning
      //of each row.
      if (i == position + 1 && tile == 'X') {
        cout << "You died on step " << deathStep << endl;
        return 0;
      }
    }
    //We are going onto the next step, so deathstep goes up 1 :)
    deathStep++;

    //An endl is in the file and so we go to the next row
    if (debugEnable)
      cout << endl;
  }

  //If you died, the program would have exited already.
  cout << "You survived!" << endl;

  //close the program
  fin.close();
  return 0;
}
