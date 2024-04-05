#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "easycurses.h"
using namespace std;


struct Point {
  char a;
  int x;
  int y;
};

struct Vector {
  int x;
  int y;
};

void generatePts(Point* pts, Vector* v, int row, int col, int length) {
  for(int i = 0; i < length; i++) {
    pts[i].a = rand() % 93 + 33;
    pts[i].x = rand() % row;
    pts[i].y = rand() % col;
    v[i].x = rand() % 2;// <1,0> or <0,1>
    v[i].y = 1 - v[i].x;
  }
}
istream& operator>> (istream& is, Point& p) {
  char dc;
  cin >> p.a >> dc >> p.x >> dc >> p.y >> dc;
  return is;
}

Point operator+ (Point p, Vector v) {
  Point tmp;
  tmp.a = p.a;
  tmp.x = p.x + v.x;
  tmp.y = p.y + v.y;
  return tmp;
};

Vector operator* (Vector v, int i) {
  v.x = v.x * i;
  v.y = v.y * i;
  return v;
}
Vector move(Vector v, int i) {
  if (v.y == 1) {
    v.y = 0;
    if (i == 0)
      v.x = -1;
    else 
      v.x = 1;
  } else if (v.x == 1) {
    v.x = 0;
    if (i == 0)
      v.y = 1;
    else 
      v.y = -1;
  }
  return v;
}
void drawAll(Point* pts, int length) {
  for(int i = 0; i < length; i++) {
    drawChar(pts[i].a, pts[i].x, pts[i].y);
  }
}

void eraseAll(Point* pts, int length) {
  for(int i = 0; i < length; i++) {
    drawChar(' ', pts[i].x, pts[i].y);
  }
}

void checkWindow(Point* pts, Vector* v, int row, int col, int length) {
  for(int i = 0; i < length; i++) {
    //top/bottom first
    if ((pts[i].x <= 0 && v[i].x <= 0) || (pts[i].x >= row && pts[i].x >= 0)) {
      v[i].x *= -1;
    }    
    //now left/right
    if ((pts[i].y <= 0 && v[i].y <= 0) || (pts[i].y >= col && pts[i].y >= 0)) {
      v[i].y *= -1;
    }
  }
}
int main() {
  int row, col;

  //Seed the random num generator
  srand(time(0)); //pretty random even for rand 

  //Get points
  // int length;
  // cin >> length;
  // Point* pts = new Point[length];
  // Vector* v = new Vector[length];
  // for(int i = 0; i < length; i++) {
  //   cin >> pts[i];
  //   v[i].x = 0;
  //   v[i].y = 1;
  // }
  int length;
  cin >> length;
  Point* pts = new Point[length];
  Vector* v = new Vector[length];

  //Initialise curses
  startCurses();
  getWindowDimensions(row, col);

  //Generate random points
  generatePts(pts, v, row, col, length);

  //Draw all points to screen
  drawAll(pts, length);

  //refresh the window
  refreshWindow();
  usleep(80000);

  //Main loop:
  char c;
  do {
    eraseAll(pts, length);
    for(int i = 0; i < length; i++) {
      //1 in 5 chance of changing direction
      if (rand () % 5 == 0) {
        int r = rand() % 2;
        v[i] = move(v[i], r);
      }
      checkWindow(pts, v, row, col, length);
      pts[i] = pts[i] + v[i];
    }
    drawAll(pts, length);
    refreshWindow();
    usleep(80000);
    c = inputChar();
  } while (c != 'q');

  
  endCurses();

  delete [] pts;

  return 0;
}
