#include "MateriaSource.hpp"
MateriaSource::MateriaSource(){
	std::cout << "MateriaSource Construct Call" << std::endl;
	for(int i = 0; i < 4; i++)
		memory[i] = 0;
}
MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource Destruct Call" << std::endl;
	for(int i = 0; i < 4; i++)
		delete memory[i];
}
MateriaSource::MateriaSource(const MateriaSource &a){
	std::cout << "MateriaSource Copy Construct Call" << std::endl;
	for(int i =0; i < 4; i++)
	{
		if(memory[i] != NULL)
			delete memory[i];
		memory[i] = a.memory[i]->clone();
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource &a){
	std::cout << "MateriaSource assignment operator Call" << std::endl;
	if (this != &a)
	{
		for (int i = 0; i < 4; i++)
		{
			if (memory[i] != NULL)
				delete memory[i];
			memory[i] = a.memory[i]->clone();
		}
	}
	return *this;
}
AMateria* MateriaSource::createMateria(std::string const & type){
	AMateria *a = 0;
	for(int i = 0; i < 4; i++)
	{
		if(memory[i]->getType() == type)
			return a = memory[i]->clone();
	}
	return a;
}
void MateriaSource::learnMateria(AMateria* a){
	for(int i = 0; i < 4; i++)
	{
		if(memory[i] == NULL)
		{
			memory[i] = a;
			return;
		}
	}
}