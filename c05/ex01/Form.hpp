#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string Name;	
	bool Sign;
	const int Required_grade;
	const int Required_execute;
	Form();
	Form &operator=(const Form &a);
public:
	class GradeTooHighException : public std::exception{
		public:
		GradeTooHighException(){}
		virtual const char* what() const throw(){return "this grade is too High to do";}
	};
	class GradeTooLowException : public std::exception{
		public:
		GradeTooLowException(){}
		virtual const char* what() const throw(){return "this grade is too Low to do ";}

	};
	Form(const std::string _Name,const int _Required_grade,const int _required_execute);
	~Form();
	Form(const Form &a);
	void beSigned(const Bureaucrat &a);
	int getRequired_grade() const;
	int getRequired_execute() const;
	const std::string getName() const;
	bool is_signed() const;
};

std::ostream& operator << (std::ostream &os, Form &a);
#endif // FORM_HPP