#include "Bureaucrat.hpp"
#include "Intern.hpp"
// void la (){system("leaks a.out");}
int main (){
    Intern someRandomIntern;
	Bureaucrat a("sabyun");
	a.increaseGrade(140);
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;	
	a.signForm(*rrf);
	rrf->execute(a);
	delete rrf;
    rrf = someRandomIntern.makeForm("nono", "sabyun");
    rrf = someRandomIntern.makeForm("shrubbery creation", "enbyel");
	delete rrf;
	// std::atexit(la);
}