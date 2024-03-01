//Andrew Bilotti 260516
//LAB07 Part 3
//2024-02-29
#include <iostream>

using namespace std;

//Prototypes go here!
int* read(int size);
void print(int* arr, int size);
bool isInOrder(int* arr, int size);
int* swap(int* arr, char s1, char s2);
int* reverse(int* arr, char s1, char s2);
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
  int points = 0;
  while(!isInOrder(A, N) || moves == 0) {
    print(A,N);
    cout << "> ";
    string cmd;
    char c1,c2;
    cin >> cmd;
    if (cmd == "swap"){
      cin >> c1 >> c2;
      A = swap(A,c1,c2);
      points += 3;
      moves++;
    } else if (cmd == "reverse") {
      cin >> c1 >> c2;
      A = reverse(A,c1,c2);
      moves++;
      points += 2;
    }
    else {
      cout << "Unknown move '" << cmd << "'" << endl;
    }
  }
  print(A,N);
  cout << points << " points! (" 
    << moves << " moves)" << endl;
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
//Changes to array it points to are seen outside
int* swap(int* arr, char s1, char s2) {
  int n1 = arr[s1 - 65];
  int n2 = arr[s2 - 65];

  arr[s1 - 65] = n2;
  arr[s2 - 65] = n1;

  return arr;
}

int* reverse(int* arr, char s1, char s2) {
  //A -> 0, D -> 3, etc for easier array stuff
  int n1 = s1 - 65;
  int n2 = s2 - 65;
  int* tmp = new int[n2 - n1 + 1];
  // A B C D E 
  // 0 1 2 3 4
  for(int i = 0; i <= n2 - n1; i++) {
    //Say 3 elements n1 = 0 n2 = 2
    //A B C 
    //0 1 2
    //i=0 
    //tmp[0] = arr[2 - 0]
    //i=1, tmp[1] = arr[2-1] 
    //i=2, tmp[2] = arr[2-2]
    //end
    tmp[i] = arr[n2 - i];
  }
  for(int i = 0; i <= n2 - n1; i++) {
    arr[n1 + i] = tmp[i];
  }
  delete [] tmp;
  return arr;
}
