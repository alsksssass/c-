#include "Bureaucrat.hpp"

int main (){
	Bureaucrat a("sabyun",150);
	try{
	a.decreaseGrade(0);
	a.increaseGrade(10);
	std::cout << a << std::endl;
	a.increaseGrade(150);
	//a.increaseGrade(140);
	a.decreaseGrade(150);
	}
	catch(std::exception &e){
		std::cout << "error "<< e.what() << std::endl;
	}
	try{
		Bureaucrat b("enbyel",-1);
	}
	catch(std::exception &e)
	{
		std::cout << "error " << e.what() << std::endl;
	}

}