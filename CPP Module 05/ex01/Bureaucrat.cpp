#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("none"){
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name){
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(grade > 150)
        throw  Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src){
    *this = src;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& obj){
    if(obj.grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(obj.grade > 150)
        throw  Bureaucrat::GradeTooLowException();
    this->grade = obj.grade;
    return *this;
}

std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::incrementGrade(){
    this->grade--;
    if(this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
    this->grade++;
    if(this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "TooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "TooLowException";
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& obj){
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return o;
}
