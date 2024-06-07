#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	std::string target;
	PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
public:
	PresidentialPardonForm(const std::string _target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &a);
	virtual void execute(Bureaucrat const & executor) const;
	const std::string getTarget() const;
};

#endif // PRESIDENTIALPARDONFORM_HPP