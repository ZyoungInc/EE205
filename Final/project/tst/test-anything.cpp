#include <iostream>
int main()
{
  int total_damage;
  float multiplier = 0.5;
  int damage = 11;

  total_damage = int(damage * multiplier);

  std::cout << total_damage << std::endl;

  return 0;
}


