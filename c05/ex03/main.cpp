#include "Bureaucrat.hpp"
#include "Intern.hpp"
//void la (){system("leaks sabyun.out");}
int main (){
    Intern someRandomIntern;
	Bureaucrat sabyun("sabyun",150);
	sabyun.increaseGrade(140);
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;	
	sabyun.signForm(*rrf);
	sabyun.executeForm(*rrf);
	delete rrf;
	try{
		rrf = someRandomIntern.makeForm("nono", "sabyun");
	}
	catch(std::exception &e)
	{
		std::cout << "error " << e.what() << std::endl;
	}
    rrf = someRandomIntern.makeForm("shrubbery creation", "enbyel");
	delete rrf;
	//std::atexit(la);
}
