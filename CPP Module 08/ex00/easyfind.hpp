#pragma once

#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>

class NotFoundException: public std::exception{
public:
	virtual const char *what() const throw(){
		return ("Not found");
	}
};

template<typename T>
typename T::iterator easyfind(T& lst, int i){
	typename T::iterator it;
	it = find(lst.begin(), lst.end(), i);

	if(it == lst.end())
		throw (NotFoundException());
	return (it);
}
