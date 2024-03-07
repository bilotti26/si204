#include <iostream>
using namespace std;

// ======================================
// Function prototypes below
// ======================================

int readN();
int* readData(int size); 
void show(int* arr, int size);
void swap(int* arr, int size);

// ======================================
// main function
// TOUCH NOTHING INSIDE THE FUNCTION!!
// ======================================
int main()
{
  int n = readN();
  int* A = readData(n);

  string cmd;
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);

    cout << "cmd: ";
  }

  delete[] A;

  return 0;
}

// ======================================
// Function definitions below
// ======================================

int readN() {
  char dc;
  int tmp;
  cin >> dc >> dc >> tmp;
  return tmp;
}

int* readData(int size) {
  int* tmp = new int[size];

  for (int i = 0; i < size; i++){
    int num;
    cin >> num;
    tmp[i] = num;
  }

  return tmp;
}

void show(int* arr, int size) {
  for(int i=0;i < size; i++) {
    cout << "[" << i << "] ";

    for(int j=0;j<arr[i];j++)
      cout << "*";

    cout << endl;

  }
}

void swap(int* arr, int size) {
  int n1,n2;
  cin >> n1 >> n2;
  int tmp1 = arr[n1];
  int tmp2 = arr[n2];
  arr[n1] = tmp2;
  arr[n2] = tmp1;
}
