#include <iostream>

using namespace std;

//Prototypes go here!
int* read(int size);
void print(int* arr, int size);
bool isInOrder(int* arr, int size);

int main()
{
  char c;
  int N;
  cin >> c >> c >> N;

  int* A = read(N);
  print(A,N);
  if (isInOrder(A,N))
    cout << "Is in order!" << endl;
  else
    cout << "Is not in order!" << endl;
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
