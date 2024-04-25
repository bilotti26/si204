#include "board.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Pos.h"
#include "easycurses.h"

using namespace std;

board readFile(string fileName) {
  //Create new board to return
  board ret;

  //file handling
  ifstream fin(fileName);
  char dc;
  if (!fin) {
    cout << "Error: file not found!!!" << endl;
    exit;
  }
  fin >> ret.row >> dc >> ret.col >> ret.numSpawns;

  //Set up the arrays to return for our board later
  ret.walls = new char*[ret.row];
  ret.spawns = new Pos[ret.numSpawns];
  int spawnCounter = 0;
  //Read in
  for(int i = 0; i < ret.row; i++) {
    ret.walls[i] = new char[ret.col];
    for(int j = 0; j < ret.col; j++) {
      char tmp;
      fin.get(tmp); //only way to NOT ignore whitespaces...
      if (tmp == '\n') //after a newline, GET THE ACTUAL CHARACTER
        fin.get(tmp);
      if (tmp == '#') {
        ret.walls[i][j] = '#';
      } else if (tmp == 'X'){
        ret.walls[i][j] = 'X';
        ret.goal.row = i;
        ret.goal.col = j;
      } else if (tmp == 'Y') {
        ret.walls[i][j] = ' ';
        ret.pStart.row = i;
        ret.pStart.col = j;
      } else if (tmp == 'Z') {
        ret.walls[i][j] = ' ';
        ret.spawns[spawnCounter].row = i;
        ret.spawns[spawnCounter].col = j;
        spawnCounter++;
      } else {
        ret.walls[i][j] = tmp;
      }
    }
  }
  return ret;
}

void drawBoard(board b) {
  for(int i = 0; i < b.row; i++) {
    for(int j = 0; j < b.col; j++) {
      //Leave out the spaces for memory savings
      if (b.walls[i][j] != ' ')
        drawChar(b.walls[i][j], i, j);
    }
  }
}

ostream& operator<< (ostream& os, Pos p) {
  cout << '(' << p.row << ',' << p.col << ')';
  return os;
}

void move(entity& P) {
  //Get keyboard
  char key = inputChar();
  int velX;
  int velY;
  switch (key) {
    case 'w':
      P.d = 0; //North
      break;
    case 'a':
      P.d = 1; //East
      break;
    case 's':
      P.d = 2; //South 
      break;
    case 'd':
      P.d = 3; //East 
      break;
    default:
      break;
  }
}

void drawEntities(player* arr, int n) {
  //Clear previous characters, update position, draw again
  for(int i = 0; i < n; i++) {
    if (arr[i].v == 1) {
      //Draw a space over the characters
      drawChar(' ', arr[i].p.row, arr[i].p.col);
      //Update position in accordance with velocity
      arr[i].p = step(arr[i].p, arr[i].d);
      //Redraw the characters 
      drawChar(arr[i].p.c, arr[i].p.row, arr[i].p.col);
    }
  }
}
