#include <iostream>
#include <string>
#include <vector>

using namespace std;

class OffensiveSpell {
private:
    int damage;
    string eff;
    int cost;
    string type;


public:
  OffensiveSpell(string n, int d, int c, string t) :
      name(n),
      damage(d),
      cost(c),
      type(e)
      {}


}
class DefensiveSpell {
private:
    int cost;
    string name;
public:
  virtual void Effect() = 0;

}

class HealSpell : public DefensiveSpell{

private:
  int healamt;

public:
   HealSpell(string n, int c, int h) :
      name(n),
      cost(c),
      healamt(h),
      {}
   virtual void Effect() override {

     player.hp = player.hp + this -> healamt;
     cout << "Player Healed for" << this -> healamt << "Health" << endl
     }
}

class BuffSpell : public DefensiveSpell{

private:
  int buffamt;
public:
   BuffSpell(string n, int c, int b) :
      name(n),
      cost(c),
      buffamt(b),
      {}
   virtual void Effect() override {

     player.def = player.def + this -> buffamt;
     cout << "Player Defense Increased by " << this -> buffamt  << endl
     }
}

class UtilitySpell
{
private:
    int cost;
    string name;
public:
  virtual void Effect() = 0;

}

class DebuffSpell : public UtilitySpell
{
private:
  int debuffamt;

public:
  DebuffSpell(string n, int c, int d) :
     name(n),
     cost(c),
     debuffamt(d),
     {}
  virtual void Effect() override{
    mob.def = mob.def - this -> debuffamt;
    cout << "Mob Defense Decreased by " << this -> debuffamt  << endl
  }
}


}
