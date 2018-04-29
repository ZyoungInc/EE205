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
		./tst/test-rand.cpp $(OBJ_FILES)
	./bin/test-rand.out

./bin/test-weapon_type.out: $(OBJ_FILES) ./tst/test-weapon_type.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-weapon_type.out \
		./tst/test-weapon_type.cpp $(OBJ_FILES)
	./bin/test-weapon_type.out

./bin/test-weapon_rare.out:$(OBJ_FILES) ./tst/test-weapon_rare.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-weapon_rare.out \
		./tst/test-weapon_rare.cpp $(OBJ_FILES)
	./bin/test-weapon_rare.out

./bin/test-display0.out:$(OBJ_FILES) ./tst/test-display0.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) -lncurses \
		-o ./bin/test-display0.out \
		./tst/test-display0.cpp $(OBJ_FILES)
	./bin/test-display0.out

./bin/test-displayMenu.out:$(OBJ_FILES) ./tst/test-displayMenu.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) -lncurses \
		-o ./bin/test-displayMenu.out \
		./tst/test-displayMenu.cpp $(OBJ_FILES)
	./bin/test-displayMenu.out

./bin/test-displayChar.out:$(OBJ_FILES) ./tst/test-displayChar.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-displayChar.out \
		./tst/test-displayChar.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayChar.out

./bin/test-displayOptions.out:$(OBJ_FILES) ./tst/test-displayOptions.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS)  \
		-o ./bin/test-displayOptions.out \
		./tst/test-displayOptions.cpp $(OBJ_FILES) -lncurses
	./bin/test-displayOptions.out

# Convenience rules for the command line to quickly test a class
# Class testing
weapon_type: ./bin/test-weapon_type.out

weapon_rare: ./bin/test-weaponr_rare.out

rand: ./bin/test-rand.out

display0: ./bin/test-display0.out

displayMenu: ./bin/test-displayMenu.out

displayChar: ./bin/test-displayChar.out

displayOptions: ./bin/test-displayOptions.out

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

clean:
	rm ./src/*.o
	rm ./bin/*.out
