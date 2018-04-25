#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Spell{
private:
  int cost;
  int damage;
  int cooldown;
  string name;
  string EleType;

public:
  Spell (int c, int d, int cd, string n, string e ):
    cost(c),
    damage(d),
    cooldown(cd),
    name(n),
    EleType(e)
  {}
  //Choice between 2 sets of spells
  Spellset(int Choice){
    if (Choice == 1)
    {
    Fireball Spell(1, 5, 1, "Fireball", "Fire")
    Torrent Spell (1, 5, 1, "Torrent", "Water")
    Wrath Spell (1, 5, 1, "Wrath", "Nature")
    Heal Spell (1, 5, 2, "Heal", "None")
    }
    else {
      Slash Spell (1, 5, 1, "Slash", "None")
      Flurry Spell (1, 5, 1, "Flurry", "None")
      HeavyBlow Spell (1, 5, 1, "HeavyBlow", "None")
      VampiricStrike Spell (1, 5, 1, "VampiricStrike", "None")
    }

}
