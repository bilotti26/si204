//Name: Andrew Bilotti
//Date: 2024-02-01
//Alpha: 260516
//Assignment: LAB04 part2
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //Print the average temperature over the dataset in Fahrenheit

  //Get the input and output
  string file_name, output_file;
  cin >> file_name >> output_file;

    
  //Open the file 
  ifstream fin(file_name);
  ofstream fout(output_file);
  

  //Main part of the code
  if (!fin) {
    cout << "Could not open file '" << file_name << "'" << endl;
    return 1;
  } else if (!fout) {
    cout << "Could not output to file '" << output_file << "'" << endl;
    return 1;
  } else {
    //Don't care strings to read through the first line of the tsv file
    string time,temp;

    fin >> time >> temp;
    
    //Header for output file
    //day   hour  temp 
    fout << "day" << '\t' << "hour" << '\t' << "temp" << endl;

    //Stores the number of inputs
    int i = 0;

    //Stores the variables we will be collectively using in the future
    double tempSum,avg,avgF,minF,maxF;
    double min = 0;
    double max = 0;

    //Dates of the min and max
    string minDate,maxDate;

    //While loop to get every single thing of text
    while (fin) {
      string date,time = "";
      int hour;
      double temp;
      
      //Basically the date will take all the text in the TSV before the tab
      fin >> date >> hour >> time >> temp;

      //
      
      //Check to make sure we're not reading over an "extra" line
      //The date input is gonna be "" if we're on the extra line
      if (date != ""){

        //Add the temp for this line to the sum of all the temperatures
        tempSum += temp;
        
        //Check if min or max and set them accordingly
        if (temp < min) {
          min = temp;
          minDate = date;
        }

        if (temp > max) {
          max = temp;
          maxDate = date;
        }

        //Add one to I so we can compute the average in the future.
        i++;
        
        double tempF = ((9.0/5.0) * temp) + 32.0;

        //Output to file
        fout << date << '\t' << (hour + 1) << '\t' << tempF << endl;
      }
    }

    //Compute the average
    avg = tempSum / i;
    
    //Make avg into FREEDOM UNITS
    avgF = ((9.0/5.0) * avg) + 32.0;
    minF = ((9.0/5.0) * min) + 32.0;
    maxF = ((9.0/5.0) * max) + 32.0;

    //Output
    cout << "file: " << file_name << endl;
    cout << "ave: " << avgF << endl;
    cout << "min: " << minF << " on " << minDate << endl;
    cout << "max: " << maxF << " on " << maxDate << endl;
    cout << "output in: " << output_file << endl;

  }

  //Close the files
  fin.close();
  fout.close();

  //Done
  return 0;
}
