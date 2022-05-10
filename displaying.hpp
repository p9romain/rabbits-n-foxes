#ifndef DISPLAYING_HPP
#define DISPLAYING_HPP

#include <iostream>
#include <string>

#include "params.hpp"

#include "grid.hpp"
#include "game.hpp"


#define RED "\033[31m"
#define BLUE "\033[34m"
#define END "\033[0m"

void print(Grid gr, std::string foldername, int filenumber) ;

std::ostream& operator<<(std::ostream& out, Game g) ;

#endif