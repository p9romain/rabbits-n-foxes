CXX = g++
CXXFLAGS = -g -W -Wall -std=c++2a -O3
LDFLAGS =
EXEC_FILES = main coord-test animal-test grid-test game-test displaying-test 
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

ARGS = $(filter-out $@, $(MAKECMDGOALS))

BIN_CMD = $(CXX) $(CXXFLAGS) -c $<
EXE_CMD = $(CXX) $(LDFLAGS) -o $@ $^ 

# Binary files
%.o: %.cpp
	@$(BIN_CMD)


# Order :
# main params linked_list utilities coord animal grid game displaying

# Executive files
main: main.o params.o linked_list.o utilities.o coord.o animal.o grid.o game.o displaying.o
	@$(EXE_CMD)

coord-test: params.o coord.o coord-test.o
	@$(EXE_CMD)

animal-test: params.o utilities.o animal.o animal-test.o
	@$(EXE_CMD)

grid-test: params.o utilities.o coord.o animal.o grid.o grid-test.o
	@$(EXE_CMD)

game-test: params.o linked_list.o utilities.o coord.o animal.o grid.o game.o game-test.o displaying.o
	@$(EXE_CMD)

displaying-test: params.o linked_list.o utilities.o coord.o animal.o grid.o game.o displaying.o displaying-test.o
	@$(EXE_CMD)


# Headers
$(OBJ): params.hpp linked_list.hpp utilities.hpp displaying.hpp doctest.h  

main.o: game.hpp

utilities.o: coord.hpp

coord.o coord-test.o: coord.hpp

animal.o animal-test.o: animal.hpp

grid.o grid-test.o: coord.hpp animal.hpp grid.hpp

game.o game-test.o: coord.hpp animal.hpp grid.hpp game.hpp

displaying.o displaying-test.o: grid.hpp game.hpp


# Utilities
all: clean clean-frames check main
	@clear
	@./main
	@make animate frame
	@make clean
	@xdg-open frame/anim.gif
	
animate:
	@convert -delay 10 -scale 300 -loop 0 $(ARGS)/*.ppm $(ARGS)/anim.gif

check: coord-test animal-test grid-test game-test displaying-test
	@./coord-test $(ARGS)
	@./animal-test $(ARGS)
	@./grid-test $(ARGS)
	@./game-test $(ARGS)
	@./displaying-test $(ARGS)

clean clear:
	@rm -f $(OBJ) $(EXEC_FILES)

clean-frames clear-frames:
	@rm -rf frame/*
	@rm -rf game_test/*
	@rm -rf displaying_test/*