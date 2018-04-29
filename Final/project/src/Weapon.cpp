#include <utility>
#include <string>
#include "game-utility.hpp"
#include "Weapon.hpp"

//Default Constructor
Weapon::Weapon() :
  rarity("Normal"),
  type("Hands"),
  wdamage(2),
  wdefense(2),
  MAXhealth(10)
  MAXmana(10) {}

//Overloaded base weapon constructor
Weapon::Weapon(std::string rarity_, std::string type_, int wdamage_, int wdefense_) :
  rarity(rarity_),
  type(type_),
  wdamage(wdamage_),
  wdefense(wdefense_) {}

//Inherited Warrior weapon class constructor
Warrior_Weap::Warrior_Weap(unsigned char rarity_level) {
  int weapon_type;
  switch(rarity_level){
    case 1: //Bronze melee weapon
		  weapon_type = RandNum(1, 3);
		    if(weapon_type == 1){
          Weapon("Bronze", "Sword", 2, 2, 10, 10);
		    }
		      else if(weapon_type == 2){
            Weapon("Bronze", "Axe", 3, 1, 10, 10);
		      }
            else{
              Weapon("Bronze", "Lance", 1, 3, 10, 10);
		        }
		  break;
    case 2: //Silver melee weapon
		  weapon_type = RandNum(1, 3);
		    if(weapon_type == 1){
          Weapon("Silver", "Sword", 3, 3, 20, 15);
		    }
          else if(weapon_type == 2){
            Weapon("Silver", "Axe", 4, 2, 20, 15);
		      }
            else{
              Weapon("Silver", "Lance", 2, 4, 20, 15);
		      }
      break;
    case 3: //Gold melee weapon
      weapon_type = RandNum(1, 3);
        if(weapon_type == 1){
          Weapon("Gold", "Sword", 4, 4, 35, 30);
        }
        else if(weapon_type == 2){
          Weapon("Gold", "Axe", 5, 3, 35, 30);
        }
          else{
            Weapon("Gold", "Lance", 3, 5, 35, 30);
          }
      break;
    case 4: //Platinum melee weapon
		  weapon_type = RandNum(1, 3);
		    if(weapon_type == 1){
			    Weapon("Platinum", "Sword", 5, 5, 55, 45);
        }
		      else if(weapon_type == 2){
            Weapon("Platinum", "Axe", 6, 4, 55, 45);
          }
		        else{
              Weapon("Platinum", "Lance", 4, 6, 55, 45);
		      }
      break;
    case 5: //Diamond melee weapon
      weapon_type = RandNum(1, 3);
		    if(weapon_type == 1){
		      Weapon("Diamond", "Sword", 6, 6, 80, 70);
        }
        else if(weapon_type == 2){
          Weapon("Diamond", "Axe", 7, 5, 80, 70);
        }
          else{
            Weapon("Diamond", "Lance", 5, 7, 80, 70);
		      }
		   break;
    case 6: //Legendary melee weapon
      weapon_type = RandNum(1, 3);
        if(weapon_type == 1){
          Weapon("Legendary", "Sword", 9, 9, 111, 99);
	      }
        else if(weapon_type == 2){
		        Weapon("Legendary", "Axe", 11, 7, 111, 99);
	      }
        else{
		        Weapon("Legendary", "Lance", 7, 11, 111, 99);
        }
    break;
    default:
		  throw "Not a weapon";
	}
}
//Inherited mage weapon class constructor
Mage_Weap::Mage_Weap(unsigned char rarity_level) {
  switch(rarity_level){
    case 1: //Bronze type staff weapon
        Weapon("Bronze", "Staff", 1, 0, 10, 10);
      break;
    case 2: //Silver type staff weapon
        Weapon("Silver", "Staff", 3, 1, 15, 25);
      break;
    case 3: //Gold type staff weapon
        Weapon("Gold", "Staff", 5, 2, 30, 50);
      break;
    case 4: //Platinum type staff weapon
        Weapon("Platinum", "Staff", 7, 3, 40, 65);
      break;
    case 5: //Diamond type staff weapon
        Weapon("Diamond", "Staff", 9, 4, 60, 80);
      break;
    case 6: //Legendary type staff weapon
        Weapon("Legendary", "Staff", 13, 5, 99, 111);
      break;
    default:
      throw "Not a weapon";
  }
}

//Getters
std::string Weapon::get_type() {return type;}
std::string Weapon::get_rarity() {return rarity;}
int Weapon::get_wdamage() {return wdamage;}
int Weapon::get_wdefense() {return wdefense;}
int Weapon::get_MAXhealth() {return MAXhealth;}
int Weapon::get_MAXmana() {return MAXmana;}

//Setters
void Weapon::set_type(std::string t) {this->type = t;}
void Weapon::set_rarity(std::string r) {this->rarity = r;}
void Weapon::set_wdamage(int dmg) {this->wdamage = dmg;}
void Weapon::set_wdefense(int def) {this->wdefense = def;}
void Weapon::get_MAXhealth(int hp) {return MAXhealth;}
void Weapon::get_MAXmana(int mp) {return MAXmana;}
