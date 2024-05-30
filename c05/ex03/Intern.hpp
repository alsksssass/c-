#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	class ErrorForm : public std::exception{
		public:
		ErrorForm(){}
		virtual const char * what() const throw(){ return "there is no form";}
	};
	Intern();
	~Intern();
	Intern(const Intern &a);
	Intern &operator=(const Intern &a);
	AForm* makeForm(std::string f_name, std::string _target);
	AForm* ShrubberyClone(std::string _target);
	AForm* RobotomyClone(std::string _target);
	AForm* PresidentClone(std::string _target);
};

#endif // INTERN_HPP