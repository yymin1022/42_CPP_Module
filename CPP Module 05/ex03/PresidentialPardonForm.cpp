#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", target, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if(this != &other){
        this->~PresidentialPardonForm();
        new (this) PresidentialPardonForm(other);
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
    if(!getIsSigned())
		throw AForm::FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
