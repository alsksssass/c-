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
		private: 
			int num;
		public:
			GradeTooHighException(int _num) : num(_num) {}
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		private:
			int num;
		public:
			GradeTooLowException(int _num) : num(_num) {}
			virtual const char* what() const throw();
	};
	Bureaucrat(std::string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &a);
	Bureaucrat &operator=(const Bureaucrat &a);
	friend std::ostream& operator << (std::ostream &os, Bureaucrat &a);
	std::string getName() const;
	int getGrade() const;
	void decreaseGrade(int num);
	void increaseGrade(int num);
};

#endif // BUREAUCRAT_HPP