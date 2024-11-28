#include <iostream>

#include "iter.hpp"

void foo(int&);

int main(){
	int arr[4] = {0, 1, 2, 3};
	std::cout << "Original Array" << std::endl;
	for(int i = 0; i < 4; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	iter(arr, 4, foo);

	std::cout << "Itered Array" << std::endl;
	for(int i = 0; i < 4; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

void foo(int& c){
	c += 10;
}
