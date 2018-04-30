#include <string>
#include <utility>
#include "game-utility.hpp"
#include "player.hpp"

using namespace std;

Weapon basicwep;
// Constructs a Player with default stats and  chosen name
player::player(string name):
  name(name),
	MAXhealth(basicwep.MAXHealth),
  MAXmana(basicwep.MAXmana),
	health(basicwep.MAXHealth),
	mana(basicwep.MAXmana),
  att(basicwep.wdamage),
  def(basicwep.wdefense) {}

  //Move Constructor
  Player::Player(Player&& other, char rarity_level) :
    newwep Warrior_Weap(rarity_level);
    name(move other.name),
    health(move(other.health)),
    mana(move(other.mana)),
    att(newwep.att),
    def(newwep.def),
    MAXHealth(newwep.MAXHealth),
    MAXMana(newwep.MAXMana) {}

    //Getters
    string get_name() {return name;}
    int get_health() {return health;}
    int get_MAXhealth() {return MAXhealth;}
    int get_mana() {return mana;}
    int get_MAXmana() {return MAXmana;}
    int get_attack(); {return attack;}
    int get_defense() {return defense;}

    //Setters
    void set_name(string s) {name = s;}
    void set_health(int hp)
    if (hp + health > MAXhealth)
      health = MAXhealth;
      else if (health + hp < 0)
      health = 0;
    else
          health += hp;
  }
    void set_MAXhealth(int hp){Maxhealth = hp;}
    void set_mana(int mp)
    if (mp + mana > MAXmana)
  		mana = MAXmana;
      else if (mana + mp < 0)
  		mana = 0;
  	else
          mana += mp;
  }
    void set_MAXmana(int mp){Maxmana = mp;}
    void set_attack(int atk){ att = atk;}
    void set_defense(int d){def = d;}




pair <string, string>  Player::get_player_eff() {
	std::pair <string, string> temp_player_eff;
	temp_player_eff.first = player_eff.first;
	temp_player_eff.second = player_eff.second;
	return temp_player_eff;
}
