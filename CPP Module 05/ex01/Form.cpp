#include "Form.hpp"

Form::Form(){
    this->name = "Unknown Form";
    this->isSignedFlag = false;
    this->gradeLevelSign = 150;
    this->gradeLevelExec = 150;
}

Form::Form(const std::string name, int signGrade, int execGrade){
    this->name = name;
    this->isSignedFlag = false;

    if(signGrade < 1 || execGrade < 1)
        throw gradeTooHighException();
    else if(signGrade > 150 || execGrade > 150)
        throw gradeTooLowException();
    else if(signGrade > execGrade)
        throw gradeTooHighException();
    else{
        this->gradeLevelSign = signGrade;
        this->gradeLevelExec = execGrade;
    }
}

Form::Form(Form const &src){
    *this = src;
}

Form::~Form(){}

Form &Form::operator=(Form const &obj){
    this->name = obj.name;
    this->isSignedFlag = obj.isSignedFlag;
    this->gradeLevelExec = obj.gradeLevelExec;
    this->gradeLevelSign = obj.gradeLevelSign;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, Form const &obj){
	out << obj.getName() << " Form:" << std::endl;
	out << "Status:" << obj.isSigned() << std::endl;
	out << "Grade to sign:" << obj.getSignGrade() << std::endl;
	out << "Grade to execute:" << obj.getExecGrade() << std::endl;
	return (out);
}

std::string Form::getName() const{
    return (this->name);
}

int Form::getSignGrade() const{
    return (this->gradeLevelSign);
}

int Form::getExecGrade() const{
    return (this->gradeLevelExec);
}

std::string Form::isSigned() const{
    if(isSignedFlag)
        return "True";
    else
        return "False";
}

void Form::setSignature(Bureaucrat const &bcrat){
	if(this->isSignedFlag == true)
        std::cout << "Form already signed" << std::endl;
    else if(this->gradeLevelSign < bcrat.getGrade()){
        std::cout << "Bureucrat " << bcrat.getName() << " not qualified to sign this form." << std::endl;
        throw gradeTooLowException();
    }else{
        this->isSignedFlag = true;
        std::cout << "Bureucrat " << bcrat.getName() << " has signed the " << this->name << " form" << std::endl;
    }

}

const char *Form::gradeTooLowException::what() const throw(){
    return "Bureucrats Grade is too low and cant sign this form";
}

const char *Form::gradeTooHighException::what() const throw(){
    return "Grade is too high should be between 1 & 150";
}
