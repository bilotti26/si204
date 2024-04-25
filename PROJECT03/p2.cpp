//Andrew Bilotti 260516
//PROJECT 3 Part 1
//10APR2004
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
#include "board.h"

using namespace std;

int main() {
  cout << "board file: ";
  string fileName;
  cin >> fileName;
  board b = readFile(fileName);
  
  startCurses();

  //Draw the game board:
  drawBoard(b);
  //Create the player:
  entity Player = {board.pStart, 'P'};

  //Main list of all entities- in the future there will be enemies too, but
  //for now we are just adding the player to this list...
  entity* entityList = new entity[1];
  entityList[0] = Player;

  refreshWindow();

  // Loop forever until user enters 'q'
  char c;
  do {
    //Sleep for .15 seconds
    usleep(150000);
    //Get the player input
    c = inputChar();
  } while ( c != 'y' );

  // Close ncurses
  endCurses();

  cout << "Player start: " << b.pStart << endl;
  cout << "Spawn spots:";
  for(int i = 0; i < b.numSpawns; i++) {
    cout << " " << b.spawns[i];
  } cout << endl;
  return 0;
}

