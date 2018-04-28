#include <iostream>
#include "game-utility.hpp"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  int xrand;
  int lowrand = 1;
  int highrand = 25;

  srand(time(0));
  xrand = RandNum(lowrand, highrand);

  cout << "random number is " << xrand << endl;

  return 0;
}
