//  HW08
//  ANDREW BILOTTi
//  260516

#include <iostream>
#include <fstream>

using namespace std;

int main() {

  //Read in a file that contains the names of several students along with their
  //hw, quiz, and exam average
  
  //Get filename
  string fileName;
  cout << "Filename: ";
  cin >> fileName;

  ifstream fin(fileName);

  //integer i to store # of students
  //integet bestStudent to shwo the best student
  int i = 0;
  double bestStudentAverage = 0;
  string bestStudent;

  if (!fin) {
    fin.close();
    cout << "Error in reading the file " << fileName << endl;
    return 1;
  } else {
    //main section of the code
    
    //While loop to get hw names and sections
    //first string
    string dc;
    fin >> dc >> dc >> dc >> dc;
    while (fin) {
      string name = "";
      double hw,quiz,exam;
      fin >> name >> hw >> quiz >> exam;

      double average = (0.2) * hw + (0.2) * quiz + (0.6) * exam;
      if (name != "")
        cout << name << "  " << average << endl;

      if (average > bestStudentAverage) {
        bestStudentAverage = average;
        bestStudent = name;
      }

    }
    cout << "The best student is " << bestStudent<< ".\n";
  }
  fin.close();
  return 0;
}
