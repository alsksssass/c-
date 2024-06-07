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
	AForm* makeForm(const std::string f_name, const std::string _target);
	AForm* ShrubberyClone(const std::string _target);
	AForm* RobotomyClone(const std::string _target);
	AForm* PresidentClone(const std::string _target);
};

#endif // INTERN_HPP