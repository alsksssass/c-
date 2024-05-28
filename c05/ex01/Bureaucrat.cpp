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
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	std::string a = "can't increase grade as much as " + std::to_string(num);
	const char *ret = a.c_str();
	return ret;
}
const char* Bureaucrat::GradeTooLowException::what() const throw(){
	std::string a = "can't decrease grade as much as " + std::to_string(num);
	const char *ret = a.c_str();
	return ret;
}

void Bureaucrat::signForm(Form &a){
	try{
		a.beSigned(*this);
	}
	catch(std::exception &e)
	{
		std::cout << this->Bureaucrat::getName() <<" couldn't sign " << a.Form::getName() << " becuse \"" << this->getGrade() << "\" " << e.what() << std::endl;
		return;
	}
	std::cout << this->Bureaucrat::getName() <<" signed " << a.Form::getName() << std::endl; 
}

void Bureaucrat::decreaseGrade(int num){
	if(grade + num > 150)
		throw Bureaucrat::GradeTooLowException(num);
	grade+=num;
	std::cout << "now " << name << "'s grade is " << grade << std::endl;
}
void Bureaucrat::increaseGrade(int num){
	if(grade - num < 1)
		throw Bureaucrat::GradeTooHighException(num);
	grade-=num;
	std::cout << "now " << name << "'s grade is " << grade << std::endl;
}

std::ostream& operator << (std::ostream &os, Bureaucrat &a){
	os << a.getName() << " bureaucrat grade " << a.getGrade() ;
	return os;
}