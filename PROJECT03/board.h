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

struct entity {
  Pos p;
  char c;   //Character to display
  int dir;  //Direction
  int v;    //Velocity
}

board readFile(string fileName);
void drawBoard(board b);

ostream& operator<< (ostream& os, Pos p);

void move(player& P);
void drawEntities(player* arr, int n);
