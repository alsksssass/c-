#include "Bureaucrat.hpp"

int main (){
	Bureaucrat a("sabyun",150);
	Form f("need water",1,1);
	try{
	a.decreaseGrade(0);
	a.increaseGrade(10);
	std::cout << a << std::endl;
	// a.increaseGrade(150);
	a.increaseGrade(138);
	}
	catch(std::exception &e){
		std::cout << "error "<< e.what() << std::endl;
	}
	a.signForm(f);
	std::cout << a << std::endl;
	std::cout << f << std::endl;
	a.increaseGrade(1);
	a.signForm(f);
	std::cout << a << std::endl;
	std::cout << f << std::endl;
	try{
		Form f("need water",-1,1);
	}
	catch(std::exception &e)
	{
		std::cout << "error " << e.what() << std::endl;
	}

}