#include <utility>
#include <ctime>
#include <stdexcept>
#include <vector>

#include "params.hpp"
#include "linked_list.hpp"

#include "game.hpp"
#include "grid.hpp"
#include "coord.hpp"
#include "animal.hpp"

Game::Game(): grid{Grid()} {
  LinkedList::List* f = LinkedList::init() ;
  LinkedList::List* r = LinkedList::init() ;

  this->foxes = f ;
  this->rabbits = r ;
}

void Game::init()
{
  int n ;

  for (int i = 0; i < RATERABBIT*GRIDSIZE.first*GRIDSIZE.second; i++) {
    do {
      n = rand() % (GRIDSIZE.first*GRIDSIZE.second);
    } while (not this->grid.isCellEmpty(n));

    this->createRabbitAt(n);
  }
  for (int i = 0; i < RATEFOX*GRIDSIZE.first*GRIDSIZE.second; i++) {
    do {
      n = rand() % (GRIDSIZE.first*GRIDSIZE.second);
    } while (not this->grid.isCellEmpty(n));

    this->createFoxAt(n);
  }
}

void Game::createRabbitAt(Coord c) {
  Rabbit* r = (Rabbit*) malloc(sizeof(Rabbit)) ;
  new (r) Rabbit() ;

  this->grid.setCell(c, r) ;
  LinkedList::pushFront(this->rabbits, c.toInt());
}
void Game::createRabbitAt(int n) {
  Coord c{n};
  this->createRabbitAt(c);
}

void Game::createFoxAt(Coord c) {
  Fox* f = (Fox*) malloc(sizeof(Fox));
  new (f) Fox() ;

  this->grid.setCell(c, f);
  LinkedList::pushFront(this->foxes, c.toInt());
}
void Game::createFoxAt(int n) {
  Coord c{n};
  this->createFoxAt(c);
}

void Game::destroyRabbitAt(Coord c) {
  auto* r = this->grid.getCell(c);
  if ( (*r).getType() != "Rabbit" )
  {
    throw std::invalid_argument("The pointed Animal is not a Rabbit.") ;
  }

  free(r);
  LinkedList::pop(this->rabbits, c.toInt());
  this->grid.freeCell(c);
}
void Game::destroyFoxAt(Coord c) {
  auto* f = this->grid.getCell(c);  
  if ( (*f).getType() != "Fox" )
  {
    throw std::invalid_argument("The pointed Animal is not a Fox.") ;
  }

  free(f);
  LinkedList::pop(this->foxes, c.toInt());
  this->grid.freeCell(c);
}

int Game::countFoxes() const {
  return this->foxes->length;
}
int Game::countRabbits() const {
  return this->rabbits->length;
}


int Game::achieveActionRabbit(Coord c) {
  int pos = -1;

  auto* r = this->grid.getCell(c);
  if ( (*r).getType() != "Rabbit" )
  {
    throw std::invalid_argument("The pointed Animal is not a Rabbit.") ;
  }

  // Move
  std::vector<Coord> neighbors = c.getNeighbors();

  std::vector<Coord> rabbitCells = {};
  std::vector<Coord> foxCells = {};
  std::vector<Coord> emptyCells = {};

  for (Coord i : neighbors) {
    if (this->grid.isCellEmpty(i)) emptyCells.push_back(i);
    else if (this->grid.getCell(i)->getType() == "Rabbit") rabbitCells.push_back(i);
    else if (this->grid.getCell(i)->getType() == "Fox") foxCells.push_back(i);
  }

  if (emptyCells.size() != 0) {
    int n = rand() % emptyCells.size();
    Coord d = emptyCells.at(n);
    
    pos = d.toInt();
    
    this->grid.setCell(d, r) ;
    this->grid.freeCell(c) ;
  }

  // Birth
  if (emptyCells.size() >= size_t(r->getMinRateBirth()) and (float) rand()/RAND_MAX <= r->getProbBirth()) this->createRabbitAt(c);

  return pos;
}

int Game::achieveActionRabbit(int n) {
  Coord c{n};
  return this->achieveActionRabbit(c);
}


void Game::moveAllRabbits() {  
  if (this->rabbits->length == 0) return;

  LinkedList::Node* p = this->rabbits->root;
  while (p != nullptr) {
    int pos = this->achieveActionRabbit(p->val);
    if (pos != -1 and pos != p->val) p->val = pos;
    p = p->next;
  }
}

/// Nous avons choisi de faire diminuer le niveau de nourriture à la fin de son action et non au début. Ceci nous paraît plus logique. ///
void Game::achieveActionFox(LinkedList::Node* p) {
  Coord c{p->val};

  auto* f = this->grid.getCell(c);
  if ( (*f).getType() != "Fox" )
  {
    throw std::invalid_argument("The pointed Animal is not a Fox.") ;
  }

  // Dead
  if (f->isDead()) {
    this->destroyFoxAt(c);
    return;
  }

  // Move
  std::vector<Coord> neighbors = c.getNeighbors();

  std::vector<Coord> rabbitCells = {};
  std::vector<Coord> foxCells = {};
  std::vector<Coord> emptyCells = {};

  for (Coord i : neighbors) {
    if (this->grid.isCellEmpty(i)) emptyCells.push_back(i);
    else if (this->grid.getCell(i)->getType() == "Rabbit") rabbitCells.push_back(i);
    else if (this->grid.getCell(i)->getType() == "Fox") foxCells.push_back(i);
  }

  if (rabbitCells.size() != 0) {
    int n = rand() % rabbitCells.size();
    Coord d{rabbitCells.at(n)};
    
    // Food intake
    if (not f->reachFoodMax()) f->setFood(f->getFood()+this->grid.getCell(d)->getfGiven());

    // Rabbit eaten
    this->destroyRabbitAt(d);

    // Move fox
    this->grid.setCell(d, f);
    this->grid.freeCell(c);
    p->val = d.toInt();
  }
  else if (emptyCells.size() != 0) {
    int n = rand() % emptyCells.size();
    Coord d{emptyCells.at(n)};
    
    // Move fox
    this->grid.setCell(d, f);
    this->grid.freeCell(c);
    p->val = d.toInt();
  }

  // Birth
  if (f->canGiveBirth() and (float) rand()/RAND_MAX <= f->getProbBirth()) this->createFoxAt(c);

  // Loss of a unit of food
  f->setFood(f->getFood()-1);
}

void Game::moveAllFoxes() {
  if (this->foxes->length == 0) return;

  LinkedList::Node* p = this->foxes->root;

  while (p != nullptr) {
    LinkedList::Node* tmp = p->next;
    this->achieveActionFox(p);
    p = tmp;
  }
}

Grid Game::getGrid()
{
  return this->grid ;
}


/** Stop conditions (at least one) :
- No more foxes (rabbits can't die anymore)
- No more rabbits
- Round number goes over one million (threshold in filenames for .ppm)
- Round number goes over custom threshold given by User
**/
bool Game::isTheEnd() const
{
  return this->foxes->length == 0 or this->rabbits->length == 0 or ROUND >= 1e6 or ROUND == ROUND_THRESHOLD ;
}