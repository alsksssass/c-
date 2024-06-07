#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
class Bureaucrat {
private:
	const std::string name;
	int grade;
	Bureaucrat();
public:
	class GradeTooHighException : public std::exception{
		public:
			GradeTooHighException() {}
			virtual const char* what() const throw() {return "can't increase grade as much as ";}
	};
	class GradeTooLowException : public std::exception{
		public:
			GradeTooLowException() {}
			virtual const char* what() const throw() {return "can't decrease grade as much as ";}
	};
	Bureaucrat(const std::string name,const int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &a);
	Bureaucrat &operator=(const Bureaucrat &a);
	const std::string getName() const;
	int getGrade() const;
	void decreaseGrade(int num);
	void increaseGrade(int num);
};

std::ostream& operator << (std::ostream &os, Bureaucrat &a);
#endif // BUREAUCRAT_HPP