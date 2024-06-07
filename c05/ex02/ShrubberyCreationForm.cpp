#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145,137) , target("NONE"){}// sign 145, exec 137
ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) : AForm("ShrubberyCreationForm",145,137) , target(_target){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : AForm(a), target(a.getTarget()){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a){
	if(this != &a)
		target = a.getTarget();
	return *this;
}
const std::string ShrubberyCreationForm::getTarget() const{
	return target;
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if(accessCheck(executor) == false)
		return;
	std::ofstream wfile;
	std::string out_name = this->getTarget() + "_shrubbery";
	try{
		wfile.open(out_name.c_str(),std::ios::out | std::ios::trunc);
		if(wfile.fail())
			throw FileOpenFail();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() <<std::endl;
		return;
	}
	std::cout << executor.getName() <<  " executed "  << this->getName() << std::endl;
	std::string tree = TREE;
    wfile << tree;
	wfile.close();
}
