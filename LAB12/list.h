#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Pair {
  string s;
  int n;
};

struct Node {
  Pair data;
  Node* next;
};

Node* add2back(Pair data, Node* L);
Node* add2front(Pair data, Node* L);
Node* deletefront(Node* L);
void printList(Node* L);
void printListString(Node* L);
int sumList(Node* L);
void deleteList(Node* L);
void loopThroughList(Node* L, Node* S);
void loopThroughList(Node* L);
void listGame(Node* L, Node* S, string sentence, int score);
void listGame(Node* L);
istream& operator>> (istream& fin, Pair& data);
ostream& operator<< (ostream& os, Pair& data);
