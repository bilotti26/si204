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

int main() {
  //Seed the random num generator
  srand(time(0)); //pretty random even for rand 

  //Get points
  int length;
  cin >> length;
  Point* pts = new Point[length];
  Vector* v = new Vector[length];
  for(int i = 0; i < length; i++) {
    cin >> pts[i];
    v[i].x = 0;
    v[i].y = 1;
  }

  //Initialise curses
  startCurses();

  //Draw all points to screen
  drawAll(pts, length);

  //refresh the window
  refreshWindow();
  usleep(80000);

  //Main loop:
  for(int frame = 0; frame < 20; frame++) {
    eraseAll(pts, length);
    for(int i = 0; i < length; i++) {
      //1 in 5 chance of changing direction
      if (rand () % 5 == 0) {
        int r = rand() % 2;
        v[i] = move(v[i], r);
      }
      pts[i] = pts[i] + v[i];
    }
    drawAll(pts, length);
    refreshWindow();
    usleep(80000);
  }

  
  endCurses();

  delete [] pts;

  return 0;
}
