#ifndef WEAPON_TYPE_HPP
#define WEAPON_TYPE_HPP

class Equip {
private:
  string name;
  int itemID;
public:
  Item(const std::string& name) : name(name), itemID(id){}
  const string& getName(void) const {return this->name}
  int getID(void) const {return this->itemID}
}

class Weapon : public Equip{
public:
  Weapon(const std::string& name, int id) : Item(name, id) {}
  virtual int getDamage(void) const = 0;
}

class Sword : public Weapon{
public:
  Sword() : Weapon("Sword", 0) {}
  virtual int getDamage(void) const {return 5}
}

class Spear : public Weapon{
public:
  Spear() : Weapon("Spear", 1) {}
  virtual int getDamage(void) const {return 5}
}

class Axe : public Weapon{
public:
  Axe() : Weapon("Axe", 2) {}
  virtual int getDamage(void) const {return 5}
}

class Staff : public Weapon{
  Staff() : Staff("Staff", 3){}
  virtual int getDamage(void) const {return 5}
};

#endif // WEAPON_TYPE_HPP
