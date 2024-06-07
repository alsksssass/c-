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

void Bureaucrat::decreaseGrade(int num){
	if(grade + num > 150)
		throw Bureaucrat::GradeTooLowException();
	grade+=num;
	std::cout << "now " << name << "'s grade is " << grade << std::endl;
}
void Bureaucrat::increaseGrade(int num){
	if(grade - num < 1)
		throw Bureaucrat::GradeTooHighException();
	grade-=num;
	std::cout << "now " << name << "'s grade is " << grade << std::endl;
}

std::ostream& operator << (std::ostream &os, Bureaucrat &a){
	os << a.getName() << " bureaucrat grade " << a.getGrade() ;
	return os;
}