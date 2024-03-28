#include <iostream>

using namespace std;

int main() {
  //get the streets and avenues
  int streets, avenues;
  string dc;

  cin >> streets >> dc >> avenues >> dc;
  //streets are the rows
  //avenues are the columns
  int** map = new int*[streets];

  //get the map
  for(int i = 0; i < streets; i++) {
    map[i] = new int[avenues];
    for(int j = 0; j < avenues; j++) {
      cin >> map[i][j];
    }
  }

  while (true) {
    cout << "> ";
    string command;
    cin >> command;
    if (command == "quit")
      break;
    else if (command == "crash") {
      char dcC;
      int street, avenue;
      cin >> street >> dcC >> dcC >> dc >> avenue >> dc;
      street -= 1;
      avenue -= 1;
      map[street][avenue]++;
      for(int i = 0; i < streets; i++) {
        for(int j = 0; j < avenues; j++) {
          cout << map[i][j] << ((j == avenues - 1) ? "" : " ");
        }
        cout << endl;
      }
    }
  }

  //always forget this part :'( but I cant believe I got away with doing this
  //w/o structs or functions :D
  for(int i = 0; i < streets; i++)
    delete [] map[i];
  delete [] map;
  return 0;
}

