# You can use variables in Makefiles in order to make all of the repetitive
# typing much easier. Here, we include the C++11 version flag as well as
# additional warning flags to make compilation stricter (and, thus, our programs
# Here, we are calling functions available in GNU Make in order to get all of
# the .o and .cpp files in ./src so we can use them in our rules later.
# safer).
#
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11

SRC_DIR := ./src
OBJ_DIR := ./src
INCLUDE_DIRS := -I./dep/ -I./include/

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
all: ./bin/test-rand.out

# This build each of the .cpp in the src dir into a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(INCLUDE_DIRS) $(CPPFLAGS) $(CXXFLAGS) -c -o  $@ $<

./bin/test-rand.out: $(OBJ_FILES) ./tst/test-rand.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-rand.out \
		./tst/test-rand.cpp $(OBJ_FILES) -lncurses
	./bin/test-rand.out

./bin/test-display0.out:$(OBJ_FILES) ./tst/test-display0.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-display0.out \
		./tst/test-display0.cpp $(OBJ_FILES) -lncurses
	./bin/test-display0.out

./bin/test-displayMenu.out:$(OBJ_FILES) ./tst/test-displayMenu.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-displayMenu.out \
		./tst/test-displayMenu.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayMenu.out

./bin/test-Enemy.out:$(OBJ_FILES) ./tst/test-Enemy.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-Enemy.out \
		./tst/test-Enemy.cpp $(OBJ_FILES) -lncurses
	./bin/test-Enemy.out

./bin/test-displayChar.out:$(OBJ_FILES) ./tst/test-displayChar.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-displayChar.out \
		./tst/test-displayChar.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayChar.out

./bin/test-displayDiag.out:$(OBJ_FILES) ./tst/test-displayDiag.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-displayDiag.out \
		./tst/test-displayDiag.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayDiag.out

./bin/test-displayOptions.out:$(OBJ_FILES) ./tst/test-displayOptions.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-displayOptions.out \
		./tst/test-displayOptions.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayOptions.out

./bin/test-displayEnemyHUD.out:$(OBJ_FILES) ./tst/test-displayEnemyHUD.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-displayEnemyHUD.out \
		./tst/test-displayEnemyHUD.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayEnemyHUD.out

./bin/test-displayPlayerHUD.out:$(OBJ_FILES) ./tst/test-displayPlayerHUD.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-displayPlayerHUD.out \
		./tst/test-displayPlayerHUD.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayPlayerHUD.out

./bin/test-Weapon.out:$(OBJ_FILES) ./tst/test-Weapon.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-Weapon.out \
		./tst/test-Weapon.cpp $(OBJ_FILES) -lncurses
	./bin/test-Weapon.out

# Convenience rules for the command line to quickly test a class
# Class testing

rand: ./bin/test-rand.out

display0: ./bin/test-display0.out

displayMenu: ./bin/test-displayMenu.out

displayChar: ./bin/test-displayChar.out

displayDiag: ./bin/test-displayDiag.out

displayOptions: ./bin/test-displayOptions.out

displayEnemyHUD: ./bin/test-displayEnemyHUD.out

displayPlayerHUD: ./bin/test-displayPlayerHUD.out

Enemy: ./bin/test-Enemy.out

Weapon: ./bin/test-Weapon.out

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

clean:
	rm ./src/*.o
	rm ./bin/*.out
