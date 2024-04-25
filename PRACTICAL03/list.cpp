/******************************************
list.cpp

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/
#include "list.h"


ostream& operator<< (ostream& os, Character c) {
  os << "[" << c.label << " (" << c.row << "," << c.col << ")]";
  return os;
}

void deletelist(Node* L)
{
  if( L == NULL )
  {
    return;
  }
  else 
  {
    deletelist(L->next);
    delete L;
  }
}

Node* add2back(Character data, Node* L) {
  if (L == NULL)
    return new Node{data, NULL};
  
  L->next = add2back(data, L->next);
  return L;
}

void print(Node* L) {
  if (L == NULL) {
    cout << endl;
    return;
  }
  else {
    cout << L->data;
    if (L->next != NULL)
      cout << " ";
    print(L->next);
  }
}
void nodesLeftOf(Node* L, int col) {
  if (L == NULL)
    return;
  else if (L->data.col < col) {
    cout << L->data << endl;
    nodesLeftOf(L->next, col);
  } else {
    nodesLeftOf(L->next, col);
  }
}
void removeThird(Node* L) {
  Node* third = L->next->next;
  if (third == NULL)
    return;
  L->next->next = third->next;
  delete third;
}
