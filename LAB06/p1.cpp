// Andrew Bilotti
// 260516
// si204 lab 6
// 22 Feb 2024
#include <cstdlib>
#include <iostream>

using namespace std;

//func declarations
//rolldie
int rolldie() {
  while (true) { //runs till we get a number from 1-6, then return
    int num = rand() % 8;
    if (num >= 1 && num <= 6)
      return num;
  }
}

//main function
int main() {
  //Set seed value for "truer" randomness
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed); //seed the rand so it doesn't mess around


  //roll die 5 times and return the output
  for(int i = 0; i < 5; i++) {
    int n1 = rolldie(); 
    int n2 = rolldie();
    //Numbers to be rolled
    cout << "Player rolled " << n1 << " + " << n2 << " = " << (n1 + n2) << endl;
  }

  return 0;
}
