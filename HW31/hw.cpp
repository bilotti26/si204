#include <iostream>

using namespace std;

struct Node
{
  string data;
  Node *next;
};
Node* add2back(string d, Node* L);
Node* reverse(Node* L);
Node* add2front(string val, Node* L);
void printWithChar(Node* L, char c);
void deletelist(Node* L);

int main() {
  cout << "Enter words followed by END: ";
  string s;
  cin >> s;
  cout << endl;
  Node* L = new Node{s, NULL};
  while (true) {
    cin >> s;
    if (s == "END")
      break;
    L = add2front(s, L);
  }   
  cout << "What letter? ";
  char t;
  cin >> t;
  printWithChar(L, t);
  deletelist(L);
  return 0;
}

Node* add2front(string val, Node* L)
{
  Node* T = new Node{val, L};
  return T;
}

void printWithChar(Node* L, char c)
{
  if (L == NULL)
    return;

  
  string tmp = L->data;
  if (tmp[0] == c)
    cout << tmp << endl;

  printWithChar(L->next, c);
  
}

void deletelist(Node* L)
{
  // Base case: if the list is empty, there is nothing to delete
  if (L == NULL)
    return;

  // Use recursion to delete all the second-to-last nodes
  deletelist(L->next);
  delete L;               // Then delete the first node
}

