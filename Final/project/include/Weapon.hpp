#ifndef WEAPON_HPP
#define WEAPON_HPP

//Abstract base class
class Weapon {
protected:
  std::string type;
  std::vector<std::string> rarity;
  int wdamage;
  int rdamage;

public:
  void set_rarity(std::vector<std::string>);
  int set_tdamage(int w, int r);
  virtual std::string type(void) = 0;
};

class Sword: public IWeapon {
public:
  virtual std::string type(void) override {
    return "Sword";
  }
};

class Axe: public IWeapon {
public:
  virtual std::string type(void) override {
    return "Axe";
  }
};

class Lance: public IWeapon {
public:
  virtual std::string type(void) override {
    return "Lance";
  }
};

class Staff: public IWeapon {
public:
  virtual std::string type(void) override {
    return "Normal";
  }
};


#endif // WEAPON_HPP
