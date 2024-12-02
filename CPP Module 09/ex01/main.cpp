#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv){
	try{
		if(argc != 2)
			throw std::string("Error: No Argument");

		RPN rpn;
		std::string expr(argv[1]);
		int length = expr.size();
		for(int i = 0; i < length; i++){
			if((i & 1) == 0)
				rpn.input(expr[i]);
			else if(expr[i] != ' ')
				throw RPN::RpnException();
		}

		std::cout << rpn.getResult() << std::endl;
	}catch(const std::string& e){
		std::cerr << e << std::endl;
		return 1;
	}catch(const RPN::RpnException& e){
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
