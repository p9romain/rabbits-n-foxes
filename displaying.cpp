#include <string>
#include <iomanip>
#include <sstream>  
#include <fstream>
#include <utility>
#include <iostream>

#include "params.hpp"

#include "displaying.hpp"
#include "grid.hpp"
#include "game.hpp"

void print(Grid gr, std::string foldername, int filenumber)
{
  int r, g, b;
  std::ostringstream filename ;

  filename << "frame_" << std::setfill('0') << std::setw(6) << filenumber << ".ppm";

  std::ofstream file ;
  file.open(foldername + "/" + filename.str()) ;

  file << "P3" << std::endl << GRIDSIZE.second+2 << " " << GRIDSIZE.first+2 << std::endl << 255 << std::endl ;
  for ( int i = -1 ; i < GRIDSIZE.first+1 ; i++ )
  {
    for ( int j = -1 ; j < GRIDSIZE.second+1 ; j++ )
    {
      if ( i == -1 or i == GRIDSIZE.first or j == -1 or j == GRIDSIZE.second )
      {
        r = 0 ;
        g = 0 ;
        b = 0 ;
      }
      else
      {  
        Coord c{i,j} ;
        if (gr.isCellEmpty(c)) {          
          r = 255 ;
          g = 255 ;
          b = 255 ;
        } else {
          auto* a = gr.getCell(c) ;
          
          if ( (*a).getType() == "Fox" ) {
            r = 255 ;
            g = 145 ;
            b = 0 ;
          }
          if ( (*a).getType() == "Rabbit" ) {
            r = 190 ;
            g = 190 ;
            b = 190 ;
          }
        }
      }
      file << r << " " << g << " " << b << " " ;
    }
    file << std::endl ;
  }
  file.close() ;
}

std::ostream& operator<<(std::ostream& out, Game g)
{
  Grid gr = g.getGrid() ;
  int f = g.countFoxes() ;
  int r = g.countRabbits() ;
  int n = GRIDSIZE.first*GRIDSIZE.second ;

  out << std::string(( GRIDSIZE.second - std::to_string(ROUND).size() - 8 ) / 2, '-') 
      << " Round " << ROUND << " " 
      << std::string(( GRIDSIZE.second - std::to_string(ROUND).size() - 8 ) / 2, '-') 
      << std::endl ;

  out << std::endl ;

  out << "Ratio of Foxes : " << ( f / ( n * 1. ) ) * 100 << "%" << std::endl ;
  out << "Ratio of Rabbits : " << ( r / ( n * 1. ) ) * 100 << "%" << std::endl ;

  for ( int i = 0 ; i < GRIDSIZE.first ; i++ )
  {
    for ( int j = 0 ; j < GRIDSIZE.second ; j++ )
    {
      Coord c{i,j} ;
      if (gr.isCellEmpty(c)) {          
        out << " " ;
      } else {
        auto* a = gr.getCell(c) ;
        if ( (*a).getType() == "Fox" ) {
          out << RED << "F" << END ;
        }
        if ( (*a).getType() == "Rabbit" ) {
          out << BLUE << "R" << END ;
        }
      }
      out << "  " ;
    }
    out << std::endl ;
  }

  out << std::string(GRIDSIZE.second, '-') << std::endl ;
 
  return out ;
}