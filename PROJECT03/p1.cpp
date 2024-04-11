//Andrew Bilotti 260516
//PROJECT 3 Part 1
//10APR2004
#include <iostream>
#include <fstream>
//Lib + dependencies + debug
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

struct pixel {
  int col; //col pos
  int row; //row pos
  char c; //letter to be displayed
  int type; //look at next comment
}

//Strategy: return 4 arrays of pixels:
//  (0) walls: player collides off of these, #
//  (3) spawn spots: don't print
//  (2) player spawn spot: print
//  (1) goals: print

pixel** readIn(string filename, int wRow, int wCol) {
  //File handling
  ifstream fin(filename);
  //Give error if file is not readable
  if (!fin) {
    cout << "Error: File can't found or can't read file!";
    exit;
  }

  //Read width and height of the board
  char dc;
  int row, col, spawns;
  fin >> row >> dc >> col >> spawns;

  //Create the arrays
  pixel** p = new pixel*[col];
    for(int i = 0; i < col; i++) {
      p[i] = new pixel*[row];
      for(int j = 0; j < col; i++) {
        p[i + j] =
      }
    }
}
