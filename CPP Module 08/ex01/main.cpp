#include <iostream>

#include "Span.hpp"

int main(){
	Span sp = Span(100000);
	sp.addNumber(1, 50000);
	sp.addNumber(1000, 49998);
	sp.addNumber(100000);

	std::cout << "-----" << std::endl;

	try{
		sp.addNumber(100, 0);
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----" << std::endl;

	try{
		sp.addNumber(100, 1000);
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----" << std::endl;

	try{
		sp.addNumber(10);
		std::cout << "Now might be full\n";
		sp.addNumber(10);
		std::cout << "Must be error\n";
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----" << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
