#include "BitcoinExchange.hpp"

int main(int argc, char** argv){
	if(argc != 2){
		std::cerr << "Error: usage: BitcoinExchange <filename>" << std::endl;
		std::exit(1);
	}

	std::cout << "Hello, World!" << std::endl;

	return 0;
}
