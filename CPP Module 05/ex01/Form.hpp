#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form{
private:
	std::string name;
	bool isSignedFlag;
	int gradeLevelExec;
	int gradeLevelSign;

public:
	Form();
	Form(const std::string name, int signGrade, int execGrade);
	Form(Form const& src);
	~Form();
	Form &operator=(Form const& obj);

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void setSignature(Bureaucrat const& bCrat);

	std::string isSigned() const;

	class gradeTooHighException: public std::exception{
	public:
		const char *what() const throw();
	};

	class gradeTooLowException: public std::exception{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream& o, Form const& obj);

#endif
