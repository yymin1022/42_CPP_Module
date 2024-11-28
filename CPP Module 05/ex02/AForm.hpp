#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
private:
	const std::string name;
	const std::string target;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	AForm();
	AForm &operator=(const AForm &other);

protected:
	AForm(const AForm &other);
	AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute);

	class FormAlreadySignedException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class FileOpenException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

class GradeTooHighException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	public:
	virtual ~AForm();
	const std::string &getName() const;
	const std::string &getTarget() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void makeSign(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
