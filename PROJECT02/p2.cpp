//PROJECT 2
//PART 2
//ANDREW BILOTTI
//260516
//2024-03-07
#include <iostream>
using namespace std;

//Prototypes
int* createDeck();
void printArray(int* arr, int l);
void deal(int* deck, int* topcard, int* hand, int* card);

int main() {
  int* deck = createDeck();
  int length = 52;
  int topCard = 0;

  printArray(deck, length);

  //Players hand cannot be more than the deck, so max size is 52
  int* phand = new int[length];
  int pcard = 0;

  int* dhand = new int[length];
  int dcard = 0;

  //Handle commands
  //Breaks on quit, true while loop (yeah ik its horrible)
  while (true) {
    string command;
    cout << "> ";
    cin >> command;

    if (command == "print-p")
      printArray(phand, pcard);
    else if (command == "print-d")
      printArray(dhand, dcard);
    else if (command == "deal-p") {
      deal(deck, &topCard, phand, &pcard);
    } else if (command == "deal-d") {
      deal(deck, &topCard, dhand, &dcard);
    } else if (command == "quit") {
      break;
    }

  }
  //done
  delete [] deck;
  delete [] phand;
  delete [] dhand;

  return 0;
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
  cout << "[";
  for(int i = 0; i < l; i++){
    if (arr[i] != 0)    
      cout << arr[i] << ((i == l - 1) ? "" : " ");
  }
  cout << "]" << endl;
}

void deal(int* deck, int* topcard, int* hand, int* card) {
  //Cool lesson: *var++ DOES NOT WORK, do *var = *var + 1 or *var += 1
  //Deal the hand
  hand[*card] = deck[*topcard];
  
  //Add one to each of the cards
  *topcard += 1;
  *card += 1;
}
