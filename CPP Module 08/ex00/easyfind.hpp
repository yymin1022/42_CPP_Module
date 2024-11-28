#pragma once

#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &in, int i){
	typename T::iterator it;
	it = find(in.begin(), in.end(), i);

	if(it == in.end())
		throw (NotFoundException());
	return (it);
}

class NotFoundException: public std::exception{
public:
	virtual const char *what() const throw(){
		return ("Not found");
	}
};
