#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
class Bureaucrat {
private:
	const std::string name;
	int grade;
	Bureaucrat();
public:
	Bureaucrat(std::string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &a);
	Bureaucrat &operator=(const Bureaucrat &a);
	std::string getName() const;
	int getGrade() const;
	void GradeTooHighException(int a);
	void GradeTooLowException(int a);
};

#endif // BUREAUCRAT_HPP