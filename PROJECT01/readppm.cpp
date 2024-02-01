//Assignment: PROJECT 1
//Name:       ANDREW BILOTTI
//Alpha:      260516
//Part 1:     readppm.cpp
//Desc:       Read a ppm format file
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //Prompt the user for file name
  cout << "Input file: ";
  string input_file;
  cin >> input_file;

  //Load the input file, specified by the user's input for the file name
  ifstream fin(input_file);
 
  //Declare the width, height, and largest possible value to be used
  int width,height,largest_possible_value;
  //Declare the file header
  string file_header;

  //Check to make sure that the file can be read
  if (!fin)
    return 1;
  else {
    //Main logic:

    //First line: file header
    fin >> file_header;
    cout << file_header << endl;

    //Second line: width and height
    fin >> width >> height;
    cout << "width = " << width << ", height = " << height << endl;

    //Third line: largest_possible_value
    fin >> largest_possible_value;
    cout << "max value = " << largest_possible_value << endl;
    
    //Nested for loops: first one (variable i) goes through each row,
    //Next one goes through each column for each row
    for (int i = 0; i < height; i++) {
      //Output once we reach a new row
      cout << "*** row " << i << " ***" << endl;
      for (int j = 0; j < width; j++) {
        int r,g,b;
        fin >> r >> g >> b;
        //Output row, col, rgb
        cout << "row " << i << ", col " << j << ": r";
        cout << r << " g" << g << " b" << b << endl;
      }
    }

    //done
    //Close the file
    fin.close();
  }

  return 0;
}
