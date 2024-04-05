#include <iostream>
#include <unistd.h>
#include <cstdlib>
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
  Vector transform;
  transform.x = 0;
  transform.y = 1;

  //Get points
  int length;
  cin >> length;
  Point* pts = new Point[length];
  for(int i = 0; i < length; i++)
    cin >> pts[i];

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
    for(int i = 0; i < length; i++)
      pts[i] = pts[i] + transform;
    drawAll(pts, length);
    refreshWindow();
    usleep(80000);
  }

  
  endCurses();

  delete [] pts;

  return 0;
}
