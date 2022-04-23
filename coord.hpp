#ifndef COORD_HPP
#define COORD_HPP

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Coord {
  private :
    pair<int, int> _coord ;


  public :
    // Constructors
    Coord(int x, int y);

    // Getters
    int getX() const;
    int getY() const;

    // Methods
    vector<Coord> getNeighbors(int height, int width) const;
} ;

// Operators
bool operator==(Coord a, Coord b) ;
bool operator!=(Coord a, Coord b) ;

ostream& operator<<(ostream& out, Coord a);

#endif
