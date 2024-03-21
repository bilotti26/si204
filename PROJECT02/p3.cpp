//PROJECT 2
//PART 3
//ANDREW BILOTTI
//260516
//2024-03-08
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
  cout << endl;

  //Players hand cannot be more than the deck, so max size is 52
  int* phand = new int[length];
  int pcard = 0;

  int* dhand = new int[length];
  int dcard = 0;

  //Deal first two cards for player & dealer
  //Yeah yeah i know i can just set the arrays manually, but I like the
  //function that I wrote

  deal(deck, &topCard, phand, &pcard);
  deal(deck, &topCard, dhand, &dcard);
  deal(deck, &topCard, phand, &pcard);
  deal(deck, &topCard, dhand, &dcard);

  //Game
  //Number of rounds
  int round = 1;
  bool turn = false; //false when player, true when dealer

  //While loop
  while (round <= 3) {
    //Print dealer and players cards
    cout << "Player: ";
    printArray(phand, pcard);
    cout << "Dealer: ";
    printArray(dhand, dcard);
    cout << endl;

    string command;
    cout << "Round " << round << " " <<
      ((turn) ? "Dealer" : "Player") << "'s turn\n";
    cout << "hit or stand ? [h/s] ";
    cin >> command;
    cout << endl;

    if (command == "h") {
      //deal for player (turn is 0, player hand)
      if (!turn) {
        deal(deck, &topCard, phand, &pcard);
      }
      else {
        deal(deck, &topCard, dhand, &dcard);
      }
    } 

    //Since player comes first, then dealer, when turn is true make round go up
    if (turn)
      round++;

    //Flip the turn for next round
    turn = !turn;
  }

  //Print last lines 
  cout << "Player: ";
  printArray(phand, pcard);
  cout << "Dealer: ";
  printArray(dhand, dcard);

  //done :)
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
