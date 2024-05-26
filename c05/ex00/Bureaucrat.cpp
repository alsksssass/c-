#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("name") , grade(150){}
Bureaucrat::Bureaucrat(std::string name) : name(name) , grade(150){}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &a) : Bureaucrat(a.getName()){
	grade = a.getGrade();
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a) {
	if(this != &a)
	{
		
	}
}
std::string Bureaucrat::getName() const{
	return name;
}
int Bureaucrat::getGrade() const{
	return grade;
}
void Bureaucrat::GradeTooHighException(int a);
void Bureaucrat::GradeTooLowException(int a);