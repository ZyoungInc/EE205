#ifndef WEAPON_RARE_HPP
#define WEAPON_RARE_HPP

using namespace std;

class Rare{
private:
public:
  Rare ();
  void Name;
  unsigned damage;
  void modify_weapon();
}

class Bronze : public Rare{
private:
protected:
  set damage = 1;
public:
}

class Silver : public Rare{
private:
protected:
  set damage = 3;
public:
}

class Gold : public Rare{
private:
protected:
  set damage = 5;
public:
}

class Platinum : public Rare{
private:
protected:
  set damage = 7;
public:
}

class Legendary : public Rare{
private:
protected:
  set damage = 9;
public:
};

/*
class Cursed : public Rare{
private:
public:
};
*/

//Cursed may be implimented later

#endif // WEAPON_RARE_HPP
