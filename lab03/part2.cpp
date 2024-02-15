#include <iostream>

using namespace std;

int main() {

  //Side lengths
  double l1, l2, l3, a, b, c;
  string triClass = "scalene";
  string theta;
  //Get input
  cout << "Enter side lengths: ";
  cin >> l1 >> l2 >> l3;

  //Get longest side
  if (!((l1 + l2 <= l3) || (l1 + l3 <= l2) || (l2 + l3 <= l1))) {
    if ((l1 > l2) && (l1 > l3)) {
      c = l1;
      a = l2;
      b = l3;
    } else if ((l2 > l1) && (l2 > l3)) {
      c = l2;
      a = l1;
      b = l3;
    } else if ((l3 > l1) && (l3 > l2)) {
      c = l3;
      a = l1;
      b = l2;
    } else if ((l1 == l2) && (l1 == l3) && (l2 == l3)) {
      a = l1;
      b = l2;
      c = l3;
      triClass = "equilateral";
    } else {
      if ((l3 < l2) && (l3 < l1)) {
        a = l3;
        b = l2;
        c = l1;
      } else {
        a = l1;
        b = l2;
        c = l3;
      }
      triClass = "isosceles";
    }
    //for testing
    //cout << a << " " << b << " " << c << endl;
    if (a*a + b*b == c*c) {
      theta = "right";
    } else if (a*a + b*b > c*c) {
      theta = "acute";
    } else {
      theta = "obtuse";
    }

    //Print the output
    cout << "This is a " << theta << " " << triClass << " triangle.";

  } else {
    cout << "Error! these lengths violate the triangle inequality!";
  }

  cout << endl;

  return 0;
}
