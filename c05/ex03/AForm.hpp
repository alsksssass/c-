#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string Name;	
	bool Sign;
	int Required_grade;
	int Required_execute;
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
	AForm(std::string _Name,int _Required_grade, int _required_execute);
	virtual ~AForm();
	AForm(const AForm &a);
	friend std::ostream& operator << (std::ostream &os, AForm &a);
	void beSigned(const Bureaucrat &a);
	bool accessCheck(const Bureaucrat &a) const;
	int getRequired_grade() const;
	int getRequired_execute() const;
	std::string getName() const;
	bool is_signed() const;
	virtual void execute(Bureaucrat const & executor) const = 0;
};

#endif // AFORM_HPP