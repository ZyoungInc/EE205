#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//random number generator between two user defined integers
int RandNum(int lowrand, int highrand) {
  int xrand;

  highrand = highrand - lowrand;

  srand(time(0));
  xrand = rand()%highrand+lowrand+1;
  return xrand;
}
