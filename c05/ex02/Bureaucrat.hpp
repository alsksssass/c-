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
	Bureaucrat(std::string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &a);
	friend std::ostream& operator << (std::ostream &os, Bureaucrat &a);
	void signForm(AForm &a);
	std::string getName() const;
	int getGrade() const;
	void decreaseGrade(int num);
	void increaseGrade(int num);
};

#endif // BUREAUCRAT_HPP