#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

#include "params.hpp"

#include "animal.hpp"
#include "coord.hpp"

class Grid {
  private :
    std::vector<std::vector<Animal*>> grid ;

  public :
    // Constructors
    Grid();

    // Getters
    Animal* getCell(Coord c) const;
    Animal* getCell(int n) const;
    int getCellId(Coord c) const;

    // Setters
    void setCell(Coord c, Animal* a);
    void setCell(int n, Animal* a);

    // Methods
    bool isCellEmpty(Coord c) const;
    bool isCellEmpty(int n) const;

    void freeCell(Coord c);
    void freeCell(int n);
} ;

#endif