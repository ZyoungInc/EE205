#include <string>
#include <utility>
#include "game-utility.hpp"
#include "player.hpp"

using namespace std;

Weapon Weapon;
// Constructs a Player with default stats and  chosen name
Player::Player(string name, Weapon wep);:
  name(name),
	MAXhealth(wep.get_MAXhealth),
  MAXmana(wep.get_MAXmana),
	health(wep.get_MAXhealth),
	mana(wep.get_MAXmana),
  att(wep.get_wdamage),
  def(wep.get_wdefense) {}

  //Move Constructor
  Player::Player(Player&& other, char rarity_level):
    Warrior_Weap newwep(rarity_level);
    name(move other.name),
    health(move(other.health)),
    mana(move(other.mana)),
    att(newwep.att),
    def(newwep.def),
    MAXHealth(newwep.MAXHealth),
    MAXMana(newwep.MAXMana) {}

    //Getters
    string get_name() {return name;}
    int Player::get_health() {return health;}
    int Player::get_MAXhealth() {return MAXhealth;}
    int Player::get_mana() {return mana;}
    int Player::get_MAXmana() {return MAXmana;}
    int Player::get_attack() {return att;}
    int Player::et_defense() {return def;}

    //Setters
    void Player::set_name(string s) {name = s;}
    void Player::set_health(int hp)
    if (hp + health > MAXhealth)
      health = MAXhealth;
      else if (health + hp < 0)
      health = 0;
    else
          health += hp;
  }
    void Player::set_MAXhealth(int hp){Maxhealth = hp;}
    void Player::set_mana(int mp)
    if (mp + mana > MAXmana)
  		mana = MAXmana;
      else if (mana + mp < 0)
  		mana = 0;
  	else
          mana += mp;
  }
    void Player::set_MAXmana(int mp){Maxmana = mp;}
    void Player::set_attack(int atk){ att = atk;}
    void Player::set_defense(int d){def = d;}




pair <string, string>  Player::get_player_eff() {
	std::pair <string, string> temp_player_eff;
	temp_player_eff.first = player_eff.first;
	temp_player_eff.second = player_eff.second;
	return temp_player_eff;
}
