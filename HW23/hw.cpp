#include <iostream>
#include <fstream>

using namespace std;

struct car {
  char name;
  double pos;
  double vel;
};

void updatePos(car* cars, int length) {
  for(int i = 0; i < length; i++) {
    cars[i].pos = cars[i].pos + cars[i].vel;
  }
}

void showCars(car* cars, int length) {
  for(int i = 0; i < length; i++ ) {
    cout << "[" << cars[i].name << ":" << cars[i].pos << "]";
  }
}

int main() {
  //read in the cars
  string fileName;
  cin >> fileName;
  ifstream fin(fileName);

  char dc;
  int length;
  fin >> dc >> dc >> length;

  //Make a car array and read it in 
  car* cars = new car[length];
  for(int i = 0; i < length; i++) {
    string dcs;
    fin >> cars[i].name >> dcs >> cars[i].pos >> dcs >> cars[i].vel;
  }
  
  //show pos for 8 hrs
  for(int i = 0; i <= 8; i++) {
    cout << "hour " << i << " ";
    showCars(cars, length);
    cout << endl;
    updatePos(cars, length);
  }
  delete [] cars;
  return 0;
}
