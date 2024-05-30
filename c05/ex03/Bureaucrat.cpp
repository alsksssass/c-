#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("name") , grade(150){}
Bureaucrat::Bureaucrat(std::string name) : name(name) , grade(150){}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &a) : name(a.getName()), grade(a.getGrade()){
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a) {
	if(this == &a) return *this;
	if(this != &a)
		grade = a.getGrade();
	return *this;
}
std::string Bureaucrat::getName() const{
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

void Bureaucrat::decreaseGrade(int num){
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
void Bureaucrat::increaseGrade(int num){
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

