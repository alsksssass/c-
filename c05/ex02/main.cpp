#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (){
	Bureaucrat sabyun("sabyun",150);
	AForm *sigined_test = new ShrubberyCreationForm("home");
	AForm *no_sigined_test = new ShrubberyCreationForm("cafe");
	AForm *robo = new RobotomyRequestForm("sabyun");
	AForm *president = new PresidentialPardonForm("chansjeo");
	
	sabyun.decreaseGrade(0);
	sabyun.increaseGrade(10);
	sabyun.increaseGrade(150);
	sabyun.decreaseGrade(150);
	std::cout << sabyun << std::endl;
	sabyun.executeForm(*sigined_test);
	sabyun.signForm(*sigined_test);
	sabyun.executeForm(*sigined_test);
	sabyun.increaseGrade(138);
	sabyun.executeForm(*sigined_test);
	sabyun.executeForm(*no_sigined_test);
	sabyun.signForm(*robo);
	sabyun.executeForm(*robo);
	sabyun.executeForm(*robo);
	sabyun.executeForm(*robo);
	sabyun.executeForm(*robo);
	sabyun.executeForm(*robo);
	sabyun.decreaseGrade(100);
	sabyun.executeForm(*robo);
	sabyun.signForm(*president);
	sabyun.executeForm(*president);
	sabyun.increaseGrade(100);
	sabyun.signForm(*president);
	sabyun.executeForm(*president);

	delete sigined_test;
	delete no_sigined_test;
	delete robo;
	delete president;

}