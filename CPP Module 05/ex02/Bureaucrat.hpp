#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat{
private:
	const std::string name;
	int grade;

	class GradeTooHighException: public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception{
		public:
			virtual const char* what() const throw();
	};

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void executeForm(const AForm &form);
	void signForm(AForm &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
