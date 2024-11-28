#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
private:
	static AForm *createPresidentialPardonForm(const std::string &target);
	static AForm *createRobotomyRequestForm(const std::string &target);
	static AForm *createShrubberyCreationForm(const std::string &target);

	class NotFoundFormException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern &operator=(const Intern &other);
	AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
