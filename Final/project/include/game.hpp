#ifndef GAME_HPP
#define GAME_HPP

class Game {
  public:
    //Constructor
    Game();
    //returns true if game should be running, false if not
    bool is_running(void);
    //starts the game
    //startGame();
    //Destructor
    ~Game();



  protected:
    bool getInput(char *c);
    void updateTimer(void);
};

#endif // GAME_HPP
