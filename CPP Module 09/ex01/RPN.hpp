#ifndef RPN_HPP
# define RPN_HPP

#include <cctype>
#include <stack>
#include <string>

class RPN{
private:
	std::stack<int> stk;

public:
	RPN();
	RPN(const RPN& copy);
	~RPN();
	RPN& operator=(const RPN& copy);

	int getResult();
	void input(char c);

	class RpnException: public std::exception{
	public:
		virtual const char *what() const throw();
	};
};

#endif
