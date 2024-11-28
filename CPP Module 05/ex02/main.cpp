#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
        Bureaucrat b1("Bureaucrat 1", 1);
        Bureaucrat b2("Bureaucrat 2", 150);
        Bureaucrat b3("Bureaucrat 3", 75);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;

        b1.incrementGrade();
    }catch(const std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Form f1("Form 1", 0, 100);
    }catch(const std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Form f1("Form 1", 170, 1);
    }catch(const std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Form f1("Form 1", 50, 100);

        std::cout << f1 << std::endl;

        Bureaucrat b6("Bureaucrat 6", 40);
        b6.signForm(f1);
        std::cout << f1 << std::endl;

        Bureaucrat b7("Bureaucrat 7", 40);
        b7.signForm(f1);
    }catch(const std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Bureaucrat b8("Bureaucrat 8", 150);
        Form f2("Form 2", 100, 100);
        b8.signForm(f2);
    }catch(const std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	return 0;
}
