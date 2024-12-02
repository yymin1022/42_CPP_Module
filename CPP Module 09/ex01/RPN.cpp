#include "RPN.hpp"

RPN::RPN(){};
RPN::~RPN(){};

RPN::RPN(const RPN& obj)
	: stk(obj.stk){};

RPN& RPN::operator=(const RPN& obj){
	if(this != &obj)
		stk = obj.stk;
	return (*this);
}

void RPN::input(char c){
	if(std::isdigit(c))
		stk.push(c - '0');
	else{
		if(stk.size() < 2)
			throw RpnException();

		int num1 = stk.top();
		stk.pop();
		int num2 = stk.top();
		stk.pop();
		switch(c){
			case '+':
				stk.push(num2 + num1);
				break;
			case '-':
				stk.push(num2 - num1);
				break;
			case '*':
				stk.push(num2 * num1);
				break;
			case '/':
				if(num1 == 0)
					throw RpnException();

				stk.push(num2 / num1);
				break;
			default:
				throw RpnException();
		}
	}
}

int RPN::getResult(){
	if(stk.size() != 1)
		throw RpnException();
	return (stk.top());
}

const char *RPN::RpnException::what() const throw(){
	return ("Error");
}
