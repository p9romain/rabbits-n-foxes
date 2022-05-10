#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  private:
    const std::string type ;
    const float probBirth ;


  public:
    float getProbBirth() const ;
    std::string getType() const ;

    Animal( std::string type, float probBirth ) ;

    // Fox
    void virtual setFood( const float f ) ;
    float virtual getFood() const ;
    bool virtual isDead() const ;
    bool virtual canGiveBirth() const ;
    bool virtual reachFoodMax() const ;

    // Rabbit
    float virtual getfGiven() const ;
    int virtual getMinRateBirth() const ;

} ;

class Fox : public Animal 
{
  private:
    const float fInit, fReprod, fMax ;
    float food ;


  public:
    void setFood( const float f ) ;

    float getFood() const ;

    bool isDead() const ;
    bool canGiveBirth() const ;
    bool reachFoodMax() const ;

    Fox() ;
} ;

class Rabbit : public Animal 
{
  private:
    const float fGiven ;
    const int minRateBirth ;


  public:
    float getfGiven() const ;
    int getMinRateBirth() const ;

    Rabbit() ;
} ;

float rng( float start, float end, float step ) ;

#endif // ANIMAL_HPP