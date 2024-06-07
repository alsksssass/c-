#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",72,45), target("NONE"){}// sign 72, exec 45
RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("RobotomyRequestForm",72,45), target(_target){}// sign 72, exec 45
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : AForm("RobotomyRequestForm",72,45), target(a.getTarget()){}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &a){
	if(this != &a)
	{
		target = a.getTarget();
	}
	return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(accessCheck(executor) == false)
		return;
	std::cout << executor.getName() <<  " executed "  << this->getName() << std::endl;
	std::srand(std::time(0) + std::rand());
	std::cout << "drilling noises!!" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomized failed" << std::endl;
}
const std::string RobotomyRequestForm::getTarget() const{
	return target;
}