#include "Intern.hpp"

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern &){
}
Intern& Intern::operator=(const Intern &){
	return *this;
}
AForm *Intern::makeForm(std::string f_name, std::string _target)
{
	std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*ptr_aform[3])(std::string) = {&Intern::ShrubberyClone, &Intern::RobotomyClone, &Intern::PresidentClone};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] == f_name)
			{
				std::cout << "Intern creates " << f_name << std::endl;
				return (this->*ptr_aform[i])(_target);
			}
		}
		throw Intern::ErrorForm();
	}
	catch (std::exception &e)
	{
		std::cout << f_name << " creation error cuz " << e.what() << std::endl;
	}
	return NULL;
}
AForm* Intern::ShrubberyClone(std::string _target){
	return new ShrubberyCreationForm(_target);
}
AForm* Intern::RobotomyClone(std::string _target){
	return new RobotomyRequestForm(_target);
}
AForm* Intern::PresidentClone(std::string _target){
	return new PresidentialPardonForm(_target);
}