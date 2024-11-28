#include "Bureaucrat.hpp"

int main(){
	try{
        Bureaucrat bureaucrat1("Bureaucrat 1", 1);
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade();
    }catch(const std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat2("Bureaucrat 2", 150);
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
    }catch(const std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat3("Bureaucrat 3", 0);
        std::cout << bureaucrat3 << std::endl;
    }catch(const std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat4("Bureaucrat 4", 151);
        std::cout << bureaucrat4 << std::endl;
    }catch(const std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat5("Bureaucrat 5", 75);
        std::cout << bureaucrat5 << std::endl;
        bureaucrat5.incrementGrade();
        std::cout << "After increment: " << bureaucrat5 << std::endl;
        bureaucrat5.decrementGrade();
        std::cout << "After decrement: " << bureaucrat5 << std::endl;
    }catch(const std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	return 0;
}
