//Assignment: PROJECT 1
//Name:       ANDREW BILOTTI
//Alpha:      260516
//rowshift.cpp v2 (improved and more efficient)
//Comments: basically I used a new approach for shift.cpp,
//it was just about as efficient as I can get w/o multithreading,
//and I deleted the old rowshift.cpp to use this much more
//efficient method
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
  int fg_width, fg_height, largest_possible_value1;
  int bg_width, bg_height, largest_possible_value2;
  int largest_possible_value;

  //Declare the file header
  string file_header;

  //Check to make sure that the file can be read
  if (!fin_fg || !fin_bg) {
    cout << "Error: Input file not found" << endl;
    return 0;
  }
  else if (!fout) {
    cout << "Error: Output file not writable" << endl;
    return 0;
  }
  else {
    //Main logic (a lot is copied and pasted from part 2&3 of the project)

    //First line: file header (it should be the same for both)
    fin_fg >> file_header;
    fin_bg >> file_header;
    fout << file_header << endl;
    
    //Second line: width and height
    fin_fg >> fg_width >> fg_height;
    fin_bg >> bg_width >> bg_height;

    //Check to make sure that the foreground file is smaller or eq
    //to the background file
    if (!((fg_width <= bg_width) && (fg_height + rowshift <= bg_height))) {
      cout << "Error: The foreground goes past the background" << endl;
      return 0;
    }
    //Header is the greater width and height
    fout << bg_width << " " << bg_height << endl;

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
    // Quick note, bg_width and bg_height is gonna be the biggest 
    // Width and height because the background has more pixels than foreground
    for (int i = 0; i < bg_height; i++) {
      //If the i value (column) is less than the rowshift, then only output
      //the background
      for (int j = 0; j < bg_width; j++) {
          //rgb values for fg and background
          int r1,g1,b1,r2,g2,b2;
          bool inShift = false;

          //Only read the tiny fg file if it is within the parameters
          //j (row #) in between the x value column shift and its width 
          //i (column #) in between the y value's row shift 
          //  & its height + row shift
          if (
              ((j < fg_width)) && 
              ((i >= rowshift) && (i < fg_height + rowshift))
             ) {
            fin_fg >> r1 >> g1 >> b1;
            inShift = true;
          }

          //Since we're drawing OVER the bg, we're always gonna read the bg 
          fin_bg >> r2 >> g2 >> b2;
          
          //This if statement has been rewritten for efficiency
          //If the pixel is not "in its shift", then draw the bg pixel
          //After, check if the foreground (greenscreen) file is NOT green
          //(that is, r1 and b1 != 0 or g1 != 255)
          //If these two conditions are met, then draw the foreground pixel.
          if (
              (inShift == true)
              && ((r1 != 0) || (g1 < largest_possible_value1) || (b1 != 0))
             ) {
            fout << r1 << " " << g1 << " " << b1 << " ";
          }
          else {
            fout << r2 << " " << g2 << " " << b2 << " ";
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
