#pragma once
#include "Pos.h"
#include <iostream>
using namespace std;

struct board {
  char** walls;   //Position
  int row;
  int col;
  Pos pStart;     //Player start
Pos goal;       //Player goal
  Pos* spawns;
  int numSpawns;
};

board readFile(string fileName);
void drawBoard(board b);

ostream& operator<< (ostream& os, Pos p);
