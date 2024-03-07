// hw.cpp
#include <iostream>
#include <string>
using namespace std;

// TO DO: Give function prototypes

void get_names(string* p1, string* p2);
bool update_counts(string selection, string candidate1, int* count1, string candidate2, int* count2);
void display_results(string candidate1, int count1, string candidate2, int count2);

// *** DON'T CHANGE main()!! ****
int main() 
{
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}


// TO DO: Give function definitions

void get_names(string* p1, string* p2){
  cout << "Candidate names: ";
  cin >> *p1 >> *p2;
}

bool update_counts(string selection, string candidate1, int* count1, string candidate2, int* count2) {
  *count1 += (selection == candidate1) ? 1 : 0;
  *count2 += (selection == candidate2) ? 1 : 0;
  if (selection == "END")
    return false;
  if (!(selection == candidate1 || selection == candidate2))
    cout << "Invalid name" << endl;
  return true;
}

void display_results(string candidate1, int count1, string candidate2, int count2) {
  if (count1 == count2)
    cout << "Tie!" << endl;
  else if (count1 > count2) {
    cout << candidate1 << " wins with " << count1 << " out of " << (count1+count2) << " votes " << endl;
  } else if (count2 > count1) {
    cout << candidate2 << " wins with " << count2 << " out of " << (count1+count2) << " votes " << endl;
  }
}

