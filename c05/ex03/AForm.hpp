#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string Name;	
	bool Sign;
	const int Required_grade;
	const int Required_execute;
	AForm();
	AForm &operator=(const AForm &a);
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
	class NotSignedException : public std::exception{
		public:
		NotSignedException(){}
		virtual const char * what() const throw() {return "Not signed yet!";}
	};
	class NullPtr : public std::exception{
		public:
		NullPtr(){}
		virtual const char *waht() const throw() {return "Null accepted!";}
	};
	AForm(const std::string _Name,const int _Required_grade,const int _Required_execute);
	virtual ~AForm();
	AForm(const AForm &a);
	void beSigned(const Bureaucrat &a);
	bool accessCheck(const Bureaucrat &a) const;
	int getRequired_grade() const;
	int getRequired_execute() const;
	const std::string getName() const;
	bool is_signed() const;
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator << (std::ostream &os, AForm &a);
#endif // AFORM_HPP