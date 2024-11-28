#include <iostream>
#include <list>

#include "easyfind.hpp"

int main(){
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(43);
	lst.push_back(44);

	std::list<int>::const_iterator it = lst.end();
	try{
		it = easyfind(lst, 42);
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	if(it != lst.end())
		std::cout << *it << " found" << std::endl;

	it = lst.end();
	try{
		it = easyfind(lst, 442);
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	if(it != lst.end())
		std::cout << *it << " found" << std::endl;

	return 0;
}
