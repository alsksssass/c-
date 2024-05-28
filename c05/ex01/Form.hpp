#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string Name;	
	bool Sign;
	int Required_grade;
	int Required_execute;
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
	Form(std::string _Name,bool _Sign, int _Required_grade, int _required_execute);
	~Form();
	Form(const Form &a);
	std::ostream& operator << (std::ostream &os);
	void beSigned(Bureaucrat &a);
	int getRequired_grade() const;
	int getRequired_execute() const;
	std::string getName() const;
	bool is_signed() const;
};

#endif // FORM_HPP