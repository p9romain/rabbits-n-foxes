#ifndef COORD_HPP
#define COORD_HPP

#include <utility>
#include <vector>
#include <iostream>

class Coord {
  private :
    std::pair<int, int> coord ;


  public :
    // Constructors
    Coord(int lin, int col);
    Coord(int n);

    // Getters
    int getLine() const;
    int getColumn() const;

    // Methods
    std::vector<Coord> getNeighbors() const;
    int toInt() const;
} ;

// Operators
bool operator==(Coord a, Coord b) ;
bool operator!=(Coord a, Coord b) ;

std::ostream& operator<<(std::ostream& out, Coord a);

// Utilities
bool isCorrectCoord(int lin, int col);

#endif // COORD_HPP