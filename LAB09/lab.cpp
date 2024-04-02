//LAB09
//Andrew Bilotti
//260516
#include <iostream>
#include <fstream>

using namespace std;
//PRO-totypes go here!!!
void readIn(double** arr, string filename, int rows, int columns);
double movieAvg(double** arr, int movieID, int rows, int columns);
double userAvg(double** arr, int userID, int rows, int columns);

//movieNames.txt isn't being used in this lab.
int main() {
  //Matrix of ratings.tsv - 610 rows, 9724 columns
  //Parameters to use when reading in
  static string fileName = "ratings.tsv";
  static int users = 610;
  static int movies = 9724;

  //create the matrix
  double** arr = new double*[users];
  //use my super awesome void to read in the array
  readIn(arr, fileName, users, movies);


  //while loop ends when "quit" so we doing while true
  while (true) {
    string command;
    cin >> command;
    //get the command, then do the action
    if (command == "movie") {
      int movieID;
      cin >> movieID;
      cout << movieAvg(arr, movieID, users, movies) << endl;
    } else if (command == "user") {
      int userID;
      cin >> userID;
      cout << userAvg(arr, userID, users, movies) << endl;
    } else if (command == "quit") {
      break;
    } 
    //super secret debug command!
    else if (command == "debug") {
      int row,col;
      cin >> row >> col;
      cout << arr[row][col];
    }
    else {
      cout << "Command not found, please try again." << endl;
    }
  }

  //dont forget to delete each element of the 2d array :)
  for (int i = 0; i < users; i++) {
    delete [] arr[i];
  }
  //then delete the array itself
  delete [] arr;
  //finally were done
  return 0;
}

void readIn(double** arr, string filename, int rows, int columns) {
  ifstream fin(filename);

  //read every movie and get their ratings
  //first three columns- rownum userID, movieId, ratings
  string dc;
  fin >> dc >> dc >> dc;
  //i will be userID
  //initialize whole array with zeroes to start
  for(int j = 0; j < rows; j++) {
    arr[j] = new double[columns];
    for(int k = 0; k < columns; k++)
      arr[j][k] = 0;
  }
  int i = 0;
  int userID;
  while(i < rows) {
    int userID, movieID;
    double rating;
    if (fin >> userID) {
      if (i == userID) {
        fin >> movieID >> rating;
        arr[i][movieID] = rating;
      } else if (i + 1 == userID){
        i++; //if the userID incremented, increment i
        if (i < rows) { //double check or segmentation fault :D
          fin >> movieID >> rating;
          arr[i][movieID] = rating;
        }
      } else { //when it jumps from 204 to 211
        i = userID;
        if (i < rows) {
          fin >> movieID >> rating;
          arr[i][movieID] = rating;
        }
      }
    } else {
      break;
    }
  }
}

double movieAvg(double** arr, int movieID, int rows, int columns) {
  double total = 0;
  int num = 0;
  for(int i = 0; i < rows; i++) {
    //rows are userID, columns are the movieID
    if (arr[i][movieID] != 0) {
      total += arr[i][movieID];
      num++;
    }
  }
  return (total / double(num));
}

double userAvg(double** arr, int userID, int rows, int columns) {
  double total = 0;
  int num = 0;
  for(int i = 0; i < columns; i++) {
    //rows are userID, columns are the movieID
    if (arr[userID][i] != 0) {
      total += arr[userID][i];
      num++;
    }
  }
  return (total / double(num));
}
