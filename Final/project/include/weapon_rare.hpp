#ifndef WEAPON_RARE_HPP
#define WEAPON_RARE_HPP

class Bonus {
private:
  string name;
  int bonusID;
public:
  Bonus(const std::string& name) : name(name), bonusID(id){}
  const string& getName(void) const {return this->name}
  int getID(void) const {return this->bonusID}
}

class Rare : Bonus{
public:
  Rare(const std::string& name, int id) : Item(name, id) {}
  virtual int getBonusDamage(void) const = 0;
}

class Bronze : public Rare{
public:
  Bronze() : Rare("Bronze", 0)
  virtual int getBonusDamage(void) const {return 1}
}

class Silver : public Rare{
public:
  Silver() : Rare("Silver", 0)
  virtual int getBonusDamage(void) const {return 3}
}

class Gold : public Rare{
public:
  Gold() : Rare("Silver", 0)
  virtual int getBonusDamage(void) const {return 5}
}

class Platinum : public Rare{
public:
  Platinum() : Rare("Platinum", 0)
  virtual int getBonusDamage(void) const {return 7}
}

class Legendary : public Rare{
public:
  Legendary() : Rare("Legendary", 0)
  virtual int getBonusDamage(void) const {return 9}
};

//Cursed may be implimented later

#endif // WEAPON_RARE_HPP
