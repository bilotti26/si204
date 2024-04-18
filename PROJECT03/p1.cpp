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

  drawBoard(b);
  refreshWindow();

  // Loop forever until user enters 'q'
  char c;
  do {
    usleep(150000);
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

