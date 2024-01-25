#include <iostream>

using namespace std;

double getMax(double x1,double x2,double x3) {
  if ((x1 > x2) && (x1 > x3)) {
    return x1;
  } else if ((x2 > x1) && (x2 > x3)) {
    return x2;
  } else {
    return x3;
  }
}

double getMin(double x1,double x2,double x3) {
  if ((x1 < x2) && (x1 < x3)) {
    return x1;
  } else if ((x2 < x1) && (x2 < x3)) {
    return x2;
  } else {
    return x3;
  }
}

int main() {
  //Variables for the 3 points
  double p1x, p1y, p2x, p2y, p3x, p3y;

  //Get input
  //CHAR INT CHAR INT CHAR   CHAR INT CHAR INT CHAR   CHAR INT CHAR INT CHAR
  
  char dc;
  //     (     x1     ,      y1    )     (      x2    ,      y2    ) 
  cin >> dc >> p1x >> dc >> p1y >> dc >> dc >> p2x >> dc >> p2y >> dc >> dc >> p3x >> dc >> p3y >> dc;

  double xMin, xMax, yMin, yMax;
  //Get the highest and lowest x and y value
  xMin = getMin(p1x,p2x,p3x);
  xMax = getMax(p1x,p2x,p3x);
  yMin = getMin(p1y,p2y,p3y);
  yMax = getMax(p1y,p2y,p3y);
  

  //Draw the bounding box
  //Bottom left
  cout << xMin << " " << yMin << endl;
  //Top Left
  cout << xMin << " " << yMax << endl;
  //Top right
  cout << xMax << " " << yMax << endl;
  //Bottom right
  cout << xMax << " " << yMin << endl;
  //Loop Back to bottom left to complete the rect
  cout << xMin << " " << yMin << endl << endl;
  
  //Draw the Triangle
  cout << p1x << " " << p1y << endl;
  cout << p2x << " " << p2y << endl;
  cout << p3x << " " << p3y << endl;
  cout << p1x << " " << p1y << endl;
  return 0;
}
