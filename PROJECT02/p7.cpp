//PROJECT 2
//PART 7
//ANDREW BILOTTI
//260516
//2024-04-01
#include <iostream>
#include <unistd.h>
using namespace std;

//Prototypes and their descriptions

//game so I can call it again...
int game(bool doShuffle);
//Create a deck of cards, kings queens aces etc.
int* createDeck();
//Print an array in the formatting we want to use
//Reworked as of part 5, added scores as of part 6, added boolean to show 
//dealer's top card as of part 7
void printArray(int* player, int* dealer, int l, bool endGame); 
//Internally make a number into a human readable card:
string cardString(int num);
//scores the hand
int score(int* hand, int l);
//Deal a card
void deal(int* deck, int* topcard, int* hand, int* card);
//Shuffle a deck
void shuffle(int* arr, int l);

int main() {
  return game(true);
}

int game(bool doShuffle) {
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

  //Only called on first run - not shuffled randomly again the second time 
  if (doShuffle) {
  //Do we want to shuffle? If so, run the shuffling algorithm with seed
    cout << "Shuffle: [n | u <seed>]: ";
    char c;
    cin >> c;
    if (c == 'u')  {
     int seed;
     cin >> seed; 
     srand(seed);
     shuffle(deck, length);
    }
    cout << endl;
  } else {
    shuffle(deck, length);
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

  //Booleans to mark when both player and dealer stand
  bool playerS = false;
  bool dealerS = false;

  //While loop
  while (!(playerS && dealerS) 
      && score(phand, pcard) < 21 
      && score(dhand, dcard) < 21) {
    //Print dealer and players cards
    printArray(phand, dhand, ((pcard > dcard) ? pcard : dcard), false);

    //Check if controlled by player or AI (dealer)
    //turn is false for player so:
    if (!turn) {
      //Take either "hit" or "stand".
      string command;
      cout << "Round " << round << " " << "Player's turn" << endl;
      cout << "hit or stand ? [h/s] ";
      cin >> command;
      cout << endl;

      if (command == "h") {
        //Hit!
        deal(deck, &topCard, phand, &pcard);
        playerS = false;
      } else if (command == "s") {
        //Stand!
        playerS = true;
      }

    } else {
      cout << "Round " << round << " " << "Dealer's turn" << endl;
      cout << "hit or stand ? [h/s]";
     
      sleep(1);
      if (score(dhand, dcard) < 17) {
        //Hit!
        cout << " h" << endl;
        deal(deck, &topCard, dhand, &dcard);
        dealerS = false;
      } else {
        //stand
        cout << " s" << endl;
        dealerS = true;
      }

      round++;
    }

    //Flip the turn for next round
    turn = !turn;
  }

  //Print last lines 
  printArray(phand, dhand, ((pcard > dcard) ? pcard : dcard), true);
  
  //Get final scores before cleaning up arrays
  int pfinalscore = score(phand, pcard);
  int dfinalscore = score(dhand, dcard);

  //delete arrays before calling winner in case of tie
  delete [] deck;
  delete [] phand;
  delete [] dhand;
  
  //Check who wins
  if (pfinalscore == dfinalscore) {
    //this is a tie -- run the game again without random seeding
    cout << endl;
    return game(false);
  } else if (dfinalscore > 21) {
    cout << "Dealer busts, player wins" << endl;
  } else if (pfinalscore > 21) {
    cout << "Player busts, dealer wins" << endl;
  } else if (pfinalscore > dfinalscore) {
    cout << "Player wins" << endl;
  } else {
    cout << "Dealer wins" << endl;
  }
  //Done!
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
void printArray(int* player, int* dealer, int l, bool endGame) {
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
      cout << ((!endGame && i == 0) ? "**" : cardString(dealer[i]));
    else 
      cout << "  ";

    cout << " |" << endl;
  }
  //Output the scores (removed as of part 7)
  // cout << "Player " << score(player, l) << ", Dealer " << score(dealer, l)
  //   << endl;
}

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
//Scores the hand
int score(int* hand, int l) {
  int total = 0;
  bool aced = false;
  //Go thru every card in the deck
  for(int i = 0; i < l; i++) {
    int number = hand[i] % 100;
    //Switch to capture K-A, default is the numerical number
    switch (number) {
      case 11:
        total += 10;
        break;
      case 12:
        total += 10;
        break;
      case 13:
        total += 10;
        break;
      case 14:
        total += 1;
        aced = true;
        break;
      default:
        total += number;
    }
  }
  //If the total score is less than eleven and theres an ace, add 10 pts.
  if (aced && total <= 11)
    total += 10;
  return total;
}
void deal(int* deck, int* topcard, int* hand, int* card) {
  //Cool lesson: *var++ DOES NOT WORK, do *var = *var + 1 or *var += 1
  //Deal the hand
  hand[*card] = deck[*topcard];
  
  //Add one to each of the cards
  *topcard += 1;
  *card += 1;
}

void shuffle(int* arr, int length) { 
  for(int i = 0; i < length; i++) {
    int j = rand() % 52;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
}
