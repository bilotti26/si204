//Assignment: PROJECT 1
//Name:       ANDREW BILOTTI
//Alpha:      260516
//rowshift.cpp
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //Declare the variables to be inputted
  string foreground_file,background_file,output_file;
   
  //Prompt the user for Input and output file name
  cout << "Foreground file: ";
  cin >> foreground_file;
  cout << "Background file: ";
  cin >> background_file;

  //Row shift
  int rowshift;

  //Prompt the user for the row shift
  cout << "Row shift: ";
  cin >> rowshift;

  //Output file
  cout << "Output file: ";
  cin >> output_file;
  

  //Load the input file
  ifstream fin_fg(foreground_file);
  ifstream fin_bg(background_file);
  
  //Load the output file
  ofstream fout(output_file);

  //Declare the width, height, and largest possible value for fg & bg
  int width1, height1, largest_possible_value1;
  int width2, height2, largest_possible_value2;
  int largest_possible_value;
  //Declare the file header
  string file_header;

  //Check to make sure that the file can be read
  if (!fin_fg || !fin_bg) {
    cout << "Error: Input file not found.";
    return 0;
  }
  else if (!fout) {
    cout << "Error: Output file not writable";
    return 0;
  }
  else {
    //Main logic (a lot is copied and pasted from part 2&3 of the project)

    //First line: file header (it should be the same for both)
    fin_fg >> file_header;
    fin_bg >> file_header;
    fout << file_header << endl;
    
    //Second line: width and height
    fin_fg >> width1 >> height1;
    fin_bg >> width2 >> height2;

    //Check to make sure that the foreground file is smaller or eq
    //to the background file
    if (!((width1 <= width2) && (height1 + rowshift <= height2))) {
      cout << "Error: The foreground goes past the background" << endl;
      return 0;
    }
    //Header is the greater width and height
    fout << width2 << " " << height2 << endl;

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
    
    // For loop
    // Quick note, width2 and height2 is gonna be the biggest width and height
    // We previously checked to make sure that they are the bigger of the two
    for (int i = 0; i < height2; i++) {
      //If the i value (column) is less than the rowshift, then only output
      //the background
      if (i <= rowshift) {
        for (int j = 0; j < width2; j++) {
          //rgb values for bg
          int r,g,b;

          //Fetch the rgb values from the fg
          fin_bg >> r >> g >> b;

          //Put the rgb values on the output file
          fout << r << " " << g << " " << b << " ";
        }
      } else {
        //Otherwise, check if it each pixel is ONLY GREEN for the fg and 
        //if the pixel is not, then output it over the BG.
        for (int j = 0; j < width2; j++) {
          //rgb values for fg and background
          int r1,g1,b1,r2,g2,b2;

          //fetch the fg and bg values of the pixels
          if (j < width1)
            fin_fg >> r1 >> g1 >> b1;
            //only read the bg values if the j value is less than its width
          fin_bg >> r2 >> g2 >> b2;
          

          //If the foreground (greenscreen) file is NOT green
          //(that is, r1 and b1 != 0 or g1 != 255)
          //Then put that pixel on the output
          //Also check that the column has not exceeded the width 
          //of the smaller image
          if ((j < width1) && ((r1 != 0) || (g1 < largest_possible_value1) || (b1 != 0))) {
            fout << r1 << " " << g1 << " " << b1 << " ";
          }
          else {
            fout << r2 << " " << g2 << " " << b2 << " ";
          }
        }
      }

      //At the end of each line, output an endl
      fout << endl;
    }
      
    //done
    fin_bg.close();
    fin_fg.close();
    fout.close();
    cout << "Image saved to " << output_file << endl;
  }

  return 0;
}
