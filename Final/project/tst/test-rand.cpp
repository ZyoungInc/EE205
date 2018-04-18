#include <iostream>
#include "game-utility.hpp"

using namespace std;

int main() {
  int xrand;
  int lowrand = 1;
  int highrand = 25;

  xrand = RandNum(lowrand, highrand);

  cout << "random number is " << xrand << endl;

  return 0;
}
