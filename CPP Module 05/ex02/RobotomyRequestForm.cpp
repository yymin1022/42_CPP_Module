#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", target, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if(this != &other){
        this->~RobotomyRequestForm();
        new (this) RobotomyRequestForm(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
    static bool isFirst = true;
    if(isFirst){
        std::srand(std::time(0));
        isFirst = false;
    }

    if(!getIsSigned())
		throw AForm::FormNotSignedException();
    if(executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    if(std::rand() % 2){
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    }else{
        std::cout << "Robotomy failed" << std::endl;
    }
}
