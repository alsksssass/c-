#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("name") , grade(150){}
Bureaucrat::Bureaucrat(const std::string name,const int _grade) : name(name) , grade(_grade){
	if(_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &a) : name(a.getName()), grade(a.getGrade()){
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a) {
	if(this == &a) return *this;
	if(this != &a)
		grade = a.getGrade();
	return *this;
}
const std::string Bureaucrat::getName() const{
	return name;
}
int Bureaucrat::getGrade() const{
	return grade;
}

void Bureaucrat::signForm(AForm &a){
	try{
		a.beSigned(*this);
	}
	catch(std::exception &e)
	{
		std::cout << this->Bureaucrat::getName() <<" couldn't sign " << a.AForm::getName() << " becuse \"" << this->getGrade() << "\" " << e.what() << std::endl;
		return;
	}
	std::cout << this->Bureaucrat::getName() <<" signed " << a.AForm::getName() << std::endl; 
}

void Bureaucrat::decreaseGrade(const int num){
	try{
		if(grade + num > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(std::exception &e)
	{
		std::cout << "error "<< e.what() << num << std::endl;
		return;
	}
	grade+=num;
	std::cout << "now " << name << "'s grade is " << grade << std::endl;
}
void Bureaucrat::increaseGrade(const int num){
	try{
		if(grade - num < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(std::exception &e)
	{
		std::cout << "error "<< e.what() << num << std::endl;
		return;
	}
	grade-=num;
	std::cout << "now " << name << "'s grade is " << grade << std::endl;
}

std::ostream& operator << (std::ostream &os, Bureaucrat &a){
	os << a.getName() << " bureaucrat grade " << a.getGrade() ;
	return os;
}

void Bureaucrat::executeForm(AForm const & form){
	form.execute(*this);
}

