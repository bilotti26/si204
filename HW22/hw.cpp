#include <iostream>

using namespace std;

int main() {
  int row,col;
  cout << "What size? ";
  char dc;
  cin >> row >> dc >> col;
  int** arr = new int*[row];
  //read in the matrix
  for (int i = 0; i < row; i++) {
    arr[i] = new int[col];
    for(int j = 0; j < col; j++)
      cin >> arr[i][j];
  }
  //check row by row to see if it adds up to a number divisible by 9
  cout << "rows:";
  for(int i = 0; i < row; i++) {
    int sum = 0;
    for(int j = 0; j < col; j++) {
      sum += arr[i][j];
    }
    if (sum % 3 == 0 && sum != 0)
      cout << " " << i;
  }
  cout << endl;

  //check col by col now :(
  cout << "cols:";
  for(int j = 0; j < col; j++) {
    int sum = 0;
    for(int i = 0; i < row; i++) {
      sum += arr[i][j];
    }
    if (sum % 3 == 0 && sum != 0)
      cout << " " << j;
  }
  cout << endl;

  return 0;

}
