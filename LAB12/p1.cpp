#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int main() {
  //file handling
  cout << "Input file is: ";
  string fileName;
  cin >> fileName;
  ifstream fin(fileName);
  if (!fin) {
    cout << "Error! File '" << fileName << "' not found!";
    return 1;
  }
  Pair p;
  //TO CREATE EMPTY LIST: Node* List = NULL!!!!!!!!
  //Not = new Node b/c that would make it point to something that has garbage
  Node* L = NULL;
  int count = 0;
  while (fin >> p) {
    L = add2front(p, L);
    count++;
  }
  cout << "Count is " << count << endl;

  printList(L);
  cout << endl;
  deleteList(L);
  return 0;
}
