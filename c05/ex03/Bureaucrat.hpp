#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat {
private:
	const std::string name;
	int grade;
	Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &a);
public:
	class GradeTooHighException : public std::exception{
		public:
			GradeTooHighException(){}
			virtual const char* what() const throw() {return "can't increase grade as much as ";}
	};
	class GradeTooLowException : public std::exception{
		public:
			GradeTooLowException(){}
			virtual const char* what() const throw() {return "can't decrease grade as much as ";}
	};
	Bureaucrat(const std::string name,const int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &a);
	void signForm(AForm &a);
	const std::string getName() const;
	int getGrade() const;
	void decreaseGrade(const int num);
	void increaseGrade(const int num);
	void executeForm(AForm const & form);
};

std::ostream& operator << (std::ostream &os, Bureaucrat &a);
#endif // BUREAUCRAT_HPP