#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (){
	Bureaucrat a("sabyun");
	ShrubberyCreationForm *b = new ShrubberyCreationForm("home");
	AForm *d = new ShrubberyCreationForm("cafe");
	AForm *e = new RobotomyRequestForm("sabyun");
	AForm *f = new PresidentialPardonForm("chansjeo");
	
	a.decreaseGrade(0);
	a.increaseGrade(10);
	a.increaseGrade(150);
	a.decreaseGrade(150);
	std::cout << a << std::endl;
	b->execute(a);
	a.signForm(*b);
	b->execute(a);
	a.increaseGrade(138);
	b->execute(a);
	d->execute(a);
	a.signForm(*e);
	e->execute(a);
	e->execute(a);
	e->execute(a);
	e->execute(a);
	e->execute(a);
	a.decreaseGrade(100);
	e->execute(a);
	a.signForm(*f);
	f->execute(a);
	a.increaseGrade(100);
	a.signForm(*f);
	f->execute(a);

	delete b;
	delete d;
	delete e;
	delete f;

}