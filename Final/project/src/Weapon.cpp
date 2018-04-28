#include "Weapon.hpp"
#include <string>
#include "game-utility.hpp"
#include <utility>

//Default Constructor
Weapon::Weapon() :
  rarity("Bronze"),
  type("Normal"),
  wdamage(2),
  wdefense(2) {}

//Overloaded base weapon Constructor
Weapon::Weapon(std::string rarity_, std::string type_, int wdamage_, int wdefense_) :
  rarity(rarity_),
  type(type_),
  wdamage(wdamage_),
  wdefense(wdefense_) {}

//Inherited Warrior weapon class constructor
Warrior_Weap::Warrior_Weap(unsigned char rarity_level) {
  int weapon_type;
  switch(rarity_level){
    case 1:
		  //Bronze
		  weapon_type = RandNum(1, 3);
		  if(weapon_type == 1){
			Weapon("Bronze", "Sword", 2, 2);
		  }
		  else if(weapon_type == 2){
			Weapon("Bronze", "Axe", 3, 1);
		  }
		  else{
			Weapon("Bronze", "Lance", 1, 3);
		  }
		  break;
    case 2:
		  //Silver
		  weapon_type = RandNum(1, 3);
		  if(weapon_type == 1){
			Weapon("Silver", "Sword", 3, 3);
		  }
		  else if(weapon_type == 2){
			Weapon("Silver", "Axe", 4, 2);
		  }
		  else{
			Weapon("Silver", "Lance", 2, 4);
		  }
		  break;
	case 3:
		//Gold
        weapon_type = RandNum(1, 3);
        if(weapon_type == 1){
          Weapon("Gold", "Sword", 4, 4);
        }
        else if(weapon_type == 2){
          Weapon("Gold", "Axe", 5, 3);
        }
        else{
          Weapon("Gold", "Lance", 3, 5);
        }
        break;
	case 4:
		  //Platinum
		  weapon_type = RandNum(1, 3);
		  if(weapon_type == 1){
			Weapon("Platinum", "Sword", 5, 5);
		  }
		  else if(weapon_type == 2){
			Weapon("Platinum", "Axe", 6, 4);
		  }
		  else{
			Weapon("Platinum", "Lance", 4, 6);
		  }
		  break;
	case 5:
		//Diamond
		weapon_type = RandNum(1, 3);
		if(weapon_type == 1){
		  Weapon("Diamond", "Sword", 6, 6);
		}
		else if(weapon_type == 2){
		  Weapon("Diamond", "Axe", 7, 5);
		}
		else{
		  Weapon("Diamond", "Lance", 5, 7);
		}
		break;
	case 6:
	  //Legendary
	  weapon_type = RandNum(1, 3);
	  if(weapon_type == 1){
		Weapon("Legendary", "Sword", 9, 9);
	  }
	  else if(weapon_type == 2){
		Weapon("Legendary", "Axe", 11, 7);
	  }
	  else{
		Weapon("Legendary", "Lance", 7, 11);
	  }
	  default:
		throw "Not a weapon";
	}
}
//Inherited mage weapon class constructor
Mage_Weap::Mage_Weap(unsigned char rarity_level) {
  switch(rarity_level){
    case 1:
      //Bronze
        Weapon("Bronze", "Staff", 1, 0);
      break;
    case 2:
      //Silver
        Weapon("Silver", "Staff", 3, 1);
      break;
      case 3:
        //Gold
          Weapon("Gold", "Staff", 5, 2);
        break;
        case 4:
          //Platinum
            Weapon("Platinum", "Staff", 7, 3);
          break;
          case 5:
            //Diamond
              Weapon("Diamond", "Staff", 9, 4);
            break;
            case 6:
              //Legendary
                Weapon("Legendary", "Staff", 13, 5);
              default:
                throw "Not a weapon";
  }
}

//Getters
std::string Weapon::get_type() {return type;}
std::string Weapon::get_rarity() {return rarity;}
int Weapon::get_wdamage() {return wdamage;}
int Weapon::get_wdefense() {return wdefense;}
//setters
void Weapon::set_type(std::string t) {this->type = t;}
void Weapon::set_rarity(std::string r) {this->rarity = r;}
void Weapon::set_wdamage(int dmg) {this->wdamage = dmg;}
void Weapon::set_wdefense(int def) {this->wdefense = def;}
