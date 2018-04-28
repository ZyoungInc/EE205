#ifndef LEVEL_HPP
#define LEVEL_HPP

class Level
{
private:
  int level;

public:
  //Constructor
  Level(int level_);

  int enemy_level(int enemies_killed);
  int levelUp(int enemies_killed);

  //getters
  int get_level();

  //setters
  void set_level(int l);


};

#endif // LEVEL_HPP
