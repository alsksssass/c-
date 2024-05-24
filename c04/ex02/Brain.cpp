#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Construct Call" << std::endl;
	ideas = new std::string [100];
}
Brain::~Brain(){
	std::cout << "Brain Destruct Call" << std::endl;
	delete []ideas;
}
Brain::Brain(const Brain &a){
	std::cout << "Brain Copy Construct Call" << std::endl;
	std::copy(a.ideas->begin(),a.ideas->end()-1,ideas);
}
Brain& Brain::operator=(const Brain &a){
	std::cout << "Brain assignment operator Call" << std::endl;
	if(this != &a)
		std::copy(a.ideas->begin(),a.ideas->end()-1,ideas);
	return *this;
}