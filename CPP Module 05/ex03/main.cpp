#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	Intern intern;
	AForm* form;

	try{
		std::cout << "Bureaucrat 'A' grade '1'\n\n";
		Bureaucrat A("A", 1);
		std::cout << A << "\n\n";

		form = intern.makeForm("shrubbery creation", "target1");
		if(form){
			A.signForm(*form);
			A.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "target1");
		if(form){
			A.signForm(*form);
			A.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "target1");
		if(form){
			A.signForm(*form);
			A.executeForm(*form);
			delete form;
		}
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		std::cout << "\n\nBureaucrat 'B' grade '50'\n\n";
		Bureaucrat B("B", 50);
		std::cout << B << "\n\n";

		form = intern.makeForm("shrubbery creation", "target2");
		if(form){
			B.signForm(*form);
			B.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "target2");
		if(form){
			B.signForm(*form);
			B.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "target2");
		if(form){
			B.signForm(*form);
			B.executeForm(*form);
			delete form;
		}
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		std::cout << "\n\nBureaucrat 'C' grade '150'\n\n";
		Bureaucrat C("C", 150);
		std::cout << C << "\n\n";

		form = intern.makeForm("shrubbery creation", "target3");
		if(form){
			C.signForm(*form);
			C.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "target3");
		if(form){
			C.signForm(*form);
			C.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "target3");
		if(form){
			C.signForm(*form);
			C.executeForm(*form);
			delete form;
		}
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		std::cout << "\n\nBureaucrat 'D' grade '33'\n\n";
		Bureaucrat D("D", 33);
		std::cout << D << "\n\n";

		form = intern.makeForm("Shrrrrrubbery creation", "target4");
		if(form){
			D.signForm(*form);
			D.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomyrequest", "target4");
		if(form){
			D.signForm(*form);
			D.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon ", "target4");
		if(form){
			D.signForm(*form);
			D.executeForm(*form);
			delete form;
		}
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
