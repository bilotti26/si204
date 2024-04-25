/************************************************
p1.cpp

DO NOT DELETE ANY CODE BELOW. 
Only add code as necessary.
*************************************************/

#include <iostream>
using namespace std;

struct position
{
  int row, col;
};

struct movement
{
  char dir;
  int length;
};

istream& operator>>(istream& is, position& p) {
  char dc;
  is >> dc >> p.row >> dc >> p.col >> dc;
  return is;
}
istream& operator>>(istream& is, movement& v) {
  is >> v.dir >> v.length;
  return is;
}
ostream& operator<<(ostream& os, position p) {
  os << '(' << p.row << ',' << p.col << ')';
  return os;
}
position operator+ (position p, movement v) {
  if (v.dir == 'N')
    p.row -= v.length;
  else if (v.dir == 'S')
    p.row += v.length;
  else if (v.dir == 'W')
    p.col -= v.length;
  else if (v.dir == 'E')
    p.col += v.length;

  return p;
}
int main()
{
  position p; 
  cout << "position? ";
  cin >> p;

  cout << "how many moves? ";
  int n; 
  cin >> n;

  for(int i=0; i<n; i++)
  {
    movement v;
    cin >> v;
    p = p + v;
    cout << p << endl;
  }

  return 0;
}
