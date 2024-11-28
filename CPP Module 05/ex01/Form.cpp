#include "Form.hpp"

Form::Form()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150){};

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

Form::~Form(){}

Form &Form::operator=(const Form &other){
    if(this != &other){
        this->~Form();
        new (this) Form(other);
    }
    return *this;
}

const std::string &Form::getName() const{
    return name;
}

bool Form::getIsSigned() const{
    return isSigned;
}

int Form::getGradeToSign() const{
    return gradeToSign;
}

int Form::getGradeToExecute() const{
    return gradeToExecute;
}

void Form::makeSign(const Bureaucrat &bureaucrat){
    if(isSigned)
        throw Form::FormAlreadySignedException();
    if(bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}

const char *Form::FormAlreadySignedException::what() const throw(){
    return "Form is already signed";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

std::ostream &operator<<(std::ostream &os, const Form &form){
    if(form.getIsSigned())
        os << form.getName() << " form is signed and grade to sign is " << form.getGradeToSign()
           << " and grade to execute is " << form.getGradeToExecute();
    else
        os << form.getName() << " form is not signed and grade to sign is " << form.getGradeToSign()
           << " and grade to execute is " << form.getGradeToExecute();
    return os;
}
