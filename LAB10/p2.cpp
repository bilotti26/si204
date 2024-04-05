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

istream& operator>> (istream& is, Point& p) {
  char dc;
  cin >> p.a >> dc >> p.x >> dc >> p.y >> dc;
  return is;
}

void loop(Point* pts, int length) {
  //Draw all points to screen
  for(int i = 0; i < length; i++) {
    drawCharAndRefresh(pts[i].a, pts[i].x, pts[i].y);
    //Pause for 0.8 seconds
    usleep(800000);
  }

  //Erase all of them at the same time on the screen 
  for(int i = 0; i < length; i++) {
    drawChar(' ', pts[i].x, pts[i].y);
  }
  refreshWindow();
  usleep(800000);
}
int main() {
  //Get points
  int length;
  cin >> length;
  Point* pts = new Point[length];
  for(int i = 0; i < length; i++)
    cin >> pts[i];

  //Initialise curses
  startCurses();

  char c;
  do {
    loop(pts, length);
    c = inputChar();
  } while (c != 'q');

  endCurses();


  return 0;
}
