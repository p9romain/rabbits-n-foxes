CXX = g++
CXXFLAGS = -g -W -Wall -std=c++2a -O3
LDFLAGS =
EXEC_FILES = main animal-test coord-test grid-test game-test
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)


# Binary files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $<


# Execitive files
main: $(OBJ)
	@$(CXX) $(LDFLAGS) -o $@ $^ 

animal-test: animal.o animal-test.o
	@$(CXX) $(LDFLAGS) -o $@ $^ 

coord-test: coord.o coord-test.o
	@$(CXX) $(LDFLAGS) -o $@ $^ 

grid-test: grid.o grid-test.o
	@$(CXX) $(LDFLAGS) -o $@ $^ 

game-test: game.o game-test.o
	@$(CXX) $(LDFLAGS) -o $@ $^ 


# Headers
$(OBJ): params.hpp
animal.o animal-test.o: animal.hpp
coord.o coord-test.o: coord.hpp
grid.o grid-test.o: grid.hpp
game.o game-test.o: game.hpp


# Utilities
all: main

check: animal-test coord-test grid-test game-test
	@./animal-test -s
	@./coord-test -s
	@./grid-test -s
	@./game-test -s

clean:
	@rm -f $(OBJ) $(EXEC_FILES)
