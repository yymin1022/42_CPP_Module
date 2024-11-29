#include <iostream>

#include "MutantStack.hpp"

int main(){
	MutantStack<int> mstk;
	mstk.push(42);
	mstk.push(43);
	mstk.pop();
	mstk.push(1234);
	mstk.push(435);

	MutantStack<int>::iterator it = mstk.begin();
	MutantStack<int>::iterator itEnd = mstk.end();

	while(it != itEnd){
		std::cout << *it << " ";
		it++;
	}

	std::cout << std::endl;

	return 0;
}
