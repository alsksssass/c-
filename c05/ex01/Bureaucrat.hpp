#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"
class Form;

class Bureaucrat {
private:
	const std::string name;
	int grade;
	Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &a);
public:
	class GradeTooHighException : public std::exception{
		private: 
			int num;
		public:
			GradeTooHighException(int _num) : num(_num) {}
			virtual ~GradeTooHighException() throw() {};
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		private:
			int num;
		public:
			GradeTooLowException(int _num) : num(_num) {}
			virtual ~GradeTooLowException() throw() {};
			virtual const char* what() const throw();
	};
	Bureaucrat(std::string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &a);
	friend std::ostream& operator << (std::ostream &os, Bureaucrat &a);
	void signForm(Form &a);
	std::string getName() const;
	int getGrade() const;
	void decreaseGrade(int num);
	void increaseGrade(int num);
};

#endif // BUREAUCRAT_HPP