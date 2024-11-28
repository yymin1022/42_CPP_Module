#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
