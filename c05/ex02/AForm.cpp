#include "AForm.hpp"

AForm::AForm() : Name("name"), Sign(false), Required_grade(150), Required_execute(150) {}
AForm::AForm(const std::string _Name,const int _Required_grade,const int _Required_execute) : 
Name(_Name) , Sign(false), Required_grade(_Required_grade), Required_execute(_Required_execute)
{
	if(_Required_grade < 1 || _Required_execute < 1)
		throw AForm::GradeTooHighException();
	if(_Required_grade > 150 || _Required_execute > 150)
		throw AForm::GradeTooLowException();
}
AForm::~AForm(){}
AForm::AForm(const AForm &a) : 
Name(a.getName()) , Sign(a.is_signed()), Required_grade(a.getRequired_grade()), Required_execute(a.getRequired_execute()) 
{}
AForm& AForm::operator=(const AForm &a) {
	if(this == &a) return *this;
	return *this;
}
int AForm::getRequired_grade() const{
	return Required_grade;
}
int AForm::getRequired_execute() const{
	return Required_execute;
}
const std::string AForm::getName() const{
	return Name;
}
bool AForm::is_signed() const{
	return Sign;
}

void AForm::beSigned(const Bureaucrat &a){
	if(a.getGrade() > this->getRequired_grade())
		throw AForm::GradeTooLowException();
	Sign = true;
}

std::ostream& operator << (std::ostream &os, AForm &a){
	os << "form name is :" << a.getName() << " is signed :" << (a.is_signed() == false ? "Not yet." : "Signed") << std::endl;
	os << "Required_grade : " << a.getRequired_grade() << " Required_execute : " << a.getRequired_execute();
	return os;
}
bool AForm::accessCheck(const Bureaucrat &a) const
{
	try
	{
		if (this->is_signed() == false)
			throw AForm::NotSignedException();
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " " << e.what() << std::endl;
		return false;
	}
	try
	{
		if (this->getRequired_execute() < a.getGrade())
			throw AForm::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << a.getName() << "can't execute " << this->getName() << " cuz " << e.what() << std::endl;
		return false;
	}
	return true;
}
