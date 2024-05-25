#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Construct Call" << std::endl;
}
Brain::~Brain(){
	std::cout << "Brain Destruct Call" << std::endl;
}
Brain::Brain(const Brain &a){
	std::cout << "Brain Copy Construct Call" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = a.ideas[i];
}
Brain& Brain::operator=(const Brain &a){
	std::cout << "Brain assignment operator Call" << std::endl;
	if(this != &a)
		for(int i = 0; i < 100; i++)
			ideas[i] = a.ideas[i];
	return *this;
}
void Brain::setBrain(int idx, const std::string memory)
{
	std::cout << "Brain Set Call" << std::endl;
	ideas[idx] = memory;
}
std::string Brain::getBrain(int idx)
{
	return ideas[idx];
}