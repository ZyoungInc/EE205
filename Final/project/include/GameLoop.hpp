#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

class GameLoop{
public:
  GameLoop();//Default Constructor
  ~GameLoop();//Destructor
  GameLoop(int state, pair<int, string> chInput, int yMax, int xMax);//Overloaded Constructer
};

#endif //GAMELOOP_HPP
