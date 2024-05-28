#include "Bureaucrat.hpp"

int main (){
	Bureaucrat a("sabyun");
	Form f("need water",false,1,1);
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

}