#include <iostream>
#include <fstream>

using namespace std;

struct fruit {
  string name;
  double price;
};

double indexSearch(string name, fruit* fruits, int fruitN) {
  for (int i = 0; i < fruitN; i++) {
    if (fruits[i].name == name)
      return fruits[i].price;
  }

  return -1;
}

int main() {
  cout << "Filename: ";
  string fileName;
  cin >> fileName;

  ifstream fin(fileName);

  if (!fin) {
    cout << "File not found!" << endl;
    return 0;
  }

  int fruitN;
  string dcs;
  char dc;

  fin >> fruitN >> dcs;

  fruit* fruits = new fruit[fruitN];

  for(int i = 0; i < fruitN; i++) {
    fin >> fruits[i].name >> dc >> fruits[i].price;
  }

  double total = 0;

  while (true) {
    cout << "command: ";
    string command;
    cin >> command;

    if (command == "add") {
      double weight;
      string name;
      cin >> weight >> dcs >> name;
      double price = indexSearch(name, fruits, fruitN);
      if (price == -1) {
        cout << "Error! " << name << " not found!" << endl;
      }
      else
        total += price * weight;

    }
    else if (command == "price") {
      string name;
      cin >> name;
      double price = indexSearch(name, fruits, fruitN);
      if (price == -1) {
        cout << "Error! " << name << " not found!" << endl;
      } else {
        cout << name << " are $" << price << " per pound" << endl;
      }
      
    }
    else if (command == "checkout") {
      cout << "total is $" << total << endl;
      break;
    }
  }

  delete [] fruits;
  fin.close();
  return 0;
}
