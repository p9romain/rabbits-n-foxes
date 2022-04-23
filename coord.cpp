#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

#include "params.hpp"
#include "coord.hpp"

using namespace std ;

// Utilities
bool isCorrectCoord(int x, int y) {
  return x >= 0 and x < GRIDSIZE.first and y >= 0 and y < GRIDSIZE.second;
}

// Constructors
Coord::Coord(int x, int y) {
	if ( not isCorrectCoord(x,y) ) throw invalid_argument("Position out of grid.");
	
	_coord.first = x;
	_coord.second = y;
}

// Getters
int Coord::getX() const { return _coord.first; }
int Coord::getY() const { return _coord.second; }

// Operators
bool operator==(Coord a, Coord b) { return a.getX() == b.getX() and a.getY() == b.getY(); }
bool operator!=(Coord a, Coord b) { return not (a == b); }

ostream& operator<<(ostream& out, Coord a) {
	out << "(" << a.getX() << "," << a.getY() << ")";
	return out;
}

// Methods
vector<Coord> Coord::getNeighbors() const {
  vector<Coord> neighbors;
  int x = getX(), y = getY();
  for (int i = x-1; i <= x+1; i++) {
    for (int j = y-1; j <= y+1; j++) {
      if ( ( i != x or j != y ) and isCorrectCoord(i,j)) neighbors.push_back(Coord{i, j});
    }
  }
  return neighbors;
}
