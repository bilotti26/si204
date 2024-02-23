// Andrew Bilotti
// 260516
// si204 lab 6
// 22 Feb 2024
// Part 3
#include <cstdlib>
#include <iostream>

using namespace std;

//Prototypes
int throwdice();
int firstroll();
int throwdice(int setpoint);

//main function
int main() {
  //Set seed value for "truer" randomness
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed); //seed the rand so it doesn't mess around

  //loop until either player or house wins:
  char playAgain = 'y';
  while (playAgain == 'y') {
    int setpoint = firstroll();
    int result = setpoint;
    while (result > 0) {
      result = throwdice(setpoint);
    }

    cout << "Play again? ";
    cin >> playAgain;
  }
  return 0;
}

//func declarations
//rolldie
int rolldie() {
  while (true) { //runs till we get a number from 1-6, then return
    int num = rand() % 8;
    if (num >= 1 && num <= 6)
      return num;
  }
}

//func for throw die - 7 or 11 player wins, 2,3,12 house wins
int firstroll() {
  int d1 = rolldie(), d2 = rolldie();
  int roll = d1 + d2;
  cout << "Player rolled " << d1 << " + " << d2 << " = " << roll << " ";
  switch(roll) {
    case 2:
      cout << "House wins!" << endl;
      return -1;
      break;
    case 3:
      cout << "House wins!" << endl;
      return -1;
      break;
    case 7:
      cout << "Player wins!" << endl;
      return 0;
      break;
    case 11:
      cout << "Player wins!" << endl;
      return 0;
      break;
    case 12:
      cout << "House wins!" << endl;
      return -1;
      break;
    default:
      cout << "setpoint is " << roll << "!" << endl;
      return roll;
  }
}

int throwdice(int setpoint) {
  int d1 = rolldie(), d2 = rolldie();
  int roll = d1 + d2;
  cout << "Player rolled " << d1 << " + " << d2 << " = " << roll << " ";
  if (roll == setpoint) {
    cout << "Player wins!" << endl;
    return 0;
  } else if (roll == 7 || roll == 12) {
    cout << "House wins!" << endl;
    return -1;
  } else {
    cout << "roll again" << endl;
    return roll;
  }
}
