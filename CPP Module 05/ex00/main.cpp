#include "Bureaucrat.hpp"

int main(){
	try{
        Bureaucrat bureaucrat("Bob", 2);
        std::cout << bureaucrat << std::endl;
    }catch(Bureaucrat::GradeTooHighException &e){
        std::cerr << e.what() << std::endl;
    }catch(Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat1("Bob", 1);
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
    }catch(Bureaucrat::GradeTooHighException &e){
        std::cerr << e.what() << std::endl;
    }catch(Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat2("Bob", 150);
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
    }catch(Bureaucrat::GradeTooHighException &e){
        std::cerr << e.what() << std::endl;
    }catch(Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
