//Required grades: sign 25, exec 5
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25,5), target("NONE"){}
PresidentialPardonForm::PresidentialPardonForm(std::string _target)  : AForm("PresidentialPardonForm",25,5), target(_target){}
PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : AForm("PresidentialPardonForm",25,5), target(a.getTarget()){}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &a){
	if(this != &a)
	{
		target = a.getTarget();
	}
	return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if(AForm::accessCheck(executor) == false)
		return;
	std::cout << this->getTarget() << " that has been pardoned by Zaphod Beeblebrox." << std::endl;
}
std::string PresidentialPardonForm::getTarget() const{
	return target;
}