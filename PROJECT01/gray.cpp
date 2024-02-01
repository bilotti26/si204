//Assignment: PROJECT 1
//Name:       ANDREW BILOTTI
//Alpha:      260516
//gray.cpp
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //Prompt the user for Input and output file name
  cout << "Input file: ";
  string input_file,output_file;
  cin >> input_file;
  cout << "Output file: ";
  cin >> output_file;
  
  //Load the input file
  ifstream fin(input_file);
  
  //Load the output file
  ofstream fout(output_file);
  //Declare the width, height, and largest possible value to be used in future for loops
  int width,height,largest_possible_value;
  //Declare the file header
  string file_header;

  //Check to make sure that the file can be read
  if (!fin) {
    cout << "Error: Input file not found.";
    return 1;
  }
  else if (!fout) {
    cout << "Error: Output file not writable";
    return 1;
  }
  else {
    //Main logic (a lot is copied and pasted from part one of the project)

    //First line: file header
    fin >> file_header;
    fout << file_header << endl;
    
    //Second line: width and height
    fin >> width >> height;
    fout << width << " " << height << endl;
    //Third line: largest_possible_value
    fin >> largest_possible_value;
    fout << largest_possible_value << endl;
    
    //For loop (please tell me we learn for loops :))
    for (int i = 0; i < height; i++) {
      //Say the row
      for (int j = 0; j < width; j++) {
        int r,g,b,avg;
        fin >> r >> g >> b;
        avg = (r + g + b) / 3;
        fout << avg << " " << avg << " " << avg << " ";
      }
      fout << endl;
    }

    //done
    fin.close();
    fout.close();
  }

  return 0;
}
