//Andrew Bilotti - 260516
//SI204 Practicum Exam
//Problem 1
//15 FEB 2023

#include <iostream>

using namespace std;

int main() {
  //take in func dc int dc  operator  double
  //Can assume input is formatted correctly
  char dc, func, oper;
  int operand;
  double opNum, result;
  //      f      (      123       )      +       12.4
  cin >> func >> dc >> operand >> dc >> oper >> opNum;

  if (func == 'r') {
    //  1   2  3
    int p1,p2,p3;
    p1 = operand / 100;
    p2 = (operand % 100) / 10;
    p3 = operand % 10;

    operand = p3 * 100 + p2 * 10 + p1;
  }
  
  if (oper == '+') {
    result = operand + opNum;
  } else {
    result = operand - opNum;
  }
  cout << operand << " " << oper << " " << opNum<< " = " << result << endl;
  return 0;
}
