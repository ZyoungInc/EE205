class Spell{
private:
  int cost;
  int damage;
  int cooldown;
  string name;
  string EleType;

public:
  //Constructor
  Spell (int c, int d, int cd, string n, string e );
  //Choice between 2 sets of spells
  Spellset(int Choice);

  // Copy Constructor
  Spell(const Spell& other);

  //Move Constructor
  Spell(Spell&& other);

  //Getters
  int get_cost();
  int get_damage();
  int get_cd();
  string get_name();
  string get_EleType();

  //Setters
  void set_cost(int c);
  void set_damage(int d);
  void set_cd(int cool);
  void set_name(string n);
  void set_Type(string e);
}
