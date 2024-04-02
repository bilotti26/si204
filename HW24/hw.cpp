#include <iostream>

using namespace std;

// ADD code necessary.
// Do NOT delete any code.

struct Point3
{
  double x, y, z;
};

//cin
istream& operator>> (istream& is, Point3& p);
//cout
ostream& operator<< (ostream& os, Point3 p);
//dot product
double operator* (Point3 p, Point3 q);

int main()
{
  Point3 a, b;

  cin >> a >> b;

  cout << "Inner product of " << a << " and " << b
       << " is " << a*b << endl;

  return 0;
}

istream& operator>> (istream& is, Point3& p) {
  char dc;
  return is >> dc >> p.x >> dc >> p.y >> dc >> p.z >> dc;
}

ostream& operator<< (ostream& os, Point3 p) {
  return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

double operator* (Point3 p, Point3 q) {
  return p.x*q.x + p.y*q.y + p.z*q.z;
}

