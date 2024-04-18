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
    cout << "File not readable";
    return 1;
  }
  Pair p;
  //TO CREATE EMPTY LIST: Node* List = NULL!!!!!!!!
  //Not = new Node b/c that would make it point to something that has garbage
  Node* L = NULL;
  while (fin >> p) {
    L = add2front(p, L);
  }
  loopThroughList(L,L);
  cout << "List is: ";
  printListString(L);
  cout << endl;
  cout << "Score is: " << sumList(L) << endl;
  deleteList(L);
  return 0;
}
