//PROJECT 2
//PART 1
//ANDREW BILOTTI
//260516
//2024-03-07
#include <iostream>
using namespace std;

//Prototypes
int* createDeck();
void printArray(int* arr, int l);

int main() {
  int* deck = createDeck();
  int length = 52;

  cout << "[";
  printArray(deck, length);
  cout << "]" << endl;
}

int* createDeck() {
  //num in ABC format
  //A: suites- 1 = clubs, 2 = diamonds, 3 = hearts, 4 = spades
  //BC: 2 thru 10, 11 = jack, 12 = queen, 13 = queen, 14 = Ace
  int* deck = new int[52];
  int k = 0;
  for(int i = 1; i <= 4; i++) {
    for (int j = 2; j <= 14; j++) {
      deck[k] = i * 100 + j;
      k++;
    }
  }
  return deck;
}

void printArray(int* arr, int l) {
  for(int i = 0; i < l; i++)
    cout << arr[i] << ((i == l - 1) ? "" : " ");
}
