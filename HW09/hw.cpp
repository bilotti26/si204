#include <iostream>
#include <fstream>

using namespace std;

int main() {

  //Get cookies
  int cookies;
  cout << "How many cookies? ";
  cin >> cookies;

  int piggiest_day = 0;
  int total_cookies = 0;
  int i = 1;

  while (total_cookies < cookies) {
    int cookie;
    cout << "Cookies eaten on day " << i << ": ";
    cin >> cookie;

    if (cookie > piggiest_day){
      piggiest_day = cookie;
    }
    total_cookies += cookie;
    i++;

    if (total_cookies > cookies) {
      cout << "Not enough cookies!" << endl;
      return 0;
    }
  }

  cout << "You ate " << total_cookies << " cookies"<< " over " << (i - 1) << " days." << endl;
  cout << "On your piggiest day you ate " << piggiest_day << " cookies." << endl;
  return 0;
}
