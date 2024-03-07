#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

int main()
{
  //Start fstream
  string fileName = "words07.txt";
  ifstream fin(fileName);

  //Get the seed value
  int seed;
  cout << "Welcome to String Guess!" << endl;
  cout << "Enter a seed value: ";
  cin >> seed;

  //Apply seed to random number generator
  srand(seed);
  int n = rand() % 1466;

  //Get the string we want
  //We cannot do an array bc we dont know how long words is so do huge String
  if (!fin) {
    cout << "Wrong input file";
    return 1;
  }
  string tmp;
  string hugeString = ""; //We know each word is 7 characters
  while (fin >> tmp) {
    hugeString += tmp;
  }
  //Select our string
  string answer = "";
  for(int i = n * 7; i < n * 7 + 7; i++)
    answer += hugeString[i];

  //cout << answer; just for testing
  //works and verified!

  //Alphabet to star out once char is selected
  string alphabet = "abcdefghijklmnopqrstuvwxyz";

  //Game part
  string guessString = mkShadowString(answer);
  int guesses = 8;
  while (guesses > 0 && guessString != answer) {
    //Print gui
    cout << "Wrong guesses remaining: " << guesses
      << '\t' << alphabet << endl;
    printSpaced(guessString);
    cout << endl;

    //Get letter
    char letter;
    cout << ": ";
    cin >> letter;

    //Logic
    string uncoveredString = uncover(answer, guessString, letter);
    if (uncoveredString != guessString)
      guessString = uncoveredString;
    else{ 
      cout << "There were no " << letter << "'s!" << endl;
      guesses--;
    }

    alphabet = crossOut(letter, alphabet);

  }

  if (guesses <= 1)
    cout << "You lose!!!! The word was" << answer << endl;
  else 
    cout << "You win!!!! The word was " << answer << endl;
  return 0;
}

//func declrs
//Print a string with spaces in between each character
void printSpaced(string s) {
  for (int i = 0; i < s.length(); i++)
    cout << s[i] << ((i == s.length() - 1) ? "" : " ");
}
//Convert a string into underscores of the same length
string mkShadowString(string s) {
  for (int i = 0; i < s.length(); i++)
    s[i] = '_';
  return s;
}
//Make characters in the covered string that match your selection appear
string uncover(string original, string covered, char c) {
  for(int i = 0; i < original.length(); i++) {
    if (original[i] == c)
      covered[i] = c;
  }
  return covered;
}
//Replaces every occurence of selected character in string with asterick
string crossOut(char c, string s) {
  for(int i = 0; i < s.length(); i++){
    if (s[i] == c) 
      s[i] = '*';
  }
  return s;
}

