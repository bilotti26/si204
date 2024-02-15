//NAME: Andrew Bilotti
//ALPHA: 260516
//DATE: 8FEB2024
//PROJECT: Lab 5 Part 1
//Comments: I am using a lot of returns to make it a lot more efficient,
//if a requirement isn't met or the player dies then might as well
//close the program then :)
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

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
  bool debugEnable = true;

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

  //String to hold the whole board
  string board, boardWPosition;

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

      if (debugEnable){
        //Give a bunch of space in between boards
        //To give the illusion of animation
        for (int j = 0; j < 30; j++) {
          cout << endl;
        }
        if (tile != '@')
          cout << board << "~";
        else {
          cout << board << "@";
        }
        //cout question marks
        for (int j = i; j <= width + 1; j++) {
          if (j == width + 1)
            cout << "@";
          else {
            cout << "?";
          }
        }
        cout << endl;
        cout << "*** Score: " << deathStep << " GOOD LUCK!" << endl;
        
        //for uniformity
        if (i != width + 2)
          cout << endl << endl;

        if (i == position + 1)
          board += 'U';
        else 
          board += tile;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
      }
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
      board += '\n';
    
    cout << endl << "Enter left right or down for your next turn: ";
    //Wait until user inputs s
    string nextTurn;
    cin >> nextTurn;

    if (nextTurn == "left") {
      position--;
    }
    else if (nextTurn == "right") {
      position++;
    }
  }

  //If you died, the program would have exited already.
  cout << "You survived!" << endl;

  //close the program
  fin.close();
  return 0;
}
