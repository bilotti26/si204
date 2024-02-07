//Assignment: PROJECT 1
//Name:       ANDREW BILOTTI
//Alpha:      260516
//fgbg.cpp
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //Prompt the user for Input and output file name
  cout << "Foreground file: ";
  string foreground_file,background_file,output_file;
  cin >> foreground_file;
  cout << "Background file: ";
  cin >> background_file;
  cout << "Output file: ";
  cin >> output_file;
  
  //Load the input file
  ifstream fin_fg(foreground_file);
  ifstream fin_bg(background_file);
  
  //Load the output file
  ofstream fout(output_file);

  //Declare the width, height, and largest possible value to be used in future for loops
  int width1, height1, largest_possible_value1, width2, height2, largest_possible_value2, largest_possible_value;
  //Declare the file header
  string file_header;

  //Check to make sure that the file can be read
  if (!fin_fg || !fin_bg) {
    cout << "Error: Input file not found" << endl;
    return 1;
  }
  else if (!fout) {
    cout << "Error: Output file not writable" << endl;
    return 1;
  }
  else {
    //Main logic (a lot is copied and pasted from part one of the project)

    //First line: file header
    fin_fg >> file_header;
    fin_bg >> file_header;
    fout << file_header << endl;
    
    //Second line: width and height
    fin_fg >> width1 >> height1;
    fin_bg >> width2 >> height2;

    //Check to make sure the two files have the same height
    if (!((width1 == width2) && (height1 == height2))) {
      cout << "Error: Images have different sizes" << endl;
      return 1;
    }
    fout << width1 << " " << height1 << endl;

    //Third line: largest_possible_value
    //Simple hack to get the biggest largest possible value from the two files
    fin_fg >> largest_possible_value1;
    fin_bg >> largest_possible_value2;
    if (largest_possible_value2 > largest_possible_value1)
      largest_possible_value = largest_possible_value2;
    else {
      largest_possible_value = largest_possible_value1;
    }

    //Give the file its largest possible value
    fout << largest_possible_value << endl;
    
    //For loop
    //Quick note, I could use height1 or height2, since I already checked
    // that height1 == height2 and the program will exit if they are NOT equal
    for (int i = 0; i < height1; i++) {
      //Row by row, check if it is green
      for (int j = 0; j < width1; j++) {
        //rgb values for fg and background
        int r1,g1,b1,r2,g2,b2;

        //fetch the fg and bg values of the pixels
        fin_fg >> r1 >> g1 >> b1;
        fin_bg >> r2 >> g2 >> b2;

        //If the foreground (greenscreen) file is NOT green
        //(that is, r1 and b1 != 0 or g1 != 255)
        //Then put that pixel on the output
        if ((r1 != 0) || (g1 < largest_possible_value1) || (b1 != 0)) {
          fout << r1 << " " << g1 << " " << b1 << " ";
        }
        else {
          fout << r2 << " " << g2 << " " << b2 << " ";
        }
      }
      fout << endl;
    }
    //Output
    
    cout << "Image saved to " << output_file << endl;

    //done
    fin_bg.close();
    fin_fg.close();
    fout.close();
  }

  return 0;
}
