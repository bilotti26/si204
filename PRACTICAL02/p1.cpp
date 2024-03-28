#include <iostream>
using namespace std;


int readN();
double* readnums(int n, char* c);
void reverse(double* A, double* B, char cA, char cB, int n);
void min(double* A, double* B, char cA, char cB, int n);
void printArr(double* A, int n);
int main()
{

  //read N
  int n = readN();

  char cA, cB;
  //read the value of label and the first vector
  double* A = readnums(n, &cA);
  //read the value of second label and the second vector
  double* B = readnums(n, &cB);
  
  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "reverse" )
      reverse(A, B, cA, cB, n);
    else if ( cmd == "min" )
      min(A, B, cA, cB, n);
    else
      cout << "invalid command!" << endl;
  }

  delete [] A;
  delete [] B;

  return 0;
}

int readN() {
  int n;
  cin >> n;
  return n;
}

double* readnums(int n, char* c) {
  char dc;
  //X:
  cin >> *c >> dc;
  double* arr = new double[n];
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  return arr;
}

void reverse(double* A, double* B, char cA, char cB, int n) {
  char c;
  cin >> c;
  if (!(c == cA || c == cB)) {
    cout << "no such vector!" << endl;
  } else {
    double* arr = new double[n];
    if (c == cA) {
      for(int i = 0; i < n; i++)
        arr[n - i - 1] = A[i];
      A = arr;
      printArr(A, n);
    } else {
      for(int i = 0; i < n; i++)
        arr[n - i - 1] = B[i];
      B = arr;
      printArr(B, n);
    }
    
    delete [] arr;
  }
}
void min(double* A, double* B, char cA, char cB, int n) {
  char c;
  cin >> c;
  if (!(c == cA || c == cB)) {
    cout << "no such vector!" << endl;
  } else {
    double min = 0;
    if (c == cA) {
      for(int i = 0; i < n; i++) {
        if (A[i] < min)
          min = A[i];
      }
    } else {
      for(int i = 0; i < n; i++) {
        if (B[i] < min)
          min = B[i];
      }
    }
    cout << min << endl;
  }
}

void printArr(double* A, int n) {
  cout << "[";
  for(int i = 0; i < n; i++)
    cout << ((i == 0) ? "" : " ") << A[i];
  cout << "]" << endl;
}
