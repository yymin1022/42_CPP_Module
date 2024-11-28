#include "AForm.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150){};

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute)
    : name(name), target(target), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), target(other.target), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

AForm::~AForm(){}

AForm& AForm::operator=(const AForm &other){
    if(this != &other){
        return *this;
    }
    return *this;
}

const std::string& AForm::getName() const{
    return name;
}

const std::string& AForm::getTarget() const{
    return target;
}

bool AForm::getIsSigned() const{
    return isSigned;
}

int AForm::getGradeToSign() const{
    return gradeToSign;
}

int AForm::getGradeToExecute() const{
    return gradeToExecute;
}

void AForm::makeSign(const Bureaucrat &bureaucrat){
    if(isSigned)
        throw AForm::FormAlreadySignedException();
    if(bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

const char *AForm::FormAlreadySignedException::what() const throw(){
    return "Form is already signed";
}

const char *AForm::FormNotSignedException::what() const throw(){
    return "Form is not signed";
}

const char *AForm::FileOpenException::what() const throw(){
    return "Failed to open file";
}

std::ostream &operator<<(std::ostream &os, const AForm &form){
    if(form.getIsSigned())
        os << form.getName() << " form is signed and grade to sign is " << form.getGradeToSign()
           << " and grade to execute is " << form.getGradeToExecute();
    else
        os << form.getName() << " form is not signed and grade to sign is " << form.getGradeToSign()
           << " and grade to execute is " << form.getGradeToExecute();
    return os;
}
