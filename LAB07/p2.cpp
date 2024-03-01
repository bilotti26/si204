//Andrew Bilotti 260516
//LAB07 Part 2
#include <iostream>

using namespace std;

//Prototypes go here!
int* read(int size);
void print(int* arr, int size);
bool isInOrder(int* arr, int size);
int* swap(int* arr, char s1, char s2);
int main()
{
  //Welcome message
  cout << "Welcome to SWARE!" << endl;
  cout << "board > ";

  //Get initial array
  char c;
  int N;
  cin >> c >> c >> N;

  int* A = read(N);

  int moves = 0;
  while(!isInOrder(A, N) || moves == 0) {
    print(A,N);
    cout << "> ";
    string cmd;
    char c1,c2;
    cin >> cmd;
    if (cmd == "swap"){
      cin >> c1 >> c2;
      A = swap(A,c1,c2);
      moves++;
    }
    else {
      cout << "Unknown move '" << cmd << "'" << endl;
    }
  }
  print(A,N);
  cout << moves * 3 << " points! (" << moves << " moves)" << endl;
  delete [] A;
  return 0;
}

//Fn Defs go here!

int* read(int size) {
  char dc; //dont care for : part
  cin >> dc;

  int* tmp = new int[size];

  for (int i = 0; i < size; i++){
    int num;
    cin >> num;
    tmp[i] = num;
  }

  return tmp;
}

void print(int* arr, int size) {
  cout << endl;

  //print numbers
  for(int i = 0; i < size; i++)
    cout << " " << arr[i];

  cout << endl << "-";
  
  //print hyphens
  for (int i = 0; i < size; i++)
    cout << "--";

  cout << endl;

  //print letters
  //char A = 65, 1 => a, so add 64
  for(int i = 0; i < size; i++)
    cout << " " << char(65 + i);

  cout << endl;
}

bool isInOrder(int* arr, int size) {
  int num = arr[0];
  for(int i = 0; i < size; i++) {
    if (num > arr[i])
      return false;
    num = arr[i];
  }
  return true;
}

int* swap(int* arr, char s1, char s2) {
  int n1 = arr[s1 - 65];
  int n2 = arr[s2 - 65];

  arr[s1 - 65] = n2;
  arr[s2 - 65] = n1;

  return arr;
}

