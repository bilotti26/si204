//PROJECT 2
//PART 5
//ANDREW BILOTTI
//260516
//2024-04-01
#include <iostream>
using namespace std;

//Prototypes and their descriptions

//Create a deck of cards, kings queens aces etc.
int* createDeck();
//Print an array in the formatting we want to use
//Reworked as of part 5
void printArray(int* player, int* dealer, int l); 
//Internally make a number into a human readable card:
string cardString(int num);
//Deal a card
void deal(int* deck, int* topcard, int* hand, int* card);
//Shuffle a deck
void shuffle(int* arr, int l, int u);

int main() {
  //Statics go here!
  static int length = 52;

  //Create the array and some card deck specific variables
  int* deck = createDeck();
  int topCard = 0;

  //Player and dealer decks!
  //Players hand cannot be more than the deck, so max size is 52
  int* phand = new int[length];
  int pcard = 0;

  int* dhand = new int[length];
  int dcard = 0;

  //Do we want to shuffle? If so, run the shuffling algorithm with seed
  cout << "Shuffle: [n | u <seed>]: ";
  char c;
  cin >> c;
  if (c == 'u')  {
   int seed;
   cin >> seed;
   shuffle(deck, length, seed);
  }

  //Deck no longer printed as of part 5

  //Deal first two cards for player & dealer
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
    printArray(phand, dhand, ((pcard > dcard) ? pcard : dcard));

    //Take commands and do what they do
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
  printArray(phand, dhand, ((pcard > dcard) ? pcard : dcard));

  //done :)
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

//The new, improved, print array function - now specific to this project
void printArray(int* player, int* dealer, int l) {
  //Header
  cout << " Player Dealer" << endl;
  
  //Every line, print out the player card and dealer card once
  for(int i = 0; i < l; i++) {
    //stop once all cards for both decks have been printed
    if (player[i] == 0 && dealer[i] == 0)
      break;
    cout << "| ";
    if (player[i] != 0)
      cout << cardString(player[i]);
    else 
      cout << "  ";

    cout << " | ";

    if (dealer[i] != 0)
      cout << cardString(dealer[i]);
    else 
      cout << "  ";

    cout << " |" << endl;
  }
}

//it just got too long to put in printarray, made it its own function
//Gets a 3 digit number then makes it into a human readable card name
string cardString(int num) {
  //ABC - A will be suites 
  int suite = num / 100;
  string suiteS;
  //1 clubs 2 diamons 3 hearts 4 spades
  switch(suite) {
    case 1:
      suiteS = "♣";
      break;
    case 2:
      suiteS = "♦";
      break;
    case 3:
      suiteS = "♥";
      break;
    case 4:
      suiteS = "♠";
      break;
    default:
      suiteS = "";
    }
  int number = num % 100;
  string numberS;
  switch(number) {
    case 11:
      numberS = "J";
      break;
    case 12:
      numberS = "Q";
      break;
    case 13:
      numberS = "K";
      break;
    case 14:
      numberS = "A";
      break;
    default:
      numberS = to_string(number);
  }

  return numberS + suiteS;
}

void deal(int* deck, int* topcard, int* hand, int* card) {
  //Cool lesson: *var++ DOES NOT WORK, do *var = *var + 1 or *var += 1
  //Deal the hand
  hand[*card] = deck[*topcard];
  
  //Add one to each of the cards
  *topcard += 1;
  *card += 1;
}

void shuffle(int* arr, int length, int u) {
  srand(u);
  for(int i = 0; i < length; i++) {
    int j = rand() % 52;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
}
