#include <utility>
#include <stdexcept>
#include <iostream>
#include <vector>

#include "params.hpp"

#include "coord.hpp"

// Utilities
bool isCorrectCoord(int lin, int col) {
  return lin >= 0 and lin < GRIDSIZE.first and col >= 0 and col < GRIDSIZE.second;
}

// Constructors
Coord::Coord(int lin, int col) {
	if (not isCorrectCoord(lin,col)) throw std::invalid_argument("Position out of grid.");
	
	this->coord.first = lin;
	this->coord.second = col;
}
Coord::Coord(int n) {
  int lin = n/GRIDSIZE.second, col = n%GRIDSIZE.second;

  if (not isCorrectCoord(lin,col)) throw std::invalid_argument("Position out of grid.");
  
  this->coord.first = lin;
  this->coord.second = col;
}

// Getters
int Coord::getLine() const { return this->coord.first; }
int Coord::getColumn() const { return this->coord.second; }

// Operators
bool operator==(Coord a, Coord b) { return a.getLine() == b.getLine() and a.getColumn() == b.getColumn(); }
bool operator!=(Coord a, Coord b) { return not (a == b); }

std::ostream& operator<<(std::ostream& out, Coord a) {
	out << "(" << a.getLine() << "," << a.getColumn() << ")";
	return out;
}

// Methods
std::vector<Coord> Coord::getNeighbors() const {
  std::vector<Coord> neighbors;
  int lin = this->getLine(), col = this->getColumn();
  for (int i = lin-1; i <= lin+1; i++) {
    for (int j = col-1; j <= col+1; j++) {
      if ((i != lin or j != col) and isCorrectCoord(i,j)) {
        neighbors.push_back(Coord{i,j});
      }
    }
  }
  return neighbors;
}

int Coord::toInt() const {
  return this->getLine()*GRIDSIZE.second+this->getColumn();
}