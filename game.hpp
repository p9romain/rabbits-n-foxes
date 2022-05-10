#ifndef GAME_HPP
#define GAME_HPP

#include "linked_list.hpp"

#include "grid.hpp"
#include "coord.hpp"

class Game
{
  private:
    Grid grid ;
    // Par sûreté avec les pointeurs
    LinkedList::List* foxes ;
    LinkedList::List* rabbits ;

  public:
    Game() ;

    void init() ;

    int countRabbits() const;
    int countFoxes() const;

    void createRabbitAt(Coord c);
    void createRabbitAt(int n);
    void createFoxAt(Coord c);
    void createFoxAt(int n);
    
    void destroyRabbitAt(Coord c);
    void destroyRabbitAt(int n);
    void destroyFoxAt(Coord c);
    void destroyFoxAt(int n);

    int achieveActionRabbit(Coord c);
    int achieveActionRabbit(int n);
    void achieveActionFox(LinkedList::Node* p);

    void moveAllRabbits();
    void moveAllFoxes();

    Grid getGrid() ;

    bool isTheEnd() const ;
};

#endif