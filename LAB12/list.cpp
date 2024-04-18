#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

Node* add2back(Pair data, Node* L) {
  if (L == NULL)
    return new Node{data, NULL};

  L->next = add2back(data, L->next);
  return L;
}
Node* add2front(Pair data, Node* L) {
  Node* T = new Node{data, L};
  return T;
}
Node* deletefront(Node* L) {
  if (L == NULL)
    return NULL;

  Node* ret = L->next;
delete L;
  return ret;
}

void printList(Node* L) {
  if (L == NULL)
    return;

  cout << L->data << " ";
  printList(L->next);
}

void printListString(Node* L) {
  if (L == NULL)
    return;

  cout << L->data.s << " ";
  printListString(L->next);

}

int sumList(Node* L) {
  if (L == NULL)
    return 0;

  return L->data.n + sumList(L->next);
}
void deleteList(Node* L) {
  while (L != NULL)
    L = deletefront(L);
}
void loopThroughList(Node* L, Node* S) {
  if (L == NULL)
    return;

  cout << "The current node: " << L->data << endl;
  int count = 0;
  cout << "Nodes before the current:";
  for(Node* T = S; T != L && T != NULL; T = T -> next)
    cout << " " << T->data;
  cout << endl << "#nodes after the current: ";
  for(Node*T = L->next; T != NULL; T = T->next)
    count++;
  cout << count << endl;
  cout << "[a]ccept or [r]eject: ";
  char c;
  cin >> c;
  cout << endl;

  loopThroughList(L->next, S);
}
void loopThroughList(Node* L) {
  loopThroughList(L,L);
}
void listGame(Node* L, Node* S, string sentence, int score) {
  if (L == NULL) {
    cout << "Sentence is:" << sentence << endl;
    cout << "Score is: " << score << endl;
    return;
  }

  cout << "The current node: " << L->data << endl;
  int count = 0;
  cout << "Sentence you made so far:" << sentence;
  cout << endl << "#words left: ";
  for(Node*T = L->next; T != NULL; T = T->next)
    count++;
  cout << count << endl;

  cout << "[a]ccept or [r]eject: ";
  char c;
  cin >> c;
  if (c == 'a') {
    sentence += " " + L->data.s;
    score += L->data.n;
  }

  cout << endl;

  listGame(L->next, S, sentence, score);
}

void listGame(Node* L) {
  listGame(L,L, "", 0);
}

istream& operator>> (istream& fin, Pair& data) {
  char dc;
  fin >> dc >> data.s >> data.n >> dc;
  return fin;
  
}

ostream& operator<< (ostream& os, Pair& data) {
  cout << '(' << data.s << ' ' << data.n << ')';
  return os;
}
