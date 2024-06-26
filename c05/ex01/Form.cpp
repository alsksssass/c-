#include "Form.hpp"

Form::Form() : Name("name"), Sign(false), Required_grade(150), Required_execute(150) {}
Form::Form(const std::string _Name,const int _Required_grade,const int _Required_execute) : 
Name(_Name) , Sign(false), Required_grade(_Required_grade), Required_execute(_Required_execute)
{
	if(_Required_grade < 1 || _Required_execute < 1)
		throw Form::GradeTooHighException();
	if(_Required_grade > 150 || _Required_execute > 150)
		throw Form::GradeTooLowException();
}
Form::~Form(){}
Form::Form(const Form &a) : 
Name(a.getName()) , Sign(a.is_signed()), Required_grade(a.getRequired_grade()), Required_execute(a.getRequired_execute()) 
{}
Form& Form::operator=(const Form &a) {
	if(this == &a) return *this;
	return *this;
}
int Form::getRequired_grade() const{
	return Required_grade;
}
int Form::getRequired_execute() const{
	return Required_execute;
}
const std::string Form::getName() const{
	return Name;
}
bool Form::is_signed() const{
	return Sign;
}

void Form::beSigned(const Bureaucrat &a){
	if(a.getGrade() > this->getRequired_grade())
		throw Form::GradeTooLowException();
	Sign = true;
}

std::ostream& operator << (std::ostream &os, Form &a){
	os << "form name is :" << a.getName() << " is signed :" << (a.is_signed() == false ? "Not yet." : "Signed") << std::endl;
	os << "Required_grade : " << a.getRequired_grade() << " Required_execute : " << a.getRequired_execute();
	return os;
}
