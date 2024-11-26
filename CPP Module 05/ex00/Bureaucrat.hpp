#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
private:
	std::string const Name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string Name, int Grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const & obj);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException: public std::exception{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException: public std::exception{
	public:
		const char *what() const throw();
	};
};

#endif
