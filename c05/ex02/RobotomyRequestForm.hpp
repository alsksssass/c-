#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
	std::string target;
	RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
public:
	RobotomyRequestForm(std::string _target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &a);
	virtual void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP