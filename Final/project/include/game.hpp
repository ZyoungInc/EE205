#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"

class Game {
  public:
    //Constructor
    Game();

    Player player;
    //returns true if game should be running, false if not
    bool is_running(void);
    //starts the game
    //startGame();
    //Destructor
    ~Game();



  protected:

};

#endif // GAME_HPP
