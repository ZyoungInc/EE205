#include <string>
#include <utility>
#include <algorithm>
#include "game-utility.hpp"
#include "Player.hpp"
#include "Weapon.hpp"

using namespace std;

//Default Constructor
Player::Player() :
  name(""),
  //rarity(""),
  //type(""),
  MAXhealth(0),
  MAXmana(0),
	health(0),
	mana(0),
  attack(0),
  defense(0) {}

Player::~Player() {}

// Constructs a Player with default stats and  chosen name
Player::Player(string name_, Weapon *weap_) :
  weap(weap_),
  name(name_),
  //rarity(weap->get_rarity()),
  //type(weap->get_type()),
  MAXhealth(weap->get_MAXhealth()),
  health(weap->get_MAXhealth()),
  MAXmana(weap->get_MAXmana()),
  mana(weap->get_MAXmana()),
  attack(weap->get_wdamage()),
  defense(weap->get_wdefense()) {}

  /*//Copy Constructor
  Player::Player(const Player& other) :
    name(other.name),
    health(other.health),
    mana(other.mana),
    attack(other.attack),
    defense(other.defense) {}
  //Move Constructor
  Player::Player(Player&& other) :
    name(move(other.name)),
    health(move(other.health)),
    mana(move(other.mana)),
    attack(move(other.attack)),
    defense(move(other.defense)) {}*/

   //Getters
    string Player::get_name() {return name;}
    //string Player::get_rarity() {return rarity;}
    //string Player::get_type() {return type;}
    int Player::get_health() {return health;}
    int Player::get_MAXhealth() {return MAXhealth;}
    int Player::get_mana() {return mana;}
    int Player::get_MAXmana() {return MAXmana;}
    int Player::get_attack() {return attack;}
    int Player::get_defense() {return defense;}

  //Setters
    void Player::set_name(string s) {name = s;}
    //void Player::set_rarity(string r) {rarity = r;}
    //void Player::set_type(string t) {type = t;}
    void Player::set_health(int hp){
    if(hp + health > MAXhealth)
      health = MAXhealth;
      else if (health + hp < 0)
      health = 0;
    else
          health += hp;
  }
    void Player::set_MAXhealth(int hp){MAXhealth = hp;}
    void Player::set_mana(int mp){
    if (mp + mana > MAXmana)
  		mana = MAXmana;
      else if (mana + mp < 0)
  		mana = 0;
  	else
          mana += mp;
  }
    void Player::set_MAXmana(int mp){MAXmana = mp;}
    void Player::set_attack(int atk){attack = atk;}
    void Player::set_defense(int d){defense = d;}
