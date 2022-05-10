#include <utility>
#include <iostream>
#include <stdexcept>

#include "params.hpp"

#include "grid.hpp"
#include "animal.hpp"
#include "coord.hpp"

// Constructors
Grid::Grid(): grid{std::vector<std::vector<Animal*>>(GRIDSIZE.first)} {
  for (size_t lin = 0; lin < grid.size(); lin++) {
    grid.at(lin) = std::vector<Animal*>(GRIDSIZE.second) ;
    for (size_t col = 0; col < grid.at(lin).size(); col++) {
      grid.at(lin).at(col) = nullptr;
    }
  }
}

// Getters
Animal* Grid::getCell(Coord c) const {
  if (this->isCellEmpty(c)) throw std::invalid_argument("Cell is empty.");
  return grid.at(c.getLine()).at(c.getColumn());
}
Animal* Grid::getCell(int n) const {
  Coord c{n};
  return this->getCell(c);
}

int Grid::getCellId(Coord c) const {
  return c.toInt();
}

// Setters
void Grid::setCell(Coord c, Animal* a) {
  grid.at(c.getLine()).at(c.getColumn()) = a;
}
void Grid::setCell(int n, Animal* a) {
  Coord c{n};
  this->setCell(c, a);
}

// Methods
bool Grid::isCellEmpty(Coord c) const {
  return grid.at(c.getLine()).at(c.getColumn()) == nullptr;
}
bool Grid::isCellEmpty(int n) const {
  Coord c{n};
  return this->isCellEmpty(c);
}

void Grid::freeCell(Coord c) {
  grid.at(c.getLine()).at(c.getColumn()) = nullptr;
}
void Grid::freeCell(int n) {
  Coord c{n};
  this->freeCell(c);
}