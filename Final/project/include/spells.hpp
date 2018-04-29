class Spell{
private:
  int cost;
  int damage;
  int hits;
  string name;
  string EleType;

public:
  //Constructor
  Spell (int c, int d, int h, string n, string e );
  //Choice between 2 sets of spells
  Spellset(int Choice);

  // Copy Constructor
  Spell(const Spell& other);

  //Move Constructor
  Spell(Spell&& other);

  //Getters
  int get_cost();
  int get_damage();
  int get_hits();
  string get_name();
  string get_EleType();

  //Setters
  void set_cost(int c);
  void set_damage(int d);
  void set_hits(int h);
  void set_name(string n);
  void set_Type(string e);

  void Effect();
}
