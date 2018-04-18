#ifndef WEAPON_TYPE_HPP
#define WEAPON_TYPE_HPP

using namespace std;

class Weapon {
private:
public:
  Weapon ();
  unsigned damage;
  void deal_damage();
}

class Sword : public Weapon{
private:
public:
}

class Spear : public Weapon{
private:
public:
}

class Axe : public Weapon{
private:
public:
};

#endif // WEAPON_TYPE_HPP
