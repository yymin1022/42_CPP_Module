#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if(this != &other){
        this->~ShrubberyCreationForm();
        new (this) ShrubberyCreationForm(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
    if(!getIsSigned())
		throw AForm::FormNotSignedException();
    if(executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

    std::ofstream file((getTarget() + "_shrubbery").c_str());

    if(!file.is_open())
		throw AForm::FileOpenException();

    file << "          @@@          &&&&&&&&&&&&&&&&&&&&&&&&&        " << std::endl;
    file << "       @@@@ @@@@     &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    " << std::endl;
    file << "     @@@ @@@ @@@   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   " << std::endl;
    file << "    @@@ @@@@@@@@  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  " << std::endl;
    file << "   @@@ @@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << std::endl;
    file << "   @@@ @@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << std::endl;
    file << "   @@@ @@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << std::endl;
    file << "      &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   " << std::endl;
    file << "          |||           |||           |||           |||  " << std::endl;
    file << "          |||           |||           |||           |||  " << std::endl;
    file.close();
}
