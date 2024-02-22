//Andrew Bilotti 260516
//Part 2 Practical 1
//15 Feb 2024

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  string filename;
  cout << "Enter a filename: ";
  cin >> filename;

  ifstream fin(filename);

  int row1=0,row2=0,row3=0,row4=0;

  if (!fin){
    cout << "Error: Input file not found" << endl;
    return 0;
  }
  //read in the file
  while (fin) {
    int temp = 255; //set it to a number out of range so it doesn't behave weird the last iteration
    fin >> temp;

    if (temp < 20)
      row1++;
    else if (temp < 30)
      row2++;
    else if (temp < 40)
      row3++;
    else if (temp < 50)
      row4++;
  }

  //output
  cout << "[10,19]: ";
  for(int i=0; i < row1; i++)
    cout << '*';
  cout << endl << "[20,29]: ";
  for(int i=0; i<row2; i++)
    cout << '*';
  cout << endl << "[30,39]: ";
  for(int i=0; i < row3; i++)
    cout << '*';
  cout << endl << "[40,49]: ";
  for(int i=0; i < row4; i++)
    cout << '*';
  cout << endl;
}
