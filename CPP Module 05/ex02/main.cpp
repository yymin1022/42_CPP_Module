#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 150);
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;

    std::cout << "\n\n";

    ShrubberyCreationForm shrubbery("Garden");
    RobotomyRequestForm robotomy("Robot");
    PresidentialPardonForm pardon("Prisoner");
    bob.signForm(shrubbery);
    bob.executeForm(shrubbery);
    bob.signForm(robotomy);
    bob.executeForm(robotomy);
    try{
        bob.executeForm(pardon);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    bob.signForm(pardon);
    bob.executeForm(pardon);

    std::cout << "\n\n";

    try{
        alice.executeForm(shrubbery);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        alice.signForm(shrubbery);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        alice.executeForm(shrubbery);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        alice.signForm(robotomy);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        alice.executeForm(robotomy);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        alice.signForm(pardon);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        alice.executeForm(pardon);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
