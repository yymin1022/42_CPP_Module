#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
        Form form1("Form 1", 150, 150);
        Bureaucrat bCrat1("Bob", 1);
        form1.setSignature(bCrat1);
        bCrat1.incrementGrade();
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "---------" << std::endl;

    try{
        Form form1("Form 1", 1, 1);
        std::cout << form1;
        Bureaucrat bCrat1("Bob", 150);
        form1.setSignature(bCrat1);
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

	return 0;
}
