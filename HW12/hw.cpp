#include <iostream>

using namespace std;

int main() {
  //Get the width and height and offset of the rectangle
  int width,height,offset;

  //User input
  cout << "Enter height (greater than 2): ";
  cin >> height;
  cout << "Enter width  (greater than 2): ";
  cin >> width;
  cout << "Enter offset: ";
  cin >> offset;

  //For loop for height
  for (int i = 0; i < height; i++) {

    //Cout offset as number of spaces
    for (int j = 0; j < offset; j++) 
      cout << " ";

    //Check if it is the top or bottom line
    if (i == 0 || i == (height - 1)) {
      //For loop with width & all asteriks
      for (int j = 0; j < width; j++) {
        cout << "*";
      }
    }
    //If it is not top or bottom line, do asterik space space asterik
    else {
      //For loop that checks if it is the first or last and makes it a *
      for(int j = 0; j < width; j++) {
        if (j == 0 || j == (width - 1))
          cout << "*";
        else 
          cout << " ";
      }
    }

    //Cout an endl after end of each line
    cout << endl;
  }

}
