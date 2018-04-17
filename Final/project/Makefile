# You can use variables in Makefiles in order to make all of the repetitive
# typing much easier. Here, we include the C++11 version flag as well as
# additional warning flags to make compilation stricter (and, thus, our programs
# safer).
#
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11

SRC_DIR := ./src
OBJ_DIR := ./src
INCLUDE_DIRS := -I./dep/ -I./include/

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all:

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

# Class testing
weapon_type: ./bin/test-weapon_type.out

weapon_rare: ./bin/test-weaponr_rare.out

clean:
	rm ./src/*.o
	rm ./bin/*.out
